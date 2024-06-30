#include "loader.h"

using namespace hk::sdl;

auto Loader::loadEvent(std::string_view name) -> Event_ptr {
  return Loader::loadGeneric<Event>(name);
}

auto Loader::loadSDL(std::string_view name) -> SDL_ptr {
  return Loader::loadGeneric<SDL>(name, Loader::sdl_flags);
}

auto Loader::loadWindow(std::string_view name, hk::Vector2i size,
                        u32 index) -> Window_ptr {
  return Loader::loadGeneric<Window>(name, size, Loader::window_position,
                                     Loader::window_flags, Loader::renderer,
                                     index);
}

auto Loader::loadIMG(std::string_view name) -> IMG_ptr {
  return Loader::loadGeneric<IMG>(name, Loader::img_flags);
}

auto Loader::loadTexture(std::string_view name,
                         Window_ptr window) -> Texture_ptr {
  return Loader::loadGeneric<Texture>(name, window, texture_sprite_tag);
}

auto Loader::loadTTF(std::string_view name) -> TTF_ptr {
  return Loader::loadGeneric<TTF>(name);
}

auto Loader::loadFont(std::string_view name, u32 font_size) -> Font_ptr {
  return Loader::loadGeneric<Font>(name, font_size);
}

auto Loader::pin(std::string_view name) -> void {
  Loader::pinned[name] = Loader::get(name);
}

auto Loader::pin(u64 id) -> void {
  auto ptr = Loader::get(id);
  Loader::pinned[ptr->name()] = ptr;
}

auto Loader::pin(Entity_ptr ptr) -> void { Loader::pinned[ptr->name()] = ptr; }

auto Loader::unpin(std::string_view name) -> void {
  Loader::pinned[name] = nullptr;
}

auto Loader::unpin(u64 id) -> void {
  auto name = Loader::get(id)->name();
  Loader::pinned.erase(name);
}

auto Loader::unpin(Entity_ptr ptr) -> void {
  Loader::pinned[ptr->name()] = nullptr;
}

auto Loader::get(std::string_view name) -> Entity_ptr {
  if (name == "stack") {
    throw std::runtime_error("Word reserved for stack variables.");
  }

  return Loader::global[name].lock();
}

auto Loader::get(u64 id) -> Entity_ptr {
  auto iter = std::ranges::find_if(Loader::global, [&](auto key_value) -> bool {
    auto& [key, value] = key_value;
    if (value.expired()) {
      return false;
    } else {
      return value.lock()->id() == id;
    }
  });

  if (iter == std::end(Loader::global)) {
    return nullptr;
  }

  auto& [_, ptr] = *iter;

  return ptr.lock();
}
