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

#include "action_layer.h"
#include "action_util.h"
#include <stdbool.h>
#include QMK_KEYBOARD_H
#include "features/layer_lock.h"

enum custom_keycodes
{
  LLOCK = SAFE_RANGE,
  VI_VSP,
  VI_HSP,
  VI_SWAP,
  VI_NEXT,
  VI_CLOSE,
  LANG_TG,
};

enum custom_layers
{
  _ColemakDH,
  _Kor,
  _Num,
  _Mov,
  _Puc,
  _Operator,
  _Mouse,
  _Plane,
  _Works,
  _Win,
};

#define WEZ_SWAP RCS(KC_X)
#define WEZ_NEXT RCS(KC_N)
#define WEZ_VSP RCS(KC_PERC)
#define WEZ_HSP RCS(KC_DQT)
#define WEZ_CLOSE RCS(KC_Q)

#define NIRI_M1 LSG(KC_1)
#define NIRI_M2 LSG(KC_2)

#define NIRI_REC LSG(KC_R)
#define NIRI_RST LSG(KC_S)

#define NIRI_PROG1 LSG(KC_1)
#define NIRI_PROG2 LSG(KC_2)
#define NIRI_PROG3 LSG(KC_3)
#define NIRI_PROG4 LSG(KC_4)
#define NIRI_PROG5 LSG(KC_5)
#define NIRI_PROG6 LSG(KC_6)
#define NIRI_PROG7 LSG(KC_7)
#define NIRI_PROG8 LSG(KC_8)

#define NIRI_SZDN LGUI(KC_MINS)
#define NIRI_SZUP LGUI(KC_EQL)
#define NIRI_SWPL LSG(KC_LEFT)
#define NIRI_SWPR LSG(KC_RIGHT)

#define COLEMAK_A LGUI_T(KC_A)
#define COLEMAK_R LALT_T(KC_R)
#define COLEMAK_S LCTL_T(KC_S)
#define COLEMAK_T LSFT_T(KC_T)
#define COLEMAK_N LSFT_T(KC_N)
#define COLEMAK_E LCTL_T(KC_E)
#define COLEMAK_I LALT_T(KC_I)
#define COLEMAK_O LGUI_T(KC_O)
#define COLEMAK_Z KC_Z
#define COLEMAK_X LT(_Works, KC_X)
#define COLEMAK_C LT(_Win, KC_C)
#define COLEMAK_D LT(_Plane, KC_D)
#define COLEMAK_H LT(_Plane, KC_H)
#define COLEMAK_QUOT LT(_Win, KC_SLSH)
#define COLEMAK_MINS LT(_Works, KC_BSLS)
#define COLEMAK_SCLN KC_COLN

#define KOR_Z KC_Z
#define KOR_X LT(_Works, KC_X)
#define KOR_C LT(_Win, KC_C)
#define KOR_V LT(_Plane, KC_V)
#define KOR_M LT(_Plane, KC_M)
#define KOR_QUOT LT(_Win, KC_SLSH)
#define KOR_MINS LT(_Works, KC_BSLS)
#define KOR_SCLN KC_COLN

