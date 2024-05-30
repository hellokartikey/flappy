#ifndef FLAPPY_FLAPPY_H
#define FLAPPY_FLAPPY_H

#include "sdl/core.h"

class Flappy : public hk::Engine {
 public:
  Flappy(std::string_view name, hk::Vector2i size);
  ~Flappy();

  auto eventsUpdate() -> void override;
  auto physicsUpdate() -> void override;
  auto renderUpdate() -> void override;

  auto beginUpdate() -> void override;
  auto endUpdate() -> void override;

 private:
  hk::sdl::Color m_background_color;
  hk::sdl::Sprite m_sprite;
};

#endif
