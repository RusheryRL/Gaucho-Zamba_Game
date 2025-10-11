#pragma once

namespace gauchoZambaGame
{
	struct Bullet
	{
		bool isSpawn;

		float x;
		float y;
		float w;
		float h;
		float speedX;
		float speedY;
	};

	const int SLEEP_BULLET_PER_BULLET = 1.5;

	const char* PLAYER_BULLET_TEXTURE = " ";
	const char* OVNI_BULLET_TEXTURE = " ";

	Bullet initBullet();
}