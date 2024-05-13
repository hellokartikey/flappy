#include <chrono>
#include <thread>

#include <fmt/core.h>
#include <fmt/ostream.h>

#include "sdl/core.h"

using namespace hk::sdl;
using namespace hk::math;

using namespace std::chrono_literals;

auto main() -> int {
  auto sdl = SDL(SDL::VIDEO);
  auto ttf = SDL_ttf();
  auto font = Font("Square.ttf", 24);
  auto window = Window("[DEMO] Flappy Bird :)", {640, 480});
  auto renderer = Renderer(window);
  auto event = Event{};

  auto fps = 0s;

  bool quit = false;
  while (quit == false) {
    auto start = getTicks();

    auto wait_time = std::chrono::system_clock::now() + 16ms;

    renderer.clear();

    // Begin rendering stuff
    auto text =
        font.renderTextSolid(fmt::format("{}fps", fps.count()), {0x00, 0x00, 0x00});
    auto text_texture = Texture(renderer, text);

    auto dst = Rectangle{0, 0, text.w(), text.h()};

    renderer.setDrawColor({0x7f, 0xff, 0x7f});

    renderer.copy(text_texture, std::nullopt, dst);
    // End rendering stuff

    renderer.present();

    while (event.pollEvent()) {
      if (event.type() == Event::QUIT) {
        quit = true;
      }
    }

    std::this_thread::sleep_until(wait_time);

    auto delta = getTicks() - start;
    fps = std::chrono::seconds(1s / delta);
  }

  return 0;
}
