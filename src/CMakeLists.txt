target_sources(
  flappy
  PRIVATE main.cc
  PRIVATE flappy.h PRIVATE flappy.cc
)

add_subdirectory(sdl)

target_link_libraries(
  flappy
  fmt::fmt
  sdl_wrapper
)
