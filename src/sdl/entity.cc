#include "entity.h"

using namespace hk::sdl;

Entity::Entity(std::string_view name) : m_name(name) {}

auto Entity::name() const -> std::string { return std::string{m_name}; }
