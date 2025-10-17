#include "asteroid.h"

#include "game/windowManagment.h"

namespace gauchoZambaGame
{
	Asteroid initAsteroid()
	{
		Asteroid asteroid;

		asteroid.x = screenWidth / 2;
		asteroid.y = screenHeight / 1.5f;
		asteroid.r = MAX_ASTROID_SIZE;
		asteroid.speedX = ASTEROID_SPEED;
		asteroid.speedY = ASTEROID_SPEED;
		asteroid.isDestroyed = false;
		asteroid.points = POINTS_PER_ASTEROID;

		return asteroid;
	}
}
