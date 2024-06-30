#ifndef SDL_WRAPPER_COLOR_H
#define SDL_WRAPPER_COLOR_H

#include <SDL2/SDL.h>
#include <fmt/format.h>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include <cstdint>
#include <string>

#include "fwd.h"

namespace hk::sdl {
class Color {
 public:
  using color_t = u8;

  Color();
  Color(color_t r, color_t g, color_t b, color_t a = 0xff);

  ~Color() = default;

  auto r() -> color_t&;
  auto r() const -> color_t;

  auto g() -> color_t&;
  auto g() const -> color_t;

  auto b() -> color_t&;
  auto b() const -> color_t;

  auto a() -> color_t&;
  auto a() const -> color_t;

  operator SDL_Color() const;

 private:
  color_t m_r, m_g, m_b, m_a;
};
}  // namespace hk::sdl

template <>
struct fmt::formatter<hk::sdl::Color> : fmt::formatter<std::string> {
  inline auto format(const hk::sdl::Color& c, format_context& ctx) const {
    return formatter<std::string>::format(
        fmt::format("[Color {:02x}, {:02x}, {:02x}, {:02x}]", c.r(), c.g(),
                    c.b(), c.a()),
        ctx);
  }
};

#endif
