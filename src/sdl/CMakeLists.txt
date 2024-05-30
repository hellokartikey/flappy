add_library(sdl_wrapper)

set_target_properties(sdl_wrapper PROPERTIES LINKER_LANGUAGE CXX)

target_sources(
  sdl_wrapper
  PRIVATE core.h
  PRIVATE fwd.h
  PRIVATE logger.h
  PRIVATE engine.h    PRIVATE engine.cc
  PRIVATE entity.h    PRIVATE entity.cc
  PRIVATE loader.h    PRIVATE loader.cc
  PRIVATE sdl.h       PRIVATE sdl.cc
  PRIVATE window.h    PRIVATE window.cc
  PRIVATE surface.h   PRIVATE surface.cc
  PRIVATE texture.h   PRIVATE texture.cc
  PRIVATE sdl_image.h PRIVATE sdl_image.cc
  PRIVATE sdl_ttf.h   PRIVATE sdl_ttf.cc
  PRIVATE font.h      PRIVATE font.cc
  PRIVATE sprite.h    PRIVATE sprite.cc
  PRIVATE global.h    PRIVATE global.cc
  PRIVATE color.h     PRIVATE color.cc
  PRIVATE rectangle.h PRIVATE rectangle.cc
  PRIVATE event.h     PRIVATE event.cc
  PRIVATE math.h
)

target_compile_definitions(
  sdl_wrapper
  PUBLIC RESOURCE="${RESOURCE}"
  PUBLIC FONT="${FONT}"
  PUBLIC SPRITE="${SPRITE}"
)

target_link_libraries(
  sdl_wrapper
  SDL2::SDL2
  SDL2_image::SDL2_image
  SDL2_ttf::SDL2_ttf
  fmt::fmt
)
