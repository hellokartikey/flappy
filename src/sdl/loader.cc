#include "loader.h"

using namespace hk::sdl;

auto Loader::global = std::unordered_map<std::string_view, Entity_weak_ptr>{};
auto Loader::pinned = std::unordered_map<std::string_view, Entity_ptr>{};

auto Loader::sdl_flags = SDL::VIDEO;

auto Loader::window_position = Window::CENTERED;
auto Loader::window_flags = Window::SHOWN;
auto Loader::renderer = Window::ACCELERATED;

auto Loader::font_size = 24;

auto Loader::loadSDL(std::string_view name) -> SDL_ptr {
  return Loader::loadGeneric<SDL>(name, Loader::sdl_flags);
}

auto Loader::loadWindow(std::string_view name, hk::math::Vector2i size,
                        std::int32_t index) -> Window_ptr {
  return Loader::loadGeneric<Window>(name, size, Loader::window_position,
                                     Loader::window_flags, Loader::renderer,
                                     index);
}

auto Loader::loadTTF(std::string_view name) -> TTF_ptr { return Loader::loadGeneric<TTF>(name); }

auto Loader::loadFont(std::string_view name) -> Font_ptr {
  return Loader::loadGeneric<Font>(name, Loader::font_size);
}
