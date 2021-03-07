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
    GAME,
    LT_EDT,
    LT_NUM
};

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
    BR_RND
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [BR_PNT] = ACTION_TAP_DANCE_DOUBLE(S(KC_COMM), S(KC_DOT)),      // <,>
    [BR_SQR] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),           // [,]
    [BR_CRL] = ACTION_TAP_DANCE_DOUBLE(S(KC_LBRC), S(KC_RBRC)),     // {,}
    [BR_RND] = ACTION_TAP_DANCE_DOUBLE(S(KC_9), S(KC_0))           // (,)
};

// clang-format off
#define HR_GASC_LAYOUT( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, \
    k40, k41, k42, k43, k44,    k45,   k47, k48, k49, k4a, k4b  \
) { \
    { k00, k01, k02, k03, k04, k05 }, \
    { k10, k11, k12, k13, k14, k15 }, \
    { k20, LGUI_T(k21), LALT_T(k22), LSFT_T(k23), LCTL_T(k24), k25 }, \
    { k30, k31, k32, k33, k34, k35 }, \
    { k06, k07, k08, k09, k0a, k0b }, \
    { k16, k17, k18, k19, k1a, k1b }, \
    { k26, RCTL_T(k27), RSFT_T(k28), LALT_T(k29), RGUI_T(k2a), k2b }, \
    { k36, k37, k38, k39, k3a, k3b }, \
    { k40, k41, k42, k49, k4a, k4b }, \
    { k45, k47, k48, k43, k44, k45 }  \
}

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
    [_QWERTY] = HR_GASC_LAYOUT(
        KC_MPLY,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_DEL,
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPC,
        KC_GESC,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,
        KC_BSLS,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_CAPS,
        KC_LGUI,    KC_LALT,    KC_LSFT,    LCTL_T(KC_EQL),  LT_EDT,           KC_SPC,           LT_NUM,     LCTL_T(KC_MINS),  KC_LSFT,    KC_LALT,    KC_LGUI
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
    [_COLEMAK] = HR_GASC_LAYOUT(
        _______,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       _______,
        _______,    KC_Q,       KC_W,       KC_F,       KC_P,       KC_B,       KC_J,       KC_L,       KC_U,       KC_Y,       KC_SCLN,    _______,
        _______,    KC_A,       KC_R,       KC_S,       KC_T,       KC_G,       KC_M,       KC_N,       KC_E,       KC_I,       KC_O,       _______,
        _______,    KC_Z,       KC_X,       KC_C,       KC_D,       KC_V,       KC_K,       KC_H,       KC_COMM,    KC_DOT,     KC_SLSH,    _______,
        _______,    _______,    _______,    _______,    _______,           _______,         _______,    _______,    _______,    _______,    _______
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
        _______,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       _______,
        _______,    KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       _______,
        _______,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    _______,
        KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    _______,
        XXXXXXX,    _______,    _______,    _______,    _______,          _______,          _______,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT
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
        _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_PGUP,    KC_BSPC,    KC_UP,      KC_DEL,     KC_PGDN,    XXXXXXX,
        _______,    KC_LGUI,    KC_LALT,    KC_LSFT,    KC_LCTL,    XXXXXXX,    KC_HOME,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_END,     XXXXXXX,
        _______,    EL_C_Z,     EL_C_X,     EL_C_C,     EL_C_V,     EL_C_Y,     XXXXXXX,    TD(BR_PNT), TD(BR_SQR), TD(BR_CRL), XXXXXXX,    XXXXXXX,
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
 * |      |      |      |      |  F3  |      |      |QWERTY|ColeDH| Game |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
    [_SYS] = LAYOUT_preonic_1x2uC(
        _______,    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      RESET,
        _______,    KC_F10,    KC_F7,       KC_F8,      KC_F9,      XXXXXXX,      XXXXXXX,      RGB_TOG,  RGB_HUI,   RGB_SAI,    RGB_VAI,       XXXXXXX,
        _______,    KC_F11,    KC_F4,       KC_F5,      KC_F6,      KC_PSCR,      XXXXXXX,      RGB_MOD,   RGB_HUD,    RGB_SAD,   RGB_VAD, XXXXXXX,
        _______,    KC_F12,    KC_F1,       KC_F2,      KC_F3,      KC_INS,      XXXXXXX,      QWERTY,     COLEMAK,     GAME,     XXXXXXX,      XXXXXXX,
        KC_APP,      XXXXXXX,      XXXXXXX,      XXXXXXX,      _______,          _______,          _______,    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX
        )
};
// clang-format on

// Toggle system layer when both other layers are on.
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _EDIT, _NUM, _SYS);
}

// uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case HR_G_L:
//             return TAPPING_TERM + 150;
//         case HR_Q_G_R:
//             return TAPPING_TERM + 150;
//         case HR_Q_A_L:
//             return TAPPING_TERM + 100;
//         case HR_Q_A_R:
//             return TAPPING_TERM + 100;
//         case HR_Q_S_L:
//             return TAPPING_TERM - 50;
//         case HR_Q_S_R:
//             return TAPPING_TERM - 50;
//         case HR_C_G_R:
//             return TAPPING_TERM + 150;
//         case HR_C_A_L:
//             return TAPPING_TERM + 100;
//         case HR_C_A_R:
//             return TAPPING_TERM + 100;
//         case HR_C_S_L:
//             return TAPPING_TERM - 50;
//         case HR_C_S_R:
//             return TAPPING_TERM - 50;
//         case LT_EDT:
//             return TAPPING_TERM - 75;
//         case LT_NUM:
//             return TAPPING_TERM - 75;
//         default:
//             return TAPPING_TERM;
//     }
// }

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
        case GAME:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_GAME);
            }
            return false;
            break;
    }
    return true;
};

#ifdef ENCODER_ENABLE
// Rotary encoder to be added later
void encoder_update_user(uint8_t index, bool clockwise) {
    if (IS_LAYER_ON(_QWERTY) || IS_LAYER_ON(_COLEMAK)) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (IS_LAYER_ON(_EDIT)) {
        if (clockwise) {
            tap_code(KC_WH_D);
        } else {
            tap_code(KC_WH_U);
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