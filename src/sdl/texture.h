#ifndef SDL_WRAPPER_TEXTURE_H
#define SDL_WRAPPER_TEXTURE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <memory>
#include <stdexcept>
#include <string>
#include <string_view>

#include "entity.h"
#include "fwd.h"
#include "math.h"
#include "rectangle.h"
#include "window.h"

namespace hk::sdl {
const auto SPRITE_PREFIX = std::string{SPRITE};

struct texture_sprite_tag_t {};
constexpr texture_sprite_tag_t texture_sprite_tag{};

class Texture : public Entity {
 public:
  Texture(std::string_view name, Window_ptr window, Surface& surface);
  Texture(std::string_view name, Window_ptr window, Surface& surface,
          no_logging_tag_t);

  Texture(std::string_view name, Window_ptr window, texture_sprite_tag_t);

  ~Texture();

  auto get() -> SDL_Texture*;

  operator SDL_Texture*();

  auto getFileName() const -> std::string;

  auto copy(Rectangle_opt src = std::nullopt,
            Rectangle_opt dst = std::nullopt) -> void;

  auto size() -> hk::Vector2i;

 private:
  Window_ptr m_window;
  SDL_Texture* m_texture;
  bool m_log;
};

using Texture_ptr = std::shared_ptr<Texture>;
}  // namespace hk::sdl

#endif
