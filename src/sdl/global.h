#ifndef SDL_WRAPPER_GLOBAL_H
#define SDL_WRAPPER_GLOBAL_H

#include <SDL2/SDL.h>

#include <chrono>

#include "fwd.h"

namespace hk::sdl {
struct no_logging_tag_t {};

constexpr no_logging_tag_t no_logging_tag{};

auto getTicks() -> std::chrono::milliseconds;
}  // namespace hk::sdl

#endif
