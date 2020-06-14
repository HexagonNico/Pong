#include "OnePlayer.h"

void hn::OnePlayer::init()
{
	hn::TwoPlayers::init();

	srand(time(NULL));
}

void hn::OnePlayer::loop()
{
	hn::TwoPlayers::loop();
	/*
	if (ball->get_shape().top < player2->get_shape().top + 50)
		player2->set_up(true);
	else
		player2->set_down(true);
	*/

	if (ball->get_shape().left == 400 || ball->get_shape().top < 10 || ball->get_shape().top > 570 || ball->get_shape().left == 600)
	{
		sf::Vector2f speed = ball->get_speed();
		float m = speed.y / speed.x;
		float q = ball->get_shape().top - m * ball->get_shape().left;

		ball_dest_y = m * player2->get_shape().left + q + 40 - rand()%140;
	}

	if (ball_dest_y > player2->get_shape().top)
		player2->set_down(true);
	else if (ball_dest_y < player2->get_shape().top)
		player2->set_up(true);
}
