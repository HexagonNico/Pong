#include "Ball.h"

hn::Ball::Ball(int x, int y, float spdx, float spdy)
{
	shape.top = y;
	shape.left = x;
	shape.width = 30;
	shape.height = 30;
	speed = sf::Vector2f(spdx, spdy);
}

void hn::Ball::move()
{
	shape.left += speed.x;
	shape.top += speed.y;
}

void hn::Ball::bounce(float angle)
{
	if (angle != -1)
	{
		speed.x = -speed.x;
		speed.y = -sin(angle * 3.14159 / 180);
	}
	else
	{
		speed.y = -speed.y;
	}
}

sf::FloatRect hn::Ball::get_shape()
{
	return shape;
}

sf::Vector2f hn::Ball::get_speed()
{
	return speed;
}

void hn::Ball::render(sf::RenderWindow* window)
{
	sf::RectangleShape rect;
	rect.setPosition(sf::Vector2f(shape.left, shape.top));
	rect.setFillColor(sf::Color::White);
	rect.setSize(sf::Vector2f(30, 30));
	rect.setOrigin(sf::Vector2f(15, 15));

	window->draw(rect);
}
