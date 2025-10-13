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

	const int POINTS_PER_ASTEROID = 50;
	const int ASTEROID_CHILDRENS = 2;
	const int MAX_ASTROID_SIZE = 30;
	
	//const char* ASTEROID_TEXTURE = " ";

	const float ASTEROID_SPEED = 50.0f;

	Asteroid initAsteroid();
}