#ifndef SDL_WRAPPER_SPRITE_H
#define SDL_WRAPPER_SPRITE_H

#include <string_view>

#include "rectangle.h"
#include "texture.h"

namespace hk::sdl {
class Sprite : public Entity {
 public:
  Sprite(std::string_view name, Texture_ptr texture,
         Rectangle_opt src = std::nullopt, Rectangle_opt dst = std::nullopt);

  ~Sprite() = default;

  auto render() -> void;

 private:
  Texture_ptr m_texture;
  Rectangle_opt m_src;
  Rectangle_opt m_dst;
};
}  // namespace hk::sdl

#endif
