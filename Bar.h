#pragma once

#include "SFML/Graphics.hpp"

#include "Ball.h"

#include <math.h>

namespace hn
{
	class Bar
	{
	private:
		sf::FloatRect shape;
		bool up;
		bool down;

	public:
		Bar(int x, int y);

		void move();

		void set_up(bool u);
		void set_down(bool d);

		bool intersects(hn::Ball* ball);

		sf::FloatRect get_shape();

		void render(sf::RenderWindow* window);
	};
}