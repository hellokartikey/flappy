#include "loader.h"

#include "font.h"
#include "sdl.h"
#include "sdl_ttf.h"

using namespace hk::sdl;

auto Loader::global = std::unordered_map<std::string_view, weak_ptr>{};
auto Loader::pinned = std::unordered_map<std::string_view, shared_ptr>{};

auto Loader::loadSDL(SDL::Flag flags) -> SDL_ptr {
  if (Loader::global["SDL"].expired()) {
    auto ptr = SDL_ptr{new SDL(flags)};
    Loader::global[ptr->name()] = ptr;
    return ptr;
  }

  return std::static_pointer_cast<SDL>(Loader::global["SDL"].lock());
}

auto Loader::loadTTF() -> TTF_ptr {
  if (Loader::global["TTF"].expired()) {
    auto ptr = TTF_ptr{new TTF()};
    Loader::global[ptr->name()] = ptr;
    return ptr;
  }

  return std::static_pointer_cast<TTF>(Loader::global["TTF"].lock());
}

auto Loader::loadFont(std::string_view name) -> font_ptr {
  if (Loader::global[name].expired()) {
    auto ptr = font_ptr{new Font(name)};
    Loader::global[ptr->name()] = ptr;
    return ptr;
  }

  return std::static_pointer_cast<Font>(Loader::global[name].lock());
}
