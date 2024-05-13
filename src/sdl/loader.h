#ifndef SDL_WRAPPER_LOADER_H
#define SDL_WRAPPER_LOADER_H

#include <memory>

#include "fwd.h"
#include "sdl.h"

namespace hk::sdl {
class Loader {
 public:
  using weak_ptr = std::weak_ptr<Entity>;
  using shared_ptr = std::shared_ptr<Entity>;

  using SDL_ptr = std::shared_ptr<SDL>;

  using TTF_ptr = std::shared_ptr<TTF>;
  using font_ptr = std::shared_ptr<Font>;

  // Loaders
  template <typename T>
  static auto loadGeneric(std::string_view name) -> std::shared_ptr<T> {
    if (Loader::global["SDL"].expired()) {
      auto ptr = std::shared_ptr<Entity>{new T(name)};
      Loader::global[ptr->name()] = ptr;
      return ptr;
    }

    return std::static_pointer_cast<T>(Loader::global[name].lock());
  }

  static auto loadSDL(SDL::Flag flags) -> SDL_ptr;

  static auto loadTTF() -> TTF_ptr;
  static auto loadFont(std::string_view name) -> font_ptr;

  // Modifiers
  static auto pin(std::string_view name) -> void;
  static auto unpin(std::string_view name) -> void;

  static std::unordered_map<std::string_view, weak_ptr> global;
  static std::unordered_map<std::string_view, shared_ptr> pinned;
};
}  // namespace hk::sdl

#endif
