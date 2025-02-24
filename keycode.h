#ifndef INCLUDE_QMK_LAYOUT_KEYCODE_H_
#define INCLUDE_QMK_LAYOUT_KEYCODE_H_

#include QMK_KEYBOARD_H

enum custom_keycodes
{
  LLOCK = SAFE_RANGE,
  VI_VSP,
  VI_HSP,
  VI_SWAP,
  VI_NEXT,
  VI_CLOSE,
  LANG_TG

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

#endif // INCLUDE_QMK-LAYOUT_KEYCODE_H_
