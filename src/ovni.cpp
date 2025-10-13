#include "ovni.h"

#include "windowManagment.h"

namespace gauchoZambaGame
{
	Ovni initOvni()
	{
		Ovni ovni;

		ovni.x = screenWidth / 4;
		ovni.y = screenWidth / 4;
		ovni.r = OVNI_RADIUS;
		ovni.speedX = OVNI_SPEED;
		ovni.isAlive = false;
		ovni.isShooting = false;
		ovni.isHitPlayer = false;
		ovni.isSpawn = false;

		return ovni;
	}
}
