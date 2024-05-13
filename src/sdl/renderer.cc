#include "renderer.h"

#include "color.h"
#include "rectangle.h"
#include "surface.h"
#include "texture.h"
#include "logger.h"
#include "window.h"

using namespace hk::sdl;

Renderer::Renderer(Window& window, std::int32_t index, std::uint32_t flags) {
  m_renderer = SDL_CreateRenderer(window.get(), index, flags);

  if (m_renderer == nullptr) {
    throw std::runtime_error(SDL_GetError());
  }

  hk::logger::ctor("SDL_CreateRenderer() with index = {} successful.", index);
}

Renderer::Renderer(SDL_Renderer* renderer) : m_renderer(renderer) {
  hk::logger::ctor("Renderer::ctor(ptr) successful.");
}

Renderer::~Renderer() {
  SDL_DestroyRenderer(m_renderer);
  hk::logger::dtor("SDL_DestroyRenderer() successful.");
}

auto Renderer::get() -> SDL_Renderer* { return m_renderer; }

Renderer::operator SDL_Renderer*() { return m_renderer; }

auto Renderer::present() -> void { SDL_RenderPresent(m_renderer); }

auto Renderer::clear() -> void {
  if (SDL_RenderClear(m_renderer)) {
    throw std::runtime_error(SDL_GetError());
  }
}

auto Renderer::setDrawColor(const Color& color) -> void {
  if (SDL_SetRenderDrawColor(m_renderer, color.r(), color.g(), color.b(),
                             color.a())) {
    throw std::runtime_error(SDL_GetError());
  }
}

auto Renderer::copy(Texture& texture, Rectangle_opt src,
                    Rectangle_opt dst) -> void {
  if (SDL_RenderCopy(m_renderer, texture.get(), src ? (*src).get() : nullptr,
                     dst ? (*dst).get() : nullptr)) {
    throw std::runtime_error(SDL_GetError());
  }
}
