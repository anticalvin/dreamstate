# Dreamstate Web Port: Engineering Baseline

Target: iPhone 17 Pro Safari first, Android Chrome second.

## Verified source audit (initial)
The upstream CMake root currently requires Boost (program_options/system), OpenAL, Bullet, GLM, FFmpeg, SDL2 and desktop OpenGL. The rwengine library also contains an OpenGL renderer, audio layer, asset loaders, physics, and game scripting.

**This is not yet a browser build.** No WebAssembly compilation or mobile gameplay has been demonstrated.

## Porting order
1. Establish a reproducible Emscripten toolchain and compile-only probe, with explicit failures for unsupported native dependencies.
2. Introduce a browser platform boundary (lifecycle, asset I/O, input, audio, rendering) without breaking desktop builds.
3. Port renderer to WebGL 2 / OpenGL ES 3-compatible calls and shaders; validate actual scene rendering.
4. Integrate original game asset import using user-supplied licensed PC files, with storage quota/error handling.
5. Add pointer/touch virtual controls and map them to existing input state.
6. Profile Safari on iPhone 17 Pro, then test Android Chrome.

## Current blockers
- Desktop OpenGL dependency and shader/API compatibility.
- FFmpeg and OpenAL browser equivalents or appropriate Emscripten builds.
- Boost and Bullet cross-compilation.
- Browser sandbox file loading and persistent storage.
- Main loop, WebGL context loss, Safari memory limits and audio activation.

## Acceptance criteria for first milestone
- CI installs a pinned Emscripten SDK.
- Build log demonstrates actual compilation of at least one OpenRW C++ target to WebAssembly (not a standalone HTML mock).
- Unsupported dependencies are documented with precise compiler errors.
- No copyrighted GTA III game data committed.

Original OpenRW is GPL-3.0-or-later; retain its copyright notices and license.
