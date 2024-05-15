#ifndef SDL_WRAPPER_ENGINE_H
#define SDL_WRAPPER_ENGINE_H

#include <chrono>
#include <ratio>

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

namespace hk::sdl {
class Engine {
 public:
  Engine(std::string_view name, math::Vector2i size);
  ~Engine();

  auto eventLoop() -> bool;

  auto gameLoop() -> void;

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

  auto fps() const -> f64;
  auto isFps() const -> bool;
  auto showFps() -> void;
  auto hideFps() -> void;

  auto renderFps() -> void;

  auto fpsColor() const -> Color;
  auto setFpsColor(Color color) -> void;

  auto fpsFont() -> Font_ptr;

  auto deltaTime() -> std::chrono::milliseconds;

  auto window() -> Window_ptr;

  auto isQuit() const -> bool;
  auto quit() -> void;

 private:
  auto setFps(f64 fps) -> void;
  auto setDeltaTime(std::chrono::milliseconds dt) -> void;

 protected:
  SDL_ptr m_sdl;
  IMG_ptr m_img;
  TTF_ptr m_ttf;

  bool m_quit;

  Window_ptr m_window;

  bool m_fps_show;
  Font_ptr m_fps_font;
  Color m_fps_color;
  f64 m_fps;
  std::chrono::milliseconds m_fps_start, m_delta_time;

  Event_ptr m_event;
};
}  // namespace hk::sdl

#endif
