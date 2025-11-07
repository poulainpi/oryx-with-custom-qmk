# Oryx with custom QMK

This repository allows combining the convenience of [Oryx’s](https://www.zsa.io/oryx) graphical layout editing with the power of [QMK](https://qmk.fm), allowing you to customize your Oryx layout with advanced QMK features like Achordion and Repeat Key, while automating firmware builds through GitHub Actions.

## How it works

Each time you run the GitHub Action, the workflow will:
1. Fetch the latest changes made in Oryx.
2. Merge them with any QMK features you've added in the source code.
3. Build the firmware, incorporating modifications from both Oryx and your custom source code.

## How to use

1. Fork this repository (be sure to **uncheck the "Copy the main branch only" option**).
2. To initialize the repository with your layout:
   - Go to the **Actions** tab.
   - Select **Fetch and build layout**.
   - Click **Run workflow**.
   - Input your layout ID and keyboard type (your layout must be public in Oryx), then run the workflow.
   - (To avoid having to input values each time, you can modify the default values at the top of the `.github/workflows/fetch-and-build-layout.yml` file).
3. A folder containing your layout will be generated at the root of the repository.
4. You can now add your custom QMK features to this folder:
   - Edit `config.h`, `keymap.c` and `rules.mk` according to the [QMK documentation](https://github.com/qmk/qmk_firmware/tree/master/docs/features).
   - Commit and push to the **main** branch.
5. You can continue editing your layout through Oryx:
   - Confirm changes by clicking the **Compile this layout** button.
6. To build the firmware (including both Oryx and code modifications), rerun the GitHub Action. The firmware will be available for download in the action’s artifacts.
7. Flash your downloaded firmware using [Keymapp](https://www.zsa.io/flash#flash-keymap).
8. Enjoy!

## Layer Architecture (Feature: Minimize Layers)

This layout uses an optimized **6-layer architecture** (reduced from the original 10 layers) for improved muscle memory and reduced cognitive load:

### Layer Structure

- **Layer 0: macOS Base** - Primary typing layer for macOS with Cmd/Ctrl home row mods
- **Layer 1: Windows Base** - Primary typing layer for Windows with Win/Ctrl home row mods
- **Layer 2: Symbols** - Unified programming symbols accessible from both OS layers
- **Layer 3: Function/Navigation** - F-keys, arrows, navigation, German umlauts (ä, ö, ü, ß, €)
- **Layer 4: Numbers** - Numpad layout with operators and OS-aware clipboard shortcuts
- **Layer 5: Config** - RGB controls, layer switching, and bootloader access

### Key Features

**OS-Specific Base Layers:**
- Both base layers share identical alpha key positions (HIEA O / DTRNS layout)
- Home row mods automatically adapt to OS conventions:
  - macOS: Cmd primary modifier (E/T keys)
  - Windows: Ctrl primary modifier (E/T keys)
- Consistent muscle memory across operating systems

**Shared Utility Layers:**
- Symbol, Function, and Number layers work identically from both base layers
- Accessed via thumb cluster: OSL (one-shot layer) and LT (layer-tap with space)
- No layer-specific duplication - reduces firmware size by ~50%

**OS-Aware Operations:**
- Clipboard shortcuts automatically use correct modifiers:
  - macOS: Cmd+Z/C/V/X
  - Windows: Ctrl+Z/C/V/X
- Implementation uses `is_macos_base()` helper for OS detection

**Layer Access:**
- Symbols: OSL(2) on left thumb (one-shot layer)
- Function: OSL(3) on right thumb (one-shot layer)
- Numbers: LT(4, Space) on right thumb (hold space for numbers)
- Config: TO(5) on top-right key (persistent toggle)

### Code Optimization

- **Original**: 10 layers, 538 lines, 16 dual-function implementations
- **Optimized**: 6 layers, 279 lines, home row mods only
- **Reduction**: ~48% code size, 40% fewer layers
- **Preserved Features**: CAPS_WORD, COMBO (4), KEY_OVERRIDE (2), LEADER, QK_REPEAT_KEY, RGB_MATRIX

### Documentation

For detailed implementation documentation, see:
- **Feature Specification**: `specs/001-minimize-layers/spec.md`
- **Implementation Plan**: `specs/001-minimize-layers/plan.md`
- **Layer Contracts**: `specs/001-minimize-layers/contracts/layer-structure.md`
- **Original Layout Backup**: `specs/001-minimize-layers/CURRENT_LAYOUT.md`
