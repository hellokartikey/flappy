#ifndef SDL_WRAPPER_RENDERER_H
#define SDL_WRAPPER_RENDERER_H

#include <SDL2/SDL.h>

#include <cstdint>
#include <optional>
#include <stdexcept>

#include "fwd.h"
#include "rectangle.h"

namespace hk::sdl {
class Renderer {
 public:
  enum Flag {
    SOFTWARE = SDL_RENDERER_SOFTWARE,
    ACCELERATED = SDL_RENDERER_ACCELERATED,
    PRESENTVSYNC = SDL_RENDERER_PRESENTVSYNC,
    TARGETTEXTURE = SDL_RENDERER_TARGETTEXTURE
  };

  Renderer(Window& window, std::int32_t index = -1,
           Flag flags = Flag::ACCELERATED);

  Renderer(SDL_Renderer* renderer);

  ~Renderer();

  auto get() -> SDL_Renderer*;

  operator SDL_Renderer*();

  auto present() -> void;

  auto clear() -> void;

  auto setDrawColor(const Color& color) -> void;

  auto copy(Texture& texture, Rectangle_opt src = std::nullopt,
            Rectangle_opt dst = std::nullopt) -> void;

 private:
  SDL_Renderer* m_renderer;
};
}  // namespace hk::sdl

#endif
