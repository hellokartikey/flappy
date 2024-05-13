add_library(sdl_wrapper)

set_target_properties(sdl_wrapper PROPERTIES LINKER_LANGUAGE CXX)

target_sources(
  sdl_wrapper
  PRIVATE core.h
  PRIVATE fwd.h
  PRIVATE logger.h
  PRIVATE sdl.h       PRIVATE sdl.cc
  PRIVATE renderer.h  PRIVATE renderer.cc
  PRIVATE window.h    PRIVATE window.cc
  PRIVATE surface.h   PRIVATE surface.cc
  PRIVATE texture.h   PRIVATE texture.cc
  PRIVATE sdl_ttf.h   PRIVATE sdl_ttf.cc
  PRIVATE font.h      PRIVATE font.cc
  PRIVATE color.h     PRIVATE color.cc
  PRIVATE rectangle.h PRIVATE rectangle.cc
  PRIVATE math.h
)

target_link_libraries(
  sdl_wrapper
  SDL2::SDL2
  SDL2_image::SDL2_image
  SDL2_ttf::SDL2_ttf
  fmt::fmt
)
