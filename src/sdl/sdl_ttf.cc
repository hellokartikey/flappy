#include "sdl_ttf.h"

#include "logger.h"

using namespace hk::sdl;

TTF::TTF() : Entity("TTF") {
  if (TTF_Init()) {
    throw std::runtime_error(TTF_GetError());
  }

  hk::logger::ctor("TTF_Init() successful.");
}

TTF::~TTF() {
  TTF_Quit();

  hk::logger::dtor("TTF_Quit() successful.");
}
