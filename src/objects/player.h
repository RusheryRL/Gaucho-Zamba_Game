#pragma once

#include "raylib.h" 

#include "bullet.h"

namespace gauchoZambaGame
{
	struct Player
	{
		float x;
		float y;
		float r;
		float speedX;
		float speedY;
		float accX;
		float accY;
		float fireTimer;

		bool isAlive;
		bool isShooting;
		bool isWinner;

		int currentPlayerLives;
		int points;
		int shots;
	};

	const int MAX_PLAYER_POINTS = 5;

	const float PLAYER_RADIUS = 15.0f;
	const float MAX_PLAYER_SPEED = 600.0f;
	const float PLAYER_ACCELERARTION = 15.0f;

	Player initPlayer();
	Vector2 playerMovment(Player& player);
	void playerScreenCollision(Player& player);
	void playerInput(Player& player);
	void playerClamp(Player& player);
	Vector2 normalize(float& dirX, float& dirY);
	void playerShoot(Player& player, Bullet& bullet);
}