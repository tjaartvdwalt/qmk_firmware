#include QMK_KEYBOARD_H
#include "keymap_dvp.h"

#define SHIFT_1 LM(1, MOD_LSFT)
#define SHIFT_3 LM(3, MOD_LSFT)

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Main
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   ;  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |  /   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  -   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   '  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[0] = LAYOUT_planck_grid(
  KC_TAB,  KC_SCLN, KC_LABK, KC_RABK, KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
  KC_LCTL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
  SHIFT_1, KC_QUOT, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    SHIFT_1,
  KC_NO,   KC_NO,   KC_NO,   KC_LGUI, KC_LALT, KC_SPC,  KC_SPC,  MO(4),   MO(2),   KC_NO,   KC_NO,   KC_NO
),

/* Shifted Main
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   :  |   <  |   >  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |  ?   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  _   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   "  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[1] = LAYOUT_planck_grid(
  KC_TAB,  KC_COLN, KC_LABK, KC_RABK, S(KC_P), S(KC_Y), S(KC_F), S(KC_G), S(KC_C), S(KC_R), S(KC_L), KC_QUES,
  KC_LCTL, S(KC_A), S(KC_O), S(KC_E), S(KC_U), S(KC_I), S(KC_D), S(KC_H), S(KC_T), S(KC_N), S(KC_S), KC_UNDS,
  KC_NO,   KC_DQT,  S(KC_Q), S(KC_J), S(KC_K), S(KC_X), S(KC_B), S(KC_M), S(KC_W), S(KC_V), S(KC_Z), KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_LGUI, KC_LALT, KC_SPC,  KC_SPC,  MO(4),   MO(2),   KC_NO,   KC_NO,   KC_NO
),

/* Top row
 * ,-----------------------------------------------------------------------------------.
 * |   $  |   &  |   [  |   {  |   }  |   (  |   =  |   *  |   )  |   +  |   ]  |  !   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |      |      |   @  |   \  |  #   | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    Space    |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[2] = LAYOUT_planck_grid(
  KC_DLR,  KC_AMPR, KC_LBRC, KC_LCBR, KC_RCBR, KC_LPRN, KC_EQL,  KC_ASTR, KC_RPRN, KC_PLUS, KC_RBRC, KC_EXLM,
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  SHIFT_3, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_AT,   KC_BSLS, KC_HASH, SHIFT_3,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_SPC,  KC_SPC,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
),

/* Shifted Top row
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   %  |   7  |   5  |   3  |   1  |   9  |   0  |   2  |   4  |   6  |   8  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   ^  |   |  |  `   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    Space    |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[3] = LAYOUT_planck_grid(
  KC_TILD, KC_PERC, KC_7,    KC_5,    KC_3,    KC_1,    KC_9,    KC_0,    KC_2,    KC_4,    KC_6,    KC_8,
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_CIRC, KC_PIPE, KC_GRV,  KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_SPC,  KC_SPC,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
),


/* Navigation layer
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |      |      |      |      |      | Ins  | Home |   Up | PgUp |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      | Del  | Left | Down | Right| Bspc |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | End  |      | PgDn |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    Bksp     |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[4] = LAYOUT_planck_grid(
  KC_ESC,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_HOME, KC_UP,   KC_PGUP,  KC_INS,   KC_DEL,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_LEFT, KC_DOWN, KC_RIGHT, KC_BSPC,  KC_ENT,
  KC_LSFT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_END,  KC_NO,   KC_PGDN,  KC_NO,    KC_RSFT,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_SPC,   KC_SPC,  KC_NO,   KC_MNXT, KC_VOLD,  KC_VOLU,  KC_MPLY
),


};
