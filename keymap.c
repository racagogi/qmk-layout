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

#define COLEMAK_A LT(_Operator, KC_A)
#define COLEMAK_R LT(_Var, KC_R)
#define COLEMAK_S LT(_Brace, KC_S)
#define COLEMAK_T LT(_Puc, KC_T)
#define COLEMAK_N LT(_Puc, KC_N)
#define COLEMAK_E LT(_Brace, KC_E)
#define COLEMAK_I LT(_Var, KC_I)
#define COLEMAK_O LT(_Operator, KC_O)
#define COLEMAK_Z KC_Z
#define COLEMAK_X LT(_Mouse, KC_X)
#define COLEMAK_C LT(_Num, KC_C)
#define COLEMAK_D LT(_Mov, KC_D)
#define COLEMAK_H LT(_Mov, KC_H)
#define COLEMAK_QUOT LT(_Num, KC_QUOT)
#define COLEMAK_MINS LT(_Mouse, KC_MINS)
#define COLEMAK_SCLN KC_SCLN

#define KOR_A LT(_Operator, KC_A)
#define KOR_S LT(_Var, KC_S)
#define KOR_D LT(_Brace, KC_D)
#define KOR_F LT(_Puc, KC_F)
#define KOR_J LT(_Puc, KC_J)
#define KOR_K LT(_Brace, KC_K)
#define KOR_L LT(_Var, KC_L)
#define KOR_P LT(_Operator, KC_P)
#define KOR_Z KC_Z
#define KOR_X LT(_Mouse, KC_X)
#define KOR_C LT(_Num, KC_C)
#define KOR_V LT(_Mov, KC_V)
#define KOR_M LT(_Mov, KC_M)
#define KOR_QUOT LT(_Num, KC_QUOT)
#define KOR_MINS LT(_Mouse, KC_MINS)
#define KOR_SCLN KC_SCLN

