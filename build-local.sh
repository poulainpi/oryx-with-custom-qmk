#!/usr/bin/env bash
# Local Docker-based QMK firmware build script for ZSA Voyager
# Usage: ./build-local.sh [--clean] [--no-build]

set -e

# Color codes
CYAN='\033[0;36m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
RED='\033[0;31m'
WHITE='\033[1;37m'
NC='\033[0m' # No Color

echo -e "${CYAN}🔨 ZSA Voyager Local Build Script${NC}"
echo -e "${CYAN}=================================${NC}"
echo ""

# Configuration
IMAGE_NAME="qmk-builder"
CONTAINER_NAME="qmk-build-temp"
KEYBOARD="voyager"
KEYMAP="JRaem"

# Parse arguments
CLEAN=false
NO_BUILD=false
for arg in "$@"; do
    case $arg in
        --clean)
            CLEAN=true
            shift
            ;;
        --no-build)
            NO_BUILD=true
            shift
            ;;
    esac
done

# Check if Docker is available
if ! command -v docker &> /dev/null; then
    echo -e "${RED}❌ Error: Docker is not installed or not in PATH${NC}"
    echo -e "${YELLOW}Please install Docker: https://docs.docker.com/get-docker/${NC}"
    exit 1
fi

# Clean up previous containers/images if requested
if [ "$CLEAN" = true ]; then
    echo -e "${YELLOW}🧹 Cleaning previous build artifacts...${NC}"
    docker rm -f $CONTAINER_NAME 2>/dev/null || true
    docker rmi -f $IMAGE_NAME 2>/dev/null || true
    echo -e "${GREEN}✅ Cleanup complete${NC}"
    echo ""
fi

# Build Docker image
if [ "$NO_BUILD" = false ]; then
    echo -e "${CYAN}🐳 Building Docker image...${NC}"
    docker build -t $IMAGE_NAME .
    echo -e "${GREEN}✅ Docker image built successfully${NC}"
    echo ""
fi

# Initialize QMK firmware in container
echo -e "${CYAN}📦 Initializing QMK firmware...${NC}"
docker run --rm \
    --name "${CONTAINER_NAME}-init" \
    -v "$(pwd):/workspace" \
    -w /workspace \
    $IMAGE_NAME \
    bash -c "
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
mkdir -p keyboards/$KEYBOARD/keymaps/$KEYMAP
cp -r /workspace/JRaem/* keyboards/$KEYBOARD/keymaps/$KEYMAP/
echo '✅ Keymap copied'
"

echo -e "${GREEN}✅ QMK firmware initialized${NC}"
echo ""

# Compile firmware
echo -e "${CYAN}⚙️  Compiling firmware for $KEYBOARD ($KEYMAP)...${NC}"
docker run --rm \
    --name "${CONTAINER_NAME}-compile" \
    -v "$(pwd):/workspace" \
    -w /workspace/qmk_firmware \
    $IMAGE_NAME \
    qmk compile -kb $KEYBOARD -km $KEYMAP

# Find and display the compiled firmware
FIRMWARE_FILE=$(find qmk_firmware -name "${KEYBOARD}_${KEYMAP}.bin" -type f | head -n 1)

if [ -n "$FIRMWARE_FILE" ]; then
    SIZE_BYTES=$(stat -f%z "$FIRMWARE_FILE" 2>/dev/null || stat -c%s "$FIRMWARE_FILE" 2>/dev/null)
    SIZE_KB=$(echo "scale=2; $SIZE_BYTES / 1024" | bc)
    SIZE_PERCENT=$(echo "scale=1; ($SIZE_BYTES / (256 * 1024)) * 100" | bc)
    
    echo ""
    echo -e "${GREEN}✅ Firmware compiled successfully!${NC}"
    echo ""
    echo -e "${CYAN}📊 Firmware Details:${NC}"
    echo -e "   ${WHITE}File: $FIRMWARE_FILE${NC}"
    echo -e "   ${WHITE}Size: $SIZE_KB KB / 256 KB ($SIZE_PERCENT%)${NC}"
    
    if (( $(echo "$SIZE_KB < 230" | bc -l) )); then
        echo -e "   ${GREEN}Status: ✅ Within 90% target (<230 KB)${NC}"
    elif (( $(echo "$SIZE_KB < 256" | bc -l) )); then
        echo -e "   ${YELLOW}Status: ⚠️  Above 90% target but still fits${NC}"
    else
        echo -e "   ${RED}Status: ❌ Too large! Exceeds flash size${NC}"
    fi
    
    echo ""
    echo -e "${CYAN}📝 Next Steps:${NC}"
    echo -e "   ${WHITE}1. Connect your ZSA Voyager${NC}"
    echo -e "   ${WHITE}2. Put it in bootloader mode (press reset button)${NC}"
    echo -e "   ${WHITE}3. Use Keymapp or QMK Toolbox to flash:${NC}"
    echo -e "      ${YELLOW}$FIRMWARE_FILE${NC}"
else
    echo -e "${YELLOW}⚠️  Warning: Firmware file not found${NC}"
    echo -e "${YELLOW}Expected: qmk_firmware/${KEYBOARD}_${KEYMAP}.bin${NC}"
fi

echo ""
echo -e "${GREEN}🎉 Build complete!${NC}"
