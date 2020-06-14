#include "TwoPlayers.h"
#include "Engine.h"

void hn::TwoPlayers::init()
{
	player1 = new hn::Bar(10, 300);
	player2 = new hn::Bar(780, 300);
	ball = new hn::Ball(400, 300, 0.5f, 0.0f);

	score1 = 0;
	score2 = 0;

	font.loadFromFile("BAUHS93.TTF");
}

void hn::TwoPlayers::loop()
{
	player1->move();
	player2->move();
	
	player1->intersects(ball);
	player2->intersects(ball);

	if (ball->get_shape().top < 10 || ball->get_shape().top > 570)
		ball->bounce(-1);

	ball->move();

	if (ball->get_shape().left < 0)
	{
		score2++;
		ball = new hn::Ball(400, 300, 0.5f, -0.1f);
	}
	else if (ball->get_shape().left > 800)
	{
		score1++;
		ball = new hn::Ball(400, 300, -0.5f, 0.1f);
	}
}

void hn::TwoPlayers::render(sf::RenderWindow* window)
{
	player1->render(window);
	player2->render(window);

	ball->render(window);

	sf::Text text;
	text.setFont(font);
	text.setString(std::to_string(score1));
	text.setCharacterSize(100);
	text.setPosition(sf::Vector2f(30, 10));
	text.setFillColor(sf::Color::White);
	window->draw(text);

	text.setString(std::to_string(score2));
	text.setPosition(sf::Vector2f(730, 10));
	window->draw(text);
}

void hn::TwoPlayers::key_pressed(int key)
{
	if (key == sf::Keyboard::W)
	{
		player1->set_up(true);
	}
	else if (key == sf::Keyboard::S)
	{
		player1->set_down(true);
	}
	else if (key == sf::Keyboard::Up)
	{
		player2->set_up(true);
	}
	else if (key == sf::Keyboard::Down)
	{
		player2->set_down(true);
	}
	else if (key == sf::Keyboard::Escape)
	{
		hn::Engine::state_manager()->back();
	}
}

void hn::TwoPlayers::key_released(int key)
{
	if (key == sf::Keyboard::W)
	{
		player1->set_up(false);
	}
	else if (key == sf::Keyboard::S)
	{
		player1->set_down(false);
	}
	else if (key == sf::Keyboard::Up)
	{
		player2->set_up(false);
	}
	else if (key == sf::Keyboard::Down)
	{
		player2->set_down(false);
	}
}
