#pragma once

namespace gauchoZambaGame
{
	struct Ovni
	{
		float x;
		float y;
		float r;
		float speedX;

		bool isAlive;
		bool isShooting;
		bool isHitPlayer;
		bool isSpawn;
	};

	const int ENEMIES_PER_ROUND = 1;

	const char* OVNI_TEXTURE = " ";

	const float OVNI_RADIUS = 10.0f;
	const float OVNI_SPEED = 50.0f;

	Ovni initOvni();
}