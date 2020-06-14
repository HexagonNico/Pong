#include "Engine.h"

sf::RenderWindow hn::Engine::window;
hn::StateManager hn::Engine::manager;
bool hn::Engine::to_close;

void hn::Engine::init()
{
	window.create(sf::VideoMode(800, 600), "PONG!");
	manager.add_state(new hn::MainMenu);
	to_close = false;
	std::cout << "Init done" << std::endl;
}

bool hn::Engine::running()
{
	return window.isOpen() && !to_close;
}

void hn::Engine::handle_events()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			std::cout << "Closing window..." << std::endl;
			window.close();
			break;
		case sf::Event::KeyPressed:
			manager.key_pressed(event.key.code);
			break;
		case sf::Event::KeyReleased:
			manager.key_released(event.key.code);
			break;
		}
	}
	manager.loop();
}

void hn::Engine::render()
{
	window.clear(sf::Color(10, 10, 40));
	manager.render(&window);
	window.display();
}

hn::StateManager* hn::Engine::state_manager()
{
	return &manager;
}

void hn::Engine::close_game()
{
	to_close = true;
}
