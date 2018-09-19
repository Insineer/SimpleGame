#pragma once

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

#include <Useful/Types.h>
#include <Useful/JSON.hpp>

class Sprite;

class Texture {
public:
    Texture(std::string path, nlohmann::json &config, uint32_t firstSpriteID);

    bool IsFramePixelTransparent(uf::vec2u pixel, uint32_t frame) const;

    //const std::vector<Sprite *> &GetSprites() const;
    const sf::Texture *GetSFMLTexture() const;

    Sprite GetSprite(uint32_t id) const;
    uf::vec2i GetNumOfTiles() const;
    uint32_t GetNumOfSprites() const;
    uint32_t GetSizeOfTile() const;

private:
    struct SpriteInfo {
        std::string title;
        uint32_t firstFrame;
        uint32_t frames;
        sf::Time frameTime;
        bool directed;
    };

    sf::Texture texture;
    uint32_t sizeOfTile;
    uf::vec2u numOfTiles;
    uint32_t firstSpriteID;
    std::vector<SpriteInfo> spritesInfo;
};