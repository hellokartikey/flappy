#ifndef SDL_WRAPPER_GLOBAL_H
#define SDL_WRAPPER_GLOBAL_H

#include <SDL2/SDL.h>

#include <chrono>

#include "fwd.h"

namespace hk::sdl {
auto getTicks() -> std::chrono::milliseconds;
}

#endif
