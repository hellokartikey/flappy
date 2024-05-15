#ifndef SDL_WRAPPER_SURFACE_H
#define SDL_WRAPPER_SURFACE_H

#include <SDL2/SDL.h>

#include <cstdint>
#include <memory>
#include <stdexcept>

#include "fwd.h"

namespace hk::sdl {
class Surface {
 public:
  Surface(SDL_Surface* surface);
  Surface(SDL_Surface* surface, no_logging_tag_t);

  ~Surface();

  auto w() const -> u32;

  auto h() const -> u32;

  auto get() -> SDL_Surface*;

  operator SDL_Surface*();

 private:
  SDL_Surface* m_surface;
  bool m_log;
};

using Surface_ptr = std::shared_ptr<Surface>;
}  // namespace hk::sdl

#endif
