#pragma once

namespace gauchoZambaGame
{
	struct Ovni
	{
		float x;
		float y;
		float r;
		float speedX;
		float speedY;

		bool isAlive;
		bool isShooting;
		bool isHitPlayer;
	};

	const int ENEMIES_PER_ROUND = 1;

	const char* OVNI_TEXTURE = " ";

	Ovni initOvni();
}