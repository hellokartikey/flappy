#ifndef SDL_WRAPPER_WINDOW_H
#define SDL_WRAPPER_WINDOW_H

#include <SDL2/SDL.h>

#include <cstdint>
#include <stdexcept>
#include <string_view>

#include "fwd.h"
#include "math.h"

namespace hk::sdl {
namespace windowpos {
constexpr hk::math::Vector2i CENTERED{SDL_WINDOWPOS_CENTERED,
                                      SDL_WINDOWPOS_CENTERED},
    UNDEFINED{SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED};
}

namespace window {
constexpr std::uint32_t FULLSCREEN = SDL_WINDOW_FULLSCREEN,
                        FULLSCREEN_DESKTOP = SDL_WINDOW_FULLSCREEN_DESKTOP,
                        OPENGL = SDL_WINDOW_OPENGL, VULKAN = SDL_WINDOW_VULKAN,
                        METAL = SDL_WINDOW_METAL, HIDDEN = SDL_WINDOW_HIDDEN,
                        BORDERLESS = SDL_WINDOW_BORDERLESS,
                        RESIZABLE = SDL_WINDOW_RESIZABLE,
                        MINIMIZED = SDL_WINDOW_MINIMIZED,
                        MAXIMIZED = SDL_WINDOW_MAXIMIZED,
                        MOUSE_GRABBED = SDL_WINDOW_MOUSE_GRABBED,
                        ALLOW_HIGHDPI = SDL_WINDOW_ALLOW_HIGHDPI,
                        SHOWN = SDL_WINDOW_SHOWN;
}

class Window {
 public:
  Window(const std::string_view& title, hk::math::Vector2i size,
         hk::math::Vector2i pos = windowpos::CENTERED,
         std::uint32_t flags = window::SHOWN);

  Window(SDL_Window* window);

  ~Window();

  auto get() -> SDL_Window*;

  operator SDL_Window*();

 private:
  SDL_Window* m_window_ptr = nullptr;
};
}  // namespace hk::sdl

#endif
