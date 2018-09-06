#include "TileGrid.h"

TileGrid::TileGrid(uf::vec2i size) :
    Widget(size), 
    shape(sf::CircleShape(100)),
    grid(size, {32, 32})
{
    shape.setFillColor(sf::Color::Green);
    SetPosition({ 0, 0 });
}

void TileGrid::draw() const
{
    buffer.clear(sf::Color::Yellow);
    buffer.draw(shape);
    buffer.display();
}
