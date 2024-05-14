#ifndef SDL_WRAPPER_LOADER_H
#define SDL_WRAPPER_LOADER_H

#include <memory>

#include "fwd.h"
#include "entity.h"
#include "font.h"
#include "sdl.h"
#include "sdl_ttf.h"
#include "window.h"

namespace hk::sdl {
class Loader {
 public:
  // Loaders
  template <typename T, typename... Args>
  static auto loadGeneric(std::string_view name,
                          Args... args) -> std::shared_ptr<T> {
    if (Loader::global[name].expired()) {
      auto ptr = std::shared_ptr<T>{new T(name, args...)};
      Loader::global[name] = ptr;
      return ptr;
    }

    return std::static_pointer_cast<T>(Loader::global[name].lock());
  }

  static auto loadSDL(std::string_view name = "SDL") -> SDL_ptr;

  static auto loadWindow(std::string_view name, hk::math::Vector2i size,
                         std::int32_t index = -1) -> Window_ptr;

  static auto loadTTF(std::string_view name = "TTF") -> TTF_ptr;

  static auto loadFont(std::string_view name) -> Font_ptr;

  // Modifiers
  static auto pin(std::string_view name) -> void;
  static auto unpin(std::string_view name) -> void;

 private:
  static std::unordered_map<std::string_view, Entity_weak_ptr> global;
  static std::unordered_map<std::string_view, Entity_ptr> pinned;

  static SDL::Flag sdl_flags;

  static hk::math::Vector2i window_position;
  static Window::Flag window_flags;
  static Window::Renderer renderer;

  static std::int32_t font_size;
};
}  // namespace hk::sdl

#endif
