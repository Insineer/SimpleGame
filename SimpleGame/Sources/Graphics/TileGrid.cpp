#include "TileGrid.h"

TileGrid::TileGrid(uf::vec2i size) :
	Widget(size), 
	pos({0,0}),
	grid(size, {32, 32})
{
	SetPosition({ 0, 0 });
}

void TileGrid::Update(sf::Time timeElapsed)
{
	pos += moving;
	grid.setPosition(-(pos.x % 32), -(pos.y % 32));
}

bool TileGrid::HandleEvent(sf::Event e)
{
	if(e.type == sf::Event::EventType::KeyPressed) {
		switch(e.key.code) {
		case sf::Keyboard::Key::Right:
			moving.x = 1;
			break;
		case sf::Keyboard::Key::Left:
			moving.x = -1;
			break;
		case sf::Keyboard::Key::Down:
			moving.y = 1;
			break;
		case sf::Keyboard::Key::Up:
			moving.y = -1;
			break;
		default:
			return false;
		}
		return true;
	} else if(e.type == sf::Event::EventType::KeyReleased) {
		switch(e.key.code) {
		case sf::Keyboard::Key::Right:
			moving.x = -sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
			break;
		case sf::Keyboard::Key::Left:
			moving.x = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
			break;
		case sf::Keyboard::Key::Down:
			moving.y = -sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
			break;
		case sf::Keyboard::Key::Up:
			moving.y = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
			break;
		default:
			return false;
		}
		return true;
	}
	return false;
}

void TileGrid::draw() const
{
	buffer.clear(sf::Color::White);
	buffer.draw(grid);
	buffer.display();
}
