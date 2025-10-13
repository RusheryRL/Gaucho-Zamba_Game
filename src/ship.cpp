#include "ship.h"

namespace gauchoZambaGame
{
	Ship initShip(float x, float y, float r, float speedX, float speedY, bool isPlayerDead)
	{
		Ship ship;

		ship.x = x;
		ship.y = y;
		ship.r = r;
		ship.speedX = speedX;
		ship.speedY = speedY;
		ship.ispPlayerDead = isPlayerDead;

		return ship;
	}
}
