#ifndef SDL_WRAPPER_SDL_TTF_H
#define SDL_WRAPPER_SDL_TTF_H

#include <SDL2/SDL_ttf.h>

#include <stdexcept>

#include "fwd.h"

namespace hk::sdl {
class TTF {
 public:
  TTF();

  ~TTF();
};
}  // namespace hk::sdl

#endif
