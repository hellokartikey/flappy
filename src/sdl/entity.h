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
  virtual ~Entity() = default;

  auto name() const -> std::string;

  auto id() const -> u64;

 private:
  std::string_view m_name;
  u64 m_id;

  static inline u64 id_count = 0;
};

using Entity_ptr = std::shared_ptr<Entity>;
using Entity_weak_ptr = std::weak_ptr<Entity>;
}  // namespace hk::sdl

#endif
