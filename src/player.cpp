#include "player.h"

#include <iostream>
#include <cmath>

#include "raylib.h"

#include "windowManagment.h"

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
		player.acc = PLAYER_ACCELERARTION;
		player.isAlive = true;
		player.isShooting = false;
		player.isWinner = false;
		player.currentPlayerLives = MAX_PLAYER_POINTS;
		player.points = 0;

		return player;
	}

	void playerMovment(Player& player)
	{

		if (GetMousePosition().x <= player.x && GetMousePosition().y <= player.y)
		{
			player.x -= player.speedX * GetFrameTime();
			player.y -= player.speedY * GetFrameTime();
		}
		else if (GetMousePosition().x >= player.x && GetMousePosition().y <= player.y)
		{
			player.x += player.speedX * GetFrameTime();
			player.y -= player.speedY * GetFrameTime();
		}
		else if (GetMousePosition().x <= player.x && GetMousePosition().y >= player.y)
		{
			player.x -= player.speedX * GetFrameTime();
			player.y += player.speedY * GetFrameTime();
		}
		else if (GetMousePosition().x >= player.x && GetMousePosition().y >= player.y)
		{
			player.x += player.speedX * GetFrameTime();
			player.y += player.speedY * GetFrameTime();
		}
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
		if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
		{
			player.speedY += player.acc * GetFrameTime();
			player.speedX += player.acc * GetFrameTime();
		}
		else if (IsMouseButtonUp(MOUSE_BUTTON_RIGHT) && player.speedY >= 0.0f)
		{
			player.speedY -= player.acc * GetFrameTime();
			player.speedX -= player.acc * GetFrameTime();
		}

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
		else if (player.speedY < 1.0f && player.speedY > 1.0f)
		{
			player.speedY = 0.0f;
		}
	}
}
