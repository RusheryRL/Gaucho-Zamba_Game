#pragma once

namespace gauchoZambaGame
{
	struct Player
	{
		float x;
		float y;
		float r;
		float speedX;
		float speedY;

		bool isAlive;
		bool isShooting;
		bool isWinner;

		int currentPlayerLives;
		int points;
	};

	const int MAX_PLAYER_POINTS = 3;

	Player initPlayer();
}