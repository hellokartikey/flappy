#include "surface.h"

#include "global.h"
#include "logger.h"

using namespace hk::sdl;

Surface::Surface(SDL_Surface* surface) : Surface(surface, no_logging_tag) {
  m_log = true;
  if (m_log) hk::logger::ctor("Surface::ctor(ptr) successful.");
}

Surface::Surface(SDL_Surface* surface, no_logging_tag_t)
    : m_surface(surface), m_log(false) {}

Surface::~Surface() {
  SDL_FreeSurface(m_surface);
  if (m_log) hk::logger::dtor("SDL_FreeSurface() successful.");
}

auto Surface::w() const -> std::int32_t { return m_surface->w; }

auto Surface::h() const -> std::int32_t { return m_surface->h; }

auto Surface::get() -> SDL_Surface* { return m_surface; }

Surface::operator SDL_Surface*() { return m_surface; }
