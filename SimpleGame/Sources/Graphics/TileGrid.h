#pragma once

#include "Widget.h"

#include "GridShape.h" 

class Camera;

class TileGrid : public Widget
{
public:
	TileGrid(uf::vec2u size);

	virtual void Update(sf::Time timeElapsed);
	virtual bool HandleEvent(sf::Event event);


protected:
	virtual void draw() const final;

private:
	Camera *camera;
	uf::vec2i moving;

	GridShape grid;
};
