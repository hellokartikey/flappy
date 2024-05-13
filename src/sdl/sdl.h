#ifndef SDL_WRAPPER_SDL_H
#define SDL_WRAPPER_SDL_H

#include <SDL2/SDL.h>

#include <cstdint>
#include <stdexcept>

#include "fwd.h"

namespace hk::sdl {
namespace init {
constexpr std::uint32_t TIMER = SDL_INIT_TIMER, AUDIO = SDL_INIT_AUDIO,
                        VIDEO = SDL_INIT_VIDEO, JOYSTICK = SDL_INIT_JOYSTICK,
                        HAPTIC = SDL_INIT_HAPTIC,
                        GAMECONTROLLER = SDL_INIT_GAMECONTROLLER,
                        EVENTS = SDL_INIT_EVENTS,
                        EVERYTHING = SDL_INIT_EVERYTHING,
                        NOPARACHUTE = SDL_INIT_NOPARACHUTE;
}

class SDL {
 public:
  SDL(std::uint32_t flags = init::EVERYTHING);
  ~SDL();
};
}  // namespace hk::sdl

#endif
