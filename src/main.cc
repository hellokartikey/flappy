#include "flappy.h"

using namespace hk::sdl;
using namespace hk::math;

using namespace std::chrono_literals;

auto main() -> int {
  const auto window_size = Vector2i{640, 480};
  auto engine = Flappy("[DEMO] Flappy Bird :)", window_size);

  engine.showFps();
  engine.gameLoop();

  return 0;
}
