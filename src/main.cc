#include <fmt/format.h>
#include <fmt/std.h>

#include "flappy.h"
#include "sdl/core.h"

using namespace std::chrono_literals;

auto main() -> int {
  const auto window_size = hk::Vector2i{640, 480};
  auto engine = Flappy("[DEMO] Flappy Bird :)", window_size);

  engine.gameLoop();

  return 0;
}
