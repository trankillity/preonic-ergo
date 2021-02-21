#include QMK_KEYBOARD_H

// Define GASC shortcuts
// Format: HR_Mod_Side
#define HR_G_L LGUI_T(KC_A)
#define HR_A_L LALT_T(KC_S)
#define HR_S_L LSFT_T(KC_D)
#define HR_C_L LCTL_T(KC_F)

#define HR_C_R RCTL_T(KC_J)
#define HR_S_R RSFT_T(KC_K)
#define HR_A_R LALT_T(KC_L)
#define HR_G_R RGUI_T(KC_SCLN)

// Define editing layer shortcuts
// Format: EL_Mod_Key
#define EL_C_BCK LCTL(KC_BSPC)
#define EL_C_DEL LCTL(KC_DEL)
#define EL_C_HME LCTL(KC_HOME)
#define EL_C_LFT LCTL(KC_LEFT)
#define EL_C_RGT LCTL(KC_RGHT)
#define EL_C_END LCTL(KC_END)
#define EL_S_HME LSFT(KC_HOME)
#define EL_S_END LSFT_T(KC_END)
#define EL_W_LFT C(G(KC_LEFT))
#define EL_W_RGT C(G(KC_RGHT))
#define EL_W_MAN G(KC_TAB)

// Tap Dance declarations
enum {
    BR_PNT,
	BR_SQR,
	BR_CRL,
	BR_RND
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [BR_PNT] = ACTION_TAP_DANCE_DOUBLE(S(KC_COMM), S(KC_DOT)),		// <,>
    [BR_SQR] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),			// [,]
    [BR_CRL] = ACTION_TAP_DANCE_DOUBLE(S(KC_LBRC), S(KC_RBRC)),		// {,}
    [BR_RND] = ACTION_TAP_DANCE_DOUBLE(S(KC_9), S(KC_0))			// (,)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Base layer:
 * ,-----------------------------------------------------------------------------------.
 * |Rotary|   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |BckSpc|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc~ |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  \   |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |      |   /  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Game |  GUI | Shft |  -   |Ent/Nm|  Edit/Space |NumLyr|   =  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
	[0] = LAYOUT_preonic_1x2uC(
		KC_MPLY,	KC_1,		KC_2,		KC_3,		KC_4,		KC_5,		KC_6,		KC_7,		KC_8,		KC_9,		KC_0,		KC_DEL,
		KC_TAB,		KC_Q,		KC_W,		KC_E,		KC_R,		KC_T,		KC_Y,		KC_U,		KC_I,		KC_O,		KC_P,		KC_BSPC,
		KC_GESC,	HR_G_L,		HR_A_L,		HR_S_L,		HR_C_L,		KC_G,		KC_H,		HR_C_R,		HR_S_R,		HR_A_R,		HR_G_R,		KC_QUOT,
		KC_BSLS,	KC_Z,		KC_X,		KC_C,		KC_V,		KC_B,		KC_N,		KC_M,		KC_COMM,	KC_DOT,		_______,	KC_SLSH,
		TG(10),		KC_LGUI,	KC_LSFT,	KC_MINS,	LT(2,KC_ENT),  LT(1,KC_SPC),		MO(2),		KC_EQL,		_______,	_______,	_______
        ),
