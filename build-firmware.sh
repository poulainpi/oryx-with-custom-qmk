#!/usr/bin/env bash
# build-firmware.sh
# Local firmware compilation script for ZSA Voyager keyboard using Docker

set -e

KEYMAP_DIR="${1:-vrMEr}"
CLEAN_BUILD=false

# Parse arguments
while [[ $# -gt 0 ]]; do
    case $1 in
        --clean)
            CLEAN_BUILD=true
            shift
            ;;
        --help)
            echo "Usage: $0 [KEYMAP_DIR] [--clean]"
            echo ""
            echo "Arguments:"
            echo "  KEYMAP_DIR    Directory containing keymap (default: vrMEr)"
            echo "  --clean       Remove previous build artifacts"
            echo ""
            echo "Example:"
            echo "  $0 vrMEr --clean"
            exit 0
            ;;
        *)
            KEYMAP_DIR="$1"
            shift
            ;;
    esac
done

echo "=== ZSA Voyager Firmware Builder ==="
echo ""

# Check Docker
if ! command -v docker &> /dev/null; then
    echo "✗ Error: Docker is not installed"
    echo "  Install Docker from: https://www.docker.com/get-started"
    exit 1
fi

if ! docker info &> /dev/null; then
    echo "✗ Error: Docker daemon is not running"
    echo "  Please start Docker and try again"
    exit 1
fi

echo "✓ Docker is available"

# Check keymap directory
if [ ! -d "$KEYMAP_DIR" ]; then
    echo "✗ Error: Keymap directory '$KEYMAP_DIR' not found"
    exit 1
fi

echo "✓ Keymap directory: $KEYMAP_DIR"

# Check/build Docker image
if ! docker images qmk-builder | grep -q qmk-builder; then
    echo "⚠ Docker image 'qmk-builder' not found. Building it now..."
    echo ""
    docker build -t qmk-builder .
    echo ""
    echo "✓ Docker image built successfully"
else
    echo "✓ Docker image: qmk-builder"
fi

# Clean if requested
if [ "$CLEAN_BUILD" = true ]; then
    echo ""
    echo "Cleaning previous build artifacts..."
    rm -f ./*.bin build.log
    echo "✓ Cleaned"
fi

echo ""
echo "Starting firmware compilation..."
echo "This may take a few minutes on first run (cloning QMK firmware)"
echo ""

# Build firmware
docker run --rm -v "$PWD:/workspace" qmk-builder bash -c "
git clone --depth=1 --recurse-submodules https://github.com/zsa/qmk_firmware.git /qmk && \
cd /qmk && \
cp -r /workspace/$KEYMAP_DIR keyboards/zsa/voyager/keymaps/ && \
make zsa/voyager:$KEYMAP_DIR 2>&1 | tee /workspace/build.log && \
cp *.bin /workspace/ 2>/dev/null || true
"

# Check results
FIRMWARE_FILE=$(ls -1 *.bin 2>/dev/null | head -1)

if [ -n "$FIRMWARE_FILE" ]; then
    SIZE_BYTES=$(stat -f%z "$FIRMWARE_FILE" 2>/dev/null || stat -c%s "$FIRMWARE_FILE" 2>/dev/null)
    SIZE_KB=$(awk "BEGIN {printf \"%.2f\", $SIZE_BYTES/1024}")
    SIZE_PERCENT=$(awk "BEGIN {printf \"%.1f\", ($SIZE_BYTES/262144)*100}")
    
    echo ""
    echo "=== Build Successful ==="
    echo ""
    echo "Firmware file: $FIRMWARE_FILE"
    echo "Size: $SIZE_KB KB / 256 KB ($SIZE_PERCENT%)"
    
    if (( $(echo "$SIZE_KB < 230" | bc -l) )); then
        echo "✓ Size is under 230KB target"
    else
        echo "⚠ Warning: Size exceeds 230KB target!"
    fi
    
    echo ""
    echo "Flash with: Keymapp application (https://www.zsa.io/flash)"
    echo "Build log: build.log"
else
    echo ""
    echo "⚠ Warning: Build completed but no .bin file found"
    echo "Check build.log for details"
fi

echo ""
