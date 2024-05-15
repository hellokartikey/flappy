#ifndef SDL_WRAPPER_RECTANGLE_H
#define SDL_WRAPPER_RECTANGLE_H

#include <SDL2/SDL.h>

#include <cstdint>
#include <optional>
#include <stdexcept>

#include "fwd.h"
#include "math.h"

namespace hk::sdl {
class Rectangle {
 public:
  Rectangle(u32 x, u32 y, u32 w, u32 h);
  Rectangle(hk::math::Vector2i top_left, hk::math::Vector2i size);

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
