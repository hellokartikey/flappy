#include "json.h"

#include <string>
#include <string_view>

#include "color.h"
#include "font.h"
#include "rectangle.h"

namespace hk::sdl {
auto to_json(json& j, const Color& color) -> void {
  j = {{"r", color.r()}, {"g", color.g()}, {"b", color.b()}, {"a", color.a()}};
}

auto from_json(const json& j, Color& color) -> void {
  color =
      hk::sdl::Color{j.at("r"), j.at("g"), j.at("b"),
                     static_cast<hk::sdl::Color::color_t>(j.value("a", 0xff))};
}

auto to_json(json& j, const Font& font) -> void {
  j = {{"type", "font"}, {"name", font.name()}, {"size", font.size()}};
}

auto from_json(const json& j, Font& font) -> void {
  auto name = std::string(j.at("name"));
  auto size = u32(j.at("size"));
  font = Font(name, size);
}

auto to_json(json& j, const Rectangle& rectangle) -> void {
  j = {{"position", rectangle.position()}, {"size", rectangle.size()}};
}

auto from_json(const json& j, Rectangle& rect) -> void {
  auto pos = hk::Vector2i(j.at("position"));
  auto size = hk::Vector2i(j.at("size"));
  rect = Rectangle{pos, size};
}
}  // namespace hk::sdl
