#ifndef VIETCONG360_PORT_STATE_H
#define VIETCONG360_PORT_STATE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct vc360_port_state {
    uint32_t frame_count;
    uint32_t input_mask;
    int initialized;
    int running;
} vc360_port_state;

void vc360_state_reset(vc360_port_state *state);
int vc360_state_initialize(vc360_port_state *state);
int vc360_state_tick(vc360_port_state *state, uint32_t input_mask);
void vc360_state_request_stop(vc360_port_state *state);

#ifdef __cplusplus
}
#endif
#endif
