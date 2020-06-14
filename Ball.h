#pragma once

#ifndef BALL



#include "SFML/Graphics.hpp"

#include <math.h>

namespace hn
{
	class Ball
	{
	private:
		sf::FloatRect shape;
		sf::Vector2f speed;

	public:

		Ball(int x, int y, float spdx, float spdy);

		void move();
		void bounce(float angle);

		sf::FloatRect get_shape();
		sf::Vector2f get_speed();

		void render(sf::RenderWindow* window);
	};
}

#endif // !BALL