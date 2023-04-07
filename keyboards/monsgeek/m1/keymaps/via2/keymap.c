/* Copyright (C) 2022 jonylee@hfd
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
#include "config.h"

#ifdef USE_SECOND_COLOR
	#include "keymap.h"
	#include <lib/lib8tion/lib8tion.h>
#endif

enum __layers {
    WIN_B,
    WIN_W,
    WIN_FN,
    MAC_B,
    MAC_W,
    MAC_FN
};


enum custom_keycodes {
#ifdef VIA_ENABLE
	// ENC_VAI = QK_USER,
	ENC_VAI = QK_KB,
#else
    ENC_VAI = SAFE_RANGE,
#endif
    ENC_VAD,
	RGB_RN,
	RGB_ALP,
	RGB_R_NEB,
	RGB_PRN,
	E_RESET
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [WIN_B] = LAYOUT_all( /* Base */
		KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12,   KC_DEL,           KC_MUTE,
		KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,KC_EQL,   KC_BSPC,          KC_HOME,
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,KC_RBRC,  KC_BSLS,          KC_PGUP,
		KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,KC_NUHS,  KC_ENT,           KC_PGDN,
		KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
		KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT, MO(WIN_FN),KC_RCTL,        KC_LEFT, KC_DOWN, KC_RGHT),

    [WIN_W] = LAYOUT_all( /* Base */
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
		_______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
		_______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, KC_W,    _______,
		_______, _______, _______,                   _______,                            _______, _______, _______,          KC_A,    KC_S,    KC_D),

    [WIN_FN] = LAYOUT_all( /* WASD/↑←↓→ */
		_______, KC_MYCM, KC_MAIL, KC_WSCH, KC_WHOM, KC_MSEL, KC_MPLY, KC_MPRV, KC_MNXT, _______, _______, _______, _______, _______,           RGB_MOD,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_SPD, RGB_SPI, _______,           _______,
		_______, _______,TG(WIN_W),_______, _______, _______, _______, _______, KC_INS,  DF(MAC_B),KC_PSCR,_______, _______, RGB_MOD,           _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_TOG, _______, _______, RGB_MOD, RGB_HUI,           _______,
		_______, _______, _______, _______, KC_CALC, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______,          _______,  RGB_VAI, _______,
		_______, GU_TOGG, _______,                   _______,                            _______, _______, _______,          RGB_SAD,  RGB_VAD, RGB_SAI),

    [MAC_B] = LAYOUT_all( /* Base */
		KC_ESC,  KC_BRID, KC_BRIU, KC_MCTL, KC_LPAD, KC_F5,   KC_F6,   KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD,KC_VOLU,  KC_DEL,           KC_MUTE,
		KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,KC_EQL,   KC_BSPC,          KC_HOME,
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,KC_RBRC,  KC_BSLS,          KC_PGUP,
		KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,KC_NUHS,  KC_ENT,           KC_PGDN,
		KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
		KC_LCTL, KC_LALT, KC_LGUI,                   KC_SPC,                             KC_RGUI, MO(MAC_FN),KC_RCTL,        KC_LEFT, KC_DOWN, KC_RGHT),

    [MAC_W] = LAYOUT_all( /* WASD/↑←↓→ */
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
		_______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
		_______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, KC_W,    _______,
		_______, _______, _______,                   _______,                            _______, _______, _______,          KC_A,    KC_S,    KC_D),

    [MAC_FN] = LAYOUT_all( /* FN */
		_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,  KC_F9,    KC_F10,  KC_F11,  KC_F12,  KC_DEL,            RGB_MOD,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_SPD, RGB_SPI, _______,           _______,
		_______, _______,TG(MAC_W),_______, _______, _______, _______, _______, KC_INS,  DF(WIN_B),KC_PSCR,_______, _______, RGB_MOD,           _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_TOG, _______, _______, RGB_MOD, RGB_HUI,           _______,
		_______, _______, _______, _______, KC_CALC, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______,          _______,  RGB_VAI, _______,
		_______, _______, _______,                   _______,                            _______, _______, _______,          RGB_SAD,  RGB_VAD, RGB_SAI)
};


// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ENC_VAI:
            if (record->event.pressed){
                if(rgb_matrix_get_val() < RGB_MATRIX_MAXIMUM_BRIGHTNESS){
                    rgb_matrix_config.hsv.v = rgb_matrix_get_val() + RGB_MATRIX_VAL_STEP;
                    rgb_matrix_sethsv(rgb_matrix_config.hsv.h, rgb_matrix_config.hsv.s, rgb_matrix_config.hsv.v);
                }
            }
            return false;
        case ENC_VAD:
            if (record->event.pressed){
                if(rgb_matrix_get_val() > 0){
                    rgb_matrix_config.hsv.v = rgb_matrix_get_val() - RGB_MATRIX_VAL_STEP;
                    rgb_matrix_sethsv(rgb_matrix_config.hsv.h, rgb_matrix_config.hsv.s, rgb_matrix_config.hsv.v);
                }
            }
            return false;
