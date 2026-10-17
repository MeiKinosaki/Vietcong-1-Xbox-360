# Controller input abstraction

The platform-neutral controller structure defines logical buttons, four signed stick axes, and two trigger values. The API provides safe clearing and bit-mask button queries.

## Important boundary

This is an input abstraction only. It does not poll a physical Xbox 360 controller, read XInput, configure USB, or prove console compatibility. A future Xbox 360 platform adapter must populate this structure using the actual supported console APIs and calibrated axis/trigger ranges.

## Test

`make clean test` compiles the host-side unit tests for lifecycle state and controller abstraction.
