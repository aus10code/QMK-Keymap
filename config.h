//Auto Mouse Layer
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define AUTO_MOUSE_DEFAULT_LAYER 3

//Achordion
#define TAPPING_TERM 180
#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD
#define TAPPING_FORCE_HOLD_PER_KEY
#define CHARYBDIS_DRAGSCROLL_REVERSE_Y

//Caps Word
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

// RGB {{{
//#define SPLIT_LED_STATE_ENABLE
#define SPLIT_LAYER_STATE_ENABLE
#ifdef RGB_MATRIX_ENABLE
#ifdef __arm__
// Enable all animations on ARM boards since they have plenty of memory
// available for it.
#define ENABLE_RGB_MATRIX_SOLID_COLOR
#define ENABLE_RGB_MATRIX_ALPHAS_MODS
#define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_BREATHING
#define ENABLE_RGB_MATRIX_BAND_SAT
#define ENABLE_RGB_MATRIX_BAND_VAL
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#define ENABLE_RGB_MATRIX_CYCLE_ALL
#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#define ENABLE_RGB_MATRIX_DUAL_BEACON
#define ENABLE_RGB_MATRIX_RAINBOW_BEACON
#define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#define ENABLE_RGB_MATRIX_RAINDROPS
#define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#define ENABLE_RGB_MATRIX_HUE_BREATHING
#define ENABLE_RGB_MATRIX_HUE_PENDULUM
#define ENABLE_RGB_MATRIX_HUE_WAVE
#define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#define ENABLE_RGB_MATRIX_DIGITAL_RAIN
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#define ENABLE_RGB_MATRIX_SPLASH
#define ENABLE_RGB_MATRIX_MULTISPLASH
#define ENABLE_RGB_MATRIX_SOLID_SPLASH
#define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#else
// Disable control of RGB matrix by keycodes (must use firmware implementation
// to control the feature).
#define RGB_MATRIX_DISABLE_KEYCODES
#endif

// Limit maximum brightness to keep power consumption reasonable, and avoid
// disconnects.
#undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 20                                                                                                          
// limit in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#undef RGB_MATRIX_LED_FLUSH_LIMIT
#define RGB_MATRIX_LED_FLUSH_LIMIT 16 

// Rainbow swirl as startup mode.
#ifndef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#endif  // ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#undef RGB_MATRIX_DEFAULT_MODE
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_RAINBOW_MOVING_CHEVRON

// Slow swirl at startup.
#undef RGB_MATRIX_DEFAULT_SPD
#define RGB_MATRIX_DEFAULT_SPD 32

// Startup values.
#undef RGB_MATRIX_DEFAULT_HUE
#define RGB_MATRIX_DEFAULT_HUE 0
#undef RGB_MATRIX_DEFAULT_SAT
#define RGB_MATRIX_DEFAULT_SAT 255
#undef RGB_MATRIX_DEFAULT_VAL
#define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
#undef RGB_MATRIX_DEFAULT_HSV
#define RGB_MATRIX_DEFAULT_HSV \
  RGB_MATRIX_DEFAULT_HUE, RGB_MATRIX_DEFAULT_SAT, RGB_MATRIX_DEFAULT_VAL
#endif  // RGB_MATRIX_ENABLE