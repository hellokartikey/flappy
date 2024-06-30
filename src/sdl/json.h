#ifndef SDL_WRAPPER_JSON_H
#define SDL_WRAPPER_JSON_H

#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include <memory>
#include <optional>

#include "fwd.h"
#include "loader.h"
#include "math.h"

namespace hk::sdl {
auto to_json(json& j, const Color& color) -> void;
auto from_json(const json& j, Color& color) -> void;

auto to_json(json& j, const Font& font) -> void;
auto from_json(const json& j, Font& font) -> void;

auto to_json(json& j, const Rectangle& rectangle) -> void;
auto from_json(const json& j, Rectangle& rect) -> void;

auto to_json(json& j, const Sprite& sprite) -> void;
auto from_json(const json& j, Sprite& sprite) -> void;
}  // namespace hk::sdl

namespace hk {
template <typename T>
auto to_json(json& j, const Vector2<T>& vector) {
  j = json{{"x", vector.x()}, {"y", vector.y()}};
}

template <typename T>
auto from_json(const json& j, Vector2<T>& vector) {
  vector = Vector2<T>{j.at("x"), j.at("y")};
}
}  // namespace hk

namespace nlohmann {
template <typename T>
struct adl_serializer<std::shared_ptr<T>> {
  static auto to_json(json& j, const std::shared_ptr<T>& ptr) {
    if (ptr) {
      j = *ptr;
    } else {
      j = nullptr;
    }
  }

  static auto from_json(const json& j, std::shared_ptr<T>& ptr) {
    if (j.is_null()) {
      ptr = nullptr;
    } else {
      T tmp = j;
      ptr = new T(tmp);
    }
  }
};
}  // namespace nlohmann

#endif
