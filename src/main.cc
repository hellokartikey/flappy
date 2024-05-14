#include <fmt/core.h>
#include <fmt/ostream.h>

#include <chrono>
#include <thread>

#include "sdl/core.h"

using namespace hk::sdl;
using namespace hk::math;

using namespace std::chrono_literals;

auto main() -> int {
  auto sdl = Loader::loadSDL();
  auto ttf = Loader::loadTTF();

  auto font = Loader::loadFont("Square.ttf");

  auto window = Loader::loadWindow("[DEMO] Flappy Bird :)", {640, 480});
  auto event = Event{};

  auto fps = 0s;

  bool quit = false;
  while (quit == false) {
    auto wait_time = std::chrono::system_clock::now() + 50ms;

    auto start = getTicks();

    window->clear();

    // Begin rendering stuff
    auto text = font->renderTextSolid(fmt::format("{}fps", fps.count()),
                                      {0x00, 0x00, 0x00});
    auto text_texture = Texture(*window, text, no_logging_tag);

    auto dst = Rectangle{0, 0, text.w(), text.h()};

    window->setDrawColor({0x7f, 0xff, 0x7f});

    window->copy(text_texture, std::nullopt, dst);
    // End rendering stuff

    window->present();

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
