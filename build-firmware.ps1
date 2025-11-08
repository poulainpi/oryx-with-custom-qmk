#!/usr/bin/env pwsh
# build-firmware.ps1
# Local firmware compilation script for ZSA Voyager keyboard using Docker

param(
    [string]$KeymapDir = "vrMEr",
    [switch]$Clean,
    [switch]$Verbose
)

$ErrorActionPreference = "Stop"

Write-Host "=== ZSA Voyager Firmware Builder ===" -ForegroundColor Cyan
Write-Host ""

# Ensure Docker is available
try {
    $dockerVersion = docker version --format '{{.Server.Version}}' 2>$null
    if ($LASTEXITCODE -ne 0) {
        throw "Docker is not running"
    }
    Write-Host "✓ Docker version: $dockerVersion" -ForegroundColor Green
} catch {
    Write-Host "✗ Error: Docker is not available or not running" -ForegroundColor Red
    Write-Host "  Please start Docker Desktop and try again." -ForegroundColor Yellow
    exit 1
}

# Clear DOCKER_HOST if set (for compatibility)
$env:DOCKER_HOST = $null

# Check if keymap directory exists
if (-not (Test-Path $KeymapDir)) {
    Write-Host "✗ Error: Keymap directory '$KeymapDir' not found" -ForegroundColor Red
    exit 1
}

Write-Host "✓ Keymap directory: $KeymapDir" -ForegroundColor Green

# Check if Docker image exists
$imageExists = docker images -q qmk-builder 2>$null
if (-not $imageExists) {
    Write-Host "⚠ Docker image 'qmk-builder' not found. Building it now..." -ForegroundColor Yellow
    Write-Host ""
    docker build -t qmk-builder .
    if ($LASTEXITCODE -ne 0) {
        Write-Host "✗ Error: Failed to build Docker image" -ForegroundColor Red
        exit 1
    }
    Write-Host ""
    Write-Host "✓ Docker image built successfully" -ForegroundColor Green
} else {
    Write-Host "✓ Docker image: qmk-builder" -ForegroundColor Green
}

# Clean previous build artifacts if requested
if ($Clean) {
    Write-Host ""
    Write-Host "Cleaning previous build artifacts..." -ForegroundColor Yellow
    Remove-Item -Path "*.bin" -ErrorAction SilentlyContinue
    Remove-Item -Path "build.log" -ErrorAction SilentlyContinue
    Write-Host "✓ Cleaned" -ForegroundColor Green
}

Write-Host ""
Write-Host "Starting firmware compilation..." -ForegroundColor Cyan
Write-Host "This may take a few minutes on first run (cloning QMK firmware)" -ForegroundColor Gray
Write-Host ""

# Build the firmware
$buildCommand = @"
git clone --depth=1 --recurse-submodules https://github.com/zsa/qmk_firmware.git /qmk && \
cd /qmk && \
cp -r /workspace/$KeymapDir keyboards/zsa/voyager/keymaps/ && \
make zsa/voyager:$KeymapDir 2>&1 | tee /workspace/build.log && \
cp *.bin /workspace/ 2>/dev/null || true
"@

docker run --rm -v "${PWD}:/workspace" qmk-builder bash -c $buildCommand

if ($LASTEXITCODE -ne 0) {
    Write-Host ""
    Write-Host "✗ Build failed! Check build.log for details." -ForegroundColor Red
    exit 1
}

# Find the generated firmware file
$firmwareFile = Get-ChildItem -Path . -Filter "*.bin" | Select-Object -First 1

if ($firmwareFile) {
    $sizeKB = [math]::Round($firmwareFile.Length / 1KB, 2)
    $sizePercent = [math]::Round(($firmwareFile.Length / 256KB) * 100, 1)
    
    Write-Host ""
    Write-Host "=== Build Successful ===" -ForegroundColor Green
    Write-Host ""
    Write-Host "Firmware file: $($firmwareFile.Name)" -ForegroundColor White
    Write-Host "Size: $sizeKB KB / 256 KB ($sizePercent%)" -ForegroundColor White
    
    if ($sizeKB -lt 230) {
        Write-Host "✓ Size is under 230KB target" -ForegroundColor Green
    } else {
        Write-Host "⚠ Warning: Size exceeds 230KB target!" -ForegroundColor Yellow
    }
    
    Write-Host ""
    Write-Host "Flash with: Keymapp application (https://www.zsa.io/flash)" -ForegroundColor Cyan
    Write-Host "Build log: build.log" -ForegroundColor Gray
} else {
    Write-Host ""
    Write-Host "⚠ Warning: Build completed but no .bin file found" -ForegroundColor Yellow
    Write-Host "Check build.log for details" -ForegroundColor Gray
}

Write-Host ""
