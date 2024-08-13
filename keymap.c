#include QMK_KEYBOARD_H

enum custom_keycodes {
    CTRL_SFT = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case CTRL_SFT:
        if (record->event.pressed) {
            register_mods(MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT));
        } else {
            unregister_mods(MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT));
        }
        return false;
    default:
        return true;
    }
}

enum exodus_layers {
    _QWERTY,
    _RAISE,
    _LOWER,
    _WORKSPACE,
    _SHORTCUTS
};
// Tap Dance declarations
enum {
    TD_SHIFT_CAPS,
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_SHIFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,--------------------------------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |      |      |   Y  |   U  |   I  |   O  |   P  |  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |      |      |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |WRKSP | SHORT|   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  | Ctrl | Del  | Enter|Ct+Sh |  fn  | Space| R+Bsp| \    | Alt  | GUI  | Ctrl |
 * `--------------------------------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                      KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,    LGUI_T(KC_DEL),
    LT(_LOWER, KC_ESC), KC_A,  KC_S,    KC_D,    KC_F,    KC_G,                             KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN, KC_QUOT,
    TD(TD_SHIFT_CAPS), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    LM(_WORKSPACE,MOD_LGUI),          LT(_SHORTCUTS,KC_ESC), KC_N, KC_M, KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LALT, KC_LGUI, KC_LCTL, LCTL_T(KC_DEL), LGUI_T(KC_ENT), CTRL_SFT,  KC_RCTL, KC_SPC, LT(_RAISE, KC_BSPC), LALT_T(KC_BSLS), KC_RALT, KC_RGUI, KC_RCTL
),

/*
 * RAISE
 * ,--------------------------------------------------------------------------------------------------------.
 * |  `   |  !   |  @   |  #   |  $   |  %   |      |      |  ^   |  &   |  *   |  (   |  )   |  +   |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |      |      |   6  |   7  |   8  |  [   |   0  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |   9  |     |  {   |  }   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |  -   |  =   |      |
 * `--------------------------------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT(
    QK_BOOT,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                   KC_CIRC, KC_AMPR,  KC_LBRC, KC_RBRC,KC_ASTR, KC_EQL,
    KC_GRV, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                      KC_6,    KC_7,    KC_8,    KC_9, KC_0, KC_MINS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                 KC_TRNS, KC_TRNS, KC_TRNS,   KC_LCBR, KC_RCBR, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_EQL,  KC_TRNS
),

/*
 * LOWER
 * ,--------------------------------------------------------------------------------------------------------.
 * |  ~   |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Home | PgDn | PgUp | End  |      |      |      | Left | Down |  Up  | Right|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      | Vol- | Vol+ | Prev | Next |
 * `--------------------------------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT(
    KC_TILD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_TRNS,                                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                 KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT
),

/*
 * WORKSPACE (i3wm left-hand)
 * ,--------------------------------------------------------------------------------------------------------.
 * |      |  1   |  2   |  3   |  4   |  5   |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  6   |  7   |  8   |  9   |  0   |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * `--------------------------------------------------------------------------------------------------------'
 */
[_WORKSPACE] = LAYOUT(
    KC_NO,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,                 KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                 KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO
),

/*
 * SHORTCUTS
 * ,--------------------------------------------------------------------------------------------------------.
 * |      | RST  |  F1  |  F2  |  F3  |  F4  |      |      |  F5  |  F6  |  F7  |  F8  |  F9  | F10  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | REC1 | PLAY1| F11  | F12  |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      | Mute | Play | Stop | Bri+ |
 * `--------------------------------------------------------------------------------------------------------'
 */
[_SHORTCUTS] = LAYOUT(
    KC_NO,   DM_RSTP, KC_F1,   KC_F2,   KC_F3,   KC_F4,                                     KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    DM_REC1, DM_PLY1, KC_F11,  KC_F12,  KC_NO,   KC_NO,                                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                   KC_NO,   KC_NO,   KC_NO,   KC_MUTE, KC_MPLY, KC_MSTP, KC_BRIU
)
};
