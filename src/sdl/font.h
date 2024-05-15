#ifndef SDL_WRAPPER_FONT_H
#define SDL_WRAPPER_FONT_H

#include <SDL2/SDL_ttf.h>

#include <cstdint>
#include <stdexcept>
#include <string>
#include <string_view>

#include "entity.h"
#include "fwd.h"

namespace hk::sdl {
const auto FONT_PREFIX = std::string{FONT};

class Font : public Entity {
 public:
  Font(std::string_view name, u32 size = 24);

  ~Font();

  auto getFilePath() const -> std::string;

  auto size() const -> u32;
  auto setSize(u32 size) -> void;

  auto get() -> TTF_Font*;

  operator TTF_Font*();

  auto renderTextSolid(std::string_view text, const Color& color) -> Surface;

 private:
  u32 m_size;
  TTF_Font* m_font;
};

using Font_ptr = std::shared_ptr<Font>;
}  // namespace hk::sdl

#endif
