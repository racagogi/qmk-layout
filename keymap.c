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

enum custom_keycodes {
  LLOCK = SAFE_RANGE,
  VI_VSP,
  VI_HSP,
  VI_SWAP,
  VI_NEXT,
  VI_CLOSE
};

enum custom_layers {
  _ColemakDH,
  _Kor,
  _Num,
  _Puc,
  _Brace,
  _Logic,
  _Var,
  _Mod,
  _Fun,
  _Mov,
  _Mdi,
  _Mouse,
  _Plane,
  _CMD,
  _Win,
  _Util
};
#define COMBO_LIST                                                             \
  COMBO_X(QGRV_BOOT, QK_BOOT, KC_Q, KC_GRV)                                    \
  COMBO_X(TN_WORD, CW_TOGG, KC_T, KC_N)                                        \
  COMBO_X(DH_KOR, TG(_Kor), KC_D, KC_H)                                        \
  COMBO_X(SE_UTIL, OSL(_Util), KC_S, KC_E)                                     \
  COMBO_X(ADQT_CMD, OSL(_CMD), KC_X, KC_DQT)                                   \
  COMBO_X(RI_WIN, OSL(_Win), KC_R, KC_I)                                       \
  COMBO_X(XUNDS_PLANE, OSL(_Plane), KC_X, KC_UNDS)                             \
  COMBO_X(AO_FUN, OSL(_Fun), KC_A, KC_O)

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
#define ROWLM(x0, x1, x2, x3, x4)                                              \
  LT(_Mov, x0), LT(_Mod, x1), LT(_Mouse, x2), LT(_Num, x3), x4
#define ROWLS(x0, x1, x2, x3, x4)                                              \
  LT(_Logic, x0), LT(_Var, x1), LT(_Brace, x2), LT(_Puc, x3), x4
#define ROWRM(x0, x1, x2, x3, x4)                                              \
  x0, LT(_Num, x1), LT(_Mouse, x2), LT(_Mod, x3), LT(_Mov, x4)
#define ROWRS(x0, x1, x2, x3, x4)                                              \
  x0, LT(_Puc, x1), LT(_Brace, x2), LT(_Var, x3), LT(_Logic, x4)
