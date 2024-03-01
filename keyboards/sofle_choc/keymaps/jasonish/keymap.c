/* Copyright 2023 Brian Low
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _NAV,
    _MED,
    _NUM,
    _SYM,
    _FUN,
    _MOS,
};

#define USE_HRM

// Home row mods - LEFT
#define HRM_A    MT(MOD_LGUI, KC_A)
#define HRM_S    MT(MOD_LALT, KC_S)
#define HRM_D    MT(MOD_LSFT, KC_D)
#define HRM_F    MT(MOD_LCTL, KC_F)

// Home row mods - RIGHT
#define HRM_J    MT(MOD_LCTL, KC_J)
#define HRM_K    MT(MOD_LSFT, KC_K)
#define HRM_L    MT(MOD_LALT, KC_L)
#define HRM_SCLN MT(MOD_LGUI, KC_SCLN)

#define _Z     KC_Z
#define _X     KC_X
#define _C     KC_C
#define _V     KC_V
#define _M     KC_M
#define _COMM  KC_COMM
#define _DOT   KC_DOT
#define _SLSH  KC_SLSH

#ifdef USE_HRM
#define _A    HRM_A
#define _S    HRM_S
#define _D    HRM_D
#define _F    HRM_F
#define _J    HRM_J
#define _K    HRM_K
#define _L    HRM_L
#define _SCLN HRM_SCLN
#else
#define _A     KC_A
#define _S     KC_S
#define _D     KC_D
#define _F     KC_F
#define _J     KC_J
#define _K     KC_K
#define _L     KC_L
#define _SCLN  KC_SCLN
#endif

// Left thumb keys.
#define NAV_BSPC LT(_NAV, KC_BSPC)
#define ALT_DEL  MT(MOD_LALT, KC_DEL)
#define SFT_DEL  MT(MOD_LSFT, KC_DEL)

#ifdef CLASSIC_MIRYOKU
#define MED_ESC  LT(_MED, KC_ESC)
#define NAV_SPC  LT(_NAV, KC_SPC)
#define MOS_TAB  LT(_MOS, KC_TAB)

#define SYM_ENT  LT(_SYM, KC_ENT)
#define NUM_BS   LT(_NUM, KC_BSPC)
#define FUN_DEL  LT(_FUN, KC_DEL)
#endif

#define MED_ESC  LT(_MED, KC_ESC)
#define NAV_BSPC LT(_NAV, KC_BSPC)
#define MOS_TAB  LT(_MOS, KC_TAB)

#define SYM_ENT  LT(_SYM, KC_ENT)
#define NUM_SPC  LT(_NUM, KC_SPC)
#define FUN_DEL  LT(_FUN, KC_DEL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,     KC_7,     KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_LCTL,  _A,     _S,      _D,      _F,      KC_G,                         KC_H,     _J,       _K,      _L,      _SCLN,   KC_QUOT,
        KC_LSFT,  _Z,     _X,      _C,      _V,      KC_B,     KC_MUTE,   KC_MPLY, KC_N,     _M,       _COMM,   _DOT,    _SLSH,   KC_RSFT,
                          _______, _______, MED_ESC, NAV_BSPC, MOS_TAB,   SYM_ENT, NUM_SPC,  FUN_DEL,  _______, _______
        ),
    
    [_NAV] = LAYOUT(
        KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,                      KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
        _______, _______, _______, _______, _______, _______,                      KC_INS , KC_PSTE, KC_COPY, KC_CUT , KC_UNDO, _______,
        _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _______,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______, _______,
                          _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
        ),

    [_MED] = LAYOUT(
        KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,                      KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
        _______, _______, _______, _______, _______, _______,                      RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______,
        _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _______,                      _______, _______, KC_VOLU, KC_VOLD, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
        ),

    [_NUM] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, KC_LBRC, KC_7   , KC_8   , KC_9   , KC_RBRC,                      _______, _______, _______, _______, _______, _______,
        _______, KC_SCLN, KC_4   , KC_5   , KC_6   , KC_EQL ,                      _______, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, _______,
        _______, KC_GRV , KC_1   , KC_2   , KC_3   , KC_BSLS, _______,    _______, _______, _______, _______, _______, _______, _______,
                          _______, _______, KC_DOT , KC_0   , KC_MINS,    _______, _______, _______, _______, _______
        ),

    [_SYM] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                      _______, _______, _______, _______, _______, _______,
        _______, KC_COLN, KC_DLR , KC_PERC, KC_CIRC, KC_PLUS,                      _______, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, _______,
        _______, KC_TILD, KC_EXLM, KC_AT  , KC_HASH, KC_PIPE, _______,    _______, _______, _______, _______, _______, _______, _______,
                          _______, _______, KC_LPRN, KC_RPRN, KC_UNDS,    _______, _______, _______, _______, _______
        ),

    [_FUN] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, KC_F12 , KC_F7  , KC_F8  , KC_F9  , KC_PSCR,                      _______, _______, _______, _______, _______, _______,
        _______, KC_F11 , KC_F4  , KC_F5  , KC_F5  , _______,                      _______, _______, _______, _______, _______, _______,
        _______, KC_F10 , KC_F1  , KC_F2  , KC_F3  , _______, _______,    _______, _______, _______, _______, _______, _______, _______,
                          _______, _______, KC_APP , KC_BSPC, _______,    _______, _______, _______, _______, _______
        ),

    [_MOS] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _______,                      KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, _______,
                          _______, _______, _______, _______, _______,    KC_BTN1, KC_BTN3, KC_BTN2, _______, _______
        ),

#if 0
    [_TMP] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
        ),
#endif
};

#if defined(ENCODER_MAP_ENABLE)
//#define MY_ENCODER_MAP { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGDN, KC_PGUP) }
#define MY_ENCODER_MAP { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    MY_ENCODER_MAP,
    MY_ENCODER_MAP,
    MY_ENCODER_MAP,
    MY_ENCODER_MAP,
    MY_ENCODER_MAP,
    MY_ENCODER_MAP,
    MY_ENCODER_MAP,
};
#endif
