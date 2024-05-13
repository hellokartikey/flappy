#ifndef SDL_WRAPPER_RECTANGLE_H
#define SDL_WRAPPER_RECTANGLE_H

#include <SDL2/SDL.h>

#include <cstdint>
#include <optional>
#include <stdexcept>

#include "fwd.h"

namespace hk::sdl {
class Rectangle {
 public:
  Rectangle(std::int32_t x, std::int32_t y, std::int32_t w, std::int32_t h);

  Rectangle(SDL_Rect rect);

  ~Rectangle() = default;

  auto get() -> SDL_Rect*;

  operator SDL_Rect*();

 private:
  SDL_Rect m_rect;
};

using Rectangle_opt = std::optional<Rectangle>;
}  // namespace hk::sdl

#endif
