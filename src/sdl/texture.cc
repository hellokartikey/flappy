#include "texture.h"

#include "global.h"
#include "logger.h"
#include "surface.h"
#include "window.h"

using namespace hk::sdl;

Texture::Texture(Window& window, Surface& surface)
    : Texture(window, surface, no_logging_tag) {
  m_log = true;
  if (m_log) hk::logger::ctor("SDL_CreateTextureFromSurface() successful.");
}

Texture::Texture(Window& window, Surface& surface, no_logging_tag_t)
    : m_texture(SDL_CreateTextureFromSurface(window, surface)) {}

Texture::~Texture() {
  SDL_DestroyTexture(m_texture);
  if (m_log) hk::logger::dtor("SDL_DestroyTexture() successful.");
}

auto Texture::get() -> SDL_Texture* { return m_texture; }

Texture::operator SDL_Texture*() { return m_texture; }
