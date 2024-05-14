#ifndef SDL_WRAPPER_SDL_TTF_H
#define SDL_WRAPPER_SDL_TTF_H

#include <SDL2/SDL_ttf.h>

#include <memory>
#include <stdexcept>
#include <string_view>

#include "entity.h"
#include "fwd.h"

namespace hk::sdl {
class TTF : public Entity {
 public:
  TTF(std::string_view name = "TTF");

  ~TTF();
};

using TTF_ptr = std::shared_ptr<TTF>;
}  // namespace hk::sdl

#endif