#define KCS(x0, x1, x2, x3, x4, x5, x6)                                        \
  LAYOUT_split_3x5_3(x0, x1, x2, x3, x4, x5, x6)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
    [_ColemakDH] = KCS(ROW(KC_Q, KC_W, KC_F, KC_P, KC_B),
                       ROW(KC_J, KC_L, KC_U, KC_Y, KC_GRV),
                       ROWLM(KC_A, KC_R, KC_S, KC_T, KC_G),
                       ROWRM(KC_M, KC_N, KC_E, KC_I, KC_O),
                       ROWLS(KC_Z, KC_X, KC_C, KC_D, KC_V),
                       ROWRS(KC_K, KC_H, KC_DQT, KC_UNDS, KC_COLN),
                       THUM(MO(_Mdi), KC_SPC, KC_BSPC, MO(_Mdi))),
    [_Kor] = KCS(ROW(KC_Q, KC_W, KC_E, KC_R, KC_T),
                 ROW(KC_Y, KC_U, KC_I, KC_O, KC_GRV),
                 ROWLM(KC_A, KC_S, KC_D, KC_F, KC_G),
                 ROWRM(KC_H, KC_J, KC_K, KC_L, KC_P),
                 ROWLS(KC_Z, KC_X, KC_C, KC_V, KC_B),
                 ROWRS(KC_N, KC_M, KC_DQT, KC_UNDS, KC_COLN),
                 THUM(MO(_Mdi), KC_SPC, KC_BSPC, MO(_Mdi))),
    [_Num] = KCS(NOROW, NOROW, ROW(KC_8, KC_6, KC_4, KC_2, KC_NO),
                 ROW(KC_NO, KC_3, KC_5, KC_7, KC_9), NOROW, NOROW,
                 THUM(LLOCK, KC_0, KC_1, LLOCK)),
    [_Puc] = KCS(NOROW, NOROW, ROW(KC_SCLN, KC_GRV, KC_QUOT, KC_DQT, KC_NO),
                 ROW(KC_NO, KC_COMM, KC_DOT, KC_QUES, KC_EXLM), NOROW, NOROW,
                 THUM(LLOCK, KC_AT, KC_HASH, LLOCK)),
    [_Logic] = KCS(NOROW, NOROW, ROW(KC_PIPE, KC_AMPR, KC_LT, KC_GT, KC_NO),
                   ROW(KC_NO, KC_QUES, KC_COLN, KC_EQL, KC_TILD), NOROW, NOROW,
                   THUM(LLOCK, KC_SLSH, KC_BSLS, LLOCK)),
    [_Brace] = KCS(NOROW, NOROW, ROW(KC_CIRC, KC_LBRC, KC_LCBR, KC_LPRN, KC_NO),
                   ROW(KC_NO, KC_RPRN, KC_RCBR, KC_RBRC, KC_DLR), NOROW, NOROW,
                   THUM(LLOCK, KC_SLSH, KC_BSLS, LLOCK)),
    [_Var] = KCS(NOROW, NOROW, ROW(KC_AT, KC_AMPR, KC_ASTR, KC_DOT, KC_NO),
                 ROW(KC_NO, KC_SLSH, KC_PERC, KC_PLUS, KC_EQL), NOROW, NOROW,
                 THUM(LLOCK, KC_UNDS, KC_MINS, LLOCK)),
    [_Mov] = KCS(NOROW, NOROW, ROW(KC_END, KC_PGDN, KC_PGUP, KC_HOME, KC_NO),
                 ROW(KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT), NOROW, NOROW,
                 THUM(LLOCK, KC_INS, KC_DEL, LLOCK)),
    [_Mouse] = KCS(NOROW, NOROW, ROW(MS_BTN5, MS_BTN4, MS_BTN2, MS_BTN1, KC_NO),
                   ROW(KC_NO, MS_LEFT, MS_DOWN, MS_UP, MS_RGHT), NOROW, NOROW,
                   THUM(LLOCK, MS_WHLD, MS_WHLU, LLOCK)),
    [_Mod] = KCS(NOROW, NOROW, ROW(KC_ESC, KC_TAB, KC_TAB, KC_ENT, KC_NO),
                 ROW(KC_NO, KC_ENT, KC_TAB, KC_TAB, KC_ESC), NOROW, NOROW,
                 THUM(LLOCK, KC_LNG2, KC_LNG1, LLOCK)),
    [_Fun] = KCS(NOROW, NOROW, ROW(KC_F8, KC_F6, KC_F4, KC_F2, KC_NO),
                 ROW(KC_NO, KC_F3, KC_F5, KC_F7, KC_F9), NOROW, NOROW,
                 THUM(KC_NO, KC_F11, KC_F1, KC_NO)),
    [_Mdi] = KCS(NOROW, NOROW, ROW(KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO),
                 ROW(KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI), NOROW, NOROW,
                 THUM(LLOCK, KC_LNG2, KC_LNG1, LLOCK)),
    [_Win] = KCS(
        NOROW, NOROW, ROW(RSG(KC_1), RSG(KC_2), RSG(KC_3), RSG(KC_4), KC_NO),
        ROW(KC_NO, LGUI(KC_DOT), LGUI(KC_COMM), RSG(KC_F), RSG(KC_C)), NOROW,
        NOROW, THUM(KC_NO, LGUI(KC_MINS), LGUI(KC_PLUS), KC_NO)),
    [_Plane] = KCS(NOROW, NOROW,
                   ROW(RCS(KC_X), RCS(KC_W), RCS(KC_PERC), RCS(KC_DQT), KC_NO),
                   ROW(KC_NO, VI_VSP, VI_HSP, VI_NEXT, VI_SWAP), NOROW, NOROW,
                   THUM(KC_NO, RCS(KC_Q), VI_CLOSE, KC_NO)),
    [_CMD] = KCS(NOROW, NOROW, ROW(KC_NO, RSG(KC_M), RSG(KC_V), RSG(KC_W), KC_NO),
                 ROW(KC_NO, KC_PSCR, LALT(KC_PSCR), RSG(KC_R), RSG(KC_S)),
                 NOROW, NOROW, THUM(KC_NO, RSG(KC_LEFT), RSG(KC_RIGHT), KC_NO)),
    [_Util] =
        KCS(NOROW, NOROW, ROW(KC_F12, KC_F10, RCS(KC_C), RCS(KC_V), KC_NO),
            ROW(KC_NO, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT), NOROW, NOROW,
            THUM(KC_NO, MS_BTN5, MS_BTN4, KC_NO)),
};
