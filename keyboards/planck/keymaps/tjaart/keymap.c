#include QMK_KEYBOARD_H
#include "keymap_dvp.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Programmers Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   ;  |   <  |   >  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |  /   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  -   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   '  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[0] = LAYOUT_planck_grid(
  KC_TAB,  DP_SCLN, DP_W,    DP_E,    DP_P,    DP_Y,    DP_F,    DP_G,    DP_C,    DP_R,    DP_L,    DP_SLSH,
  KC_LCTL, DP_A,    DP_O,    DP_E,    DP_U,    DP_I,    DP_D,    DP_H,    DP_T,    DP_N,    DP_S,    DP_MINS,
  KC_LSFT, DP_QUOT, DP_Q,    DP_J,    DP_K,    DP_X,    DP_B,    DP_M,    DP_W,    DP_V,    DP_Z,    KC_RSFT ,
  KC_NO,   KC_NO,   KC_NO,   KC_LGUI, KC_LALT, KC_SPC,  KC_SPC,  MO(2),   MO(1),   KC_NO,   KC_NO,   KC_NO
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   $  |   &  |   [  |   {  |   }  |   (  |   =  |   *  |   )  |   +  |   ]  |  !   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |   @  |   \  |  #   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    Space    |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[1] = LAYOUT_planck_grid(
  DP_DLR,  DP_AMPR, DP_LBRC, DP_LCBR, DP_RCBR, DP_LPRN, DP_EQL,  DP_ASTR, DP_RPRN, DP_PLUS, DP_RBRC, DP_EXLM,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   DP_AT,   DP_BSLS, DP_HASH,
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_SPC,  KC_SPC,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |      |      |      |      |      |      | Ins  | Home |   Up | PgUp |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Del  | Left | Down | Right| Bspc |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | End  |      | PgDn |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    Bksp     |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[2] = LAYOUT_planck_grid(
  KC_ESC,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_INS,  KC_HOME, KC_UP,    KC_PGUP,  KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_DEL,  KC_LEFT, KC_DOWN,  KC_RIGHT, KC_BSPC,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_END,  KC_NO,    KC_PGDN,  KC_ENT,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_SPC,   KC_SPC,  KC_NO,   KC_MNXT, KC_VOLD,  KC_VOLU,  KC_MPLY
),


};
