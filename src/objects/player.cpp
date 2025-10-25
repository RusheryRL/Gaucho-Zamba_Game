#include "player.h"

#include <iostream>
#include <cmath>

#include "raylib.h"

#include "game/windowManagment.h"

using namespace std;
namespace gauchoZambaGame
{
	Player initPlayer()
	{
		Player player;

		player.x = screenWidth / 2;
		player.y = screenHeight / 2;
		player.r = PLAYER_RADIUS;
		player.speedX = 0.0f;
		player.speedY = 0.0f;
		player.accX = PLAYER_ACCELERARTION;
		player.accY = PLAYER_ACCELERARTION;
		player.isAlive = true;
		player.isShooting = false;
		player.isWinner = false;
		player.currentPlayerLives = MAX_PLAYER_POINTS;
		player.points = 0;
		player.shots = 0;
		player.fireTimer = 0.0f;

		return player;
	}

	Vector2 playerMovment(Player& player)
	{
		float dirX = player.x;
		float dirY = player.y;

		Vector2 dirNormalize = normalize(dirX, dirY);

		if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
		{
			dirX = GetMouseX() - player.x;
			dirY = GetMouseY() - player.y;


			dirNormalize = normalize(dirX, dirY);

			player.accX += dirNormalize.x;
			player.accY += dirNormalize.y;

		}


		player.x += player.accX * GetFrameTime() * 0.1f;
		player.y += player.accY * GetFrameTime() * 0.1f;

		return dirNormalize;

	}
	void playerScreenCollision(Player& player)
	{
		if (player.y + PLAYER_RADIUS <= 0)
			player.y = screenHeight - PLAYER_RADIUS;
		else if (player.y >= (GetScreenHeight() + PLAYER_RADIUS))
			player.y = PLAYER_RADIUS;
		else if (player.x + PLAYER_RADIUS <= 0)
			player.x = screenWidth - PLAYER_RADIUS;
		else if (player.x >= (GetScreenWidth() + PLAYER_RADIUS))
			player.x = PLAYER_RADIUS;
	}
	void playerInput(Player& player) //preguntar
	{
		/*if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
		{
			player.speedY += player.accY * GetFrameTime();
			player.speedX += player.accX * GetFrameTime();
		}*/

		playerClamp(player);
	}

	void playerClamp(Player& player)
	{
		if (player.accY >= MAX_PLAYER_SPEED)
		{
			player.accY = MAX_PLAYER_SPEED;
		}
		else if (player.accY <= -MAX_PLAYER_SPEED)
		{
			player.accY = -MAX_PLAYER_SPEED;
		}

		if (player.accX >= MAX_PLAYER_SPEED)
		{
			player.accX = MAX_PLAYER_SPEED;
		}
		else if (player.accX <= -MAX_PLAYER_SPEED)
		{
			player.accX = -MAX_PLAYER_SPEED;
		}
	}

	Vector2 normalize(float& dirX, float& dirY)
	{
		float lenght = static_cast<float>(sqrt((pow(dirX, 2) + pow(dirY, 2))));

		dirX /= lenght;
		dirY /= lenght;

		return { dirX, dirY };
	}
	void playerShoot(Player& player, Bullet& bullet)
	{
		static float lastFireTime = 0.0f;

		lastFireTime -= GetFrameTime();
		if (lastFireTime <= 0.0f)
			lastFireTime = 0.0f;

		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && lastFireTime <= 0.0f, bullet.spawnBullet == false)
		{
			bullet.spawnBullet = true;
			bullet.x = player.x;
			bullet.y = player.y;

			float bulletDirX = GetMouseX() - player.x;
			float bulletDirY = GetMouseY() - player.y;

			Vector2 bulletDirNormalize = normalize(bulletDirX, bulletDirY);

			bullet.speedX = bulletDirNormalize.x * BULLET_SPEED;
			bullet.speedY = bulletDirNormalize.y * BULLET_SPEED;

			lastFireTime = BULLET_FIRE_RATE;
		}

		bulletMovement(bullet);
	}
}