bool
process_record_user(uint16_t keycode, keyrecord_t* record)
{
  static bool ctl_active = false;
  static bool alt_active = false;
  static bool gui_active = false;
  if (!process_layer_lock(keycode, record, LLOCK)) {
    return false;
  }
  if (get_mods() == MOD_BIT(KC_LCTL) && layer_state_is(_Kor)) {
    layer_off(_Kor);
    ctl_active = true;
  } else if (ctl_active) {
    layer_on(_Kor);
    ctl_active = false;
  }
  if (get_mods() == MOD_BIT(KC_LALT) && layer_state_is(_Kor)) {
    layer_off(_Kor);
    alt_active = true;
  } else if (alt_active) {
    layer_on(_Kor);
    alt_active = false;
  }
  if (get_mods() == MOD_BIT(KC_LGUI) && layer_state_is(_Kor)) {
    layer_off(_Kor);
    gui_active = true;
  } else if (gui_active) {
    layer_on(_Kor);
    gui_active = false;
  }
  switch (keycode) {
    case VI_VSP:
      if (record->event.pressed) {
        tap_code16(LCTL(KC_W));
        tap_code(KC_V);
        break;
      }
    case VI_HSP:
      if (record->event.pressed) {
        tap_code16(LCTL(KC_W));
        tap_code(KC_S);
        break;
      }
    case VI_NEXT:
      if (record->event.pressed) {
        tap_code16(LCTL(KC_W));
        tap_code(KC_W);
        break;
      }
    case VI_SWAP:
      if (record->event.pressed) {
        tap_code16(LCTL(KC_W));
        tap_code(KC_X);
        break;
      }
    case VI_CLOSE:
      if (record->event.pressed) {
        tap_code16(LCTL(KC_W));
        tap_code(KC_Q);
        break;
      }
    case LANG_TG:
      if (record->event.pressed) {
        layer_invert(_Kor);
        tap_code(KC_LNG1);
        break;
      }
  }
  return true;
}

const key_override_t f1_key_override =
  ko_make_basic(MOD_MASK_SHIFT, KC_1, KC_F1);
const key_override_t f2_key_override =
  ko_make_basic(MOD_MASK_SHIFT, LSFT_T(KC_2), KC_F2);
const key_override_t f3_key_override =
  ko_make_basic(MOD_MASK_SHIFT, LSFT_T(KC_3), KC_F3);
const key_override_t f4_key_override =
  ko_make_basic(MOD_MASK_SHIFT, LCTL_T(KC_4), KC_F4);
const key_override_t f5_key_override =
  ko_make_basic(MOD_MASK_SHIFT, LCTL_T(KC_5), KC_F5);
const key_override_t f6_key_override =
  ko_make_basic(MOD_MASK_SHIFT, LALT_T(KC_6), KC_F6);
const key_override_t f7_key_override =
  ko_make_basic(MOD_MASK_SHIFT, LALT_T(KC_7), KC_F7);
const key_override_t f8_key_override =
  ko_make_basic(MOD_MASK_SHIFT, LGUI_T(KC_8), KC_F8);
const key_override_t f9_key_override =
  ko_make_basic(MOD_MASK_SHIFT, LGUI_T(KC_9), KC_F9);
const key_override_t f10_key_override =
  ko_make_basic(MOD_MASK_SHIFT, KC_0, KC_F10);

// This globally defines all key overrides to be used
const key_override_t* key_overrides[] = {
  &f1_key_override, &f2_key_override,  &f3_key_override, &f4_key_override,
  &f5_key_override, &f6_key_override,  &f7_key_override, &f8_key_override,
  &f9_key_override, &f10_key_override,
};

#define COMBO_LIST                                                             \
  COMBO_X(QGRV_BOOT, QK_BOOT, KC_Q, KC_UNDS)                                    \
  COMBO_X(TN_WORD, CW_TOGG, COLEMAK_T, COLEMAK_N)                              \
  COMBO_X(ST_ENT, KC_ENT, COLEMAK_S, COLEMAK_T)                                \
  COMBO_X(NE_ENT, KC_ENT, COLEMAK_N, COLEMAK_E)                                \
  COMBO_X(RS_TAB, KC_TAB, COLEMAK_R, COLEMAK_S)                                \
  COMBO_X(EI_TAB, KC_TAB, COLEMAK_E, COLEMAK_I)                                \
  COMBO_X(AR_ESC, KC_ESC, COLEMAK_A, COLEMAK_R)                                \
  COMBO_X(IO_ESC, KC_ESC, COLEMAK_I, COLEMAK_O)                                \
  COMBO_X(TD_TG, TG(_Kor), COLEMAK_T, COLEMAK_D)                               \
  COMBO_X(NH_KOR, KC_LNG1, COLEMAK_N, COLEMAK_H)                               \
  COMBO_X(SC_HAN, KC_LNG2, COLEMAK_S, COLEMAK_C)                               \
  COMBO_X(EQUT_HAN, KC_LNG2, COLEMAK_E, COLEMAK_QUOT)                          \
  COMBO_X(XR_DEL, KC_DEL, COLEMAK_X, COLEMAK_R)                                \
  COMBO_X(IMIN_DEL, KC_DEL, COLEMAK_I, COLEMAK_MINS)                           \
  COMBO_X(AZ_INS, KC_INS, COLEMAK_A, COLEMAK_Z)                                \
  COMBO_X(OSCLN_DEL, KC_INS, COLEMAK_O, COLEMAK_SCLN)                          \
  COMBO_X(TG_LANG, LANG_TG, KC_SPC, KC_BSPC)                                   \
  COMBO_X(DH_LOCK, LLOCK, COLEMAK_D, COLEMAK_H)

