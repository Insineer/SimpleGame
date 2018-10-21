#include "TileGrid.h"
#include <Game.h>

TileGrid::TileGrid(uf::vec2u size) :
	Widget(size), 
	grid(size, {32, 32})
{
	SetPosition({ 0, 0 });
}

void TileGrid::Update(sf::Time timeElapsed)
{
	Game::Get()->GetPlayer()->GetMob()->Move(moving);
	grid.setPosition(uf::vec2i(Game::Get()->GetPlayer()->GetMob()->GetPos() + uf::vec2i{384, 304}) % 32 * -1);
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
			moving.x = -int(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left));
			break;
		case sf::Keyboard::Key::Left:
			moving.x = int(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right));
			break;
		case sf::Keyboard::Key::Down:
			moving.y = -int(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up));
			break;
		case sf::Keyboard::Key::Up:
			moving.y = int(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down));
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
	for(auto &obj: Game::Get()->GetPlayer()->GetMob()->GetLoc()->GetObjects()) {
		obj->sprite.Draw(&buffer, obj->GetPos() - Game::Get()->GetPlayer()->GetMob()->GetPos() + uf::vec2i{384, 304});
	}
	buffer.display();
}
