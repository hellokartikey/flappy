#include "entity.h"

using namespace hk::sdl;

Entity::Entity(std::string_view name)
    : m_name(name), m_id(Entity::id_count++) {}

auto Entity::name() const -> std::string { return std::string{m_name}; }

auto Entity::id() const -> u64 { return m_id; }
