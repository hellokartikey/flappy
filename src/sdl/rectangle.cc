#include "rectangle.h"

using namespace hk::sdl;

Rectangle::Rectangle(u32 x, u32 y, u32 w, u32 h) : m_rect(x, y, w, h) {}

Rectangle::Rectangle(hk::Vector2i position, hk::Vector2i size)
    : m_rect(position.x(), position.y(), size.x(), size.y()) {}

Rectangle::Rectangle(SDL_Rect rect) : m_rect(rect) {}

auto Rectangle::get() -> SDL_Rect* { return &m_rect; }

auto Rectangle::size() const -> hk::Vector2i { return {m_rect.w, m_rect.h}; }

auto Rectangle::position() const -> hk::Vector2i {
  return {m_rect.x, m_rect.y};
}

Rectangle::operator SDL_Rect*() { return &m_rect; }

namespace hk::sdl {
auto operator+(const Rectangle& rectangle,
               const hk::Vector2i& vector) -> Rectangle {
  return Rectangle{rectangle.position() + vector, rectangle.size()};
}

auto operator-(const Rectangle& rectangle,
               const hk::Vector2i& vector) -> Rectangle {
  return Rectangle{rectangle.position() - vector, rectangle.size()};
}
}  // namespace hk::sdl
