#ifndef SDL_WRAPPER_FWD_H
#define SDL_WRAPPER_FWD_H

#include <cstdint>

namespace hk::sdl {
class Engine;

struct no_logging_tag_t;

class Color;
class Rectangle;

class Entity;
class Loader;

class SDL;
class Window;
class Renderer;
class Surface;
class Texture;

class IMG;

class Event;

class TTF;
class Font;
}  // namespace hk::sdl

namespace hk {
using u8 = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;

using i8 = std::int8_t;
using i16 = std::int16_t;
using i32 = std::int32_t;
using i64 = std::int64_t;

using f32 = float;
using f64 = double;
}  // namespace hk

#endif
