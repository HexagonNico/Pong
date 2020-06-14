#pragma once
#include "GameState.h"

#include "Bar.h"
#include "Ball.h"

namespace hn
{
	class TwoPlayers : public hn::GameState
	{
	private:
		sf::Font font;

	protected:
		hn::Bar* player1;
		hn::Bar* player2;
		hn::Ball* ball;
		int score1;
		int score2;

	public:
		void init();
		void loop();
		void render(sf::RenderWindow* window);
		void key_pressed(int key);
		void key_released(int key);
	};
}