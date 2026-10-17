#include "port_state.h"

void vc360_state_reset(vc360_port_state *state)
{
    if (state == 0) return;
    state->frame_count = 0U;
    state->input_mask = 0U;
    state->initialized = 0;
    state->running = 0;
}

int vc360_state_initialize(vc360_port_state *state)
{
    if (state == 0) return -1;
    vc360_state_reset(state);
    state->initialized = 1;
    state->running = 1;
    return 0;
}

int vc360_state_tick(vc360_port_state *state, uint32_t input_mask)
{
    if (state == 0 || !state->initialized || !state->running) return -1;
    state->input_mask = input_mask;
    state->frame_count++;
    return 0;
}

void vc360_state_request_stop(vc360_port_state *state)
{
    if (state == 0) return;
    state->running = 0;
}
