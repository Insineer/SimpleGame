#pragma once

#include <Useful/Types.h>

#include "Texture.h"

class Sprite {
public:
    friend Texture;

    Sprite();
    Sprite(const Sprite &) = default;
    Sprite &operator=(const Sprite &) = default;
    Sprite(Sprite &&) = default;
    Sprite &operator=(Sprite &&) = default;

    void Draw(sf::RenderTarget *, uf::vec2i pos) const;
    // true if animation was switched to first sprite
    bool Update(sf::Time timeElapsed);
    void Resize(int tileSize);
    
    void SetDirection(uf::Direction direction);

    const std::string &GetKey() const;
    // true if sprite has few frames
    bool IsValid() const;
    bool IsAnimated() const;
    bool PixelTransparent(uf::vec2u pixel) const;

private:
    mutable sf::Sprite sfSprite;

    const Texture *texture;
    std::string key;
    uint32_t firstFrame;
    uint32_t frames;
    sf::Time frameTime;
    bool directed;

    uint32_t curFrame;
    uf::Direction direction;
    float scale;
    sf::Rect<int> rect;
    sf::Time curFrameTime;

    void updateSpriteVariables();
};
