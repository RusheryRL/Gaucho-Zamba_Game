#include "gameplay.h"

#include "raylib.h"

#include "windowManagment.h"
#include "objects/player.h"
#include "objects/ovni.h"
#include "objects/asteroid.h"
#include "objects/ship.h"
#include "objects/bullet.h"

namespace gauchoZambaGame
{
	void GameRun()
	{
		InitWindow(screenWidth, screenHeight, "Gaucho Zamba");
		//Inits
		Asteroid asteroid[ASTEROID_MIN_ARRAY] = {};
		Bullet playerBullet[MAX_BULLETS] = {};
		static Player player = initPlayer();
		static Ship ship = initShip(player.x, player.y, player.r, player.speedX, player.speedY, player.isAlive);
		//static Ovni ovni = initOvni();
		//static Bullet Ovnibullet = initBullet(ovni.x, ovni.y);

		for (int i = 0; i < ASTEROID_MIN_ARRAY; i++)
		{
			asteroid[i] = initAsteroid();
		}
		for (int i = 0; i < MAX_BULLETS; i++)
		{
			playerBullet[i] = initBullet(player.x, player.y);
		}

		while (!WindowShouldClose())
		{
			//FPS
#ifdef _DEBUG
			DrawFPS(0, 0);
#endif _DEBUG

			//Update
			playerInput(player);
			Vector2 dirNormalize = playerMovment(player);
			playerScreenCollision(player);


			for (int i = 0; i < MAX_BULLETS; i++)
			{
				playerShoot(player, playerBullet[i]);
			}

			for (int i = 0; i < ASTEROID_MIN_ARRAY; i++) //esto despues se puede meter en una func
			{
				asteroidScreenCollision(asteroid[i]);
				asteroidMovement(asteroid[i]);
			}

			//start Draw
			BeginDrawing();
#ifdef _DEBUG
			DrawCircleLines(GetMouseX(), GetMouseY(), 5.0f, YELLOW);
#endif _DEBUG
			DrawCircleLines(static_cast<int>(player.x), static_cast<int>(player.y), player.r, WHITE);
			for (int i = 0; i < ASTEROID_MIN_ARRAY; i++) //esto despues se puede meter en una func
			{
				DrawCircleLines(static_cast<int>(asteroid[i].x), static_cast<int>(asteroid[i].y), asteroid[i].r, RED);
			}
			for (int i = 0; i < MAX_BULLETS; i++)//esto despues se puede meter en una func
			{
				DrawCircleLines(static_cast<int>(playerBullet[i].x), static_cast<int>(playerBullet[i].y), playerBullet[i].r, GREEN);
			}
#ifdef _DEBUG
			DrawLine(static_cast<int>(player.x), static_cast<int>(player.y), static_cast<int>(player.x + dirNormalize.x * 20), static_cast<int>(player.y + dirNormalize.y * 20), YELLOW);
#endif _DEBUG
			ClearBackground(BLACK);

			//end Draw
			EndDrawing();
		}

		//De-Init
		CloseWindow();
	}
}