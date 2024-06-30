#include "flappy.h"

#include <fmt/core.h>

Flappy::Flappy(std::string_view name, hk::Vector2i size)
    : hk::Engine(name, size),
      m_sprite("full", hk::sdl::Loader::loadTexture("flappy.png", window()),
               hk::sdl::Rectangle{{110, 280}, {50, 50}}, hk::Vector2i{50, 50}) {
  showFps();

  m_background_color = hk::sdl::Color{0x7f, 0xff, 0x7f};
  window()->setDrawColor(m_background_color);
}

Flappy::~Flappy() { fmt::print("Good bye! :D\n"); }

auto Flappy::eventsUpdate() -> void {}

auto Flappy::physicsUpdate() -> void {}

auto Flappy::renderUpdate() -> void { m_sprite.render(); }

auto Flappy::beginUpdate() -> void {}

auto Flappy::endUpdate() -> void {}
