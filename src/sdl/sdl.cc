#include "sdl.h"

#include "logger.h"

using namespace hk::sdl;

SDL::SDL(std::uint32_t flags) {
  if (SDL_Init(flags) != 0) {
    throw std::runtime_error(SDL_GetError());
  }

  hk::logger::ctor("SDL_Init() successful.");
}

SDL::~SDL() {
  SDL_Quit();
  hk::logger::dtor("SDL_Quit() successful.");
}
