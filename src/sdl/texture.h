#ifndef SDL_WRAPPER_TEXTURE_H
#define SDL_WRAPPER_TEXTURE_H

#include <SDL2/SDL.h>

#include <stdexcept>

#include "fwd.h"

namespace hk::sdl {
class Texture {
 public:
  Texture(Renderer& renderer, Surface& surface);
  Texture(Renderer& renderer, Surface& surface, no_logging_tag_t);

  ~Texture();

  auto get() -> SDL_Texture*;

  operator SDL_Texture*();

 private:
  SDL_Texture* m_texture;
  bool m_log;
};
}  // namespace hk::sdl

#endif
