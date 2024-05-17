#ifndef SDL_WRAPPER_MATH_H
#define SDL_WRAPPER_MATH_H

#include <fmt/ostream.h>

#include <iosfwd>

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

 private:
  T m_x, m_y;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector2<T>& obj) {
  os << "(" << obj.x() << ", " << obj.y() << ")";
  return os;
}

using Vector2f = Vector2<f32>;
using Vector2i = Vector2<u32>;
}  // namespace hk

template <typename T>
struct fmt::formatter<hk::Vector2<T>> : ostream_formatter {};

#endif
