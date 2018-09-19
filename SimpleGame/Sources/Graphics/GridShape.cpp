#include "GridShape.h"

GridShape::GridShape(uf::vec2u size, uf::vec2u cellSize) :
	size(size), cellSize(cellSize)
{
	for (unsigned int y = 0; y <= size.y; y += cellSize.y)
	{
		horizontalLinesVertices.push_back(sf::Vertex({ -32, static_cast<float>(y) }, sf::Color::Black));
		horizontalLinesVertices.push_back(sf::Vertex({ static_cast<float>(size.x + 32), static_cast<float>(y) }, sf::Color::Black));
	}

	for (unsigned int x = 0; x <= size.x; x += cellSize.x) {
		verticalLinesVertices.push_back(sf::Vertex({ static_cast<float>(x), -32 }, sf::Color::Black));
		verticalLinesVertices.push_back(sf::Vertex({ static_cast<float>(x), static_cast<float>(size.y + 32) }, sf::Color::Black));
	}
}

void GridShape::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform = getTransform();
	target.draw(verticalLinesVertices.data(), verticalLinesVertices.size(), sf::Lines, states);
	target.draw(horizontalLinesVertices.data(), horizontalLinesVertices.size(), sf::Lines, states);
}
