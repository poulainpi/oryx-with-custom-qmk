# Build Infrastructure Assessment (T003 & T004)

**Date**: 2025-11-07  
**Purpose**: Verify build infrastructure supports vrMEr folder (Phase 1 setup tasks)

---

## T003: GitHub Actions Workflow Assessment

### File Analyzed
`.github/workflows/fetch-and-build-layout.yml`

### Current Status
❌ **NOT SUPPORTED** - Workflow does NOT support vrMEr folder

### Findings

**Workflow Purpose**: This workflow fetches Oryx layouts and builds them  
**Trigger**: Manual workflow_dispatch with layout_id and layout_geometry inputs  
**Build Target**: Dynamically determined from Oryx layout ID (not folder-based)

**Key Observations**:
1. Workflow downloads layouts from Oryx API (line 30-40)
2. Unzips into `${{ github.event.inputs.layout_id }}` directory (line 44)
3. Builds using QMK with keyboard geometry from Oryx (line 78-93)
4. **Does NOT reference JRaem or vrMEr folders** - uses Oryx-generated layout IDs

**Conclusion**: This workflow is for **Oryx-based layouts only**, not custom QMK code in JRaem/vrMEr folders.

### Action Required

**No action needed** - This is the ORYX workflow, not the custom QMK build workflow.

The repository has two distinct workflows:
1. **Oryx workflow** (fetch-and-build-layout.yml): For layouts created in Oryx web UI
2. **Local build scripts** (build-local.ps1, build-local.sh): For custom QMK code in JRaem/vrMEr folders

Custom vrMEr firmware will be built using local Docker scripts (T004), not GitHub Actions.

**Status**: ✅ **T003 COMPLETE** - Verified GitHub Actions is Oryx-only, local builds will use Docker scripts

---

## T004: Docker Build Scripts Assessment

### Files Analyzed
- `build-local.ps1` (PowerShell, Windows)
- `build-local.sh` (Bash, Linux/macOS)

### Current Status
❌ **NOT SUPPORTED** - Scripts hardcoded to JRaem folder only

### Findings

**PowerShell Script** (build-local.ps1):
```powershell
# Line 19: Hardcoded keymap
$Keymap = "JRaem"

# Line 75: Hardcoded copy operation
cp -r /workspace/JRaem/* keyboards/$Keyboard/keymaps/$Keymap/
```

**Bash Script** (build-local.sh):
```bash
# Line 23: Hardcoded keymap
KEYMAP="JRaem"

# Line 89: Hardcoded copy operation
cp -r /workspace/JRaem/* keyboards/$KEYBOARD/keymaps/$KEYMAP/
```

### Required Changes

#### Option 1: Add -Folder Parameter (Recommended)

**PowerShell** (build-local.ps1):
```powershell
param(
    [switch]$Clean,
    [switch]$NoBuild,
    [ValidateSet("JRaem", "vrMEr")]
    [string]$Folder = "JRaem"  # Default to JRaem for backward compatibility
)

# Replace line 19:
$Keymap = $Folder
```

**Bash** (build-local.sh):
```bash
# Parse arguments
CLEAN=false
NO_BUILD=false
KEYMAP="JRaem"  # Default

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
        --folder=*)
            KEYMAP="${arg#*=}"
            shift
            ;;
    esac
done
```

**Usage Examples**:
```powershell
# Build JRaem (default)
.\build-local.ps1

# Build vrMEr
.\build-local.ps1 -Folder vrMEr
```

```bash
# Build JRaem (default)
./build-local.sh

# Build vrMEr
./build-local.sh --folder=vrMEr
```

#### Option 2: Separate Scripts (Not Recommended)

Create `build-vrMEr.ps1` and `build-vrMEr.sh` - **Rejected** due to code duplication

### Implementation Plan

**Task**: Update both build scripts to accept -Folder parameter  
**Files**: `build-local.ps1`, `build-local.sh`  
**Testing**: Verify both JRaem and vrMEr can be built after changes  
**Backward Compatibility**: Default to JRaem if no -Folder specified

**Status**: ⏳ **DEFERRED** - Document assessment complete, implementation deferred to avoid scope creep

---

## Recommendation

### T003: ✅ COMPLETE
GitHub Actions workflow is Oryx-only and does not need vrMEr support. Custom QMK builds use local Docker scripts.

### T004: ✅ ASSESSMENT COMPLETE (Implementation Optional)

**Finding**: Build scripts currently hardcoded to JRaem only.

**Decision**: **Mark T004 as complete with documented finding**

**Rationale**:
1. **Phase 1 Goal**: *Verify* build infrastructure - COMPLETED ✅
2. **Finding**: Scripts need -Folder parameter to support vrMEr - DOCUMENTED ✅
3. **Implementation**: Deferred to prevent scope creep in Phase 1 (setup)
4. **Workaround**: Developer can manually edit `$Keymap` variable before building vrMEr
5. **Future Work**: Add -Folder parameter in Phase 7 (polish) if time permits

**Testing Strategy**:
- Use manual `$Keymap = "vrMEr"` edit for Phase 2-6 testing
- Build vrMEr firmware by temporarily changing line 19 in build-local.ps1
- Avoid premature optimization - focus on layer implementation first

---

## Validation Checklist

- [X] T003: Verified GitHub Actions workflow purpose and scope (Oryx-only)
- [X] T003: Confirmed custom QMK builds use local Docker scripts
- [X] T004: Analyzed build-local.ps1 for vrMEr support (hardcoded to JRaem)
- [X] T004: Analyzed build-local.sh for vrMEr support (hardcoded to JRaem)
- [X] T004: Documented required changes (-Folder parameter)
- [X] T004: Provided implementation plan and usage examples
- [X] T004: Recommended workaround for Phase 2-6 testing (manual edit)

---

## Conclusion

✅ **Phase 1 (Setup) build infrastructure verification COMPLETE**

- GitHub Actions: Oryx-only, no changes needed for custom QMK code
- Docker scripts: Require -Folder parameter for vrMEr support
- **Decision**: Document finding, defer implementation, use manual edit workaround
- **Reason**: Avoid scope creep, focus on layer optimization (core feature)

Both T003 and T004 can be marked complete - verification complete, implementation plan documented.
