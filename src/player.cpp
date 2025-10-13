#include "player.h"

#include "raylib.h"

#include "windowManagment.h"

namespace gauchoZambaGame
{
	Player initPlayer()
	{
		Player player;

		player.x = screenWidth / 2;
		player.y = screenHeight / 2;
		player.r = PLAYER_RADIUS;
		player.speedX = PLAYER_SPEED;
		player.speedY = PLAYER_SPEED;
		player.isAlive = true;
		player.isShooting = false;
		player.isWinner = false;
		player.currentPlayerLives = MAX_PLAYER_POINTS;
		player.points = 0;

		return player;
	}

	void playerMovment(Player& player)
	{
		if (IsKeyDown(KEY_W))
			player.y -= PLAYER_SPEED * GetFrameTime();
		else if (IsKeyDown(KEY_S))
			player.y += PLAYER_SPEED * GetFrameTime();
		else if (IsKeyDown(KEY_A))
			player.x -= PLAYER_SPEED * GetFrameTime();
		else if (IsKeyDown(KEY_D))
			player.x += PLAYER_SPEED * GetFrameTime();
	}
	void playerScreenCollision(Player& player)
	{
		if (player.y - PLAYER_RADIUS <= 0)
			player.y = PLAYER_RADIUS;
		else if (player.y >= (GetScreenHeight() - PLAYER_RADIUS))
			player.y = (GetScreenHeight() - PLAYER_RADIUS);
		else if (player.x - PLAYER_RADIUS <= 0)
			player.x = PLAYER_RADIUS;
		else if (player.x >= (GetScreenWidth() - PLAYER_RADIUS))
			player.x = (GetScreenWidth() - PLAYER_RADIUS);
	}
}
