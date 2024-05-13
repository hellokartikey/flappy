#include "global.h"


namespace hk::sdl {
auto getTicks() -> std::chrono::milliseconds {
  return std::chrono::milliseconds(SDL_GetTicks());
}
}
