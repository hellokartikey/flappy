#ifndef SDL_WRAPPER_LOADER_H
#define SDL_WRAPPER_LOADER_H

#include <memory>

#include "entity.h"
#include "event.h"
#include "font.h"
#include "fwd.h"
#include "sdl.h"
#include "sdl_image.h"
#include "sdl_ttf.h"
#include "texture.h"
#include "window.h"

namespace hk::sdl {
class Loader {
 public:
  // Loaders
  template <typename T, typename... Args>
  static auto loadGeneric(std::string_view name,
                          Args... args) -> std::shared_ptr<T> {
    if (Loader::get(name) == nullptr) {
      auto ptr = std::shared_ptr<T>{new T(name, args...)};
      Loader::global[name] = ptr;
      return ptr;
    }

    return std::static_pointer_cast<T>(Loader::get(name));
  }

  static auto loadEvent(std::string_view name = "Event") -> Event_ptr;

  static auto loadSDL(std::string_view name = "SDL") -> SDL_ptr;

  static auto loadWindow(std::string_view name, hk::Vector2i size,
                         u32 index = 1) -> Window_ptr;

  static auto loadIMG(std::string_view name = "IMG") -> IMG_ptr;

  static auto loadTexture(std::string_view name,
                          Window_ptr window) -> Texture_ptr;

  static auto loadTTF(std::string_view name = "TTF") -> TTF_ptr;

  static auto loadFont(std::string_view name) -> Font_ptr;

  // Modifiers - NOT WORKING
  static auto pin(std::string_view name) -> void;
  static auto pin(u64 id) -> void;
  static auto pin(Entity_ptr ptr) -> void;

  static auto unpin(std::string_view name) -> void;
  static auto unpin(u64 id) -> void;
  static auto unpin(Entity_ptr ptr) -> void;

  // Access
  static auto get(std::string_view name) -> Entity_ptr;
  static auto get(u64 id) -> Entity_ptr;

 public:
  static std::unordered_map<std::string_view, Entity_weak_ptr> global;
  static std::unordered_map<std::string_view, Entity_ptr> pinned;

  static SDL::Flag sdl_flags;

  static IMG::Flag img_flags;

  static hk::Vector2i window_position;
  static Window::Flag window_flags;
  static Window::Renderer renderer;

  static u32 font_size;
};
}  // namespace hk::sdl

#endif
