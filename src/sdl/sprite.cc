#include "sprite.h"

#include <fmt/std.h>

using namespace hk::sdl;

Sprite::Sprite(std::string_view name, Texture_ptr texture, Rectangle_opt rect,
               hk::Vector2i position)
    : Entity(name), m_texture(texture), m_rect(rect), m_position(position) {}

auto Sprite::render() -> void {
  auto src = Rectangle_opt{std::nullopt};
  auto dst = Rectangle_opt{std::nullopt};
  if (m_rect) {
    src = *m_rect;
    dst = Rectangle{m_position, m_rect->size()};
  }

  m_texture->copy(src, dst);
}

auto Sprite::texture() -> Texture_ptr { return m_texture; }

auto Sprite::setTexture(Texture_ptr texture) -> void { m_texture = texture; }

auto Sprite::rectangle() const -> Rectangle_opt { return m_rect; }

auto Sprite::setRectangle(const Rectangle_opt& rectangle) {
  m_rect = rectangle;
}

auto Sprite::position() const -> Vector2i { return m_position; }

auto Sprite::position() -> Vector2i& { return m_position; }

auto Sprite::setPosition(const hk::Vector2i& position) -> void {
  m_position = position;
}
