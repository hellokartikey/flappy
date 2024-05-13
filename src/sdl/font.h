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
const std::string FONT_PREFIX{FONT};

class Font : public Entity {
 public:
  Font(const std::string_view& name);

  ~Font();

  auto getFilePath() const -> std::string;

  auto size() const -> std::int32_t;
  auto setSize(std::int32_t size) -> void;

  auto get() -> TTF_Font*;

  operator TTF_Font*();

  auto renderTextSolid(const std::string_view& text,
                       const Color& color) -> Surface;

 private:
  std::string_view m_name;
  std::int32_t m_size;
  TTF_Font* m_font;
};
}  // namespace hk::sdl

#endif
