# Build notes

## Portable host test

Requirements: a C compiler compatible with C99 and GNU Make.

```sh
make clean test
```

This builds and runs only the portable lifecycle-state unit test on the host. It does **not** build the game, the original engine, a Xenon binary, or `default.xex`.

## Xbox 360 / Xenon

A real Xenon build requires a legally obtained and working Xbox 360 toolchain, compatible platform libraries, and the relevant source code/dependencies. Verify the compiler and linker paths before adding a cross-build target. Do not treat a host build as evidence of a Xenon build.

The eventual packaging pipeline must explicitly identify the compiler, linker, XEX conversion tool, command lines, exit codes, and resulting artifact. Keep proprietary game data and unauthorized SDK components out of this repository.
