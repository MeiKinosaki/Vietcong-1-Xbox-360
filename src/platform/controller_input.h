#ifndef VIETCONG360_CONTROLLER_INPUT_H
#define VIETCONG360_CONTROLLER_INPUT_H

#include <stdint.h>

/* Platform-neutral logical buttons; platform adapters map hardware input here. */
enum vc360_button {
    VC360_BUTTON_NONE   = 0U,
    VC360_BUTTON_A      = 1U << 0,
    VC360_BUTTON_B      = 1U << 1,
    VC360_BUTTON_X      = 1U << 2,
    VC360_BUTTON_Y      = 1U << 3,
    VC360_BUTTON_START  = 1U << 4,
    VC360_BUTTON_BACK   = 1U << 5,
    VC360_BUTTON_LB     = 1U << 6,
    VC360_BUTTON_RB     = 1U << 7,
    VC360_BUTTON_LS     = 1U << 8,
    VC360_BUTTON_RS     = 1U << 9,
    VC360_BUTTON_DPAD_UP    = 1U << 10,
    VC360_BUTTON_DPAD_DOWN  = 1U << 11,
    VC360_BUTTON_DPAD_LEFT  = 1U << 12,
    VC360_BUTTON_DPAD_RIGHT = 1U << 13
};

typedef struct vc360_controller_state {
    uint32_t buttons;
    int16_t left_x;
    int16_t left_y;
    int16_t right_x;
    int16_t right_y;
    uint8_t left_trigger;
    uint8_t right_trigger;
} vc360_controller_state;

void vc360_controller_clear(vc360_controller_state *state);
int vc360_controller_button_down(const vc360_controller_state *state,
                                 uint32_t button_mask);

#endif
