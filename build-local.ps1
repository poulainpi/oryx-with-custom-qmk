#!/usr/bin/env pwsh
# Local Docker-based QMK firmware build script for ZSA Voyager
# Usage: .\build-local.ps1 [-Keymap vrMEr] [-Clean]

param(
    [string]$Keymap = "vrMEr",
    [switch]$Clean
)

$ErrorActionPreference = "Stop"

Write-Host "🔨 ZSA Voyager Local Build Script" -ForegroundColor Cyan
Write-Host "=================================" -ForegroundColor Cyan
Write-Host ""

# Configuration
$ImageName = "qmk-builder"
$Keyboard = "zsa/voyager"

# Configuration
$ImageName = "qmk-builder"
$Keyboard = "zsa/voyager"

# Check if keymap directory exists
if (-not (Test-Path $Keymap)) {
    Write-Host "❌ Error: Keymap directory '$Keymap' not found" -ForegroundColor Red
    exit 1
}

Write-Host "✅ Keymap: $Keymap" -ForegroundColor Green

# Clear DOCKER_HOST for compatibility
$env:DOCKER_HOST = $null

# Check if Docker is available
try {
    $dockerVersion = docker version --format '{{.Server.Version}}' 2>$null
    if ($LASTEXITCODE -ne 0) {
        throw "Docker not running"
    }
    Write-Host "✅ Docker: $dockerVersion" -ForegroundColor Green
} catch {
    Write-Host "❌ Error: Docker is not available or not running" -ForegroundColor Red
    Write-Host "   Please start Docker Desktop and try again." -ForegroundColor Yellow
    exit 1
}

# Clean up previous artifacts if requested
if ($Clean) {
    Write-Host ""
    Write-Host "🧹 Cleaning previous build artifacts..." -ForegroundColor Yellow
    Remove-Item -Path "*.bin" -ErrorAction SilentlyContinue
    Remove-Item -Path "build.log" -ErrorAction SilentlyContinue
    Write-Host "✅ Cleanup complete" -ForegroundColor Green
    Write-Host ""
}

# Check/Build Docker image
$imageExists = docker images -q $ImageName 2>$null
if (-not $imageExists) {
    Write-Host ""
    Write-Host "🐳 Building Docker image..." -ForegroundColor Cyan
    Write-Host "   (This may take 2-3 minutes on first build)" -ForegroundColor Yellow
    Write-Host ""
    docker build -t $ImageName .
    if ($LASTEXITCODE -ne 0) {
        Write-Host "❌ Docker build failed" -ForegroundColor Red
        exit 1
    }
    Write-Host "✅ Docker image built successfully" -ForegroundColor Green
    Write-Host ""
} else {
    Write-Host "✅ Docker image: $ImageName" -ForegroundColor Green
}

Write-Host ""
Write-Host "⚙️  Compiling firmware..." -ForegroundColor Cyan
Write-Host "   Keyboard: $Keyboard" -ForegroundColor Gray
Write-Host "   Keymap: $Keymap" -ForegroundColor Gray
Write-Host "   (This may take a few minutes on first run)" -ForegroundColor Yellow
Write-Host ""

# Build firmware using the proven working method from ZSA fork
$buildCommand = @"
git clone --depth=1 --recurse-submodules https://github.com/zsa/qmk_firmware.git /qmk && \
cd /qmk && \
cp -r /workspace/$Keymap keyboards/zsa/voyager/keymaps/ && \
make zsa/voyager:$Keymap 2>&1 | tee /workspace/build.log && \
cp *.bin /workspace/ 2>/dev/null || true
"@

docker run --rm -v "${PWD}:/workspace" $ImageName bash -c $buildCommand

if ($LASTEXITCODE -ne 0) {
    Write-Host ""
    Write-Host "❌ Firmware compilation failed" -ForegroundColor Red
    Write-Host "   Check build.log for details" -ForegroundColor Yellow
    exit 1
}

# Find and display the compiled firmware
$FirmwareFile = Get-ChildItem -Path . -Filter "*.bin" | Select-Object -First 1

if ($FirmwareFile) {
    $SizeKB = [math]::Round($FirmwareFile.Length / 1KB, 2)
    $SizePercent = [math]::Round(($FirmwareFile.Length / 256KB) * 100, 1)
    
    Write-Host ""
    Write-Host "✅ Firmware compiled successfully!" -ForegroundColor Green
    Write-Host ""
    Write-Host "📊 Firmware Details:" -ForegroundColor Cyan
    Write-Host "   File: $($FirmwareFile.Name)" -ForegroundColor White
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
    Write-Host "   1. Flash using Keymapp: https://www.zsa.io/flash" -ForegroundColor White
    Write-Host "   2. Build log saved to: build.log" -ForegroundColor Gray
} else {
    Write-Host ""
    Write-Host "⚠️  Warning: Firmware file not found" -ForegroundColor Yellow
    Write-Host "   Check build.log for details" -ForegroundColor Gray
}

Write-Host ""
Write-Host "🎉 Build complete!" -ForegroundColor Green
Write-Host ""
