#include "TextureCache.h"
#include <iostream>

namespace engine {

const sdl2wrap::Texture& TextureCache::load(const sdl2wrap::Renderer& renderer,
                                            const TexturePath& texturePath)
{
    if (isCached(texturePath)) {
        return *(textureMap_.at(texturePath));
    }

    UniqueTexture texture = std::make_unique<sdl2wrap::Texture>(renderer, texturePath);
    return *(textureMap_.emplace(texturePath, std::move(texture)).first->second);
}

bool TextureCache::isCached(const TexturePath& texturePath) const
{
    return textureMap_.find(texturePath) != textureMap_.end();
}

}