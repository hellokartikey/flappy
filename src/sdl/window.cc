#include "window.h"

#include "color.h"
#include "logger.h"
#include "math.h"
#include "rectangle.h"
#include "surface.h"
#include "texture.h"

using namespace hk::sdl;

Window::Window(std::string_view name, hk::Vector2i size, hk::Vector2i pos,
               Flag flags, Renderer renderer, u32 index)
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

  hk::logger::ctor("({}) SDL_CreateWindow({}x{}) successful.", Entity::id(),
                   size.x(), size.y());

  hk::logger::ctor("({}) SDL_CreateRenderer(idx={}) successful.", Entity::id(),
                   index);
}

Window::~Window() {
  SDL_DestroyRenderer(m_renderer);
  hk::logger::dtor("({}) SDL_DestroyRenderer() successful.", Entity::id());

  SDL_DestroyWindow(m_window);
  hk::logger::dtor("({}) SDL_DestroyWindow() successful.", Entity::id());
}

auto Window::get() -> SDL_Window* { return m_window; }

auto Window::getr() -> SDL_Renderer* { return m_renderer; }

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
