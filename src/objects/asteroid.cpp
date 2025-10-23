#include "asteroid.h"

#include "raylib.h"

#include "game/windowManagment.h"

namespace gauchoZambaGame
{
	Asteroid initAsteroid()
	{
		Asteroid asteroid;

		asteroid.x = static_cast<float>(GetRandomValue(1, GetScreenWidth()));
		asteroid.y = static_cast<float>(GetRandomValue(1, GetScreenWidth()));
		asteroid.r = MAX_ASTROID_RADIUS;
		asteroid.speedX = ASTEROID_SPEED;
		asteroid.speedY = ASTEROID_SPEED;
		asteroid.isDestroyed = false;
		asteroid.points = POINTS_PER_ASTEROID;

		return asteroid;
	}
	void asteroidScreenCollision(Asteroid& asteroid)
	{
		if (asteroid.y + MAX_ASTROID_RADIUS <= 0)
			asteroid.y = screenHeight - MAX_ASTROID_RADIUS;
		else if (asteroid.y >= (GetScreenHeight() + MAX_ASTROID_RADIUS))
			asteroid.y = MAX_ASTROID_RADIUS;
		else if (asteroid.x + MAX_ASTROID_RADIUS <= 0)
			asteroid.x = screenWidth - MAX_ASTROID_RADIUS;
		else if (asteroid.x >= (GetScreenWidth() + MAX_ASTROID_RADIUS))
			asteroid.x = MAX_ASTROID_RADIUS;
	}
	void asteroidMovement(Asteroid& asteroid)
	{
		asteroid.x += asteroid.speedX * GetFrameTime();
		asteroid.y += asteroid.speedY * GetFrameTime();
	}
}
