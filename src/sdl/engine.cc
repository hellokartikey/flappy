#include "engine.h"

using namespace hk::sdl;

Engine::Engine(std::string_view name, math::Vector2i size)
    : m_sdl(Loader::loadSDL()),
      m_img(Loader::loadIMG()),
      m_ttf(Loader::loadTTF()),
      m_quit(false),
      m_window(Loader::loadWindow(name, size)),
      m_fps_color({0x00, 0x00, 0x00}),
      m_fps_font(Loader::loadFont("Square.ttf")),
      m_fps_show(false),
      m_fps(0.0),
      m_event(Loader::loadEvent()) {}

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
    if (m_event->type() == Event::QUIT) {
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
  m_fps_start = getTicks();

  beginUpdate();
}

auto Engine::baseEndUpdate() -> void {
  setDeltaTime(getTicks() - m_fps_start);
  setFps(1.0 / f64(deltaTime().count()));

  endUpdate();
}

auto Engine::eventsUpdate() -> void {}

auto Engine::physicsUpdate() -> void {}

auto Engine::renderUpdate() -> void {}

auto Engine::beginUpdate() -> void {}

auto Engine::endUpdate() -> void {}

auto Engine::fps() const -> f64 { return m_fps; }

auto Engine::isFps() const -> bool { return m_fps_show; }

auto Engine::setFps(f64 fps) -> void { m_fps = fps; }

auto Engine::showFps() -> void { m_fps_show = true; }

auto Engine::hideFps() -> void { m_fps_show = false; }

auto Engine::renderFps() -> void {
  auto text =
      fpsFont()->renderTextSolid(fmt::format("{}fps", fps()), fpsColor());

  auto text_texture = Texture("stack", m_window, text, no_logging_tag);
  auto dst = Rectangle{0, 0, text.w(), text.h()};
  text_texture.copy(std::nullopt, dst);
}

auto Engine::fpsColor() const -> Color { return m_fps_color; }

auto Engine::setFpsColor(Color color) -> void { m_fps_color = color; }

auto Engine::fpsFont() -> Font_ptr { return m_fps_font; }

auto Engine::deltaTime() -> std::chrono::milliseconds { return m_delta_time; }

auto Engine::setDeltaTime(std::chrono::milliseconds dt) -> void {
  m_delta_time = dt;
}

auto Engine::window() -> Window_ptr { return m_window; }

auto Engine::isQuit() const -> bool { return m_quit; }

auto Engine::quit() -> void { m_quit = true; }
