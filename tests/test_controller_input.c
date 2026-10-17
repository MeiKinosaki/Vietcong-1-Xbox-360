#include <assert.h>
#include <stdio.h>
#include "../src/platform/controller_input.h"

int main(void)
{
    vc360_controller_state state;
    state.buttons = VC360_BUTTON_A | VC360_BUTTON_START;
    state.left_x = 100;
    state.left_y = -100;
    state.right_x = 0;
    state.right_y = 0;
    state.left_trigger = 25U;
    state.right_trigger = 0U;

    assert(vc360_controller_button_down(&state, VC360_BUTTON_A));
    assert(vc360_controller_button_down(&state, VC360_BUTTON_A | VC360_BUTTON_START));
    assert(!vc360_controller_button_down(&state, VC360_BUTTON_B));
    assert(!vc360_controller_button_down(&state, VC360_BUTTON_NONE));
    assert(!vc360_controller_button_down(0, VC360_BUTTON_A));

    vc360_controller_clear(&state);
    assert(state.buttons == VC360_BUTTON_NONE);
    assert(state.left_x == 0 && state.left_y == 0);
    assert(state.right_x == 0 && state.right_y == 0);
    assert(state.left_trigger == 0U && state.right_trigger == 0U);
    puts("PASS: controller input abstraction tests");
    return 0;
}
