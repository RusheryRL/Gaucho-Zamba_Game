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
	void playerInput(Player& player)
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
		if (player.speedY >= MAX_PLAYER_SPEED)
		{
			player.speedY = MAX_PLAYER_SPEED;
		}
		else if (player.speedY <= -MAX_PLAYER_SPEED)
		{
			player.speedY = -MAX_PLAYER_SPEED;
		}
	}

	Vector2 normalize(float& dirX, float& dirY)
	{
		float lenght = static_cast<float>(sqrt((pow(dirX, 2) + pow(dirY, 2))));

		dirX /= lenght;
		dirY /= lenght;

		return { dirX, dirY };
	}
	void playerShoot()
	{
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		{

		}
	}
}
