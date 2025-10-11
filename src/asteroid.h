#pragma once

namespace gauchoZambaGame
{
	struct Asteroid
	{
		float x;
		float y;
		float r;
		float speedX;
		float speedY;

		bool isDestroyed;

		int points;
	};

	const int POINTS_PER_ASTEROID = 100;
	const int ASTEROID_CHILDRENS = 2;
	
	const char* ASTEROID_TEXTURE = " ";

	Asteroid initAsteroid();
}