#pragma once

namespace gauchoZambaGame
{
	struct Bullet
	{
		float x;
		float y;
		float r;
		float speedX;
		float speedY;

		bool spawnBullet;
	};

	const int MAX_BULLETS = 25;

	//const char* PLAYER_BULLET_TEXTURE = " ";
	//const char* OVNI_BULLET_TEXTURE = " ";

	const float BULLET_RADIUS = 3.0f;
	const float BULLET_SPEED = 100.0f;

	Bullet initBullet(float x, float y);
}