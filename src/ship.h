#pragma once

namespace gauchoZambaGame
{
	struct Ship
	{
		float x;
		float y;
		float r;
		float speedX;
		float speedY;
		bool playerIsDead;
	};

	const char* SHIP_TEXTURE = " ";

	Ship initShip(float x, float y, float r, float speedX, float speedY, bool playerIsDead);
}