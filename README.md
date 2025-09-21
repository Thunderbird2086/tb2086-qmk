# Thunderbird2086's QMK Userspace

This repository contains custom QMK firmware for various keyboards. All keymaps are Mac and **pinky** friendly.

## Supported Keyboards

### BWIT
- 3x5 macro keypad

### Non Nemo Wired
- A 3x5 split keyboard with RGB matrix support
- **Hardware Availability**: [Non Nemo Wired](https://github.com/Thunderbird2086/non-nemo)

### OmniCode:9001
- Modular keyboard with VIA support
- Available in both default and VIA configurations
- **Hardware Availability**: [OmniCode:9001](https://github.com/Thunderbird2086/OmniCode-9001)

### Paddle
- 3x5 macro keypad
- Supports both Pro Micro and Elite-C controllers
- Features custom OLED display support
- Available layouts:
  - Default with RGB matrix effects

### TPCM
- HK Split keyboard
- Available in both default and VIA configurations

### Unicorne
- 3x5 and 3x6 split keyboard
- Supports both Pro Micro (avrdude) and Elite-C (dfu) controllers
- Features custom OLED display support
- Multiple layout options:
  - Default with RGB matrix
  - No OLED version
  - No RGB version
  - Plain version
  - Custom thunderbird2086 layout: only 3x6 layout
  - VIA-compatible version
- **Hardware Availability**: [uniCorne](https://github.com/Thunderbird2086/uniCorne)

### uniKey
- a compact PCB for sigle key swithecs
- example: Bastardkb Skeletyl support
- **Hardware Availability**: [uniKeyPCB](https://github.com/Thunderbird2086/uniKeyPCB)

### Winry
- Winry315 support

## Features
- All keyboards with RGB support use the new RM_* keycodes (updated from RGB_*)
- Custom OLED fonts and indicators available for supported keyboards
- VIA support for selected keyboards
- Mac-oriented default configurations
- Common features across keyboards:
  - RGB Matrix support where available
  - OLED support where available
  - Split keyboard support where applicable
  - Multiple layout options for most keyboards