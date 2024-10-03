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
  COMBO_X(QGRV_BOOT, QK_BOOT, KC_Q, KC_GRV)                                    \
  COMBO_X(TN_WORD, CW_TOGG, LCTL_T(KC_T), LCTL_T(KC_N))

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
#define NOROW KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
#define ROWHL(x0, x1, x2, x3, x4)                                              \
  LGUI_T(x0), LALT_T(x1), LCTL_T(x2), LSFT_T(x3), x4
#define ROWHR(x0, x1, x2, x3, x4)                                              \
  x0, LSFT_T(x1), LCTL_T(x2), LALT_T(x3), LGUI_T(x4)
#define THUM(x0, x1, x2, x3) KC_NO, x0, x1, x2, x3, KC_NO
#define KCS(x0, x1, x2, x3, x4, x5, x6)                                        \
  LAYOUT_split_3x5_3(x0, x1, x2, x3, x4, x5, x6)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = KCS(
        ROW(KC_Q, KC_W, KC_F, KC_P, KC_B), ROW(KC_J, KC_L, KC_U, KC_Y, KC_GRV),
        ROWHL(KC_A, KC_R, KC_S, KC_T, KC_G),
        ROWHR(KC_M, KC_N, KC_E, KC_I, KC_O), ROW(KC_Z, KC_X, KC_C, KC_D, KC_V),
        ROW(KC_K, KC_H, KC_DQT, KC_UNDS, KC_COLN),
        THUM(LT(2, KC_COMM), KC_SPC, KC_BSPC, LT(3, KC_DOT))),
    [1] = KCS(
        ROW(KC_Q, KC_W, KC_E, KC_R, KC_T), ROW(KC_Y, KC_U, KC_I, KC_O, KC_GRV),
        ROWHL(KC_A, KC_S, KC_D, KC_F, KC_G),
        ROWHR(KC_H, KC_J, KC_K, KC_L, KC_P), ROW(KC_Z, KC_X, KC_C, KC_V, KC_B),
        ROW(KC_N, KC_M, KC_DQT, KC_UNDS, KC_COLN),
        THUM(LT(2, KC_COMM), KC_SPC, KC_BSPC, LT(3, KC_DOT))),
    [2] = KCS(NOROW, NOROW, ROW(KC_8, KC_6, KC_4, KC_2, KC_NO),
              ROW(KC_NO, KC_3, KC_5, KC_7, KC_9), NOROW, NOROW,
              THUM(KC_NO, KC_0, KC_1, KC_NO)),
    [3] = KCS(NOROW, NOROW, ROW(KC_SCLN, KC_GRV, KC_QUOT, KC_DQT, KC_NO),
              ROW(KC_NO, KC_COMM, KC_DOT, KC_QUES, KC_EXLM), NOROW, NOROW,
              THUM(KC_NO, KC_AT, KC_HASH, KC_NO)),
    [4] = KCS(NOROW, NOROW, ROW(KC_PIPE, KC_AMPR, KC_LT, KC_GT, KC_NO),
              ROW(KC_NO, KC_QUES, KC_COLN, KC_EQL, KC_TILD), NOROW, NOROW,
              THUM(KC_NO, KC_SLSH, KC_BSLS, KC_NO)),
    [5] = KCS(NOROW, NOROW, ROW(KC_CIRC, KC_LBRC, KC_LCBR, KC_LPRN, KC_NO),
              ROW(KC_NO, KC_RPRN, KC_RCBR, KC_RBRC, KC_DLR), NOROW, NOROW,
              THUM(KC_NO, KC_SLSH, KC_BSLS, KC_NO)),
    [6] = KCS(NOROW, NOROW, ROW(KC_AT, KC_AMPR, KC_ASTR, KC_DOT, KC_NO),
              ROW(KC_NO, KC_SLSH, KC_PERC, KC_PLUS, KC_EQL), NOROW, NOROW,
              THUM(KC_NO, KC_UNDS, KC_MINS, KC_NO)),
    [7] = KCS(NOROW, NOROW, ROW(KC_END, KC_PGDN, KC_PGUP, KC_HOME, KC_NO),
              ROW(KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT), NOROW, NOROW,
              THUM(KC_NO, KC_INS, KC_DEL, KC_NO)),
    [8] = KCS(NOROW, NOROW, ROW(MS_BTN5, MS_BTN4, MS_BTN2, MS_BTN1, KC_NO),
              ROW(KC_NO, MS_LEFT, MS_DOWN, MS_UP, MS_RGHT), NOROW, NOROW,
              THUM(KC_NO, MS_WHLD, MS_WHLU, KC_NO)),
    [9] = KCS(NOROW, NOROW, ROW(KC_ESC, KC_TAB, KC_TAB, KC_ENT, KC_NO),
              ROW(KC_NO, KC_ENT, KC_TAB, KC_TAB, KC_ESC), NOROW, NOROW,
              THUM(KC_NO, KC_LNG2, KC_LNG1, KC_NO)),
    [10] = KCS(NOROW, NOROW, ROW(KC_F8, KC_F6, KC_F4, KC_F2, KC_NO),
               ROW(KC_NO, KC_F3, KC_F5, KC_F7, KC_F9), NOROW, NOROW,
               THUM(KC_NO, KC_F11, KC_F1, KC_NO)),
};
