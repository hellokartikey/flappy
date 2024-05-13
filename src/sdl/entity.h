#ifndef SDL_WRAPPER_ENTITY_H
#define SDL_WRAPPER_ENTITY_H

#include <memory>
#include <string>
#include <string_view>
#include <unordered_map>

#include "fwd.h"

namespace hk::sdl {
class Entity {
 public:
  explicit Entity(std::string_view name);
  ~Entity() = default;

  auto name() const -> std::string;

 private:
  std::string_view m_name;
};
}  // namespace hk::sdl

#endif
