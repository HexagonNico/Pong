#pragma once

#include <stack>

#include "SFML/Graphics.hpp"

#include "GameState.h"

namespace hn
{
	class StateManager
	{
	private:
		std::stack<GameState*> states;

	public:
		void add_state(GameState* state);
		void back();

		void loop();
		void render(sf::RenderWindow* window);
		void key_pressed(int key);
		void key_released(int key);
	};
}

