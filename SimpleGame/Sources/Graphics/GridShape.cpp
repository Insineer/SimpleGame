#include "GridShape.h"

GridShape::GridShape(uf::vec2u size, uf::vec2u cellSize) :
    size(size), cellSize(cellSize)
{
    for (int y = 0; y < size.y; y += cellSize.y) 
    {
        horizontalLinesVertices.push_back(sf::Vertex({ -32, y }));
        horizontalLinesVertices.push_back(sf::Vertex({ size.x + 32, y }));
    }

    for (int x = 0; x < size.x; x += cellSize.x) {
        horizontalLinesVertices.push_back(sf::Vertex({ x, -32 }));
        horizontalLinesVertices.push_back(sf::Vertex({ x, size.y + 32 }));
    }
}

void GridShape::draw(sf::RenderTarget &target, sf::RenderStates states) const
{

}
