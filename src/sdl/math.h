#ifndef SDL_WRAPPER_MATH_H
#define SDL_WRAPPER_MATH_H

#include <fmt/ostream.h>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include <iosfwd>
#include <string>

namespace hk {
template <typename T>
class Vector2 {
 public:
  constexpr Vector2() = default;
  constexpr Vector2(T x, T y) : m_x(x), m_y(y) {}

  ~Vector2() = default;

  constexpr auto x() -> T& { return m_x; }
  constexpr auto x() const -> T { return m_x; }

  constexpr auto y() -> T& { return m_y; }
  constexpr auto y() const -> T { return m_y; }

  constexpr auto operator==(const Vector2& rhs) -> bool {
    return x() == rhs.x() && y() == rhs.y();
  }

  constexpr auto operator+(const Vector2& rhs) -> Vector2 {
    return Vector2{x() + rhs.x(), y() + rhs.y()};
  }

  constexpr auto operator-(const Vector2& rhs) -> Vector2 {
    return Vector2{x() - rhs.x(), y() - rhs.y()};
  }

  constexpr auto operator-() -> Vector2 { return Vector2{-x(), -y()}; }

  static auto zero() -> Vector2 { return {T{0}, T{0}}; }

  static auto left() -> Vector2 { return {T{-1}, T{0}}; }
  static auto right() -> Vector2 { return {T{1}, T{0}}; }

  static auto up() -> Vector2 { return {T{0}, T{-1}}; }
  static auto down() -> Vector2 { return {T{0}, T{1}}; }

 private:
  T m_x, m_y;
};

using Vector2f = Vector2<f32>;
using Vector2i = Vector2<i32>;

}  // namespace hk

template <typename T>
struct fmt::formatter<hk::Vector2<T>> : fmt::formatter<std::string> {
  inline auto format(const hk::Vector2<T>& v, format_context& ctx) const {
    return formatter<std::string>::format(
        fmt::format("[Vector {}, {}]", v.x(), v.y()), ctx);
  }
};

#endif
