#ifndef SDL_WRAPPER_LOGGER_H
#define SDL_WRAPPER_LOGGER_H

#include <fmt/core.h>

#include <string_view>

namespace hk::logger {
template <typename... Args>
auto ctor(std::string_view message, Args... args) -> void {
  fmt::print("[ INFO ++ ] {}\n", fmt::format(fmt::runtime(message), args...));
}

template <typename... Args>
auto dtor(std::string_view message, Args... args) -> void {
  fmt::print("[ INFO -- ] {}\n", fmt::format(fmt::runtime(message), args...));
}
}  // namespace hk::logger

#endif
