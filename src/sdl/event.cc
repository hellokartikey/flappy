#include "event.h"

using namespace hk::sdl;

auto Event::pollEvent() -> bool { return SDL_PollEvent(&m_event); }

auto Event::type() const -> Type { return static_cast<Type>(m_event.type); }
