/* Copyright 2020 Dane Evans
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

// CRKBD

#include QMK_KEYBOARD_H


char layer_state_str[24];


enum userspace_layers {
    _DEFAULTS = 0,
    _DVORAK = 0,
    _COLEMAK,
    _QWERTY,
    _NUM,
    _SYM,
    _COMMAND,
    _NUMPAD,
    _SWITCH,
    _MOVE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	// devorak
	[_DVORAK] = LAYOUT_split_3x6_3(
	//,-----------------------------------------------------.                    ,-----------------------------------------------------.
 LT(_NUMPAD,KC_TAB), KC_QUOT, KC_COMM,  KC_DOT,    KC_P,    KC_Y,      	                  KC_F,    KC_G,    KC_C,    KC_R,    KC_L, KC_BSPC,
	//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     LCTL_T(KC_ESC),    KC_A,    KC_O,    KC_E,    KC_U,    KC_I,			  KC_D,    KC_H,    KC_T,    KC_N,    KC_S, KC_MINS,
	//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	    KC_LSFT, KC_SCLN,    KC_Q,    KC_J,    KC_K,    KC_X,			  KC_B,    KC_M,    KC_W,    KC_V,    KC_Z, KC_RSFT,
	//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
					     KC_LGUI,   MO(_NUM),LALT_T(KC_SPC),KC_ENT,LT(_SYM,KC_SPC), KC_RALT
					    //`--------------------------'  `--------------------------'
	),
	
	// colemak
	[_COLEMAK] = LAYOUT_split_3x6_3(
	//,-----------------------------------------------------.                    ,-----------------------------------------------------.
 LT(_NUMPAD,KC_TAB), 	KC_Q, 	 KC_W, 	  KC_F,    KC_P,    KC_G,    	      		  KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_BSPC,
	//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     LCTL_T(KC_ESC),    KC_A,    KC_R,    KC_S,    KC_T,    KC_D,  		 	  KC_H,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT,
	//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_K,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
	//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
					     KC_LGUI,   MO(_NUM),LALT_T(KC_SPC),KC_ENT,LT(_SYM,KC_SPC), KC_RALT
					    //`--------------------------'  `--------------------------'
	),

	// qwerty
	[_QWERTY] = LAYOUT_split_3x6_3(
	//,-----------------------------------------------------.                    ,-----------------------------------------------------.
 LT(_NUMPAD,KC_TAB), 	KC_Q, 	 KC_W, 	  KC_E,    KC_R,    KC_T,		 	  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
	//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     LCTL_T(KC_ESC),    KC_A, 	 KC_S, 	  KC_D,	   KC_F,    KC_G,  			  KC_H,    KC_J,    KC_K,    KC_L, KC_SLSH, KC_QUOT,
	//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	    KC_LSFT, 	KC_Z, 	 KC_X, 	  KC_C,    KC_V,    KC_B,			  KC_N,	   KC_M, KC_COMM,  KC_DOT, KC_SCLN, KC_RSFT,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
					     KC_LGUI,   MO(_NUM),LALT_T(KC_SPC),KC_ENT,LT(_SYM,KC_SPC), KC_RALT
					    //`--------------------------'  `--------------------------'
	),

	// numbers  - L thumb
	[_NUM] = LAYOUT_split_3x6_3(
	//,-----------------------------------------------------.                    ,-----------------------------------------------------.
	     KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,		          KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
	//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	    _______, XXXXXXX, KC_LSFT, KC_LALT, KC_LGUI, XXXXXXX, 		       KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX,  KC_DEL,
	//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,		       KC_VOLD, KC_VOLU, KC_MPLY, KC_MNXT, KC_MUTE, XXXXXXX,
	//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
					        _______, _______,  _______,   _______, MO(_COMMAND), _______
					    //`--------------------------'  `--------------------------'
	),

	// symbols  - R thumb
	[_SYM] = LAYOUT_split_3x6_3(
	//,-----------------------------------------------------.                    ,-----------------------------------------------------.
	     KC_ESC, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, 		       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 		       KC_MINS,  KC_EQL, KC_LCBR, KC_RCBR, KC_PIPE, KC_GRV,
	//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 		       KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS, KC_TILD,
	//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
					      	_______,MO(_COMMAND),_______, _______, _______, _______
				            //`--------------------------'  `--------------------------'
	),

	// commands - both thumbs
	[_COMMAND] = LAYOUT_split_3x6_3(
	//,-----------------------------------------------------.                    ,-----------------------------------------------------.
	      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   			 KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	    RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI,DF(_DVORAK),DF(_COLEMAK),                C(G(KC_LEFT)), XXXXXXX, XXXXXXX,C(G(KC_RGHT)),XXXXXXX,XXXXXXX,
	//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	    RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD,DF(_QWERTY),XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
	//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
					        _______, _______, _______,    _______, _______, _______
					    //`--------------------------'  `--------------------------'
	),

	// numpad
	[_NUMPAD] = LAYOUT_split_3x6_3(
	//,-----------------------------------------------------.                    ,-----------------------------------------------------.
	    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 		       KC_CIRC,   KC_P7,   KC_P8,   KC_P9, KC_ASTR, KC_BSPC,
	//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 			KC_MINS,   KC_P4,   KC_P5,   KC_P6, KC_EQL,  KC_DEL,
	//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 		       KC_PLUS,   KC_P1,   KC_P2,   KC_P3, KC_SLSH, XXXXXXX,
	//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
					   OSM(MOD_MEH), XXXXXXX, _______,     KC_ENT,   KC_P0,  KC_PDOT
					    //`--------------------------'  `--------------------------'
	),

	// layer switcher
	[_SWITCH] = LAYOUT_split_3x6_3(
	//,-----------------------------------------------------.                    ,-----------------------------------------------------.
	      TO(0),   TO(1),   TO(2),   TO(3),   TO(4),   TO(5),   		       XXXXXXX,   TO(7), XXXXXXX, XXXXXXX, XXXXXXX,   RESET,
	//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	    XXXXXXX, XXXXXXX, KC_BRIU, XXXXXXX, XXXXXXX, XXXXXXX, 		       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, EEP_RST,
	//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_SYSTEM_SLEEP, XXXXXXX, KC_BRID, XXXXXXX, XXXXXXX, XXXXXXX, 		       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
	//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
					        XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
					    //`--------------------------'  `--------------------------'

	),

	// amovement
	[_MOVE] = LAYOUT_split_3x6_3(
	//,-----------------------------------------------------.                    ,-----------------------------------------------------.
	    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,		       KC_HOME,   KC_UP, KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX,
	//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 		       KC_LEFT,  KC_ENT, KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX,
	//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	     KC_APP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,	                KC_END, KC_DOWN, KC_PGDN,  KC_DEL, XXXXXXX, XXXXXXX,
	//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
		                                XXXXXXX, XXXXXXX, XXXXXXX,    _______, XXXXXXX, XXXXXXX
					    //`--------------------------'  `--------------------------'
	)

};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oled_render_layer_state(void) {
  char string [24];
  switch (get_highest_layer(default_layer_state|layer_state))
  {
      case _QWERTY:
        oled_write_ln_P(PSTR("Layer: QWERTY"),false);
        break;
      case _COLEMAK:
        oled_write_ln_P(PSTR("Layer: COLEMAK"),false);
        break;
      case _DVORAK:
        oled_write_ln_P(PSTR("Layer: DVORAK"),false);
        break;
      case _NUM:
        oled_write_ln_P(PSTR("layer: mov+num"),false);
        break;
      case _SYM:
        oled_write_ln_P(PSTR("Layer: Symbols"),false);
        break;
      case _COMMAND:
        oled_write_ln_P(PSTR("Layer: Command"),false);
        break;
      case _NUMPAD:
        oled_write_ln_P(PSTR("Layer: Numpad"),false);
        break;
      case _MOVE:
        oled_write_ln_P(PSTR("Layer: Movement"),false);
        break;
      case _SWITCH:
        oled_write_ln_P(PSTR("Layer: Layer Switch"),false);
        break;
      default:
        snprintf(string, sizeof(string), "%ld",layer_state);
        oled_write_P(PSTR("Layer: Undef-"),false);
        oled_write_ln(string, false);
    }
 }

char keylog_str[24] = {};
const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE

