# Development status

## v0.1b — foundation work

### Implemented in repository
- Portable lifecycle state structure: initialization, frame counter, input-mask storage, and stop request.
- Host-side unit tests for lifecycle state.
- Makefile test target.
- GitHub Actions workflow to compile and run host tests.

### Not implemented
- Vietcong game engine integration.
- Renderer, audio, physics, scripting, resource/map loader, networking, or save system.
- Xbox 360 controller and video platform integration.
- Xenon cross-compilation.
- `default.xex` generation or Xbox 360 runtime validation.

### Verification status
The source and CI configuration have been committed. A CI run has not yet been inspected, so test success is not claimed here. The first verification step is to run `make clean test` locally or inspect the GitHub Actions run after push.

## Version policy
Keep v0.1b until the current foundation has a successful test result and the next increment adds a distinct, testable capability. Do not skip version numbers.
