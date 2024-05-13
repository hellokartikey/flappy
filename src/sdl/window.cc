#include "window.h"

#include "logger.h"
#include "math.h"

using namespace hk::sdl;

Window::Window(const std::string_view& title, hk::math::Vector2i size,
               hk::math::Vector2i pos, Flag flags) {
  m_window_ptr = SDL_CreateWindow(title.data(), pos.x(), pos.y(), size.x(),
                                  size.y(), flags);
  if (m_window_ptr == nullptr) {
    throw std::runtime_error(SDL_GetError());
  }

  hk::logger::ctor("SDL_CreateWindow() of size {}x{} successful.", size.x(),
                   size.y());
}

Window::Window(SDL_Window* window) : m_window_ptr(window) {
  hk::logger::ctor("Window::ctor(ptr) successful");
}

Window::~Window() {
  SDL_DestroyWindow(m_window_ptr);
  hk::logger::dtor("SDL_DestroyWindow() successful.");
}

auto Window::get() -> SDL_Window* { return m_window_ptr; }

Window::operator SDL_Window*() { return m_window_ptr; }
