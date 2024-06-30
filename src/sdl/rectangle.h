#ifndef SDL_WRAPPER_RECTANGLE_H
#define SDL_WRAPPER_RECTANGLE_H

#include <SDL2/SDL.h>
#include <fmt/core.h>

#include <cstdint>
#include <optional>
#include <stdexcept>
#include <string>

#include "fwd.h"
#include "math.h"

namespace hk::sdl {
class Rectangle {
 public:
  Rectangle(u32 x, u32 y, u32 w, u32 h);
  Rectangle(Vector2i position = Vector2i::zero(),
            Vector2i size = Vector2i::zero());

  Rectangle(SDL_Rect rect);

  ~Rectangle() = default;

  auto get() -> SDL_Rect*;

  auto size() const -> hk::Vector2i;

  auto position() const -> hk::Vector2i;

  operator SDL_Rect*();

 private:
  SDL_Rect m_rect;
};

auto operator+(const Rectangle& rectangle,
               const hk::Vector2i& vector) -> Rectangle;

auto operator-(const Rectangle& rectangle,
               const hk::Vector2i& vector) -> Rectangle;

using Rectangle_opt = std::optional<Rectangle>;
}  // namespace hk::sdl

template <>
struct fmt::formatter<hk::sdl::Rectangle> : fmt::formatter<std::string> {
  inline auto format(const hk::sdl::Rectangle& r, format_context& ctx) const {
    auto pos = r.position();
    auto size = r.size();
    return formatter<std::string>::format(
        fmt::format("[Rectangle [{}, {}] +> [{}, {}]]", pos.x(), pos.y(),
                    size.x(), size.y()),
        ctx);
  }
};

#endif
