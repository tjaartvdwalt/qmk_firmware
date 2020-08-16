#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |   &  |   [  |   {  |   }  |   (  |  =   |           |   *  |   )  |   +  |   ]  |   !  |   #  | Bksp   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   ;  |   ,  |   .  |   p  |   y  |  $   |           |  @   |   f  |   g  |   c  |   r  |   l  |   /    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Ctrl   |   a  |   o  |   e  |   u  |   i  |------|           |------|   d  |   h  |   t  |   n  |   s  |   -    |
 * |--------+------+------+------+------+------|      |           |  \   |------+------+------+------+------+--------|
 * | MO(1)  |   '  |   q  |   j  |   k  |   x  |      |           |      |   b  |   m  |   w  |   v  |   z  | MO(1)  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Gui | Alt   |                                       |TG(1) | TG(2)|      |       |       |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|  ~   |------|       |------|  Tab   |MO(2) |
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,         S(KC_7),      KC_LBRC,   KC_LCBR,   KC_RCBR,   KC_LPRN,   KC_EQL,
        KC_TAB,         KC_SCLN,      KC_COMM,   KC_DOT,    KC_P,      KC_Y,      KC_DLR,
        KC_LCTL,        KC_A,         KC_O,      KC_E,      KC_U,      KC_I,
        LM(1,MOD_LSFT), KC_QUOT,      KC_Q,      KC_J,      KC_K,      KC_X,      KC_NO,
        TG(1),          KC_NO,        KC_NO,     KC_LGUI,   KC_LALT,
                                                      KC_NO,  KC_NO,
                                                              KC_NO,
                                               KC_SPC,KC_BSPC,KC_NO,
        // right hand
             KC_ASTR,     KC_RPRN,   KC_PLUS,  KC_RBRC,   KC_EXLM,   KC_HASH,  KC_BSPC,
             KC_AT,       KC_F,      KC_G,     KC_C,      KC_R,      KC_L,     KC_SLSH,
                          KC_D,      KC_H,     KC_T,      KC_N,      KC_S,     KC_MINS,
             KC_BSLS,     KC_B,      KC_M,     KC_W,      KC_V,      KC_Z,     LM(1, MOD_LSFT),
                                     KC_NO,    KC_NO,     KC_NO,     KC_NO,    KC_NO,
             KC_NO,       KC_NO,
             KC_NO,
             KC_NO,KC_NO, MO(2)
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |   Esc   |   %  |  7   |  5   |   3  |   1  |  9   |           |  0   |  2   |  4   |  6   |  8   |  `   |  Del   |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |   Tab   |   :  |  <   |  >   |   P  |   Y  |  ~   |           |  ^   |  F   |  G   |  C   |  R   |  L   |  ?     |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   Ctrl  |   A  |  O   |  E   |  U   |  I   |------|           |------|  D   |  H   |  T   |  N   |  S   | Return |
 * |---------+------+------+------+------+------|      |           |  |   |------+------+------+------+------+--------|
 * |   TRNS  |   "  |  Q   |  J   |  K   |  X   |      |           |      |  B   |  M   |  W   |  V   |  Z   |  TRNS  |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      | Gui  | Alt  |                                       | TRNS | TRNS |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |TRNS  | TRNS |       | TRNS | TRNS |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |TRNS  |TRNS  | TRNS |       | TRNS | TRNS | TRNS |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      | TRNS |       | TRNS |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_PERC,KC_7,   KC_5,   KC_3,   KC_1,   KC_9,
       KC_TRNS,KC_COLN,KC_LT,  KC_GT,  S(KC_P),S(KC_Y),KC_TILD,
       KC_TRNS,S(KC_A),S(KC_O),S(KC_E),S(KC_U),S(KC_I),
       KC_TRNS,KC_DQT, S(KC_Q),S(KC_J),S(KC_K),S(KC_X),KC_NO,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_0,    KC_2,    KC_4,   KC_6,    KC_8,    KC_GRV,  KC_DEL,
       KC_CIRC, S(KC_F), S(KC_G),S(KC_C), S(KC_R), S(KC_L), KC_QUES,
                S(KC_D), S(KC_H),S(KC_T), S(KC_N), S(KC_S), S(KC_MINS),
       KC_PIPE, S(KC_B), S(KC_M),S(KC_W), S(KC_V), S(KC_Z), KC_TRNS,
                         KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |   Esc   |  F1  |  F2  |   F3 |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |  Del   |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |   Tab   |      |      |      |      |      |VolUp |           |Bright|      | Home |   Up | PGUP |      |        |
 * |---------+------+------+------+------+------|      |           |  +   |------+------+------+------+------+--------|
 * |   Ctrl  |      | Prev | Play | Next | Mute |------|           |------|      |Left  | Down | Right| Bksp | Return |
 * |---------+------+------+------+------+------|VolDn |           |Bright|------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |  -   |      | End  |      | PGDn |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |TRNS  | TRNS |       | TRNS | TRNS |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |TRNS  |TRNS  | TRNS |       | TRNS | TRNS | TRNS |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      | TRNS |       | TRNS |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
       KC_TRNS, KC_NO, KC_NO,     KC_NO,   KC_NO,   KC_NO, KC__VOLUP,
       KC_TRNS, KC_NO, KC_MPRV,   KC_MPLY, KC_MNXT, KC_MUTE,
       KC_TRNS, KC_NO, KC_NO,     KC_NO,   KC_NO,   KC_NO, KC__VOLDOWN,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_F7, KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,
       KC_NO, KC_NO,   KC_HOME, KC_UP,   KC_PGUP, KC_NO, KC_NO,
              KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC, KC_ENT,
       KC_NO, KC_NO,   KC_END,  KC_MPRV, KC_PGDN, KC_NO, KC_NO,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