enum combos
{
#define COMBO_X(name, combos, ...) name,
  COMBO_LIST
#undef COMBO_X
};

#define COMBO_X(name, combos, ...)                                             \
  const uint16_t PROGMEM name##_combo[] = { __VA_ARGS__, COMBO_END };
COMBO_LIST;
#undef COMBO_X

combo_t key_combos[] = {
#define COMBO_X(name, combos, ...) [name] = COMBO(name##_combo, combos),
  COMBO_LIST
#undef COMBO_X
};

#define ROW(x0, x1, x2, x3, x4) x0, x1, x2, x3, x4
#define ROHRW(x0, x1, x2, x3, x4)                                              \
  x0, LSFT_T(x1), LCTL_T(x2), LALT_T(x3), LGUI_T(x4)
#define ROHLW(x0, x1, x2, x3, x4)                                              \
  LGUI_T(x0), LALT_T(x1), LCTL_T(x2), LSFT_T(x3), x4
#define NOROW KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
#define RMOD KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI
#define LMOD KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO
#define TRROW KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
#define THUM(x0, x1, x2, x3) KC_NO, x0, x1, x2, x3, KC_NO
// #define THUM(x0, x1, x2, x3) x0, x1, x2, x3

// #define KCS(x0, x1, x2, x3, x4, x5, x6)
// LAYOUT_split_3x5_2(x0, x1, x2, x3, x4, x5, x6)
#define KCS(x0, x1, x2, x3, x4, x5, x6)                                        \
  LAYOUT_split_3x5_3(x0, x1, x2, x3, x4, x5, x6)
