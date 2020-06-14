#include "Bar.h"

hn::Bar::Bar(int x, int y)
{
	shape.top = y;
	shape.left = x;
	shape.width = 15;
	shape.height = 100;
	up = false;
	down = false;
}

void hn::Bar::move()
{
	if (up && shape.top > 10) shape.top -= 1;
	else if (down && shape.top < 490) shape.top += 1;
}

void hn::Bar::set_up(bool u)
{
	up = u;
	down = false;
}

void hn::Bar::set_down(bool d)
{
	down = d;
	up = false;
}

bool hn::Bar::intersects(hn::Ball* ball)
{
	float bounce_pos = ball->get_shape().top - shape.top;
	float xc = ball->get_shape().left - shape.left;

	if (bounce_pos > 0 && bounce_pos < 100 && xc == 0)
	{
		ball->bounce(50 - bounce_pos);
		return true;
	}
	return false;
}

sf::FloatRect hn::Bar::get_shape()
{
	return shape;
}

void hn::Bar::render(sf::RenderWindow* window)
{
	sf::RectangleShape rect;
	rect.setPosition(sf::Vector2f(shape.left, shape.top));
	rect.setFillColor(sf::Color::White);
	rect.setSize(sf::Vector2f(shape.width, shape.height));

	window->draw(rect);
}
