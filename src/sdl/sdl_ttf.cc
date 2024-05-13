#include "sdl_ttf.h"

#include "logger.h"

using namespace hk::sdl;

SDL_ttf::SDL_ttf() {
  if (TTF_Init()) {
    throw std::runtime_error(TTF_GetError());
  }

  hk::logger::ctor("TTF_Init() successful.");
}

SDL_ttf::~SDL_ttf() {
  TTF_Quit();

  hk::logger::dtor("TTF_Quit() successful.");
}
