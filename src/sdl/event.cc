#include "event.h"

#include "logger.h"

using namespace hk::sdl;

Event::Event(std::string_view name) : Entity(name) {
  hk::logger::ctor("({}) SDL_Event() successful.", Entity::id());
}

Event::~Event() {
  hk::logger::dtor("({}) ~SDL_Event() successful.", Entity::id());
}

auto Event::pollEvent() -> bool { return SDL_PollEvent(&m_event); }

auto Event::type() const -> Type { return static_cast<Type>(m_event.type); }
