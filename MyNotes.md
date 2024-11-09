# Notes for C Code on QMK Firmware for V1 Max

## Source Directory - keyboards/keychron/v1_max/

### config.h
* .h files are header files used to define the function headers.
* .c files are where the function body is defined. 

* This file defines the configuration of the keyboard. There are some definitions which are only defined if its a wireless enabled.

### rules.mk
* Including rules from `keychron/common/`.
* `keychron/common/wireless/wireless.mk`
* `keychron/common/keychron_common.mk`

### ansi_encoder/keymaps/default/keymap.c
* `process_record_keychron_common` is being used to handle Keychron specific events.
* process_record_user - Can use to handle custom events
    * Return false, if you don't want further handling.
    * Return true, if you want further handling.

## Implementing Features
* [Modifier Keys](https://docs.qmk.fm/feature_advanced_keycodes)
* [Quantum KC](https://docs.qmk.fm/quantum_keycodes) - To reset to bootloader etc.
* [Dynamic Macros](https://docs.qmk.fm/features/dynamic_macros)
* [Leader Keys](https://docs.qmk.fm/features/leader_key)
    * Enable in rules.mk - `LEADER_ENABLE = yes`
    * Supports upto 5 keys
* [Mod-Tap](https://docs.qmk.fm/mod_tap)
    * Acts like Modifier when held, and a regular keycode when tapped.
* [Macros](https://docs.qmk.fm/feature_macros)
    * Can be defined in JSON or C Files.
* [Mouse Keys](https://docs.qmk.fm/features/mouse_keys)
    * Enable in rules.mk - `MOUSEKEY_ENABLE = yes`
    * Configuration options can be defined in `config.h` - in the keymaps folder
* [Auto Shift](https://docs.qmk.fm/features/auto_shift)
    * Tap to get a character, hold to get the shifted character.
    * Add to rules.mk - `AUTO_SHIFT_ENABLE = yes`
    * Define the settings in `config.h` - in the keymaps folder
* [Combos](https://docs.qmk.fm/features/combo)
    * You list them out separately, and it gets handled.
    * Don't have to add it to `process_bool_user`
    * You can either define them separately, or handle it via - `process_combo_event`.
    * You can enable / disable combo events.
    * advanced combos can be defined in `config.h`
* [Layers](https://docs.qmk.fm/feature_layers)

| Command | Explanation |
|---------|-------------|
| DF(layer) | Set new default Layer |
| MO(layer) | Momentarily activates a layer |
| LM(layer, mod) | Momentarily activates a layer and keeps a mod pressed |
| LT(layer, kc) | Momentarily activates a layer when held and sends only kc when tapped |
| OSL(layer) | Activates a layer until next key is pressed |
| TT(layer) | Toggles on and Off a layer |

* [One Shot Keys](https://docs.qmk.fm/one_shot_keys)
* [Secure](https://docs.qmk.fm/features/secure)
    * Add an unlock sequence to the keyboard.
* [Send String](https://docs.qmk.fm/features/send_string)
    * Allows to send a sequence of keystrokes to be sent automatically.
* [Tap Dance](https://docs.qmk.fm/features/tap_dance)
    * Enable in `rules.mk`- `TAP_DANCE_ENABLE = yes`


## Other Features
* [Grave Escape](https://docs.qmk.fm/features/grave_esc)
* [Repeat Key](https://docs.qmk.fm/features/repeat_key)
* [MIDI Sequencer](https://docs.qmk.fm/features/sequencer)
* [Swap Hands](https://docs.qmk.fm/features/swap_hands)


## Firmware Sizes

| Version | Size | Description | 
|-|-|-|
| Base | 92K | No Changes from Base |
| Added Console Enable | 92K | |
| Added features I needed | 93K | |
| Lighting | 93K | Defined in config.h, but left info.json as is |
| Lighting | 90K | Defined in config.h, disabled in info.|
