#ifndef SDL_WRAPPER_TEXTURE_H
#define SDL_WRAPPER_TEXTURE_H

#include <SDL2/SDL.h>

#include <memory>
#include <stdexcept>

#include "fwd.h"

namespace hk::sdl {
class Texture {
 public:
  Texture(Window& window, Surface& surface);
  Texture(Window& window, Surface& surface, no_logging_tag_t);

  ~Texture();

  auto get() -> SDL_Texture*;

  operator SDL_Texture*();

 private:
  SDL_Texture* m_texture;
bool m_log;
};

using Texture_ptr = std::shared_ptr<Texture>;
}  // namespace hk::sdl

#endif
