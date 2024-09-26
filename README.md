# Oryx with custom QMK

This repository allows combining the convenience of Oryx’s graphical layout editing with the power of QMK, allowing you to customize your Oryx layout with advanced features like Achordion and Caps Word, while automating firmware builds through GitHub Actions.

## How to Use

1. Fork this repository (be sure to **uncheck the "Copy the main branch only" option**).
2. To initialize the repository with your layout:
   - Go to the **Actions** tab.
   - Select **Fetch and build layout**.
   - Click **Run workflow**.
   - Input your layout ID and keyboard type, then run the workflow.
   - (To avoid having to input values each time, you can modify the default values at the top of the `.github/workflows/fetch-and-build-layout.yml` file.)
3. A folder containing your layout will be generated at the root of the repository.
4. You can now add your custom QMK features to this folder.
5. You can continue editing your layout through Oryx.
6. To build the firmware, rerun the GitHub Action. The firmware will be available for download in the action’s artifacts.
7. Flash your downloaded firmware using [Keymapp](https://www.zsa.io/flash#flash-keymap).
8. Enjoy!
