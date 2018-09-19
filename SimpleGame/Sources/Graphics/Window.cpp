#include "Window.h"

#include <SFML/Graphics.hpp>

Window::Window() :
	window(sf::VideoMode(800, 640), "SFML works!"),
	tileGrid({ 800, 640 })
{
	window.clear(sf::Color::Black);
	window.setVerticalSyncEnabled(true);
}

void Window::Update()
{
	sf::Event event;
	while (window.pollEvent(event)) {
		if (tileGrid.HandleEvent(event)) {
			continue;
		}
		if (event.type == sf::Event::Closed) {
			window.close();
		}
	}
	tileGrid.Update(sf::Time());
	tileGrid.Draw(window);
	//window.draw(tileGrid);
	window.display();
}

bool Window::IsOpen() const
{
	return window.isOpen();
}

void Window::fps_sleep() {
	sf::Time timeElapsed = frame_clock.getElapsedTime();

	if (timeElapsed.asMicroseconds() < 1000 * 1000 / req_FPS)
		sf::sleep(sf::microseconds(1000 * 1000 / req_FPS) - timeElapsed);

	lastFrameTime = frame_clock.restart();
}