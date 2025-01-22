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
#include "features/layer_lock.h"
#include "keycode.h"
#include "macro.h"
#include "override.h"
#include "combo.h"

#define ROW(x0, x1, x2, x3, x4) x0, x1, x2, x3, x4
#define ROHRW(x0, x1, x2, x3, x4)                                              \
  x0, LSFT_T(x1), LCTL_T(x2), LALT_T(x3), LGUI_T(x4)
#define ROHLW(x0, x1, x2, x3, x4)                                              \
  LGUI_T(x0), LALT_T(x1), LCTL_T(x2), LSFT_T(x3), x4
#define NOROW KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
#define TRROW KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
// #define THUM(x0, x1, x2, x3) KC_NO, x0, x1, x2, x3, KC_NO
#define THUM(x0, x1, x2, x3)  x0, x1, x2, x3

#define KCS(x0, x1, x2, x3, x4, x5, x6)                                        \
  LAYOUT_split_3x5_2(x0, x1, x2, x3, x4, x5, x6)
  // LAYOUT_split_3x5_3(x0, x1, x2, x3, x4, x5, x6)
/* #define KCS(x0, x1, x2, x3, x4, x5, x6) \
  LAYOUT_planck_grid(x0,                                                       \
                     KC_NO,                                                    \
                     KC_NO,                                                    \
                     x1,                                                       \
                     x2,                                                       \
                     KC_NO,                                                    \
                     KC_NO,                                                    \
                     x3,                                                       \
                     x4,                                                       \
                     KC_NO,                                                    \
                     KC_NO,                                                    \
                     x5,                                                       \
                     KC_NO,                                                    \
                     KC_NO,                                                    \
                     KC_NO,                                                    \
                     x6,                                                       \
                     KC_NO,                                                    \
                     KC_NO,                                                    \
                     KC_NO) */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_ColemakDH] =
    KCS(ROW(KC_Q, KC_W, KC_F, KC_P, KC_B),
        ROW(KC_J, KC_L, KC_U, KC_Y, KC_GRV),
        ROW(COLEMAK_A, COLEMAK_R, COLEMAK_S, COLEMAK_T, KC_G),
        ROW(KC_M, COLEMAK_N, COLEMAK_E, COLEMAK_I, COLEMAK_O),
        ROW(COLEMAK_Z, COLEMAK_X, COLEMAK_C, COLEMAK_D, KC_V),
        ROW(KC_K, COLEMAK_H, COLEMAK_QUOT, COLEMAK_MINS, COLEMAK_SCLN),
        THUM(LT(_Num, KC_COMM), KC_SPC, KC_BSPC, LT(_Mov, KC_DOT))),
  [_Kor] = KCS(ROW(KC_Q, KC_W, KC_E, KC_R, KC_T),
               ROW(KC_Y, KC_U, KC_I, KC_O, KC_GRV),
               ROW(KOR_A, KOR_S, KOR_D, KOR_F, KC_G),
               ROW(KC_H, KOR_J, KOR_K, KOR_L, KOR_P),
               ROW(KOR_Z, KOR_X, KOR_C, KOR_V, KC_B),
               ROW(KC_N, KOR_M, KOR_QUOT, KOR_MINS, KOR_SCLN),
               THUM(KC_TRNS, KC_SPC, KC_BSPC, KC_TRNS)),
  [_Num] = KCS(NOROW,
               NOROW,
               ROHLW(KC_9, KC_7, KC_5, KC_3, KC_NO),
               ROHRW(KC_NO, KC_2, KC_4, KC_6, KC_8),
               ROW(KC_NO, KC_NO, KC_NO, KC_1, KC_NO),
               ROW(KC_NO, KC_0, KC_NO, KC_NO, KC_NO),
               THUM(MO(_Mouse), KC_SPC, KC_BSPC, MO(_Mouse))),
  [_Puc] = KCS(NOROW,
               NOROW,
               ROW(KC_SCLN, KC_AT, KC_QUES, KC_UNDS, KC_NO),
               ROW(KC_NO, KC_COLN, KC_EXLM, KC_HASH, KC_GRV),
               ROW(KC_LGUI, KC_LALT, KC_LCTL, KC_NO, KC_NO),
               ROW(KC_NO, KC_NO, KC_LCTL, KC_LALT, KC_LGUI),
               THUM(KC_LSFT, KC_QUOT, KC_DQT, KC_LSFT)),
  [_Brace] = KCS(NOROW,
                 NOROW,
                 ROW(KC_CIRC, KC_DLR, KC_SLSH, KC_BSLS, KC_NO),
                 ROW(KC_NO, KC_LBRC, KC_LCBR, KC_RCBR, KC_RBRC),
                 ROW(KC_LGUI, KC_LALT, KC_NO, KC_LCTL, KC_NO),
                 ROW(KC_NO, KC_LCTL, KC_NO, KC_LALT, KC_LGUI),
                 THUM(KC_LSFT, KC_LPRN, KC_RPRN, KC_LSFT)),
  [_Operator] = KCS(NOROW,
                    NOROW,
                    ROW(KC_PIPE, KC_AMPR, KC_LT, KC_GT, KC_NO),
                    ROW(KC_NO, KC_ASTR, KC_PERC, KC_EQL, KC_PLUS),
                    ROW(KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_NO),
                    ROW(KC_NO, KC_LCTL, KC_LALT, KC_LGUI, KC_NO),
                    THUM(KC_LSFT, KC_MINS, KC_TILD, KC_LSFT)),
  [_Mov] = KCS(NOROW,
               NOROW,
               ROW(KC_HOME, KC_PGUP, KC_PGDN, KC_END, KC_NO),
               ROW(KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT),
               ROW(KC_LGUI, KC_LALT, KC_LCTL, KC_VOLD, KC_NO),
               ROW(KC_NO, KC_VOLU, KC_LCTL, KC_LALT, KC_LGUI),
               THUM(MO(_Mouse), KC_NO, KC_NO, MO(_Mouse))),
  [_Mouse] = KCS(NOROW,
                 NOROW,
                 ROW(MS_BTN5, MS_BTN4, MS_BTN2, MS_BTN1, KC_NO),
                 ROW(KC_NO, MS_LEFT, MS_DOWN, MS_UP, MS_RGHT),
                 ROW(KC_LGUI, KC_LALT, KC_LCTL, MS_WHLD, KC_NO),
                 ROW(KC_NO, MS_WHLU, KC_LCTL, KC_LALT, KC_LGUI),
                 THUM(KC_NO, KC_NO, KC_NO, KC_NO)),
  [_Plane] = KCS(NOROW,
                 NOROW,
                 ROW(WEZ_SWAP, WEZ_NEXT, WEZ_HSP, WEZ_VSP, KC_NO),
                 ROW(KC_NO, VI_VSP, VI_HSP, VI_NEXT, VI_SWAP),
                 NOROW,
                 NOROW,
                 THUM(KC_TRNS, WEZ_CLOSE, VI_CLOSE, KC_NO)),
  [_Win] = KCS(NOROW,
               NOROW,
               ROW(KC_NO, NIRI_WAYD, NIRI_VIVA, NIRI_WEZ, KC_NO),
               ROW(KC_NO, NIRI_M1, NIRI_M2, NIRI_M3, NIRI_M4),
               NOROW,
               NOROW,
               THUM(KC_NO, NIRI_SWPL, NIRI_SWPR, KC_NO)),
  [_Works] = KCS(NOROW,
                 NOROW,
                 ROW(KC_NO, NIRI_CUN, NIRI_EXPL, NIRI_FULL, NIRI_CLOSE),
                 ROW(KC_NO, KC_PSCR, LALT(KC_PSCR), NIRI_REC, NIRI_RST),
                 NOROW,
                 NOROW,
                 THUM(KC_TRNS, NIRI_SZDN, NIRI_SZUP, KC_TRNS)),
};
