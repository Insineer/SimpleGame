#pragma once

#include "Widget.h"

#include "GridShape.h" 

class Camera;

class TileGrid : public Widget
{
public:
    TileGrid(uf::vec2i size);

    virtual void Update(sf::Time timeElapsed) {};
    virtual bool HandleEvent(sf::Event event) { return false; };


protected:
    virtual void draw() const final;

private:
    Camera *camera;

    sf::CircleShape shape;
    GridShape grid;
};
