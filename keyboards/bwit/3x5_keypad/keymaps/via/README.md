# VIA
VIA is a powerful and user-friendly graphical interface for configuring keyboards that use QMK firmware. It allows users to customize their keymaps, layers, and other features in real-time without needing to recompile or flash the firmware manually.

Key Features of VIA:
- Real-Time Keymap Customization: Modify keymaps and layers instantly while the keyboard is connected.
- Layer Management: Easily configure multiple layers for advanced functionality.
- Macros and Special Functions: Assign macros, media controls, and other special functions to keys.
- RGB Lighting Control: Adjust RGB lighting settings (if supported by the keyboard).
- Cross-Platform: Available as a desktop app or via the usevia.app web app.

## Using the Custom VIA Configuration File

To configure your BWIT 3x5 Macro Keypad using the VIA tool, follow these steps:

1. **Download the VIA Configuration File**:
   Ensure you have the [`bwit-3x5-keypad-via.json`](bwit-3x5-keypad-via.json) file.

2. **Open the VIA Web App**:
Navigate to the [usevia.app](https://usevia.app) website in your browser. Make sure that your browser supports [WebHID API](https://caniuse.com/?search=webhid).

3. **Enable Developer Mode**:
  - Click the gear icon in the top of the VIA web app.
  - Enable the "Show Design tab" or "Developer Mode" option.

4. **Load the Custom Configuration File**:
  - Go to the "Design" tab in the VIA web app.
  - Click the "Load" button and select the `bwit-3x5-keypad-via.json` file from your computer.

5. **Connect Your Keyboard**:
  - Plug in your BWIT 3x5 Macro Keypad.
  - Make sure that the keyboard is recognized by the VIA web app.
  - Click the "Authorize Device+" button, and you will see a popup window.
  - Select "3x5 Keypad", and click "Connect" button.

6. **Customize Your Keymap**:
  - Use the VIA interface to customize your keymap, layers, and other settings.
  - Changes will be applied to your keyboard in real-time.

7. **Save Your Configuration**:
  - Once you’ve finished customizing, you can save your configuration for future use.

By following these steps, you can easily configure your BWIT 3x5 Macro Keypad using the VIA tool and the provided custom configuration file.