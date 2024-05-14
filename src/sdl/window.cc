#include "window.h"

#include "color.h"
#include "logger.h"
#include "math.h"
#include "rectangle.h"
#include "surface.h"
#include "texture.h"

using namespace hk::sdl;

Window::Window(std::string_view name, hk::math::Vector2i size,
               hk::math::Vector2i pos, Flag flags, Renderer renderer,
               std::int32_t index)
    : Entity(name) {
  m_window = SDL_CreateWindow(name.data(), pos.x(), pos.y(), size.x(), size.y(),
                              flags);
  if (m_window == nullptr) {
    throw std::runtime_error(SDL_GetError());
  }

  m_renderer = SDL_CreateRenderer(m_window, index, renderer);

  if (m_renderer == nullptr) {
    throw std::runtime_error(SDL_GetError());
  }

  hk::logger::ctor("SDL_CreateWindow() of size {}x{} successful.", size.x(),
                   size.y());

  hk::logger::ctor("SDL_CreateRenderer() with index = {} successful.", index);
}

Window::~Window() {
  SDL_DestroyRenderer(m_renderer);
  hk::logger::dtor("SDL_DestroyRenderer() successful.");

  SDL_DestroyWindow(m_window);
  hk::logger::dtor("SDL_DestroyWindow() successful.");
}

auto Window::get() -> SDL_Window* { return m_window; }

Window::operator SDL_Window*() { return m_window; }

Window::operator SDL_Renderer*() { return m_renderer; }

auto Window::present() -> void { SDL_RenderPresent(m_renderer); }

auto Window::clear() -> void {
  if (SDL_RenderClear(m_renderer)) {
    throw std::runtime_error(SDL_GetError());
  }
}

auto Window::setDrawColor(const Color& color) -> void {
  if (SDL_SetRenderDrawColor(m_renderer, color.r(), color.g(), color.b(),
                             color.a())) {
    throw std::runtime_error(SDL_GetError());
  }
}

auto Window::copy(Texture& texture, Rectangle_opt src,
                  Rectangle_opt dst) -> void {
  if (SDL_RenderCopy(m_renderer, texture.get(), src ? (*src).get() : nullptr,
                     dst ? (*dst).get() : nullptr)) {
    throw std::runtime_error(SDL_GetError());
  }
}
