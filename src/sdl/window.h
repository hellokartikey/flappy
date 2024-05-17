#ifndef SDL_WRAPPER_WINDOW_H
#define SDL_WRAPPER_WINDOW_H

#include <SDL2/SDL.h>

#include <cstdint>
#include <memory>
#include <stdexcept>
#include <string_view>

#include "entity.h"
#include "fwd.h"
#include "math.h"
#include "rectangle.h"

namespace hk::sdl {
class Window : public Entity {
 public:
  static constexpr hk::Vector2i CENTERED{SDL_WINDOWPOS_CENTERED,
                                         SDL_WINDOWPOS_CENTERED};
  static constexpr hk::Vector2i UNDEFINED{SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED};

  enum Flag {
    FULLSCREEN = SDL_WINDOW_FULLSCREEN,
    FULLSCREEN_DESKTOP = SDL_WINDOW_FULLSCREEN_DESKTOP,
    OPENGL = SDL_WINDOW_OPENGL,
    VULKAN = SDL_WINDOW_VULKAN,
    METAL = SDL_WINDOW_METAL,
    HIDDEN = SDL_WINDOW_HIDDEN,
    BORDERLESS = SDL_WINDOW_BORDERLESS,
    RESIZABLE = SDL_WINDOW_RESIZABLE,
    MINIMIZED = SDL_WINDOW_MINIMIZED,
    MAXIMIZED = SDL_WINDOW_MAXIMIZED,
    MOUSE_GRABBED = SDL_WINDOW_MOUSE_GRABBED,
    ALLOW_HIGHDPI = SDL_WINDOW_ALLOW_HIGHDPI,
    SHOWN = SDL_WINDOW_SHOWN
  };

  enum Renderer {
    SOFTWARE = SDL_RENDERER_SOFTWARE,
    ACCELERATED = SDL_RENDERER_ACCELERATED,
    PRESENTVSYNC = SDL_RENDERER_PRESENTVSYNC,
    TARGETTEXTURE = SDL_RENDERER_TARGETTEXTURE
  };

  Window(std::string_view name, hk::Vector2i size, hk::Vector2i pos = CENTERED,
         Flag flags = SHOWN, Renderer renderer = ACCELERATED, u32 index = 1);

  ~Window();

  auto get() -> SDL_Window*;
  auto getr() -> SDL_Renderer*;

  operator SDL_Window*();
  operator SDL_Renderer*();

  auto present() -> void;

  auto clear() -> void;

  auto setDrawColor(const Color& color) -> void;

 private:
  SDL_Window* m_window;
  SDL_Renderer* m_renderer;
};

using Window_ptr = std::shared_ptr<Window>;
}  // namespace hk::sdl

#endif