enum custom_layers
{
  _ColemakDH,
  _Kor,
  _Num,
  _Fun,
  _Puc,
  _Brace,
  _Operator,
  _Var,
  _Mov,
  _Mouse,
  _Plane,
  _Win,
  _CMD,
  _Util,
  _Mrdi,
  _Mldi,
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
  COMBO_X(LOCK_L, LLOCK, KC_SPC, KC_BSPC)                                      \
  COMBO_X(DH_KOR, TG(_Kor), COLEMAK_D, COLEMAK_H)                              \
  COMBO_X(AO_FUN, OSL(_Fun), COLEMAK_A, COLEMAK_O)                             \
  COMBO_X(SE_PLANE, OSL(_Plane), COLEMAK_S, COLEMAK_E)                         \
  COMBO_X(CQUOT_WIN, OSL(_Win), COLEMAK_C, COLEMAK_QUOT)                       \
  COMBO_X(RI_UTIL, OSL(_Util), COLEMAK_R, COLEMAK_I)                           \
  COMBO_X(XMIN_CMD, OSL(_CMD), COLEMAK_X, COLEMAK_MINS)

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
#define NOROW KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
#define TRROW KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
#define THUM(x0, x1, x2, x3) KC_NO, x0, x1, x2, x3, KC_NO
#define KCS(x0, x1, x2, x3, x4, x5, x6)                                        \
  LAYOUT_split_3x5_3(x0, x1, x2, x3, x4, x5, x6)
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_ColemakDH] =
    KCS(ROW(KC_Q, KC_W, KC_F, KC_P, KC_B),
        ROW(KC_J, KC_L, KC_U, KC_Y, KC_GRV),
        ROW(COLEMAK_A, COLEMAK_R, COLEMAK_S, COLEMAK_T, KC_G),
        ROW(KC_M, COLEMAK_N, COLEMAK_E, COLEMAK_I, COLEMAK_O),
        ROW(COLEMAK_Z, COLEMAK_X, COLEMAK_C, COLEMAK_D, KC_V),
        ROW(KC_K, COLEMAK_H, COLEMAK_QUOT, COLEMAK_MINS, COLEMAK_SCLN),
        THUM(MO(_Mldi), KC_SPC, KC_BSPC, MO(_Mrdi))),
  [_Kor] = KCS(ROW(KC_Q, KC_W, KC_E, KC_R, KC_T),
               ROW(KC_Y, KC_U, KC_I, KC_O, KC_GRV),
               ROW(KOR_A, KOR_S, KOR_D, KOR_F, KC_G),
               ROW(KC_H, KOR_J, KOR_K, KOR_L, KOR_P),
               ROW(KOR_Z, KOR_X, KOR_C, KOR_V, KC_B),
               ROW(KC_N, KOR_M, KOR_QUOT, KOR_MINS, KOR_SCLN),
               THUM(KC_TRNS, KC_SPC, KC_BSPC, KC_TRNS)),
  [_Num] = KCS(NOROW,
               NOROW,
               ROW(KC_9, KC_7, KC_5, KC_3, KC_NO),
               ROW(KC_NO, KC_2, KC_4, KC_6, KC_8),
               NOROW,
               NOROW,
               THUM(KC_TRNS, KC_1, KC_0, KC_TRNS)),
  [_Fun] = KCS(NOROW,
               NOROW,
               ROW(KC_F9, KC_F7, KC_F5, KC_F3, KC_NO),
               ROW(KC_NO, KC_F2, KC_F4, KC_F6, KC_F8),
               NOROW,
               NOROW,
               THUM(KC_TRNS, KC_F1, KC_F11, KC_TRNS)),
  [_Puc] = KCS(NOROW,
               NOROW,
               ROW(KC_SCLN, KC_GRV, KC_QUOT, KC_DQT, KC_NO),
               ROW(KC_NO, KC_COMM, KC_DOT, KC_QUES, KC_EXLM),
               NOROW,
               NOROW,
               THUM(KC_TRNS, KC_AT, KC_HASH, KC_TRNS)),
  [_Brace] = KCS(NOROW,
                 NOROW,
                 ROW(KC_CIRC, KC_LBRC, KC_LCBR, KC_LPRN, KC_NO),
                 ROW(KC_NO, KC_RPRN, KC_RCBR, KC_RBRC, KC_DLR),
                 NOROW,
                 NOROW,
                 THUM(KC_TRNS, KC_SLSH, KC_BSLS, KC_TRNS)),
  [_Var] = KCS(NOROW,
               NOROW,
               ROW(KC_AT, KC_AMPR, KC_ASTR, KC_DOT, KC_NO),
               ROW(KC_NO, KC_QUES, KC_COLN, KC_EQL, KC_TILD),
               NOROW,
               NOROW,
               THUM(KC_TRNS, KC_EXLM, KC_SCLN, KC_TRNS)),
  [_Operator] = KCS(NOROW,
                    NOROW,
                    ROW(KC_PIPE, KC_AMPR, KC_LT, KC_GT, KC_NO),
                    ROW(KC_NO, KC_ASTR, KC_PERC, KC_PLUS, KC_EQL),
                    NOROW,
                    NOROW,
                    THUM(KC_TRNS, KC_UNDS, KC_MINS, KC_TRNS)),
  [_Mov] = KCS(NOROW,
               NOROW,
               ROW(KC_END, KC_PGDN, KC_PGUP, KC_HOME, KC_NO),
               ROW(KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT),
               NOROW,
               NOROW,
               THUM(KC_TRNS, KC_INS, KC_DEL, KC_TRNS)),
  [_Mouse] = KCS(NOROW,
                 NOROW,
                 ROW(MS_BTN5, MS_BTN4, MS_BTN2, MS_BTN1, KC_NO),
                 ROW(KC_NO, MS_LEFT, MS_DOWN, MS_UP, MS_RGHT),
                 NOROW,
                 NOROW,
                 THUM(KC_TRNS, MS_WHLD, MS_WHLU, KC_TRNS)),
  [_Plane] = KCS(NOROW,
                 NOROW,
                 ROW(WEZ_SWAP, WEZ_NEXT, WEZ_HSP, WEZ_VSP, KC_NO),
                 ROW(KC_NO, VI_VSP, VI_HSP, VI_NEXT, VI_SWAP),
                 NOROW,
                 NOROW,
                 THUM(KC_TRNS, WEZ_CLOSE, VI_CLOSE, KC_NO)),
  [_Win] = KCS(NOROW,
               NOROW,
               ROW(NIRI_M1, NIRI_M2, NIRI_M3, NIRI_M4, KC_NO),
               ROW(KC_NO, NIRI_CUN, NIRI_EXPL, NIRI_FULL, NIRI_CLOSE),
               NOROW,
               NOROW,
               THUM(KC_TRNS, NIRI_SZDN, NIRI_SZUP, KC_TRNS)),
  [_CMD] = KCS(NOROW,
               NOROW,
               ROW(KC_NO, NIRI_WAYD, NIRI_VIVA, NIRI_WEZ, KC_NO),
               ROW(KC_NO, KC_PSCR, LALT(KC_PSCR), NIRI_REC, NIRI_RST),
               NOROW,
               NOROW,
               THUM(KC_NO, NIRI_SWPL, NIRI_SWPR, KC_NO)),
  [_Util] = KCS(NOROW,
                NOROW,
                ROW(KC_ESC, KC_TAB, KC_TAB, KC_ENT, KC_NO),
                ROW(KC_NO, KC_ENT, KC_TAB, KC_TAB, KC_ESC),
                NOROW,
                NOROW,
                THUM(KC_TRNS, KC_F12, KC_F10, KC_TRNS)),
  [_Mrdi] = KCS(TRROW,
                TRROW,
                TRROW,
                ROW(KC_TRNS, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI),
                TRROW,
                TRROW,
                THUM(KC_TRNS, KC_LNG2, KC_LNG1, KC_TRNS)),
  [_Mldi] = KCS(TRROW,
                TRROW,
                ROW(KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_TRNS),
                TRROW,
                TRROW,
                TRROW,
                THUM(KC_TRNS, KC_LNG2, KC_LNG1, KC_TRNS)),
};
