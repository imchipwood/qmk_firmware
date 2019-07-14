#include QMK_KEYBOARD_H

// Layer names
#define _QWERTY     0 // default layer
#define _NUMBERS    1 // numbers/etc.
#define _MEDIA      2 // media keys


// Tap Dance Declarations
enum {
    TD_RIGHT_END = 0,
    TD_LEFT_HOME,
    TD_RSPC_CAPS,
};

// Tap Dance actions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Double tap right -> END
    [TD_RIGHT_END] = ACTION_TAP_DANCE_DOUBLE(KC_RIGHT, KC_END),
    // Double tap left -> HOME
    [TD_LEFT_HOME] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT, KC_HOME),
    // Double tap right shift -> CAPS LOCK
    [TD_RSPC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_RSPC, KC_CAPS),
};

// KC_-prefixed macros for quantum actions to work with KC_-less layouts
#define KC_REND     TD(TD_RIGHT_END)
#define KC_LOME     TD(TD_LEFT_HOME)
#define KC_RTCAP    TD(TD_RSPC_CAPS)

// Layers
#define KC_TGNB     TG(_NUMBERS)
#define KC_TGMD     TG(_MEDIA)
#define KC_MONB     MO(_NUMBERS)
#define KC_MOMD     MO(_MEDIA)

// Reset to bootloader
#define KC_RESET    RESET

// three underscores "___" for transparent
#define KC____      KC_TRNS

