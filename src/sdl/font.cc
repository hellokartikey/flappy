#include "font.h"

#include <array>

#include "color.h"
#include "global.h"
#include "logger.h"
#include "surface.h"

using namespace hk::sdl;

Font::Font(std::string_view name, std::int32_t size) : m_name(name), m_size(size), Entity(name) {
  m_font = TTF_OpenFont(getFilePath().data(), m_size);

  if (m_font == nullptr) {
    throw std::runtime_error(TTF_GetError());
  }

  hk::logger::ctor("TTF_OpenFont() loaded {} at {}pt", name, m_size);
}

Font::~Font() {
  TTF_CloseFont(m_font);
  hk::logger::dtor("TTF_CloseFont() closing {} successful.", m_name);
}

auto Font::getFilePath() const -> std::string {
  return FONT_PREFIX + std::string(m_name);
}

auto Font::size() const -> std::int32_t { return m_size; }

auto Font::setSize(std::int32_t size) -> void {
  m_size = size;
  TTF_SetFontSize(m_font, m_size);
}

auto Font::get() -> TTF_Font* { return m_font; }

Font::operator TTF_Font*() { return m_font; }

auto Font::renderTextSolid(std::string_view text,
                           const Color& color) -> Surface {
  return Surface{TTF_RenderText_Solid(*this, text.data(), color),
                 no_logging_tag};
}
