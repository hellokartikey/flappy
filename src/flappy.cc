#include "flappy.h"

#include <fmt/core.h>

Flappy::Flappy(std::string_view name, Vector2i size)
    : Engine(name, size),
      m_sprite(Loader::loadTexture("flappy.png", window())) {}

Flappy::~Flappy() {}

auto Flappy::eventsUpdate() -> void {}

auto Flappy::physicsUpdate() -> void {}

auto Flappy::renderUpdate() -> void {
  const auto background_color = Color{0x7f, 0xff, 0x7f};
  m_window->setDrawColor(background_color);

  auto dst = Rectangle({0, 0}, m_sprite->size());
  m_sprite->copy(std::nullopt, dst);
}

auto Flappy::beginUpdate() -> void {}

auto Flappy::endUpdate() -> void {}
