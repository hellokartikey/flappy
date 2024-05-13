#include <fmt/core.h>
#include <fmt/ostream.h>

#include "sdl/core.h"

using namespace hk::sdl;
using namespace hk::math;

auto main() -> int {
  auto sdl = SDL(SDL::VIDEO);
  auto ttf = SDL_ttf();

  auto font = Font(FONT "Square.ttf", 24);

  auto window = Window("[DEMO] Flappy Bird :)", {640, 480});
  auto renderer = Renderer(window);

  auto text = font.renderTextSolid("60fps", {0x00, 0x00, 0x00});
  auto text_texture = Texture(renderer, text);

  auto dst = Rectangle{0, 0, text.w(), text.h()};

  renderer.setDrawColor({0x7f, 0xff, 0x7f});

  auto event = Event{};

  bool quit = false;
  while (quit == false) {
    renderer.clear();

    // Begin rendering stuff
    renderer.copy(text_texture, std::nullopt, dst);
    // End rendering stuff

    renderer.present();

    while (event.pollEvent()) {
      if (event.type() == Event::QUIT) {
        quit = true;
      }
    }
  }

  return 0;
}