#ifdef USE_SECOND_COLOR
		case RGB_RN:  // RGB_MATRIX_DIGITAL_RAIN
			if (record->event.pressed) {
				rgb_matrix_mode_noeeprom(RGB_MATRIX_DIGITAL_RAIN);
			}
			return false;
		case RGB_ALP :  // ALPHAS_MODS_2
			if (record->event.pressed) {
				rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_ALPHAS_MODS_2);
			}
			return false;
		case RGB_R_NEB :  //SOLID_REACTIVE_NEXUS 
			if (record->event.pressed) {
				rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_NEXUS );
			}
			return false;
		case RGB_PRN:  // RGB_MATRIX_DIGITAL_RAIN
			if (record->event.pressed) {
				rgb_matrix_mode_noeeprom(RGB_MATRIX_PIXEL_RAIN);
			}
			return false;
#endif
    }
    return true;
}


// clang-format off
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [WIN_B] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [WIN_W] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [WIN_FN] = { ENCODER_CCW_CW(ENC_VAI, ENC_VAD) },
    [MAC_B] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [MAC_W] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [MAC_FN] = { ENCODER_CCW_CW(ENC_VAI, ENC_VAD) }
};
#endif



#ifdef USE_SECOND_COLOR

via2_config_t rgb_color2_config;

enum via_color2_value {
    id_color2_brightness   = 1,
    id_color2_color        = 2
    // id_color2_effect_speed = 3,
    // id_color2_effect       = 4
};

// already defined in quantum/quantum.h
// uint8_t id_custom_channel  = 0;

void rgb_color2_sethsv(uint16_t hue, uint8_t sat, uint8_t val) {
    rgb_color2_config.hsv.h = hue;
    rgb_color2_config.hsv.s = sat;
    rgb_color2_config.hsv.v = (val > RGB_MATRIX_MAXIMUM_BRIGHTNESS) ? RGB_MATRIX_MAXIMUM_BRIGHTNESS : val;
}
HSV rgb_color2_get_hsv(void) {
    return rgb_color2_config.hsv;
}
uint8_t rgb_color2_get_hue(void) {
    return rgb_color2_config.hsv.h;
}
uint8_t rgb_color2_get_sat(void) {
    return rgb_color2_config.hsv.s;
}
uint8_t rgb_color2_get_val(void) {
    return rgb_color2_config.hsv.v;
}

void m1_custom_config_get_value(uint8_t *data) {
    // data = [ value_id, value_data ]
    uint8_t *value_id   = &(data[0]);
    uint8_t *value_data = &(data[1]);

    switch (*value_id) {
        case id_color2_brightness: {
            value_data[0] = ((uint16_t)rgb_matrix_get_val() * UINT8_MAX) / RGB_MATRIX_MAXIMUM_BRIGHTNESS;
            break;
        }
        case id_color2_color: {
            value_data[0] = rgb_color2_get_hue();
            value_data[1] = rgb_color2_get_sat();
            break;
        }
    }
}
void m1_custom_config_set_value(uint8_t *data) {
    // data = [ value_id, value_data ]
    uint8_t *value_id   = &(data[0]);
    uint8_t *value_data = &(data[1]);
    switch (*value_id) {
        case id_color2_brightness: {
            rgb_color2_sethsv(rgb_color2_get_hue(), rgb_color2_get_sat(), scale8(value_data[0], RGB_MATRIX_MAXIMUM_BRIGHTNESS));
            break;
        }
        case id_color2_color: {
            rgb_color2_sethsv(value_data[0], value_data[1], rgb_color2_get_val());
            break;
        }
    }
}
void m1_custom_config_save(void)
{
	eeconfig_update_user(rgb_color2_config.raw); // Writes the new status to EEPROM
    // eeprom_update_block( &g_buttglow_config,
        // ((void*)BUTTGLOW_CONFIG_EEPROM_ADDR),
        // sizeof(buttglow_config) );
}


void via_custom_value_command_kb(uint8_t *data, uint8_t length) {
    // data = [ command_id, channel_id, value_id, value_data ]
    uint8_t *command_id        = &(data[0]);
    uint8_t *channel_id        = &(data[1]);
    uint8_t *value_id_and_data = &(data[2]);

    if ( *channel_id == id_custom_channel  ) {
        switch ( *command_id )
        {
            case id_custom_set_value:
            {
                m1_custom_config_set_value(value_id_and_data);
                break;
            }
            case id_custom_get_value:
            {
                m1_custom_config_get_value(value_id_and_data);
                break;
            }
            case id_custom_save:
            {
                m1_custom_config_save();
                break;
            }
            default:
            {
                // Unhandled message.
                *command_id = id_unhandled;
                break;
            }
        }
        return;
    }

    // Return the unhandled state
    *command_id = id_unhandled;

    // DO NOT call raw_hid_send(data,length) here, let caller do this
}


void keyboard_post_init_user(void) {
  // Read the user config from EEPROM
  rgb_color2_config.raw = eeconfig_read_user();

  // Set default layer, if enabled
  // if (rgb_color2_config.rgb_layer_change) {
    // rgblight_enable_noeeprom();
    // rgblight_sethsv_noeeprom(HSV_CYAN);
    // rgblight_mode_noeeprom(1);
  // }
}	  	
#endif