# oryx-with-custom-qmk Development Guidelines

Auto-generated from all feature plans. Last updated: 2025-11-07

## Active Technologies

- C (QMK Firmware compatible with AVR-GCC compiler) + QMK Firmware (qmk_firmware submodule), Oryx layout API, German keyboard layout definitions (keymap_german.h) (001-minimize-layers)

## Project Structure

```text
JRaem/                  # Custom QMK code for ZSA Voyager
  config.h              # QMK configuration (USB, RGB, timing)
  keymap.c              # Layer definitions and custom logic
  rules.mk              # QMK feature flags
  i18n.h                # German keyboard layout aliases
  keymap.json           # Oryx layout export (reference)
qmk_firmware/           # QMK base firmware (submodule)
specs/001-minimize-layers/  # Feature documentation
  spec.md               # Feature specification
  plan.md               # Implementation plan
  tasks.md              # Task breakdown
  CURRENT_LAYOUT.md     # Original 10-layer backup
  TESTING_CHECKLIST.md  # Hardware test procedures
  contracts/            # Layer contracts
  quickstart.md         # Testing guide
.github/workflows/      # GitHub Actions for firmware builds
```

## Layer Architecture (001-minimize-layers)

**6-Layer Structure** (reduced from 10):
- Layer 0: macOS Base (LAYER_MAC_BASE) - Cmd-optimized home row mods
- Layer 1: Windows Base (LAYER_WIN_BASE) - Ctrl/Win-optimized home row mods  
- Layer 2: Symbols (LAYER_SYMBOLS) - Unified programming symbols
- Layer 3: Function/Navigation (LAYER_FUNCTION) - F-keys, arrows, umlauts
- Layer 4: Numbers (LAYER_NUMBERS) - Numpad with OS-aware clipboard
- Layer 5: Config (LAYER_CONFIG) - RGB controls, layer switching, bootloader

**Key Features**:
- OS-specific base layers with identical alpha layout (HIEA O / DTRNS)
- Shared utility layers accessible from both bases (OSL/LT)
- OS-aware clipboard (is_macos_base() helper)
- Home row mods using MT() (no custom dual-functions)
- 48% code reduction (538 → 279 lines)

## Commands

### Build Firmware
```bash
# Via GitHub Actions (recommended)
# 1. Push changes to main branch
# 2. Run workflow: .github/workflows/fetch-and-build-layout.yml
# 3. Download firmware from artifacts

# Local QMK build (if qmk_firmware submodule initialized)
# Note: Not configured in this repo - use GitHub Actions
```

### Flash Firmware
```bash
# Use Keymapp application from ZSA
# Download from: https://www.zsa.io/flash
```

## Code Style

C (QMK Firmware compatible with AVR-GCC compiler): Follow QMK coding conventions

**Layer enum naming**: LAYER_<PURPOSE> (e.g., LAYER_MAC_BASE, LAYER_SYMBOLS)  
**Custom keycodes**: OS_<ACTION> for OS-aware operations (e.g., OS_COPY, OS_PASTE)  
**Home row mods**: MT(MOD_<modifier>, KC_<key>) for modifier-tap keys  
**German layout**: Use DE_* keycodes from keymap_german.h (DE_UE, DE_SS, etc.)  
**Comments**: Document layer purpose, custom keycodes, and OS-specific logic

## Constitution Compliance

All code changes MUST comply with .specify/memory/constitution.md:
1. **Minimal Firmware Size**: Target <230KB (90% of 256KB flash)
2. **Layer Minimization**: Achieved 6 layers (vs 10 original)
3. **OS-Specific Optimization**: Separate bases, shared utilities
4. **Oryx Integration**: GitHub Actions workflow maintained
5. **Code Maintainability**: Clear structure, enum constants, no magic numbers

## Recent Changes

- 001-minimize-layers: Implemented 6-layer architecture with OS-aware clipboard, removed 16 dual-functions, reduced code by 48%

<!-- MANUAL ADDITIONS START -->
<!-- MANUAL ADDITIONS END -->
