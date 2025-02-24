#ifndef INCLUDE_QMK_LAYOUT_COMBO_H_
#define INCLUDE_QMK_LAYOUT_COMBO_H_

#define COMBO_LIST                                                             \
  COMBO_X(QGRV_BOOT, QK_BOOT, KC_Q, KC_GRV)                                    \
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
    COMBO_LIST;
#undef COMBO_X

combo_t key_combos[] = {
#define COMBO_X(name, combos, ...) [name] = COMBO(name##_combo, combos),
  COMBO_LIST
#undef COMBO_X
};

#endif // INCLUDE_QMK-LAYOUT_COMBO_H_
