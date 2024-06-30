#include "color.h"

namespace hk::sdl {
Color::Color() : m_r(0x00), m_g(0x00), m_b(0x00), m_a(0xff) {}

Color::Color(color_t r, color_t g, color_t b, color_t a)
    : m_r(r), m_g(g), m_b(b), m_a(a) {}

auto Color::r() -> color_t& { return m_r; }

auto Color::r() const -> color_t { return m_r; }

auto Color::g() -> color_t& { return m_g; }

auto Color::g() const -> color_t { return m_g; }

auto Color::b() -> color_t& { return m_b; }

auto Color::b() const -> color_t { return m_b; }

auto Color::a() -> color_t& { return m_a; }

auto Color::a() const -> color_t { return m_a; }

Color::operator SDL_Color() const { return SDL_Color{m_r, m_g, m_b, m_a}; }
}  // namespace hk::sdl
