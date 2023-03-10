CUSTOM_UNICODE_ENABLE = no
CUSTOM_POINTING_DEVICE = no
CUSTOM_SPLIT_TRANSPORT_SYNC = no
MOUSEKEY_ENABLE = yes
CAPS_WORD_ENABLE = yes
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812
AUTOCORRECT_ENABLE = yes

SRC += features/achordion.c
#SRC += features/autocorrection.c

ifeq ($(strip $(KEYBOARD)), bastardkb/charybdis/4x6/blackpill)
    # MCU name
    # Bootloader selection
    BOOTLOADER := tinyuf2

    AUDIO_ENABLE          = yes # Audio output
    AUDIO_SUPPORTED       = yes # is set to no in kb, needs to be forcibly enabled
    AUDIO_DRIVER          = pwm_hardware

    BACKLIGHT_DRIVER      = pwm

    OVERLOAD_FEATURES = yes
endif

ifeq ($(strip $(KEYBOARD)), bastardkb/charybdis/4x6/v2/stemcell)
    OVERLOAD_FEATURES = yes
endif
ifeq ($(strip $(KEYBOARD)), bastardkb/charybdis/4x6/v2/splinky)
    OVERLOAD_FEATURES = yes
endif
ifeq ($(strip $(MCU)), atmega32u4)
    LTO_ENABLE = yes
    BOOTLOADER = qmk-hid
    BOOTLOADER_SIZE = 512
endif

ifeq ($(strip $(OVERLOAD_FEATURES)), yes)
    BOOTMAGIC_ENABLE      = yes # Enable Bootmagic Lite
    MOUSEKEY_ENABLE       = yes # Mouse keys
    EXTRAKEY_ENABLE       = yes # Audio control and System control
    CONSOLE_ENABLE        = yes # Console for debug
    COMMAND_ENABLE        = no  # Commands for debug and configuration
    NKRO_ENABLE           = yes # Enable N-Key Rollover
    RGBLIGHT_ENABLE       = no  # Enable keyboard RGB underglow

    KEYBOARD_SHARED_EP    = yes
    MOUSE_SHARED_EP       = yes

    AUTOCORRECT_ENABLE    = yes
    CAPS_WORD_ENABLE      = yes
    SWAP_HANDS_ENABLE     = yes
    TAP_DANCE_ENABLE      = yes
    DEBOUNCE_TYPE         = asym_eager_defer_pk
    WPM_ENABLE            = yes
    LTO_ENABLE            = no
    # OPT                   = 3

    CUSTOM_UNICODE_ENABLE = yes
    CUSTOM_POINTING_DEVICE = yes
    CUSTOM_SPLIT_TRANSPORT_SYNC = yes

endif
