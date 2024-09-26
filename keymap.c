/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#define COMBO_LIST                                                             \
  COMBO_X(AB_ESC, KC_ESC, KC_A, KC_B)                                          \
  COMBO_X(QW_SFT, KC_LSFT, KC_Q, KC_W)

enum combos {
#define COMBO_X(name, combos, ...) name,
  COMBO_LIST
#undef COMBO_X
};

#define COMBO_X(name, combos, ...)                                             \
  const uint16_t PROGMEM name##_combo[] = {__VA_ARGS__, COMBO_END};
COMBO_LIST
#undef COMBO_X

combo_t key_combos[] = {
#define COMBO_X(name, combos, ...) [name] = COMBO(name##_combo, combos),
    COMBO_LIST
#undef COMBO_X
};

#define ROW(x0, x1, x2, x3, x4) x0, x1, x2, x3, x4
#define ROWHL(x0, x1, x2, x3, x4)                                              \
  LGUI_T(x0), LALT_T(x1), LCTL_T(x2), LSFT_T(x3), x4
#define ROWHR(x0, x1, x2, x3, x4)                                              \
  x0, LSFT_T(x1), LCTL_T(x2), LALT_T(x3), LGUI_T(x4)
#define THUM(x0, x1, x2, x3) KC_NO, x0, x1, x2, x3, KC_NO
#define KCS(x0, x1, x2, x3, x4, x5, x6)                                        \
  LAYOUT_split_3x5_3(x0, x1, x2, x3, x4, x5, x6)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = KCS(ROW(KC_Q, KC_W, KC_F, KC_P, KC_B),
              ROW(KC_J, KC_L, KC_U, KC_Y, LSFT(KC_QUOTE)),
              ROWHL(KC_A, KC_R, KC_S, KC_T, KC_G),
              ROWHR(KC_M, KC_N, KC_E, KC_I, KC_O),
              ROW(KC_Z, KC_X, KC_C, KC_D, KC_V),
              ROW(KC_K, KC_H, LSFT(KC_9), LSFT(KC_0), LSFT(KC_SCLN)),
              THUM(LT(3,KC_SPACE), MO(2), MO(2), LT(4,KC_BSPC))),
    [1] = KCS(ROW(KC_Q, KC_W, KC_E, KC_R, KC_T),
              ROW(KC_Y, KC_U, KC_I, KC_O, LSFT(KC_QUOTE)),
              ROWHL(KC_A, KC_S, KC_D, KC_F, KC_G),
              ROWHR(KC_H, KC_J, KC_K, KC_L, KC_P),
              ROW(KC_Z, KC_X, KC_C, KC_V, KC_B),
              ROW(KC_N, KC_M, LSFT(KC_9), LSFT(KC_0), LSFT(KC_SCLN)),
              THUM(LT(3,KC_SPACE), MO(2), MO(2), LT(4,KC_BSPC)))
};
