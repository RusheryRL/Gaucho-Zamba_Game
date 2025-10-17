#include "bullet.h"

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
}
