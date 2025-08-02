# OmniCode:9001 Default Keymap

The default keymap for OmniCode:9001 is designed to provide a powerful and intuitive typing experience across all three modules.

## Layer Overview

### Layer 0: QWERTY Layer
![Base Layer](https://imgur.com/i5GKNq0.png)

Standard ANSI layout with function keys and media controls:
- Volume controls in the top right (Mute, Vol-, Vol+)
- Brightness controls on F-row right side
- Standard navigation cluster
- Full numpad

### Layer 1: Colemak Layer
![Colemak Layer](https://imgur.com/lePWZ9E.png)

Alternative Colemak layout for ergonomic typing, maintaining same function keys and media controls as Layer 0.

### Layer 2: Navigation Layer (MO(2))
![Navigation Layer](https://imgur.com/8TyfIks.png)

Enhanced navigation and shortcuts:
- WASD-style arrow cluster (Home, Up, PgUp, Left, Down, Right, End, PgDn)
- Zoom meeting controls (Video: Comma, Audio: Dot)
- Space triggers Layer 3

### Layer 3: Settings Layer (via Layer 2 + Space)
![Function Layer](https://imgur.com/r2LamDC.png)

System functions:
- QK_BOOT in ESC position
- Layout selection (F1: Layer 0/QWERTY, F2: Layer 1/Colemak)
- Other keys transparent to base layer

## Special Features

### Layout Switching
- Layer 2 + Space + F1: Switch to QWERTY
- Layer 2 + Space + F2: Switch to Colemak

### Zoom Controls (Layer 2)
- Comma: Toggle Video (⌘⇧V on macOS, Alt+V on Windows/Linux)
- Dot: Toggle Audio (⌘⇧A on macOS, Alt+A on Windows/Linux)

### System Controls
- Top right cluster: Mute, Volume Down, Volume Up
- F-row right side: Screen brightness controls
- QK_BOOT available through Layer 3

## Customization

To customize this keymap:

1. Edit `keymap.c` in this directory
2. Compile with:
   ```bash
   qmk compile -kb omnicode9001 -km default
   ```
3. Flash using:
   ```bash
   qmk flash -kb omnicode9001 -km default
   ```

## Additional Notes

- RGB animations can be customized in `rgb_matrix_user.c`
- Macro definitions are in `process_record_user.c`
- OLED display shows current layer and module status
- VIA support is enabled by default

For more advanced customization options, check the [QMK Documentation](https://docs.qmk.fm/).
