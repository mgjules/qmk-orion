#include QMK_KEYBOARD_H

enum custom_keycodes {
    USR_UNDO = SAFE_RANGE,
    USR_CUT,
    USR_COPY,
    USR_PASTE,
    USR_SAVE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_split_3x5_2(
		KC_Q,			KC_W,			KC_F,			KC_P,			KC_B,				KC_J,			KC_L,			KC_U,			KC_Y,			KC_QUOT,
		KC_A,			KC_R,			KC_S,			KC_T,			KC_G,				KC_M,			KC_N,			KC_E,			KC_I,			KC_O,
		KC_Z,			KC_X,			KC_C,			KC_D,			KC_V,				KC_K,			KC_H,			KC_COMM,		KC_DOT,			KC_SLSH,
											MO(2),			KC_SPC,			        KC_LSFT,		MO(1)
    ),
	[1] = LAYOUT_split_3x5_2(
		KC_EXLM,		KC_AT,			KC_HASH,		KC_DLR,			KC_PERC,			KC_CIRC,		KC_AMPR,		KC_ASTR,		KC_TRNS,		KC_TRNS,
		KC_GRV,			KC_LT,			KC_LCBR,		KC_LPRN,		KC_LBRC,			KC_PIPE,		KC_COLN,		KC_MINS,		KC_QUOT,		KC_EQL,
		KC_TILD,		KC_GT,			KC_RCBR,		KC_RPRN,		KC_RBRC,			KC_BSLS,		KC_SCLN,		KC_UNDS,		KC_DQUO,		LSFT(KC_EQL),
											MO(3),			KC_TRNS,			KC_TRNS,		KC_TRNS
    ),
	[2] = LAYOUT_split_3x5_2(
		KC_ESC,			QK_RBT,			KC_VOLD,		KC_MUTE,		KC_VOLU,			KC_PGUP,		KC_HOME,		KC_UP,			KC_END,			KC_INS,
		KC_LCTL,		KC_LALT,		KC_LGUI,		KC_LSFT,		KC_TAB,				KC_PGDN,		KC_LEFT,		KC_DOWN,		KC_RGHT,		KC_DEL,
		USR_UNDO,		USR_CUT,		USR_COPY,		USR_PASTE,		USR_SAVE,		    QK_REP,			KC_ENT,		 	KC_PSCR,		KC_SCRL,		KC_BSPC,
											KC_TRNS,		KC_TRNS,			KC_TRNS,		MO(3)
    ),
	[3] = LAYOUT_split_3x5_2(
		KC_F1,			KC_F2,			KC_F3,			KC_F4,			KC_F5,				KC_PAST,		KC_7,		  	KC_8,			KC_9,			LSFT(KC_EQL),
		KC_LCTL,		KC_LALT,		KC_LGUI,		KC_LSFT,		KC_COMM,			KC_PSLS,		KC_4,			KC_5,			KC_6,			KC_MINS,
		KC_F6,			KC_F7,			KC_F8,			KC_F9,			KC_F10,				KC_0,			KC_1,			KC_2,			KC_3,			KC_PEQL,
											KC_TRNS,		KC_TRNS,			KC_TRNS,		KC_TRNS
    )
};

const uint16_t PROGMEM uy_combo[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM wf_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM commadot_combo[] = {KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
combo_t key_combos[] = {
	COMBO(uy_combo, KC_BSPC),
	COMBO(wf_combo, KC_ESC),
	COMBO(commadot_combo, KC_ENTER),
	COMBO(xc_combo, KC_TAB),
};

void process_platform_combo(uint16_t keycode, keyrecord_t *record) {
  os_variant_t host_os = detected_host_os();
  uint16_t keycode_to_press = KC_NO;
  if (host_os == OS_MACOS || host_os == OS_IOS) {
    switch (keycode) {
      case USR_UNDO:
        keycode_to_press = G(KC_Z);
        break;
      case USR_CUT:
        keycode_to_press = G(KC_X);
        break;
      case USR_COPY:
        keycode_to_press = G(KC_C);
        break;
      case USR_PASTE:
        keycode_to_press = G(KC_V);
        break;
      case USR_SAVE:
        keycode_to_press = G(KC_S);
        break;
    }
  } else {
    switch (keycode) {
      case USR_UNDO:
        keycode_to_press = C(KC_Z);
        break;
      case USR_CUT:
        keycode_to_press = C(KC_X);
        break;
      case USR_COPY:
        keycode_to_press = C(KC_C);
        break;
      case USR_PASTE:
        keycode_to_press = C(KC_V);
        break;
      case USR_SAVE:
        keycode_to_press = C(KC_S);
        break;
    }
  }
  if (record->event.pressed) {
    register_code16(keycode_to_press);
  } else {
    unregister_code16(keycode_to_press);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case USR_UNDO:
    case USR_CUT:
    case USR_COPY:
    case USR_PASTE:
    case USR_SAVE:
        process_platform_combo(keycode, record);
        return false;
    }

    return true;
};
