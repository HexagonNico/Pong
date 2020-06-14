#pragma once

#include "SFML/Graphics.hpp"

#include <iostream>

#include "StateManager.h"
#include "MainMenu.h"

namespace hn
{
	class Engine
	{
	private:
		static sf::RenderWindow window;
		static hn::StateManager manager;
		static bool to_close;

	public:
		static void init();
		static bool running();
		static void handle_events();
		static void render();

		static hn::StateManager* state_manager();
		static void close_game();
	};
}

