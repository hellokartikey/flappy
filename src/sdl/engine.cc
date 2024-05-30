#include "engine.h"

#include <chrono>
#include <thread>

using namespace hk;

using std::chrono::duration_cast;

Engine::Engine(std::string_view name, hk::Vector2i size)
    : m_sdl(sdl::Loader::loadSDL()),
      m_img(sdl::Loader::loadIMG()),
      m_ttf(sdl::Loader::loadTTF()),
      m_quit(false),
      m_window(sdl::Loader::loadWindow(name, size)),
      m_fps_color({0x00, 0x00, 0x00}),
      m_fps_font(sdl::Loader::loadFont("Square.ttf")),
      m_fps_show(false),
      m_fps(0),
      m_fps_fixed(0),
      m_fixed_delta_time(0),
      m_delta_time(0),
      m_event(sdl::Loader::loadEvent()) {}

Engine::~Engine() {}

auto Engine::eventLoop() -> bool {
  baseBeginUpdate();

  baseEventsUpdate();
  basePhysicsUpdate();
  baseRenderUpdate();

  baseEndUpdate();

  return m_quit;
}

auto Engine::gameLoop() -> void { while (!eventLoop()); }

auto Engine::baseEventsUpdate() -> void {
  while (m_event->pollEvent()) {
    if (m_event->type() == sdl::Event::QUIT) {
      m_quit = true;
    }

    eventsUpdate();
  }
}

auto Engine::basePhysicsUpdate() -> void { physicsUpdate(); }

auto Engine::baseRenderUpdate() -> void {
  m_window->clear();

  renderUpdate();

  if (isFps()) {
    renderFps();
  }

  m_window->present();
}

auto Engine::baseBeginUpdate() -> void {
  m_fps_start = clock::now();

  if (isFixedFps()) {
    m_wait_time = m_fps_start +
                  duration_cast<std::chrono::milliseconds>(fixedDeltaTime());
  }

  beginUpdate();
}

auto Engine::baseEndUpdate() -> void {
  if (isFixedFps()) {
    std::this_thread::sleep_until(m_wait_time);
  }

  auto delta = clock::now() - m_fps_start;
  setDeltaTime(duration_cast<milliseconds>(delta));

  setFps(seconds{1} / deltaTime());

  endUpdate();
}

auto Engine::eventsUpdate() -> void {}

auto Engine::physicsUpdate() -> void {}

auto Engine::renderUpdate() -> void {}

auto Engine::beginUpdate() -> void {}

auto Engine::endUpdate() -> void {}

auto Engine::fps() const -> u32 { return m_fps; }

auto Engine::isFps() const -> bool { return m_fps_show; }

auto Engine::setFps(u32 fps) -> void { m_fps = fps; }

auto Engine::showFps() -> void { m_fps_show = true; }

auto Engine::hideFps() -> void { m_fps_show = false; }

auto Engine::renderFps() -> void {
  auto text = fpsFont()->renderTextSolid(fmt::format("{}", fps()), fpsColor());

  auto text_texture =
      sdl::Texture("stack", m_window, text, sdl::no_logging_tag);
  auto dst = sdl::Rectangle{0, 0, text.w(), text.h()};
  text_texture.copy(std::nullopt, dst);
}

auto Engine::fpsColor() const -> sdl::Color { return m_fps_color; }

auto Engine::setFpsColor(sdl::Color color) -> void { m_fps_color = color; }

auto Engine::fpsFont() -> sdl::Font_ptr { return m_fps_font; }

auto Engine::fixedFps() const -> u32 { return m_fps_fixed; }

auto Engine::setFixedFps(u32 fps) -> void {
  m_fps_fixed = fps;
  if (m_fps_fixed) {
    m_fixed_delta_time = milliseconds{1000} / fixedFps();
  } else {
    m_fixed_delta_time = milliseconds{0};
  }
}

auto Engine::isFixedFps() -> bool { return m_fps_fixed != 0; }

auto Engine::deltaTime() -> milliseconds { return m_delta_time; }

auto Engine::setDeltaTime(milliseconds dt) -> void { m_delta_time = dt; }

auto Engine::fixedDeltaTime() -> milliseconds { return m_fixed_delta_time; }

auto Engine::window() -> sdl::Window_ptr { return m_window; }

auto Engine::event() -> sdl::Event_ptr { return m_event; }

auto Engine::isQuit() const -> bool { return m_quit; }

auto Engine::quit() -> void { m_quit = true; }
