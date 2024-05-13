#include "rectangle.h"

using namespace hk::sdl;

Rectangle::Rectangle(std::int32_t x, std::int32_t y, std::int32_t w,
                     std::int32_t h)
    : m_rect(x, y, w, h) {}

Rectangle::Rectangle(SDL_Rect rect) : m_rect(rect) {}

auto Rectangle::get() -> SDL_Rect* { return &m_rect; }

Rectangle::operator SDL_Rect*() { return &m_rect; }
