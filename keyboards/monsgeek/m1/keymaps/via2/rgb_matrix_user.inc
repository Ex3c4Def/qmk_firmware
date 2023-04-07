//#include "m1.h"
//#include "m1_help.h"

// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)


RGB_MATRIX_EFFECT(ALPHAS_MODS_2)
RGB_MATRIX_EFFECT(ALPHAS_MODS_S)
RGB_MATRIX_EFFECT(ALPHAS_MODS_V)

// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#include "keymap.h"
uint8_t     custom_flags[RGB_MATRIX_LED_COUNT] = {
			1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
			1,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  1,  1,
			1,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  1,  1,
			1,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  1,  1,
			1,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  1,  1,  1,
			1,  1,  1,          4,              1,  1,  1,  1,  1,  1,
			2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
			2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2
};
//uint8_t     custom_flags[RGB_MATRIX_LED_COUNT] = {
//			1,  4,  4,  4,  4,  1,  1,  1,  1,  4,  4,  4,  4,  1,
//			1,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  1,  1,
//			1,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  1,  1,
//			1,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  1,  1,
//			1,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  1,  1,  1,
//			1,  1,  1,          4,              1,  1,  1,  1,  1,  1,
//			2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
//			2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2
//};


// alphas = color1, mods = color2
static bool ALPHAS_MODS_2(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    HSV hsv  = rgb_matrix_config.hsv;
    RGB rgb1 = rgb_matrix_hsv_to_rgb(hsv);
	
	
    //hsv.h += (rgb_matrix_config.speed - 0);
	hsv      = rgb_color2_config.hsv;
    RGB rgb2 = rgb_matrix_hsv_to_rgb(hsv);

    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        //if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
		if (HAS_FLAGS(custom_flags[i], LED_FLAG_MODIFIER)) {
            rgb_matrix_set_color(i, rgb2.r, rgb2.g, rgb2.b);
        } else {
            rgb_matrix_set_color(i, rgb1.r, rgb1.g, rgb1.b);
        }
    }
    return rgb_matrix_check_finished_leds(led_max);
}

// alphas = color1, mods = color2
static bool ALPHAS_MODS_S(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    HSV hsv  = rgb_matrix_config.hsv;
    RGB rgb1 = rgb_matrix_hsv_to_rgb(hsv);
    hsv.s += (rgb_matrix_config.speed - 0);
    RGB rgb2 = rgb_matrix_hsv_to_rgb(hsv);

    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        //if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
		if (HAS_FLAGS(custom_flags[i], LED_FLAG_MODIFIER)) {
            rgb_matrix_set_color(i, rgb2.r, rgb2.g, rgb2.b);
        } else {
            rgb_matrix_set_color(i, rgb1.r, rgb1.g, rgb1.b);
        }
    }
    return rgb_matrix_check_finished_leds(led_max);
}

// alphas = color1, mods = color2
static bool ALPHAS_MODS_V(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    HSV hsv  = rgb_matrix_config.hsv;
    RGB rgb1 = rgb_matrix_hsv_to_rgb(hsv);
    hsv.v += (rgb_matrix_config.speed - 0);
    RGB rgb2 = rgb_matrix_hsv_to_rgb(hsv);

    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        //if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
		if (HAS_FLAGS(custom_flags[i], LED_FLAG_MODIFIER)) {
            rgb_matrix_set_color(i, rgb2.r, rgb2.g, rgb2.b);
        } else {
            rgb_matrix_set_color(i, rgb1.r, rgb1.g, rgb1.b);
        }
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
