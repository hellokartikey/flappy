#ifndef SDL_WRAPPER_SPRITE_H
#define SDL_WRAPPER_SPRITE_H

#include <string_view>

#include "rectangle.h"
#include "texture.h"

namespace hk::sdl {
class Sprite : public Entity {
 public:
  Sprite(std::string_view name, Texture_ptr texture,
         Rectangle_opt rectangle = std::nullopt,
         hk::Vector2i position = hk::Vector2i::zero());

  ~Sprite() = default;

  // TODO - Implement scaling
  auto render() -> void;

  auto texture() -> Texture_ptr;
  auto setTexture(Texture_ptr texture) -> void;

  auto rectangle() const -> Rectangle_opt;
  auto setRectangle(const Rectangle_opt& rectangle);

  auto position() const -> Vector2i;
  auto position() -> Vector2i&;
  auto setPosition(const hk::Vector2i& position) -> void;

 private:
  Texture_ptr m_texture;
  Rectangle_opt m_rect;
  Vector2i m_position;
};
}  // namespace hk::sdl

#endif
