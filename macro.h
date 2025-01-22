#pragma once
#include "keycode.h"
#include QMK_KEYBOARD_H

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
    case LANG_TG:
      if (record->event.pressed) {
        layer_invert(_Kor);
        tap_code(KC_LNG1);
        break;
      }
  }
  return true;
}

