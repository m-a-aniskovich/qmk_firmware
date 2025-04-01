// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define DEFAULT_LAYER 0
#define MUSIC_LAYER 1
#define INTELLIJ_LAYER 2
#define GAMING_LAYER 3
#define ADDON_LAYER_COUNT 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEFAULT_LAYER] = LAYOUT_ortho_4x4(
        KC_F21,  KC_F22,  KC_F23,  KC_F24,
        KC_F17,  KC_F18,  KC_F19,  KC_F20,
        KC_F13,  KC_F14,  KC_F15,  KC_F16,
        TO(DEFAULT_LAYER), KC_MUTE
    ),
    [MUSIC_LAYER] = LAYOUT_ortho_4x4(
        KC_F21,        KC_F22,   KC_F23,       KC_F24,
        KC_F17,        KC_MPRV,  KC_MPLY,      KC_MNXT,
        LCTL(KC_F13),  KC_MUTE,  LCTL(KC_F15), LCTL(KC_F16),
        TO(DEFAULT_LAYER), KC_MUTE
    ),
    [INTELLIJ_LAYER] = LAYOUT_ortho_4x4(
        KC_F21,  KC_F22,  KC_F23,  KC_F24,
        KC_F17,  KC_F18,  KC_F19,  KC_F20,
        KC_F13,  LCTL(KC_Z),  LCTL(LSFT(KC_Z)),  KC_F16,
        TO(DEFAULT_LAYER), KC_MUTE
    ),
    [GAMING_LAYER] = LAYOUT_ortho_4x4(
        KC_P8 ,  KC_P9 ,  KC_ENT,  KC_PSCR,
        KC_P4 ,  KC_P5 ,  KC_P6 ,  KC_P7 ,
        KC_P0 ,  KC_P1 ,  KC_P2 ,  KC_P3 ,
        TO(DEFAULT_LAYER), KC_MUTE
    ),
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { oled_clear(); return OLED_ROTATION_180; }
bool wpm_keycode_user(uint16_t keycode) { return true; }

bool oled_task_user(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case MUSIC_LAYER:
            oled_write_ln_P(PSTR("Music"), false);
            oled_write_ln_P(PSTR("AAAA|BBBC|CCDD|DEEE "), false);
            oled_write_ln_P(PSTR("AAAA|Prev|Play|Next "), false);
            oled_write_ln_P(PSTR("iTun|Mute|Out-|Out+ "), false);
            break;
        case INTELLIJ_LAYER:
            oled_write_ln_P(PSTR("IntelliJ"), false);
            oled_write_ln_P(PSTR("AAAA|BBBC|CCDD|DEEE "), false);
            oled_write_ln_P(PSTR("AAAA|BBBC|CCDD|DEEE "), false);
            oled_write_ln_P(PSTR("AAAA|Undo|Redo|DEEE "), false);
            break;
        case GAMING_LAYER:
            oled_write_ln_P(PSTR("Game"), false);
            oled_write_ln_P(PSTR("Num8|Num9|Entr|PrSc "), false);
            oled_write_ln_P(PSTR("Num4|Num5|Num6|Num7 "), false);
            oled_write_ln_P(PSTR("Num0|Num1|Num2|Num3 "), false);
            break;
        default:
            oled_write_ln_P(PSTR("Default"), false);
            oled_write_ln_P(PSTR("F21 |F22 |F23 |F24  "), false);
            oled_write_ln_P(PSTR("F17 |F18 |F19 |F20  "), false);
            oled_write_ln_P(PSTR("F13 |F14 |F15 |F16  "), false);
    }   
    return false;
}
#endif

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0){
        int next_layer = get_highest_layer(layer_state) + (clockwise ? 1 : -1);
        if(next_layer < 0) next_layer = ADDON_LAYER_COUNT;
        if(next_layer > ADDON_LAYER_COUNT) next_layer = 0;
        layer_move(next_layer);
        return false;
    }

    //index = 1
    tap_code(!clockwise ? KC_VOLD : KC_VOLU);
    return false;
}