/* Copyright 2023 Colin Lam (Ploopy Corporation)
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
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

#define Layer_main 0
#define Layer_edit 1    // ctrl key functions (cut, copy, paste, find & ctrl-click)
#define Layer_keys 2    // keyboard keys (enter, escape, lock-pc, win-tab)
#define Layer_media 3   // vol, mute and mouse dpi
#define Layer_games 4   // gaming

// example: https://github.com/ArtiomSu/qmk_firmware/blob/artiomsu_ploopy_adept/keyboards/ploopy_adept/keymaps/default/keymap.c
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [Layer_main] = LAYOUT(
        KC_BTN4,            LT(Layer_keys,KC_BTN5),     DRAG_SCROLL,    LT(Layer_edit,KC_BTN2),
        KC_BTN1,                                                        LT(Layer_media,KC_BTN3)
    ),
    [Layer_edit] = LAYOUT(
        C(KC_X),            C(KC_C),                    C(KC_V),        _______,
        C(MS_BTN1),                                                     C(KC_F)
    ),
    [Layer_keys] = LAYOUT(
        TO(Layer_games),    _______,                    KC_ENT,         KC_ESC,
        LCA(KC_TAB),                                                    G(KC_L)
    ),
    [Layer_media] = LAYOUT(
        KC_MUTE,            KC_VOLD,                    KC_VOLU,        _______,
        DPI_CONFIG,                                                     _______
    ),
    [Layer_games] = LAYOUT(
        KC_BTN4,            KC_BTN5,                    KC_BTN3,        KC_BTN2,
        KC_BTN1,                                                        TO(Layer_main)
    )
};
