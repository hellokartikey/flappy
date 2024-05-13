#include "texture.h"

#include "logger.h"
#include "renderer.h"
#include "surface.h"

using namespace hk::sdl;

Texture::Texture(Renderer& renderer, Surface& surface)
    : m_texture(SDL_CreateTextureFromSurface(renderer, surface)) {
  hk::logger::ctor("SDL_CreateTextureFromSurface() successful.");
}

Texture::~Texture() {
  SDL_DestroyTexture(m_texture);
  hk::logger::dtor("SDL_DestroyTexture() successful.");
}

auto Texture::get() -> SDL_Texture* { return m_texture; }

Texture::operator SDL_Texture*() { return m_texture; }
