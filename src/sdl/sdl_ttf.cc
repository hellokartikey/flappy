#include "sdl_ttf.h"

#include "logger.h"

using namespace hk::sdl;

TTF::TTF(std::string_view name) : Entity(name) {
  if (TTF_Init()) {
    throw std::runtime_error(TTF_GetError());
  }

  hk::logger::ctor("({}) TTF_Init() successful.", Entity::id());
}

TTF::~TTF() {
  TTF_Quit();

  hk::logger::dtor("({}) TTF_Quit() successful.", Entity::id());
}
