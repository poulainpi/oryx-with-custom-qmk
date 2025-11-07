#!/usr/bin/env pwsh
# Local Docker-based QMK firmware build script for ZSA Voyager
# Usage: .\build-local.ps1

param(
    [switch]$Clean,
    [switch]$NoBuild
)

$ErrorActionPreference = "Stop"

Write-Host "🔨 ZSA Voyager Local Build Script" -ForegroundColor Cyan
Write-Host "=================================" -ForegroundColor Cyan
Write-Host ""

# Configuration
$ImageName = "qmk-builder"
$ContainerName = "qmk-build-temp"
$Keyboard = "voyager"
$Keymap = "JRaem"

# Check if Docker is available
try {
    docker --version | Out-Null
} catch {
    Write-Host "❌ Error: Docker is not installed or not in PATH" -ForegroundColor Red
    Write-Host "Please install Docker Desktop: https://www.docker.com/products/docker-desktop" -ForegroundColor Yellow
    exit 1
}

# Clean up previous containers/images if requested
if ($Clean) {
    Write-Host "🧹 Cleaning previous build artifacts..." -ForegroundColor Yellow
    docker rm -f $ContainerName 2>$null | Out-Null
    docker rmi -f $ImageName 2>$null | Out-Null
    Write-Host "✅ Cleanup complete" -ForegroundColor Green
    Write-Host ""
}

# Build Docker image
if (-not $NoBuild) {
    Write-Host "🐳 Building Docker image..." -ForegroundColor Cyan
    docker build -t $ImageName .
    if ($LASTEXITCODE -ne 0) {
        Write-Host "❌ Docker build failed" -ForegroundColor Red
        exit 1
    }
    Write-Host "✅ Docker image built successfully" -ForegroundColor Green
    Write-Host ""
}

# Initialize QMK firmware in container
Write-Host "📦 Initializing QMK firmware..." -ForegroundColor Cyan
docker run --rm `
    --name "${ContainerName}-init" `
    -v "${PWD}:/workspace" `
    -w /workspace `
    $ImageName `
    bash -c @"
# Clone QMK if qmk_firmware doesn't exist or is empty
if [ ! -d qmk_firmware/.git ]; then
    echo '📥 Cloning QMK firmware repository...'
    git clone --recurse-submodules https://github.com/qmk/qmk_firmware.git
    cd qmk_firmware
    qmk setup -y
else
    echo '✅ QMK firmware already initialized'
    cd qmk_firmware
    git pull
fi

# Copy custom keymap to QMK directory
echo '📋 Copying custom keymap...'
mkdir -p keyboards/$Keyboard/keymaps/$Keymap
cp -r /workspace/JRaem/* keyboards/$Keyboard/keymaps/$Keymap/
echo '✅ Keymap copied'
"@

if ($LASTEXITCODE -ne 0) {
    Write-Host "❌ QMK initialization failed" -ForegroundColor Red
    exit 1
}
Write-Host "✅ QMK firmware initialized" -ForegroundColor Green
Write-Host ""

# Compile firmware
Write-Host "⚙️  Compiling firmware for $Keyboard ($Keymap)..." -ForegroundColor Cyan
docker run --rm `
    --name "${ContainerName}-compile" `
    -v "${PWD}:/workspace" `
    -w /workspace/qmk_firmware `
    $ImageName `
    qmk compile -kb $Keyboard -km $Keymap

if ($LASTEXITCODE -ne 0) {
    Write-Host "❌ Firmware compilation failed" -ForegroundColor Red
    exit 1
}

# Find and display the compiled firmware
$FirmwareFile = Get-ChildItem -Path "qmk_firmware" -Filter "${Keyboard}_${Keymap}.bin" -Recurse -ErrorAction SilentlyContinue | Select-Object -First 1

if ($FirmwareFile) {
    $SizeKB = [math]::Round($FirmwareFile.Length / 1KB, 2)
    $SizePercent = [math]::Round(($FirmwareFile.Length / 256KB) * 100, 1)
    
    Write-Host ""
    Write-Host "✅ Firmware compiled successfully!" -ForegroundColor Green
    Write-Host ""
    Write-Host "📊 Firmware Details:" -ForegroundColor Cyan
    Write-Host "   File: $($FirmwareFile.FullName)" -ForegroundColor White
    Write-Host "   Size: $SizeKB KB / 256 KB ($SizePercent%)" -ForegroundColor White
    
    if ($SizeKB -lt 230) {
        Write-Host "   Status: ✅ Within 90% target (<230 KB)" -ForegroundColor Green
    } elseif ($SizeKB -lt 256) {
        Write-Host "   Status: ⚠️  Above 90% target but still fits" -ForegroundColor Yellow
    } else {
        Write-Host "   Status: ❌ Too large! Exceeds flash size" -ForegroundColor Red
    }
    
    Write-Host ""
    Write-Host "📝 Next Steps:" -ForegroundColor Cyan
    Write-Host "   1. Connect your ZSA Voyager" -ForegroundColor White
    Write-Host "   2. Put it in bootloader mode (press reset button)" -ForegroundColor White
    Write-Host "   3. Use Keymapp or QMK Toolbox to flash:" -ForegroundColor White
    Write-Host "      $($FirmwareFile.FullName)" -ForegroundColor Yellow
} else {
    Write-Host "⚠️  Warning: Firmware file not found" -ForegroundColor Yellow
    Write-Host "Expected: qmk_firmware/${Keyboard}_${Keymap}.bin" -ForegroundColor Yellow
}

Write-Host ""
Write-Host "🎉 Build complete!" -ForegroundColor Green