/* Editing layer:
 * ,-----------------------------------------------------------------------------------.
 * |Rotary|      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |      |      | C+Bck| C+Del|      | C+Hme| C+Lft|  Up  | C+Rgt| C+End|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc~ |      | S+Hme|  Bck |  Del | S+End| Home | Left | Down | Right|  End |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   \  |      | <  > | [  ] | {  } | (  ) | PgUp | Vol- | MNext| Vol+ | PgDn |   /  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |    (hold)   |      | Mute |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
	[1] = LAYOUT_preonic_1x2uC(
        KC_TRNS,	KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
        KC_TRNS,	KC_NO,		KC_NO,		EL_C_BCK,	EL_C_DEL,	KC_NO,		EL_C_HME,	EL_C_LFT,	KC_UP,		EL_C_RGT,	EL_C_END,	KC_NO,
        KC_TRNS,	KC_NO,		EL_S_HME,	KC_BSPC,	KC_DEL,		EL_S_END,	KC_HOME,	KC_LEFT,	KC_DOWN,	KC_RGHT,	KC_END,		KC_NO,
        KC_TRNS,	KC_NO,		TD(BR_PNT),	TD(BR_SQR),	TD(BR_CRL),	TD(BR_RND),	KC_PGUP,	KC_VOLD,	KC_MNXT,	KC_VOLU,	KC_PGDN,	KC_NO,
        KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_TRNS,	KC_TRNS,				KC_TRNS,	KC_MUTE,	KC_NO,		KC_NO,		KC_NO
        ),
/* Numpad/Function layer:
 * ,-----------------------------------------------------------------------------------.
 * |Rotary|      |      |      |      |      |      |   $  |   %  |   ^  |   -  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |  F1  |  F2  |  F3  |  F4  |      | NumLk|   7  |   8  |   9  |   +  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc~ |  F5  |  F6  |  F7  |  F8  |      |PrtScn|   4  |   5  |   6  |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |      |  Ins |   1  |   2  |   3  |   *  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |(hold)|             |(hold)|   0  |   .  | Enter|      |
 * `-----------------------------------------------------------------------------------'
 */
	[2] = LAYOUT_preonic_1x2uC(
        KC_TRNS,	KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_DLR,		KC_PERC,	KC_CIRC,	KC_PMNS,	KC_NO,
        KC_TRNS,	KC_F1,		KC_F2,		KC_F3,		KC_F4,		KC_NO,		KC_NLCK,	KC_P7,		KC_P8,		KC_P9,		KC_PPLS,	KC_NO,
        KC_TRNS,	KC_F5,		KC_F6,		KC_F7,		KC_F8,		KC_NO,		KC_PSCR,	KC_P4,		KC_P5,		KC_P6,		KC_PSLS,	KC_NO,
        KC_NO,		KC_F9,		KC_F10,		KC_F11,		KC_F12,		KC_NO,		KC_INS,		KC_P1,		KC_P2,		KC_P3,		KC_PAST,	KC_NO,
        KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_TRNS,	KC_TRNS,				KC_TRNS,	KC_P0,		KC_PDOT,	KC_PENT,	KC_NO
        ),
	[3] = LAYOUT_preonic_1x2uC(),
	[4] = LAYOUT_preonic_1x2uC(),
	[5] = LAYOUT_preonic_1x2uC(),
	[6] = LAYOUT_preonic_1x2uC(),
	[7] = LAYOUT_preonic_1x2uC(),
	[8] = LAYOUT_preonic_1x2uC(),
	[9] = LAYOUT_preonic_1x2uC(),
/* Gaming layer:
 * ,-----------------------------------------------------------------------------------.
 * |Rotary|   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |BckSpc|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc~ |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |   /  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Ctrl |  Alt |   -  | Enter|    Space    |NumLyr|   =  | Left | Down | Right|
 * `-----------------------------------------------------------------------------------'
 */
	[10] = LAYOUT_preonic_1x2uC(
        KC_TRNS,	KC_1,		KC_2,		KC_3,		KC_4,		KC_5,		KC_6,		KC_7,		KC_8,		KC_9,		KC_0,		KC_DEL,
        KC_TAB,		KC_Q,		KC_W,		KC_E,		KC_R,		KC_T,		KC_Y,		KC_U,		KC_I,		KC_O,		KC_P,		KC_BSPC,
        KC_GESC,	KC_A,		KC_S,		KC_D,		KC_F,		KC_G,		KC_H,		KC_J,		KC_K,		KC_L,		KC_SCLN,	KC_QUOT,
        KC_LSFT,	KC_Z,		KC_X,		KC_C,		KC_V,		KC_B,		KC_N,		KC_M,		KC_COMM,	KC_DOT,		KC_UP,		KC_SLSH,
        KC_TRNS,	KC_LCTL,	KC_LALT,	KC_MINS,	KC_ENT,		KC_SPC,					MO(2),		KC_EQL,		KC_LEFT,	KC_DOWN,	KC_RGHT
        )
};