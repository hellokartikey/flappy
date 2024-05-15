#include "texture.h"

#include "global.h"
#include "logger.h"
#include "surface.h"

using namespace hk::sdl;

Texture::Texture(std::string_view name, Window_ptr window, Surface& surface)
    : Texture(name, window, surface, no_logging_tag) {
  m_log = true;
  if (m_log) {
    hk::logger::ctor("({}) SDL_CreateTextureFromSurface() successful.",
                     Entity::id());
  }
}

Texture::Texture(std::string_view name, Window_ptr window, Surface& surface,
                 no_logging_tag_t)
    : Entity(name),
      m_texture(SDL_CreateTextureFromSurface(*window, surface)),
      m_log(false),
      m_window(window) {}

Texture::Texture(std::string_view name, Window_ptr window, texture_sprite_tag_t)
    : Entity(name),
      m_texture(IMG_LoadTexture(*window, getFileName().data())),
      m_window(window),
      m_log(true) {
  if (m_texture == nullptr) {
    throw std::runtime_error(IMG_GetError());
  }

  hk::logger::ctor("({}) IMG_LoadTexture({}) successful.", Entity::id(), name);
}

Texture::~Texture() {
  SDL_DestroyTexture(m_texture);
  if (m_log) {
    hk::logger::dtor("({}) SDL_DestroyTexture({}) successful.", Entity::id(),
                     Entity::name());
  }
}

auto Texture::get() -> SDL_Texture* { return m_texture; }

auto Texture::size() -> hk::math::Vector2i {
  i32 x = 0, y = 0;
  SDL_QueryTexture(m_texture, nullptr, nullptr, &x, &y);
  return hk::math::Vector2i{static_cast<u32>(x), static_cast<u32>(y)};
}

Texture::operator SDL_Texture*() { return m_texture; }

auto Texture::getFileName() const -> std::string {
  return SPRITE_PREFIX + std::string{Entity::name()};
};

auto Texture::copy(Rectangle_opt src, Rectangle_opt dst) -> void {
  if (SDL_RenderCopy(*m_window, m_texture, src ? (*src).get() : nullptr,
                     dst ? (*dst).get() : nullptr)) {
    throw std::runtime_error(SDL_GetError());
  }
}
