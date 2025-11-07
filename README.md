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
- **Testing Checklist**: `specs/001-minimize-layers/TESTING_CHECKLIST.md`

## Troubleshooting

### Layer Access Issues

**Problem**: Cannot access symbol/function/number layer  
**Solution**: 
- Verify you're using the correct thumb key (OSL for symbols/function, LT+space for numbers)
- Check if you're stuck on another layer - press TO(LAYER_MAC_BASE) or TO(LAYER_WIN_BASE) to reset
- Ensure firmware is up to date (recompile and reflash)

**Problem**: Layer doesn't return to base after one-shot  
**Solution**:
- OSL (one-shot layer) should auto-return after one keypress
- If stuck, manually return by accessing config layer and switching to desired base
- Check ONESHOT_TIMEOUT setting in config.h (default: 5000ms)

**Problem**: Wrong base layer active (macOS vs Windows)  
**Solution**:
- Access LAYER_CONFIG (top-right key on any layer)
- Press TO(LAYER_MAC_BASE) or TO(LAYER_WIN_BASE) to switch
- LED color will change to indicate active base (blue/teal for Mac, green for Windows)

### Home Row Mod Issues

**Problem**: Home row mods trigger accidentally during fast typing  
**Solution**:
- Increase TAPPING_TERM in config.h (currently 200ms, try 250ms)
- Practice keeping fingers light when typing quickly
- Consider disabling home row mods on less-used keys

**Problem**: Home row mods don't activate when held  
**Solution**:
- Hold key longer than TAPPING_TERM (>200ms)
- Ensure you're pressing the correct home row key (H, I, E, T, R, N)
- Check if you're on the correct base layer (Mac vs Windows have different mods)

**Problem**: Wrong modifier activates  
**Solution**:
- Verify you're on the correct OS base layer
- macOS: H=Ctrl, I=Alt, E=Cmd, T=Cmd, R=Alt, N=Ctrl
- Windows: H=Win, I=Alt, E=Ctrl, T=Ctrl, R=Alt, N=Win
- Use TO() keys in config layer to switch base layers

### Clipboard Operation Issues

**Problem**: OS_COPY/PASTE/CUT doesn't work  
**Solution**:
- Verify you're on the correct OS base layer (detection based on LAYER_MAC_BASE vs LAYER_WIN_BASE)
- Access number layer (hold space) to find clipboard keys
- macOS uses Cmd+C/V/X, Windows uses Ctrl+C/V/X automatically
- Ensure is_macos_base() helper is working (check layer state with LED colors)

**Problem**: Wrong modifier used for clipboard shortcuts  
**Solution**:
- Switch to correct base layer using config layer
- OS detection is based on active base layer, not actual OS
- Use TO(LAYER_MAC_BASE) when on macOS, TO(LAYER_WIN_BASE) when on Windows

### RGB/LED Issues

**Problem**: LEDs don't change color per layer  
**Solution**:
- Access LAYER_CONFIG and press RGB_TOG to ensure LEDs are enabled
- Only 3 layers have custom LED colors (MAC_BASE, WIN_BASE, CONFIG)
- Symbol/Function/Number layers use default matrix colors
- Adjust brightness with RGB_VAI/VAD if LEDs are too dim

**Problem**: Cannot access config layer  
**Solution**:
- Press TO(LAYER_CONFIG) on top-right key (works from any layer)
- If unresponsive, try pressing from base layer first
- Check if key is mapped correctly in keymap.c

### Build/Flash Issues

**Problem**: Firmware won't compile in GitHub Actions  
**Solution**:
- Check GitHub Actions log for specific error messages
- Verify all syntax in keymap.c, config.h, rules.mk is correct
- Ensure firmware size is <256KB (check build log output)
- Review recent code changes for syntax errors

**Problem**: Firmware won't flash to keyboard  
**Solution**:
- Use Keymapp application (not QMK Toolbox)
- Enter bootloader mode: Access LAYER_CONFIG, press QK_BOOT (top-right key)
- Keyboard should be detected by Keymapp
- Ensure you downloaded the correct .bin file from GitHub Actions artifacts

**Problem**: Keyboard behaves unexpectedly after flash  
**Solution**:
- Verify you flashed the correct firmware file (check filename matches keyboard model)
- Reset EEPROM: Unplug keyboard, press QK_BOOT while plugging back in
- Reflash known-good firmware version
- Check TESTING_CHECKLIST.md to systematically validate all features

### Getting Help

If issues persist:
1. Review detailed documentation in `specs/001-minimize-layers/`
2. Check quickstart.md for testing procedures
3. Validate implementation against contracts in `contracts/` folder
4. Create GitHub issue with:
   - Description of problem
   - Steps to reproduce
   - Expected vs actual behavior
   - Firmware version/commit hash
   - OS (macOS/Windows) and keyboard model

