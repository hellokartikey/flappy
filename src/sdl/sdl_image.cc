#include "sdl_image.h"

#include "logger.h"

using namespace hk::sdl;

IMG::IMG(std::string_view name, Flag flag) : Entity(name) {
  if (IMG_Init(flag) != flag) {
    throw std::runtime_error(IMG_GetError());
  }

  hk::logger::ctor("({}) IMG_Init() successful.", Entity::id());
}

IMG::~IMG() {
  IMG_Quit();

  hk::logger::dtor("({}) IMG_Quit() successful.", Entity::id());
}
