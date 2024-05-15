#include "rectangle.h"

using namespace hk::sdl;

Rectangle::Rectangle(u32 x, u32 y, u32 w, u32 h) : m_rect(x, y, w, h) {}

Rectangle::Rectangle(hk::math::Vector2i top_left, hk::math::Vector2i size)
    : m_rect(top_left.x(), top_left.y(), size.x(), size.y()) {}

Rectangle::Rectangle(SDL_Rect rect) : m_rect(rect) {}

auto Rectangle::get() -> SDL_Rect* { return &m_rect; }

Rectangle::operator SDL_Rect*() { return &m_rect; }
