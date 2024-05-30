#include "sprite.h"

using namespace hk::sdl;

Sprite::Sprite(std::string_view name, Texture_ptr texture, Rectangle_opt src,
               Rectangle_opt dst)
    : Entity(name), m_texture(texture), m_src(src), m_dst(dst) {}

auto Sprite::render() -> void { m_texture->copy(m_src, m_dst); }
