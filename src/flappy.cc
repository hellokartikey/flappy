#include "flappy.h"

#include <fmt/core.h>

Flappy::Flappy(std::string_view name, hk::Vector2i size)
    : hk::Engine(name, size),
      m_sprite(hk::sdl::Loader::loadTexture("flappy.png", window())) {
  showFps();
  setFixedFps(60);
}

Flappy::~Flappy() {}

auto Flappy::eventsUpdate() -> void {}

auto Flappy::physicsUpdate() -> void {}

auto Flappy::renderUpdate() -> void {
  const auto background_color = hk::sdl::Color{0x7f, 0xff, 0x7f};
  window()->setDrawColor(background_color);

  auto dst = hk::sdl::Rectangle({0, 0}, m_sprite->size());
  m_sprite->copy(std::nullopt, dst);
}

auto Flappy::beginUpdate() -> void {}

auto Flappy::endUpdate() -> void {}
