#pragma once

#include <SFML/Graphics.hpp>

#include <Useful/Types.h>

class GridShape : public sf::Drawable, public sf::Transformable
{
public:
	GridShape(uf::vec2u size, uf::vec2u cellSize);

protected:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const final;

private:
	uf::vec2u size;
	uf::vec2u cellSize;

	std::vector<sf::Vertex> verticalLinesVertices;
	std::vector<sf::Vertex> horizontalLinesVertices;
};
