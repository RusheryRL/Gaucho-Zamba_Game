#include "bullet.h"

#include "player.h"
#include "game/windowManagment.h"

namespace gauchoZambaGame
{
	Bullet initBullet(float x, float y)
	{
		Bullet bullet;

		bullet.x = x;
		bullet.y = y;
		bullet.r = BULLET_RADIUS;
		bullet.speedX = BULLET_SPEED;
		bullet.speedY = BULLET_SPEED;
		bullet.spawnBullet = false;

		return bullet;
	}
	void bulletMovement(Bullet& bullet)
	{
		if (bullet.spawnBullet)
		{
			bullet.x += bullet.speedX * GetFrameTime();
			bullet.y += bullet.speedY * GetFrameTime();

			if (bullet.x <= 0 || bullet.x >= screenWidth ||
				bullet.y <= 0 || bullet.y >= screenHeight)
				bullet.spawnBullet = false;
		}
	}
}
