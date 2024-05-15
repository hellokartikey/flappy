#include "sdl.h"

#include "logger.h"

using namespace hk::sdl;

SDL::SDL(std::string_view name, Flag flags) : Entity(name) {
  if (SDL_Init(flags) != 0) {
    throw std::runtime_error(SDL_GetError());
  }

  hk::logger::ctor("({}) SDL_Init() successful.", Entity::id());
}

SDL::~SDL() {
  SDL_Quit();
  hk::logger::dtor("({}) SDL_Quit() successful.", Entity::id());
}
