#include QMK_KEYBOARD_H

// __attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

// Declare layers
enum custom_layers {
    _QWERTY = 0,
    _COLEMAK,
    _GAME,
    _EDIT,
    _NUM,
    _SYS
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK,
    LT_EDT,
    LT_NUM,
    CW_TOG,
    CW_ENA,
    CW_DIS
};

// Define GASC shortcuts
// Format: HR_Layout_Mod_Side
#define HR_G_L LGUI_T(KC_A)
#define HR_Q_A_L LALT_T(KC_S)
#define HR_Q_S_L LSFT_T(KC_D)
#define HR_Q_C_L LCTL_T(KC_F)
#define HR_Q_C_R RCTL_T(KC_J)
#define HR_Q_S_R RSFT_T(KC_K)
#define HR_Q_A_R LALT_T(KC_L)
#define HR_Q_G_R RGUI_T(KC_SCLN)

#define HR_G_L LGUI_T(KC_A)
#define HR_C_A_L LALT_T(KC_R)
#define HR_C_S_L LSFT_T(KC_S)
#define HR_C_C_L LCTL_T(KC_T)
#define HR_C_C_R RCTL_T(KC_N)
#define HR_C_S_R RSFT_T(KC_E)
#define HR_C_A_R LALT_T(KC_I)
#define HR_C_G_R RGUI_T(KC_O)

// Define editing layer shortcuts
// Format: EL_Mod_Key
#define EL_C_Z LCTL(KC_Z)
#define EL_C_X LCTL(KC_X)
#define EL_C_C LCTL(KC_C)
#define EL_C_V LCTL(KC_V)
#define EL_C_Y LCTL(KC_Y)

#define LT_EDT LT(_EDIT,KC_ENT)
#define LT_NUM LT(_NUM,KC_ENT)

// Tap Dance declarations
enum {
    BR_PNT,
    BR_SQR,
    BR_CRL,
    BR_RND,
    KL_SFT,
    TG_GME
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [BR_PNT] = ACTION_TAP_DANCE_DOUBLE(S(KC_COMM), S(KC_DOT)),      // <,>
    [BR_SQR] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),           // [,]
    [BR_CRL] = ACTION_TAP_DANCE_DOUBLE(S(KC_LBRC), S(KC_RBRC)),     // {,}
    [BR_RND] = ACTION_TAP_DANCE_DOUBLE(S(KC_9), S(KC_0)),           // (,)
    [KL_SFT] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, CW_ENA),            // Shift,CAPS
    [TG_GME] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_ENT, _GAME)         // Enter,_GAME
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* QWERTY layer:
 * ,-----------------------------------------------------------------------------------.
 * |Rotary|   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |BckSpc|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc~ | A|GUI| S|ALT| D|SHF| F|CTL|   G  |   H  | J|CTL| K|SHF| L|ALT| ;|GUI|   '  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  \   |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Game |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  GUI |  Alt | Shift|Ctrl|=|EntEdt|    Space    |EntNum|Ctrl|-| Shift|  Alt |  GUI |
 * `-----------------------------------------------------------------------------------'
 */
    [_QWERTY] = LAYOUT_preonic_1x2uC(
        KC_MPLY,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_DEL,
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPC,
        KC_GESC,    HR_G_L,     HR_Q_A_L,   HR_Q_S_L,   HR_Q_C_L,   KC_G,       KC_H,       HR_Q_C_R,   HR_Q_S_R,   HR_Q_A_R,   HR_Q_G_R,   KC_QUOT,
        KC_BSLS,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_CAPS,
        KC_LGUI,    KC_LALT,    TD(KL_SFT), LCTL_T(KC_EQL),  LT_EDT,           KC_SPC,           LT_NUM,     LCTL_T(KC_MINS),  KC_LSFT,    KC_LALT,    KC_LGUI
        ),
/* Colemak-DH layer:
 * ,-----------------------------------------------------------------------------------.
 * |Rotary|   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  |BckSpc|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc~ | A|GUI| R|ALT| S|SHF| T|CTL|   G  |   M  | N|CTL| E|SHF| I|ALT| O|GUI|   '  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  \   |   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  | Game |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  GUI |  Alt | Shift|Ctrl|=|EntEdt|    Space    |EntNum|Ctrl|-| Shift|  Alt |  GUI |
 * `-----------------------------------------------------------------------------------'
 */
    [_COLEMAK] = LAYOUT_preonic_1x2uC(
        KC_MPLY,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_DEL,
        KC_TAB,     KC_Q,       KC_W,       KC_F,       KC_P,       KC_B,       KC_J,       KC_L,       KC_U,       KC_Y,       KC_SCLN,    KC_BSPC,
        KC_GESC,    HR_G_L,     HR_C_A_L,   HR_C_S_L,   HR_C_C_L,   KC_G,       KC_M,       HR_C_C_R,   HR_C_S_R,   HR_C_A_R,   HR_C_G_R,   KC_QUOT,
        KC_BSLS,    KC_Z,       KC_X,       KC_C,       KC_D,       KC_V,       KC_K,       KC_H,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_CAPS,
        KC_LGUI,    KC_LALT,    TD(KL_SFT), LCTL_T(KC_EQL),  LT_EDT,           KC_SPC,           LT_NUM,     LCTL_T(KC_MINS),  KC_LSFT,    KC_LALT,    KC_LGUI
        ),
