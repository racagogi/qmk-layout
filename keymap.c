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

enum custom_keycodes
{
  LLOCK = SAFE_RANGE,
  VI_VSP,
  VI_HSP,
  VI_SWAP,
  VI_NEXT,
  VI_CLOSE
};

enum custom_layers
{
  _ColemakDH,
  _Kor,
  _Num,
  _Puc,
  _Brace,
  _Operator,
  _Mov,
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
#define NIRI_M3 LSG(KC_3)
#define NIRI_M4 LSG(KC_4)
#define NIRI_REC LSG(KC_R)
#define NIRI_RST LSG(KC_S)
#define NIRI_WEZ LSG(KC_W)
#define NIRI_WAYD LSG(KC_M)
#define NIRI_VIVA LSG(KC_V)
#define NIRI_CUN LGUI(KC_COMM)
#define NIRI_EXPL LGUI(KC_DOT)
#define NIRI_CLOSE LSG(KC_Q)
#define NIRI_SZDN LGUI(KC_MINS)
#define NIRI_SZUP LGUI(KC_EQL)
#define NIRI_SWPL LSG(KC_LEFT)
#define NIRI_SWPR LSG(KC_RIGHT)
#define NIRI_FULL LGUI(KC_F)

#define COLEMAK_A LGUI_T(KC_A)
#define COLEMAK_R LALT_T(KC_R)
#define COLEMAK_S LCTL_T(KC_S)
#define COLEMAK_T LSFT_T(KC_T)
#define COLEMAK_N LSFT_T(KC_N)
#define COLEMAK_E LCTL_T(KC_E)
#define COLEMAK_I LALT_T(KC_I)
#define COLEMAK_O LGUI_T(KC_O)
#define COLEMAK_Z KC_Z
#define COLEMAK_X LT(_Operator, KC_X)
#define COLEMAK_C LT(_Brace, KC_C)
#define COLEMAK_D LT(_Puc, KC_D)
#define COLEMAK_H LT(_Puc, KC_H)
#define COLEMAK_QUOT LT(_Brace, KC_QUOT)
#define COLEMAK_MINS LT(_Operator, KC_MINS)
#define COLEMAK_SCLN KC_SCLN

#define KOR_A LGUI_T(KC_A)
#define KOR_S LALT_T(KC_S)
#define KOR_D LCTL_T(KC_D)
#define KOR_F LSFT_T(KC_F)
#define KOR_J LSFT_T(KC_J)
#define KOR_K LCTL_T(KC_K)
#define KOR_L LALT_T(KC_L)
#define KOR_P LGUI_T(KC_P)
#define KOR_Z KC_Z
#define KOR_X LT(_Operator, KC_X)
#define KOR_C LT(_Brace, KC_C)
#define KOR_V LT(_Puc, KC_V)
#define KOR_M LT(_Puc, KC_M)
#define KOR_QUOT LT(_Brace, KC_QUOT)
#define KOR_MINS LT(_Operator, KC_MINS)
#define KOR_SCLN KC_SCLN

bool
process_record_user(uint16_t keycode, keyrecord_t* record)
{
  if (!process_layer_lock(keycode, record, LLOCK)) {
    return false;
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
  ko_make_basic(MOD_MASK_SHIFT, KC_0, KC_F11);

// This globally defines all key overrides to be used
const key_override_t* key_overrides[] = {
  &f1_key_override, &f2_key_override,  &f3_key_override, &f4_key_override,
  &f5_key_override, &f6_key_override,  &f7_key_override, &f8_key_override,
  &f9_key_override, &f10_key_override,
};

#define COMBO_LIST                                                             \
  COMBO_X(QGRV_BOOT, QK_BOOT, KC_Q, KC_GRV)                                    \
  COMBO_X(TN_WORD, CW_TOGG, COLEMAK_T, COLEMAK_N)                              \
  COMBO_X(ST_ENT, KC_ENT, COLEMAK_S, COLEMAK_T)                                \
  COMBO_X(NE_ENT, KC_ENT, COLEMAK_N, COLEMAK_E)                                \
  COMBO_X(RS_TAB, KC_TAB, COLEMAK_R, COLEMAK_S)                                \
  COMBO_X(EI_TAB, KC_TAB, COLEMAK_E, COLEMAK_I)                                \
  COMBO_X(AR_ESC, KC_ESC, COLEMAK_A, COLEMAK_R)                                \
  COMBO_X(IO_ESC, KC_ESC, COLEMAK_I, COLEMAK_O)                                \
  COMBO_X(TD_KOR, KC_LNG1, COLEMAK_T, COLEMAK_D)                               \
  COMBO_X(NH_KOR, KC_LNG1, COLEMAK_N, COLEMAK_H)                               \
  COMBO_X(SC_HAN, KC_LNG2, COLEMAK_S, COLEMAK_C)                               \
  COMBO_X(EQUT_HAN, KC_LNG2, COLEMAK_E, COLEMAK_QUOT)                          \
  COMBO_X(XR_DEL, KC_DEL, COLEMAK_X, COLEMAK_R)                                \
  COMBO_X(IMIN_DEL, KC_DEL, COLEMAK_I, COLEMAK_MINS)                           \
  COMBO_X(AZ_INS, KC_INS, COLEMAK_A, COLEMAK_Z)                                \
  COMBO_X(OSCLN_DEL, KC_INS, COLEMAK_O, COLEMAK_SCLN)                          \
  COMBO_X(TG_LANG, TG(_Kor), KC_SPC, KC_BSPC)                                  \
  COMBO_X(DH_LOCK, LLOCK, COLEMAK_D, COLEMAK_H)                                \
  COMBO_X(DC_PLANE, OSL(_Plane), COLEMAK_D, COLEMAK_C)                         \
  COMBO_X(CX_WIN, OSL(_Win), COLEMAK_C, COLEMAK_X)                             \
  COMBO_X(XZ_WORKS, OSL(_Works), COLEMAK_X, COLEMAK_Z)                         \
  COMBO_X(HQUOT_PLANE, OSL(_Plane), COLEMAK_H, COLEMAK_QUOT)                   \
  COMBO_X(MINQUOT_WIN, OSL(_Win), COLEMAK_MINS, COLEMAK_QUOT)                  \
  COMBO_X(SCLNMIN_WORKS, OSL(_Works), COLEMAK_SCLN, COLEMAK_MINS)

enum combos
{
#define COMBO_X(name, combos, ...) name,
  COMBO_LIST
#undef COMBO_X
};

#define COMBO_X(name, combos, ...)                                             \
  const uint16_t PROGMEM name##_combo[] = { __VA_ARGS__, COMBO_END };
COMBO_LIST
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
#define TRROW KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
#define THUM(x0, x1, x2, x3) KC_NO, x0, x1, x2, x3, KC_NO

/* #define KCS(x0, x1, x2, x3, x4, x5, x6) \ LAYOUT_split_3x5_3(x0, x1, x2, x3,
  x4, x5, x6) */
#define KCS(x0, x1, x2, x3, x4, x5, x6)                                        \
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
                     KC_NO)

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
               ROW(KC_LGUI, KC_LALT, KC_LCTL, KC_1, KC_NO),
               ROW(KC_NO, KC_0, KC_LCTL, KC_LALT, KC_LGUI),
               THUM(MO(_Mouse), KC_LSFT, KC_LSFT, MO(_Mouse))),
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
               ROW(NIRI_M1, NIRI_M2, NIRI_M3, NIRI_M4, KC_NO),
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
