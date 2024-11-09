/* Copyright 2023 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keychron_common.h"

enum layers {
    UNIX_BASE,
    FN_LAYER,
    MAC_BASE,
    LAYER1,
    LAYER2,
    LAYER3,
    LAYER4,
    LAYER5,
};

// └ ┌ ┬ ┴ ┤ ─ ┐ ┘ │ ┼

// ┌─────┬──────┬──────┬─────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
// │ ESC │  F1  │  F2  │  F3 │  F4  │  F5  │  F6  │  F7  │  F8  │  F9  │ F10  │ F11  │ F12  │  DEL │ KNOB │
// ├─────┼──────┼──────┼─────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
// │ `~  │  1!  │  2@  │  3# │  4$  │  5%  │  6^  │  7&  │  8*  │  9(  │  0)  │  -_  │  +=  │BKSPC │ PGUP │
// ├─────┼──────┼──────┼─────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
// │ TAB │   Q  │   W  │  E  │   R  │   T  │   Y  │   U  │   I  │   O  │   P  │  {[  │  }]  │  |   │ PGDN │
// ├─────┼──────┼──────┼─────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
// │ CLK │   A  │   S  │  D  │   F  │   G  │   H  │   J  │   K  │   L  │  :;  │  '"  │    ENTER    │  HM  │
// ├─────┼──────┼──────┼─────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┴──────┼──────┼──────┤
// │ SHT │   Z  │   X  │  C  │   V  │   B  │   N  │   M  │  ,<  │  .>  │  /?  │    SHIFT    │  UP  │      │
// ├─────┼──────┼──────┼─────┴──────┴──────┴──────┴──────┴──────┼──────┼──────┼──────┬──────┼──────┼──────┤
// │ CTR │ OPT  │ CMD  │               SPACE                    │ CMD  │  FN  │ CTRL │ LFT  │  DN  │ RGHT │
// └─────┴──────┴──────┴────────────────────────────────────────┴──────┴──────┴──────┴──────┴──────┴──────┘


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [UNIX_BASE] = LAYOUT_ansi_82(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,       KC_F12,   KC_DEL,             KC_MUTE,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,      KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,      KC_RBRC,  KC_BSLS,            KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,      KC_ENT,                       DB_TOGG,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,      KC_RSFT,             KC_UP,
        KC_LCTL,  KC_LGUI, KC_LALT,                               KC_SPC,                                   KC_RALT,  MO(FN_LAYER),  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT
        ),

    [FN_LAYER] = LAYOUT_ansi_82(
        _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,           RGB_TOG,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            KC_END,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,            _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______
        ),

    [MAC_BASE] = LAYOUT_ansi_82(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,       KC_F12,   KC_DEL,             KC_MUTE,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,      KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,      KC_RBRC,  KC_BSLS,            KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,      KC_ENT,                       KC_HOME,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,      KC_RSFT,             KC_UP,
        KC_LCTL,  KC_LOPTN, KC_LCMMD,                                KC_SPC,                                 KC_RCMMD, MO(FN_LAYER),   KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT
        ),

    [LAYER1] = LAYOUT_ansi_82(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  BAT_LVL,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______
        ),

    [LAYER2] = LAYOUT_ansi_82(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  BAT_LVL,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______
        ),
    [LAYER3] = LAYOUT_ansi_82(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  BAT_LVL,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______
        ),
    [LAYER4] = LAYOUT_ansi_82(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  BAT_LVL,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______
        ),
    [LAYER5] = LAYOUT_ansi_82(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  BAT_LVL,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______
        ),
};

// clang-format on
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [UNIX_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [FN_LAYER]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER1]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [LAYER2] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER3]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [LAYER4] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER5]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
};
#endif // ENCODER_MAP_ENABLE

// Defining Key Combos
enum combos {
    COMBO_LAYER1,
    COMBO_LAYER2,
    COMBO_LAYER3,
    COMBO_LAYER4,
    COMBO_LAYER5,
    SAMPLE_COMBO
};

const uint16_t PROGMEM combo_layer1[] = {KC_LCTL, KC_L, KC_1, COMBO_END};
const uint16_t PROGMEM combo_layer2[] = {KC_LCTL, KC_L, KC_2, COMBO_END};
const uint16_t PROGMEM combo_layer3[] = {KC_LCTL, KC_L, KC_3, COMBO_END};
const uint16_t PROGMEM combo_layer4[] = {KC_LCTL, KC_L, KC_4, COMBO_END};
const uint16_t PROGMEM combo_layer5[] = {KC_LCTL, KC_L, KC_5, COMBO_END};
const uint16_t PROGMEM sample_combo[] = {KC_A, KC_S, COMBO_END};

combo_t key_combos[] = {
    [COMBO_LAYER1] = COMBO_ACTION(combo_layer1),
    [COMBO_LAYER2] = COMBO_ACTION(combo_layer2),
    [COMBO_LAYER3] = COMBO_ACTION(combo_layer3),
    [COMBO_LAYER4] = COMBO_ACTION(combo_layer4),
    [COMBO_LAYER5] = COMBO_ACTION(combo_layer5),
    [SAMPLE_COMBO] = COMBO_ACTION(sample_combo),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }
    return true;
}

// PRocessing for Combo Events
void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case COMBO_LAYER1:
            if (pressed) {
                layer_move(LAYER1);
            }
            break;
        case COMBO_LAYER2:
            if (pressed) {
                layer_move(LAYER2);
            }
            break;
        case COMBO_LAYER3:
            if (pressed) {
                layer_move(LAYER3);
            }
            break;
        case COMBO_LAYER4:
            if (pressed) {
                layer_move(LAYER4);
            }
            break;
        case COMBO_LAYER5:
            if (pressed) {
                layer_move(LAYER5);
            }
            break;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case UNIX_BASE:
            rgblight_sethsv_noeeprom(HSV_RED);
            break;
        case LAYER1:
            rgblight_sethsv_noeeprom(HSV_BLUE);
            break;
        case LAYER2:
            rgblight_sethsv_noeeprom(HSV_GREEN);
            break;
        case LAYER3:
            rgblight_sethsv_noeeprom(HSV_PURPLE);
            break;
        case LAYER4:
            rgblight_sethsv_noeeprom(HSV_OFF);
            break;
        case LAYER5:
            rgblight_sethsv_noeeprom(HSV_GOLDENROD);
            break;
    }
    return state;
}
