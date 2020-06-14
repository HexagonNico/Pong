#pragma once
#include "TwoPlayers.h"

#include <cstdlib>
#include <ctime>

namespace hn
{
	class OnePlayer : public hn::TwoPlayers
	{
	private:
		float ball_dest_y;

	public:
		void init();
		void loop();
	};


}