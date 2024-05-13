#include "surface.h"

#include "logger.h"

using namespace hk::sdl;

Surface::Surface(SDL_Surface* surface) : m_surface(surface) {
  hk::logger::ctor("Surface::ctor(ptr) successful.");
}

Surface::~Surface() {
  SDL_FreeSurface(m_surface);
  hk::logger::dtor("SDL_FreeSurface() successful.");
}

auto Surface::w() const -> std::int32_t { return m_surface->w; }

auto Surface::h() const -> std::int32_t { return m_surface->h; }

auto Surface::get() -> SDL_Surface* { return m_surface; }

Surface::operator SDL_Surface*() { return m_surface; }
