#include <fmt/core.h>
#include <fmt/ostream.h>

#include "sdl/core.h"

using namespace hk::sdl;
using namespace hk::math;

auto main() -> int {
  SDL sdl(init::VIDEO);
  SDL_ttf ttf;

  Font font(RESOURCE "/fonts/Square.ttf", 24);

  Window window("[DEMO] Flappy Bird :)", {640, 480});
  Renderer renderer(window);

  Surface text = font.renderTextSolid("60fps", {0x00, 0x00, 0x00});
  Texture text_texture(renderer, text);

  Rectangle dst{0, 0, text.w(), text.h()};

  renderer.setDrawColor({0x7f, 0xff, 0x7f});

  SDL_Event event;
  bool quit = false;
  while (quit == false) {
    renderer.clear();

    // Begin rendering stuff
    renderer.copy(text_texture, std::nullopt, dst);
    // End rendering stuff

    renderer.present();

    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        quit = true;
      }
    }
  }

  return 0;
}
