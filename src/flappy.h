#ifndef FLAPPY_FLAPPY_H
#define FLAPPY_FLAPPY_H

#include "sdl/core.h"

using namespace hk::sdl;
using namespace hk::math;

class Flappy : public Engine {
 public:
  Flappy(std::string_view name, Vector2i size);
  ~Flappy();

  auto eventsUpdate() -> void override;
  auto physicsUpdate() -> void override;
  auto renderUpdate() -> void override;

  auto beginUpdate() -> void override;
  auto endUpdate() -> void override;

 private:
  Color m_background_color;
  Texture_ptr m_sprite;
};

#endif