/* Gaming layer:
 * ,-----------------------------------------------------------------------------------.
 * |Rotary|   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |BckSpc|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc~ |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Base |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  Alt | Shift| Ctrl |EntEdt|    Space    |EntNum| Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 */
    [_GAME] = LAYOUT_preonic_1x2uC(
        _______,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_DEL,
        _______,    KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPC,
        _______,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,
        KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    _______,
        XXXXXXX,      _______,    KC_LSFT,    _______,    _______,          _______,          _______,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT
        ),
/* Editing layer:
 * ,-----------------------------------------------------------------------------------.
 * |Rotary|      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |      |      |      |      |      | PgUp | BkSpc|  Up  |  Del | PgDn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc~ |      |      |      |      |      | Home | Left | Down | Right|  End |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  C+Z |  C+C |  C+X |  C+V |  C+Y |      | <  > | [  ] | {  } |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |(hold)|             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
    [_EDIT] = LAYOUT_preonic_1x2uC(
        _______,    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
        _______,    _______,    _______,    _______,    _______,    _______,    KC_PGUP,    KC_BSPC,    KC_UP,      KC_DEL,     KC_PGDN,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    KC_HOME,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_END,     _______,
        _______,    EL_C_Z,    EL_C_X,     EL_C_C,    EL_C_V,    EL_C_Y,    XXXXXXX,      TD(BR_PNT), TD(BR_SQR), TD(BR_CRL), XXXXXXX,      XXXXXXX,
        _______,    _______,    _______,    _______,    _______,          _______,          _______,    _______,    _______,    _______,    _______
        ),
/* Numpad layer:
 * ,-----------------------------------------------------------------------------------.
 * |Rotary|      |      |      |      |      | NumLk|   $  |   %  |   ^  |   -  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |  F1  |  F2  |  F3  |  F4  |      |PrtScn|   7  |   8  |   9  |   +  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc~ |  F5  |  F6  |  F7  |  F8  |      |  Ins |   4  |   5  |   6  |   *  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |      |   =  |   1  |   2  |   3  |   /  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |             |(hold)|   0  |   .  | Enter|      |
 * `-----------------------------------------------------------------------------------'
 */

    [_NUM] = LAYOUT_preonic_1x2uC(
        _______,    KC_CIRC,      KC_NLCK,      KC_PSLS,      KC_PAST,      XXXXXXX,      XXXXXXX,    XXXXXXX,     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        _______,    KC_PERC,      KC_P7,      KC_P8,      KC_P9,      KC_PMNS,      _______,    _______,      _______,      _______,      _______,    XXXXXXX,
        _______,    KC_DLR,      KC_P4,      KC_P5,      KC_P6,      KC_PSLS,      _______,     _______,      _______,      _______,      _______,    XXXXXXX,
        XXXXXXX,    TD(BR_RND),      KC_P1,      KC_P2,      KC_P3,     KC_PEQL,      _______,     _______,      _______,      _______,      _______,    XXXXXXX,
        XXXXXXX,    XXXXXXX,    KC_P0,    KC_PDOT,    _______,          _______,          _______,    _______,      _______,    _______,    XXXXXXX
        ),
