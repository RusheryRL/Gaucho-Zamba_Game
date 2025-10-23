#pragma once

namespace gauchoZambaGame
{
	enum class AsteroidSize
	{
		BIG = 1,
		MID = 2,
		LIL = 4
	};

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
	const int MAX_ASTROID_RADIUS = 30;
	const int SPAWN_ASTEROID_CHILDS_ANGLE = 30;
	const int ASTEROID_MIN_ARRAY = 15;
	
	//const char* ASTEROID_TEXTURE = " ";

	const float ASTEROID_SPEED = 25.0f;

	Asteroid initAsteroid();
	void asteroidScreenCollision(Asteroid& Asteroid);
	void asteroidMovement(Asteroid& Asteroid);
}