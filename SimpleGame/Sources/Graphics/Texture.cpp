#include "Texture.h"

#include "Sprite.h"

Texture::Texture(std::string path, nlohmann::json &config, uint32_t firstSpriteID) {
    this->firstSpriteID = firstSpriteID;
    texture.loadFromFile(path);

    sizeOfTile = config["tileSize"];
    numOfTiles = texture.getSize() / sizeOfTile;

    std::string title; // Can be same for few sequential sprites
	uint32_t firstFrame = 0;
    for (auto sprite_config : config["sprites"]) {
        SpriteInfo spriteInfo;

        // Sprite title
        auto iter = sprite_config.find("sprite");
        if (iter != sprite_config.end()) {
            title = iter->get<std::string>();
        }
        spriteInfo.title = title;

        // Frames
        iter = sprite_config.find("frames");
        if (iter != sprite_config.end()) spriteInfo.frames = iter->get<int>();
        else spriteInfo.frames = 1;

        // Frame Time
        iter = sprite_config.find("frame_time");
        if (iter != sprite_config.end()) spriteInfo.frameTime = sf::seconds(iter->get<float>());
        else {
            iter = sprite_config.find("loop_time");
            if (iter != sprite_config.end())
                spriteInfo.frameTime = sf::seconds(iter->get<float>() / spriteInfo.frames);
            else
                spriteInfo.frameTime = sf::seconds(0.1f);
        }

        // Directed
        iter = sprite_config.find("directed");
        if (iter != sprite_config.end()) spriteInfo.directed = iter->get<bool>();
        else spriteInfo.directed = false;

        spriteInfo.firstFrame = firstFrame;

        firstFrame += spriteInfo.frames * (int(spriteInfo.directed) * 3 + 1);
        spritesInfo.push_back(std::move(spriteInfo));
    }
}

bool Texture::IsFramePixelTransparent(uf::vec2u pixel, uint32_t frame) const {
    uf::vec2u texturePixel = pixel;

    texturePixel.x += frame % numOfTiles.x * sizeOfTile;
    texturePixel.y += frame / numOfTiles.x * sizeOfTile;

    if (texturePixel >= uf::vec2i(0, 0) && texturePixel < texture.getSize()) {
        if (texture.copyToImage().getPixel(texturePixel.x, texturePixel.y).a == 0) return true;
        return false;
    }

    return true;
}

//const std::vector<Sprite *> &Texture::GetSprites() const { return sprites; }

Sprite Texture::GetSprite(uint32_t id) const {
    id -= firstSpriteID;
    if (id >= 0 && id < firstSpriteID + spritesInfo.size()) {
        Sprite sprite;
        sprite.texture = this;
        sprite.key = spritesInfo[id].title;
        sprite.firstFrame = spritesInfo[id].firstFrame;
        sprite.frames = spritesInfo[id].frames;
        sprite.frameTime = spritesInfo[id].frameTime;
        sprite.directed = spritesInfo[id].directed;
        sprite.updateSpriteVariables();
        return std::move(sprite);
    }
    return std::move(Sprite());
}
uf::vec2i Texture::GetNumOfTiles() const { return numOfTiles; }
uint32_t Texture::GetNumOfSprites() const { return uint32_t(spritesInfo.size()); }
uint32_t Texture::GetSizeOfTile() const { return sizeOfTile; }
const sf::Texture *Texture::GetSFMLTexture() const { return &texture; }

