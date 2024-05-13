#include "font.h"

#include "color.h"
#include "logger.h"
#include "surface.h"

using namespace hk::sdl;

Font::Font(const std::string_view& name, std::int32_t size)
    : m_name(name), m_size(size) {
  m_font = TTF_OpenFont(m_name.data(), m_size);

  if (m_font == nullptr) {
    throw std::runtime_error(TTF_GetError());
  }

  hk::logger::ctor("TTF_OpenFont() loaded {} at {}pt", name, size);
}

Font::Font(TTF_Font* font) : m_font(font) {
  hk::logger::ctor("Font::ctor(ptr) successful.");
}

Font::~Font() {
  TTF_CloseFont(m_font);
  hk::logger::dtor("TTF_CloseFont() closing {} successful.", m_name);
}

auto Font::get() -> TTF_Font* { return m_font; }

Font::operator TTF_Font*() { return m_font; }

auto Font::renderTextSolid(const std::string_view& text,
                           const Color& color) -> Surface {
  return Surface{TTF_RenderText_Solid(*this, text.data(), color)};
}
