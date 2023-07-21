#include QMK_KEYBOARD_H


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_split_3x5_2(
		KC_Q,			KC_W,			KC_F,			KC_P,			KC_B,				KC_J,			KC_L,			KC_U,			KC_Y,			KC_QUOT,
		KC_A,			KC_R,			KC_S,			KC_T,			KC_G,				KC_M,			KC_N,			KC_E,			KC_I,			KC_O,
		KC_Z,			KC_X,			KC_C,			KC_D,			KC_V,				KC_K,			KC_H,			KC_COMM,		KC_DOT,			KC_SLSH,
											MO(2),			KC_SPC,				KC_LSFT,		MO(1)
    ),
	[1] = LAYOUT_split_3x5_2(
		KC_EXLM,		KC_AT,			KC_HASH,		KC_DLR,			KC_PERC,			KC_CIRC,		KC_AMPR,		KC_ASTR,		KC_TRANS,		KC_TRANS, 
		KC_GRV,			KC_LT,			KC_LCBR,		KC_LPRN,		KC_LBRC,			KC_PIPE,		KC_COLN,		KC_MINS,		KC_QUOT,		KC_PEQL, 
		KC_TILD,		KC_GT,			KC_RCBR,		KC_RPRN,		KC_RBRC,			KC_BSLS,		KC_SCLN,		KC_UNDS,		KC_DQUO,		KC_PPLS, 
											MO(3),			KC_TRANS,			KC_TRANS,		KC_TRANS
    ),
	[2] = LAYOUT_split_3x5_2(
		KC_ESC,			QK_RBT,			KC_VOLD,		KC_MUTE,		KC_VOLU,			KC_PGUP,		KC_HOME,		KC_UP,			KC_END,			KC_INS, 
		KC_LCTL,		KC_LALT,		KC_LGUI,		KC_LSFT,		KC_TAB,				KC_PGDN,		KC_LEFT,		KC_DOWN,		KC_RGHT,		KC_DEL, 
		LGUI(KC_Z),		LGUI(KC_X),		LGUI(KC_C),		LGUI(KC_V),		LGUI(KC_S),		 	QK_REP,			KC_ENT,		 	KC_PSCR,		KC_SCRL,		KC_BSPC, 
											KC_TRANS,		KC_TRANS,			KC_TRANS,		MO(3)
    ),
	[3] = LAYOUT_split_3x5_2(
		KC_F1,			KC_F2,			KC_F3,			KC_F4,			KC_F5,				KC_PAST,		KC_P7,		  	KC_P8,			KC_P9,			KC_PPLS, 
		KC_LCTL,		KC_LALT,		KC_LGUI,		KC_LSFT,		KC_PCMM,			KC_PSLS,		KC_P4,			KC_P5,			KC_P6,			KC_PMNS, 
		KC_F6,			KC_F7,			KC_F8,			KC_F9,			KC_F10,				KC_P0,			KC_P1,			KC_P2,			KC_P3,			KC_PEQL, 
											KC_TRANS,		KC_TRANS,			KC_TRANS,		KC_TRANS
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
