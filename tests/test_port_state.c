#include <assert.h>
#include <stdio.h>
#include "../src/core/port_state.h"

int main(void)
{
    vc360_port_state state;
    vc360_state_reset(&state);
    assert(state.initialized == 0);
    assert(state.running == 0);
    assert(vc360_state_tick(&state, 1U) == -1);
    assert(vc360_state_initialize(&state) == 0);
    assert(state.initialized == 1);
    assert(state.running == 1);
    assert(vc360_state_tick(&state, 0x12U) == 0);
    assert(state.frame_count == 1U);
    assert(state.input_mask == 0x12U);
    vc360_state_request_stop(&state);
    assert(state.running == 0);
    assert(vc360_state_tick(&state, 0U) == -1);
    puts("PASS: portable port lifecycle tests");
    return 0;
}
