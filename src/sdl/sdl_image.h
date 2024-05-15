#ifndef SDL_WRAPPER_SDL_IMAGE_H
#define SDL_WRAPPER_SDL_IMAGE_H

#include <SDL2/SDL_image.h>

#include <memory>
#include <stdexcept>
#include <string_view>

#include "entity.h"
#include "fwd.h"

namespace hk::sdl {
class IMG : public Entity {
 public:
  enum Flag {
    JPG = IMG_INIT_JPG,
    PNG = IMG_INIT_PNG,
    TIF = IMG_INIT_TIF,
    WEBP = IMG_INIT_WEBP,
    JXL = IMG_INIT_JXL,
    AVIF = IMG_INIT_AVIF,
    EVERYTHING = JPG | PNG | TIF | WEBP | JXL | AVIF
  };

  IMG(std::string_view name, Flag flag = EVERYTHING);
  ~IMG();
};

using IMG_ptr = std::shared_ptr<IMG>;
}  // namespace hk::sdl

#endif
