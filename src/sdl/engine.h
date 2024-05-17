#ifndef SDL_WRAPPER_ENGINE_H
#define SDL_WRAPPER_ENGINE_H

#include <chrono>
#include <thread>

#include "color.h"
#include "font.h"
#include "fwd.h"
#include "global.h"
#include "loader.h"
#include "math.h"
#include "rectangle.h"
#include "sdl.h"
#include "sdl_image.h"
#include "sdl_ttf.h"
#include "surface.h"
#include "window.h"

namespace hk {
class Engine {
 protected:
  using milliseconds = std::chrono::duration<f32, std::milli>;
  using seconds = std::chrono::duration<f32>;
  using clock = std::chrono::high_resolution_clock;
  using time_point = std::chrono::time_point<clock>;

 public:
  auto gameLoop() -> void;

 protected:
  Engine(std::string_view name, hk::Vector2i size);
  ~Engine();

  auto eventLoop() -> bool;

  auto baseEventsUpdate() -> void;
  auto basePhysicsUpdate() -> void;
  auto baseRenderUpdate() -> void;

  auto baseBeginUpdate() -> void;
  auto baseEndUpdate() -> void;

  virtual auto eventsUpdate() -> void;
  virtual auto physicsUpdate() -> void;
  virtual auto renderUpdate() -> void;

  virtual auto beginUpdate() -> void;
  virtual auto endUpdate() -> void;

  auto fps() const -> u32;
  auto isFps() const -> bool;
  auto showFps() -> void;
  auto hideFps() -> void;

  auto fixedFps() const -> u32;
  auto setFixedFps(u32 fps) -> void;

  auto renderFps() -> void;

  auto fpsColor() const -> sdl::Color;
  auto setFpsColor(sdl::Color color) -> void;

  auto fpsFont() -> sdl::Font_ptr;

  auto deltaTime() -> milliseconds;

  auto fixedDeltaTime() -> milliseconds;

  auto window() -> sdl::Window_ptr;

  auto event() -> sdl::Event_ptr;

  auto isQuit() const -> bool;
  auto quit() -> void;

 private:
  auto setFps(u32 fps) -> void;
  auto setDeltaTime(milliseconds dt) -> void;

  sdl::SDL_ptr m_sdl;
  sdl::IMG_ptr m_img;
  sdl::TTF_ptr m_ttf;

  bool m_quit;

  sdl::Window_ptr m_window;

  bool m_fps_show;
  sdl::Font_ptr m_fps_font;
  sdl::Color m_fps_color;
  u32 m_fps;
  u32 m_fps_fixed;
  time_point m_fps_start;
  time_point m_wait_time;
  milliseconds m_fixed_delta_time;
  milliseconds m_delta_time;

  sdl::Event_ptr m_event;
};
}  // namespace hk

#endif
