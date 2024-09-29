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
  COMBO_X(AR_ESC, KC_ESC, LGUI_T(KC_A), LALT_T(KC_R))                          \
  COMBO_X(IO_ESC, KC_ESC, LGUI_T(KC_O), LALT_T(KC_I))                          \
  COMBO_X(RS_TAB, KC_TAB, LCTL_T(KC_S), LALT_T(KC_R))                          \
  COMBO_X(EI_TAB, KC_TAB, LCTL_T(KC_E), LALT_T(KC_I))                          \
  COMBO_X(ST_ENT, KC_ENT, LCTL_T(KC_S), LSFT_T(KC_T))                          \
  COMBO_X(NE_ENT, KC_ENT, LCTL_T(KC_E), LSFT_T(KC_N))                          \
  COMBO_X(PF_LPRN, KC_LPRN, KC_P, KC_F)                                        \
  COMBO_X(FW_LCBR, KC_LCBR, KC_F, KC_W)                                        \
  COMBO_X(QW_BRC, KC_LBRC, KC_Q, KC_W)                                         \
  COMBO_X(LU_RPAR, KC_RPRN, KC_L, KC_U)                                        \
  COMBO_X(UY_RCBR, KC_RCBR, KC_U, KC_Y)                                        \
  COMBO_X(YGRV_BRC, KC_RBRC, KC_Y, KC_GRV)                                     \
  COMBO_X(ZX_PERC, KC_PERC, KC_Z, KC_X)                                        \
  COMBO_X(XC_PLUS, KC_PLUS, KC_X, KC_C)                                        \
  COMBO_X(CD_ASTR, KC_ASTR, KC_C, KC_D)                                        \
  COMBO_X(HCOM_SLS, KC_SLSH, KC_H, KC_DQT)                                     \
  COMBO_X(COMDOT_BSLS, KC_BSLS, KC_UNDS, KC_DQT)                               \
  COMBO_X(DOTCOL_TILD, KC_TILD, KC_UNDS, KC_COLN)                              \
  COMBO_X(PT_PIPE, KC_PIPE, KC_P, LSFT_T(KC_T))                                \
  COMBO_X(FS_AMPR, KC_AMPR, KC_F, LCTL_T(KC_S))                                \
  COMBO_X(LN_CIRC, KC_CIRC, KC_L, LSFT_T(KC_N))                                \
  COMBO_X(UE_DLR, KC_DLR, KC_U, LCTL_T(KC_E))                                  \
  COMBO_X(GM_TG1, TG(1), KC_G, KC_M)                                           \
  COMBO_X(BJ_TG4, TG(4), KC_B, KC_J)                                           \
  COMBO_X(VK_LNG, KC_LNG1, KC_V, KC_K)                                         \
  COMBO_X(TN_TOGG, CW_TOGG, LSFT_T(KC_T), LSFT_T(KC_N))                        \
  COMBO_X(QGRV_BOOT, QK_BOOT, KC_Q, KC_GRV)

const key_override_t min_key_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_UNDS, KC_MINS);
const key_override_t quot_key_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_DQT, KC_QUOT);
const key_override_t col_key_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_COLN, KC_EQL);
const key_override_t grv_key_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_GRV, KC_SCLN);
// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {&min_key_override, &quot_key_override,
                                         &col_key_override, &grv_key_override};

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
    [2] = KCS(ROW(KC_1, KC_2, KC_3, KC_HASH, KC_NO),
              ROW(KC_NO, KC_PSCR, LALT(KC_PSCR), LSG(KC_R), LSG(KC_S)),
              ROW(KC_4, KC_5, KC_6, KC_0, KC_NO),
              ROW(KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI),
              ROW(KC_7, KC_8, KC_9, KC_AT, KC_B),
              ROW(KC_NO, KC_QUES, KC_EXLM, KC_PIPE, KC_AMPR),
              THUM(KC_NO, KC_NO, KC_NO, KC_NO)),
    [3] = KCS(ROW(KC_F1, KC_F2, KC_F3, KC_F10, KC_NO),
              ROW(KC_NO, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT),
              ROW(KC_F4, KC_F5, KC_F6, KC_F11, KC_NO),
              ROW(KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT),
              ROW(KC_F7, KC_F8, KC_F9, KC_F12, KC_NO),
              ROW(KC_NO, KC_END, KC_PGDN, KC_PGUP, KC_HOME),
              THUM(KC_NO, KC_NO, KC_NO, KC_NO)),
    [4] = KCS(ROW(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
              ROW(KC_NO, MS_WHLU, MS_WHLD, MS_WHLL, MS_WHLR),
              ROW(MS_BTN5, MS_BTN4, MS_BTN2, MS_BTN1, KC_NO),
              ROW(KC_NO, MS_LEFT, MS_DOWN, MS_UP, MS_RGHT),
              ROW(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
              ROW(KC_NO, MS_BTN1, MS_BTN2, MS_BTN4, MS_BTN5),
              THUM(KC_NO, KC_NO, KC_NO, KC_NO))};


