#include "controller_input.h"

void vc360_controller_clear(vc360_controller_state *state)
{
    if (state == 0) return;
    state->buttons = VC360_BUTTON_NONE;
    state->left_x = 0;
    state->left_y = 0;
    state->right_x = 0;
    state->right_y = 0;
    state->left_trigger = 0U;
    state->right_trigger = 0U;
}

int vc360_controller_button_down(const vc360_controller_state *state,
                                 uint32_t button_mask)
{
    if (state == 0 || button_mask == VC360_BUTTON_NONE) return 0;
    return (state->buttons & button_mask) == button_mask;
}