/* Sys layer:
 * ,-----------------------------------------------------------------------------------.
 * |Rotary|      |      |      |      |      |      |      |      |      |      | Reset|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |      |      |      |  F9  |      |      |RGBTog| HUE+ | SAT+ | VAL+ |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc~ |      |      |      |  F5  |      |      |RGBMDE| HUE- | SAT- | VAL- |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |  F3  |      |      |QWERTY|ColeDH|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
    [_SYS] = LAYOUT_preonic_1x2uC(
        _______,    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      RESET,
        _______,    KC_F10,    KC_F7,       KC_F8,      KC_F9,      XXXXXXX,      XXXXXXX,      RGB_TOG,  RGB_HUI,   RGB_SAI,    RGB_VAI,       XXXXXXX,
        _______,    KC_F11,    KC_F4,       KC_F5,      KC_F6,      KC_PSCR,      XXXXXXX,      RGB_MOD,   RGB_HUD,    RGB_SAD,   RGB_VAD, XXXXXXX,
        _______,    KC_F12,    KC_F1,       KC_F2,      KC_F3,      KC_INS,      XXXXXXX,      QWERTY,     COLEMAK,     TG(_GAME),     XXXXXXX,      XXXXXXX,
        KC_APP,      XXXXXXX,      XXXXXXX,      XXXXXXX,      _______,          _______,          _______,    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX
        )
};

// Toggle system layer when both other layers are on.
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _EDIT, _NUM, _SYS);
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HR_G_L:
            return TAPPING_TERM + 150;
        case HR_Q_G_R:
            return TAPPING_TERM + 150;
        case HR_Q_A_L:
            return TAPPING_TERM + 100;
        case HR_Q_A_R:
            return TAPPING_TERM + 100;
        case HR_Q_S_L:
            return TAPPING_TERM - 50;
        case HR_Q_S_R:
            return TAPPING_TERM - 50;
        case HR_C_G_R:
            return TAPPING_TERM + 150;
        case HR_C_A_L:
            return TAPPING_TERM + 100;
        case HR_C_A_R:
            return TAPPING_TERM + 100;
        case HR_C_S_L:
            return TAPPING_TERM - 50;
        case HR_C_S_R:
            return TAPPING_TERM - 50;
        case LT_EDT:
            return TAPPING_TERM - 75;
        case LT_NUM:
            return TAPPING_TERM - 75;
        default:
            return TAPPING_TERM;
    }
}

// bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case LT_EDT:
//             return false;
//         case LT_NUM:
//             return false;
//         default:
//             return true;
//     }
// }

#ifdef CAPSWORD_ENABLE
// Caps word: deactivate caps lock following a word
void process_caps_word(uint16_t keycode, keyrecord_t *record) {
	// Get the base key code of a mod or layer tap
	switch (keycode) {
	case QK_MOD_TAP ... QK_MOD_TAP_MAX:
	case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
		if (!record->tap.count) { return; }
		keycode = keycode & 0xFF;
	}
	// Toggle caps lock with the following key codes
	switch (keycode) {
	case KC_ESC:
	case KC_SPC:
	case KC_ENT:
	case KC_TAB:
	case KC_DOT:
	case KC_COMM:
		if (record->event.pressed) { tap_code(KC_CAPS); }
	}
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CAPSWORD_ENABLE
	// Monitor key codes to toggle caps lock
	if (host_keyboard_led_state().caps_lock) { process_caps_word(keycode, record); }
#endif
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
            break;
    }
    if (host_keyboard_led_state().caps_lock) { process_caps_word(keycode, record); }
    return false;
};

#ifdef ENCODER_ENABLE
// Rotary encoder to be added later
void encoder_update_user(uint8_t index, bool clockwise) {
if (IS_LAYER_ON(_QWERTY) || IS_LAYER_ON(_COLEMAK)) {
        if (clockwise) {
            register_code(KC_VOLU);
            unregister_code(KC_VOLU);
        } else {
            register_code(KC_VOLD);
            unregister_code(KC_VOLD);
        }
    } else {
        if (clockwise) {
            register_code(KC_VOLU);
            unregister_code(KC_VOLU);
        } else {
            register_code(KC_VOLD);
            unregister_code(KC_VOLD);
        }
    }
}
#endif