// Layer definitions
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_ergodox_pretty_kc(
/* Keymap 0: Basic layer
 *        ,--------------------------------------------------.                    ,--------------------------------------------------.
 *        |   =    |   1  |   2  |   3  |   4  |   5  | ESC  |                    |BkTick|   6  |   7  |   8  |   9  |   0  |   -    |
 *        |--------+------+------+------+------+-------------|                    |------+------+------+------+------+------+--------|
 *        | Tab    |   Q  |   W  |   E  |   R  |   T  |  L1  |                    |  L2  |   Y  |   U  |   I  |   O  |   P  |   [    |
 *        |--------+------+------+------+------+------|      |                    |      |------+------+------+------+------+--------|
 *        | BkSlsh |   A  |   S  |   D  |   F  |   G  |------|                    |------|   H  |   J  |   K  |   L  |  ;   |   '    |
 *        |--------+------+------+------+------+------| MO(2)|                    | MO(1)|------+------+------+------+------+--------|
 *        | LSFT/( |   Z  |   X  |   C  |   V  |   B  |      |                    |      |   N  |   M  |   ,  |   .  |   /  |SFT/)/CAP
 *        `--------+------+------+------+------+-------------'                    `-------------+------+------+------+------+--------'
 *          |LCTRL | LALT | GUI  |L/HOME|R/END |                                                |  Up  | Down | LEFT | RIGHT| PRSCR|
 *          `----------------------------------'                                                `----------------------------------'
 *                                                       ,-------------.  ,-------------.
 *                                                       | DEL  | INS  |  | Ctrl |  Alt |
 *                                                ,------|------|------|  |------+--------+------.
 *                                                |      |      | Home |  | PgUp |        |      |
 *                                                | Enter|MO(1) |------|  |------|  Bksp  |Space |
 *                                                |      |      | End  |  | PgDn |        |      |
 *                                                `--------------------'  `----------------------'
 */
//                                                    Left hand                   Right hand
//    ,-------------------------------------------------------.                   ,-------------------------------------------------------.
        EQL,    1,      2,      3,      4,      5,      ESC,                        GRV,    6,      7,      8,      9,      0,      MINS,
//    |-------+-------+-------+-------+-------+-------+-------|                   |-------+-------+-------+-------+-------+-------+-------|
        TAB,    Q,      W,      E,      R,      T,      TGNB,                       TGMD,   Y,      U,      I,      O,      P,      LBRC,
//    |-------+-------+-------+-------+-------+-------+       |                   |       +-------+-------+-------+-------+-------+-------|
        BSLS,   A,      S,      D,      F,      G,                                          H,      J,      K,      L,      SCLN,   QUOT,
//    |-------+-------+-------+-------+-------+-------+-------|                   |-------+-------+-------+-------+-------+-------+-------|
        LSPO,   Z,      X,      C,      V,      B,      MOMD,                       MONB,   N,      M,      COMM,   DOT,    SLSH,   RTCAP,
//    `-------+-------+-------+-------+-------+---------------'                   `---------------+-------+-------+-------+-------+-------'
        LCTL,   LALT,   LGUI,   LOME,   REND,                                                       UP,     DOWN,   LEFT,   RGHT,   PSCR,
//     `--------------------------------------'                                                   `--------------------------------------'
//                                                    ,---------------.   ,---------------.
                                                        DEL,    INS,        LCTL,   LALT,
//                                            ,-------+-------+-------|   |-------+-------+-------.
                                                                HOME,       PGUP,
//                                            |       |       +-------|   |-------+       |       |
                                                ENT,    MONB,   END,        PGDN,   BSPC,   SPC
//                                            `-----------------------'   `-----------------------'
    ),
    [_NUMBERS] = LAYOUT_ergodox_pretty_kc(
/* Keymap 1: Numpad, function keys, and some convenience keys
 *        ,---------------------------------------------------.                   ,--------------------------------------------------.
 *        |         |  F1  |  F2  |  F3  |  F4  |  F5  |      |                   |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 *        |---------+------+------+------+------+------+------|                   |------+------+------+------+------+------+--------|
 *        |         |      |      |      |      |      |      |                   |      |   7  |   8  |   9  |   *  |   /  |    ]   |
 *        |---------+------+------+------+------+------|      |                   |      |------+------+------+------+------+--------|
 *        |         |      |      |      |      |      |------|                   |------|   4  |   5  |   6  |   +  |   -  |        |
 *        |---------+------+------+------+------+------|      |                   |      |------+------+------+------+------+--------|
 *        |         |      |      |      |      |      |      |                   |      |   1  |   2  |   3  |   =  |  up  |  enter |
 *        `---------+------+------+------+------+-------------'                   `-------------+------+------+------+------+--------'
 *          |       |      |      | PgUp | PgDn |                                               |   0  |   .  | left | down |right |
 *          `-----------------------------------'                                               `----------------------------------'
 *                                                      ,-------------.   ,-------------.
 *                                                      |      |      |   |      |      |
 *                                               ,------|------|------|   |------+------+------.
 *                                               |      |      |      |   |      | Del  | Esc  |
 *                                               | Enter|      |------|   |------|      |      |
 *                                               |      |      |      |   |      |      |      |
 *                                               `--------------------'   `--------------------'
 */
//                                                    Left hand                   Right hand
//    ,-------------------------------------------------------.                   ,-------------------------------------------------------.
        ___,    F1,     F2,     F3,     F4,     F5,     ___,                        F12,    F6,     F7,     F8,     F9,     F10,    F11,
//    |-------+-------+-------+-------+-------+-------+-------|                   |-------+-------+-------+-------+-------+-------+-------|
        ___,    ___,    ___,    ___,    ___,    ___,    ___,                        ___,    7,      8,      9,      PAST,   PSLS,   RBRC,
//    |-------+-------+-------+-------+-------+-------+       |                   |       +-------+-------+-------+-------+-------+-------|
        ___,    ___,    ___,    ___,    ___,    ___,                                        4,      5,      6,      PPLS,   PMNS,   ___,
//    |-------+-------+-------+-------+-------+-------+-------|                   |-------+-------+-------+-------+-------+-------+-------|
        ___,    ___,    ___,    ___,    ___,    ___,    ___,                        ___,    1,      2,      3,      PEQL,   UP,     PENT,
//    `-------+-------+-------+-------+-------+---------------'                   `---------------+-------+-------+-------+-------+-------'
        ___,    ___,    ___,    PGUP,   PGDN,                                                       0,      PDOT,   LEFT,   DOWN,   RGHT,
//     `--------------------------------------'                                                   `--------------------------------------'
//                                                    ,---------------.   ,---------------.
                                                        ___,    ___,        ___,    ___,
//                                            ,-------+-------+-------|   |-------+-------+-------.
                                                                ___,        ___,
//                                            |       |       +-------|   |-------+       |       |
                                                ENT,    ___,    ___,        ___,    DEL,    ESC
//                                            `-----------------------'   `-----------------------'
    ),
    [_MEDIA] = LAYOUT_ergodox_pretty_kc(
/* Keymap 2: Media and mouse keys
 *         ,--------------------------------------------------.                   ,--------------------------------------------------.
 *         |        |      |      |      |      |      |      |                   |      |      |      |      |      |      |        |
 *         |--------+------+------+------+------+-------------|                   |------+------+------+------+------+------+--------|
 *         |        |      |      | MsUp |      |      |      |                   |      |      |      |      |      |      |        |
 *         |--------+------+------+------+------+------|      |                   |      |------+------+------+------+------+--------|
 *         |        |      |MsLeft|MsDown|MsRght|      |------|                   |------|      |      |      |      |      |        |
 *         |--------+------+------+------+------+------|      |                   |      |------+------+------+------+------+--------|
 *         |        |      |      |      |      |      |      |                   |      |      | Mute |      |      |      |        |
 *         `--------+------+------+------+------+-------------'                   `-------------+------+------+------+------+--------'
 *           |      |      |      | Lclk | Rclk |                                               |VolUp |VolDn | Prev | Next |      |
 *           `----------------------------------'                                               `----------------------------------'
 *                                                      ,-------------.   ,-------------.
 *                                                      |RESET |      |   |      |      |
 *                                               ,------|------|------|   |------+------+------.
 *                                               |      |      |      |   |      |      |      |
 *                                               |      |      |------|   |------|      |Play  |
 *                                               |      |      |      |   |      |      |      |
 *                                               `--------------------'   `--------------------'
 */
//                                                    Left hand                   Right hand
//    ,-------------------------------------------------------.                   ,-------------------------------------------------------.
        ___,    ___,    ___,    ___,    ___,    ___,    ___,                        ___,    ___,    ___,    ___,    ___,    ___,    ___,
//    |-------+-------+-------+-------+-------+-------+-------|                   |-------+-------+-------+-------+-------+-------+-------|
        ___,    ___,    ___,    MS_U,   ___,    ___,    ___,                        ___,    ___,    ___,    ___,    ___,    ___,    ___,
//    |-------+-------+-------+-------+-------+-------+       |                   |       +-------+-------+-------+-------+-------+-------|
        ___,    ___,    MS_L,   MS_D,   MS_R,   ___,                                        ___,    ___,    ___,    ___,    ___,    ___,
//    |-------+-------+-------+-------+-------+-------+-------|                   |-------+-------+-------+-------+-------+-------+-------|
        ___,    ___,    ___,    ___,    ___,    ___,    ___,                        ___,    ___,    MUTE,   ___,    ___,    ___,    ___,
//    `-------+-------+-------+-------+-------+---------------'                   `---------------+-------+-------+-------+-------+-------'
        ___,    ___,    ___,    BTN1,   BTN2,                                                       VOLU,   VOLD,   MPRV,   MNXT,   ___,
//     `--------------------------------------'                                                   `--------------------------------------'
//                                                    ,---------------.   ,---------------.
                                                        RESET,  ___,        ___,    ___,
//                                            ,-------+-------+-------|   |-------+-------+-------.
                                                                ___,        ___,
//                                            |       |       +-------|   |-------+       |       |
                                                ___,    ___,    ___,        ___,    ___,    MPLY
//                                            `-----------------------'   `-----------------------'
    )
};