/* #define KCS(x0, x1, x2, x3, x4, x5, x6) \
  LAYOUT_planck_grid(x0, \
                     KC_NO, \
                     KC_NO, \
                     x1, \
                     x2, \
                     KC_NO, \
                     KC_NO, \
                     x3, \
                     x4, \
                     KC_NO, \
                     KC_NO, \
                     x5, \
                     KC_NO, \
                     KC_NO, \
                     KC_NO, \
                     x6, \
                     KC_NO, \
                     KC_NO, \ KC_NO) */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_ColemakDH] =
    KCS(ROW(KC_Q, KC_W, KC_F, KC_P, KC_B),
        ROW(KC_J, KC_L, KC_U, KC_Y, KC_UNDS),
        ROHLW(KC_A, KC_R, KC_S, KC_T, KC_G),
        ROHRW(KC_M, KC_N, KC_E, KC_I, KC_O),
        ROW(COLEMAK_Z, COLEMAK_X, COLEMAK_C, COLEMAK_D, KC_V),
        ROW(KC_K, COLEMAK_H, COLEMAK_QUOT, COLEMAK_MINS, COLEMAK_SCLN),
        THUM(LT(_Num, KC_COMM), KC_SPC, KC_BSPC, LT(_Mov, KC_DOT))),
  [_Kor] = KCS(ROW(KC_Q, KC_W, KC_E, KC_R, KC_T),
               ROW(KC_Y, KC_U, KC_I, KC_O, KC_UNDS),
               ROHLW(KC_A, KC_S, KC_D, KC_F, KC_G),
               ROHRW(KC_H, KC_J, KC_K, KC_L, KC_P),
               ROW(KOR_Z, KOR_X, KOR_C, KOR_V, KC_B),
               ROW(KC_N, KOR_M, KOR_QUOT, KOR_MINS, KOR_SCLN),
               THUM(KC_TRNS, KC_SPC, KC_BSPC, KC_TRNS)),
  [_Num] = KCS(ROW(KC_LBRC, KC_LCBR, KC_LPRN, KC_LT, KC_NO),
               ROW(KC_NO, KC_GT, KC_RPRN, KC_RCBR, KC_RBRC),
               ROHLW(KC_9, KC_7, KC_5, KC_3, KC_NO),
               ROHRW(KC_NO, KC_2, KC_4, KC_6, KC_8),
               ROW(KC_NO, KC_NO, KC_F11, KC_1, KC_NO),
               ROW(KC_NO, KC_0, KC_F12, KC_NO, KC_NO),
               THUM(MO(_Mouse), KC_NO, MO(_Puc), MO(_Mouse))),
  [_Mov] = KCS(LMOD,
               RMOD,
               ROW(KC_HOME, KC_PGUP, KC_PGDN, KC_END, KC_NO),
               ROW(KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT),
               NOROW,
               NOROW,
               THUM(MO(_Mouse), MO(_Operator), KC_NO, MO(_Mouse))),
  [_Puc] = KCS(NOROW,
               ROW(KC_NO, KC_SCLN, KC_QUES, KC_EXLM, KC_NO),
               LMOD,
               ROW(KC_NO, KC_DQT, KC_QUOT, KC_GRV, KC_NO),
               NOROW,
               ROW(KC_NO, KC_HASH, KC_AT, KC_DLR, KC_NO),
               THUM(KC_NO, KC_NO, KC_NO, KC_NO)),
  [_Operator] = KCS(ROW(KC_NO, KC_NO, KC_CIRC, KC_PERC, KC_NO),
                    NOROW,
                    ROW(KC_PLUS, KC_ASTR, KC_MINS, KC_EQL, KC_NO),
                    RMOD,
                    ROW(KC_NO, KC_TILD, KC_AMPR, KC_PIPE, KC_NO),
                    NOROW,
                    THUM(KC_NO, KC_NO, KC_NO, KC_NO)),
  [_Mouse] = KCS(LMOD,
                 RMOD,
                 ROW(MS_BTN5, MS_BTN4, MS_BTN2, MS_BTN1, KC_NO),
                 ROW(KC_NO, MS_LEFT, MS_DOWN, MS_UP, MS_RGHT),
                 ROW(KC_NO, KC_NO, MS_WHLL, MS_WHLD, KC_NO),
                 ROW(KC_NO, MS_WHLU, MS_WHLR, KC_NO, KC_NO),
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
               ROW(NIRI_PROG1, NIRI_PROG2, NIRI_PROG3, NIRI_PROG4, KC_NO),
               ROW(KC_NO, NIRI_PROG5, NIRI_PROG6, NIRI_PROG7, NIRI_PROG8),
               NOROW,
               NOROW,
               THUM(KC_NO, NIRI_M1, NIRI_M2, KC_NO)),
  [_Works] = KCS(NOROW,
                 NOROW,
                 ROW(NIRI_RST, NIRI_REC, LALT(KC_PSCR), KC_PSCR, KC_NO),
                 ROW(KC_NO, NIRI_SWPL, NIRI_SZDN, NIRI_SZUP, NIRI_SWPR),
                 NOROW,
                 NOROW,
                 THUM(KC_TRNS, NIRI_M1, NIRI_M2, KC_TRNS)),
};
