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

	const int MAX_PLAYER_POINTS = 5;

	const float PLAYER_RADIUS = 15.0f;
	const float PLAYER_SPEED = 150.0f;

	Player initPlayer();
	void playerMovment(Player& player);
	void playerScreenCollision(Player& player);
}