#ifndef SDL_WRAPPER_SDL_TTF_H
#define SDL_WRAPPER_SDL_TTF_H

#include <SDL2/SDL_ttf.h>

#include <stdexcept>
#include <string_view>

#include "entity.h"
#include "fwd.h"

namespace hk::sdl {
class TTF : public Entity {
 public:
  TTF();

  ~TTF();
};
}  // namespace hk::sdl

#endif
