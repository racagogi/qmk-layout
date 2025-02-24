#ifndef INCLUDE_QMK_LAYOUT_OVERRIDE_H_
#define INCLUDE_QMK_LAYOUT_OVERRIDE_H_


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

#endif  // INCLUDE_QMK-LAYOUT_OVERRIDE_H_
