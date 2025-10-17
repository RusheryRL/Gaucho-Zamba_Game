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
		Player player = initPlayer();
		Ship ship = initShip(player.x, player.y, player.r, player.speedX, player.speedY, player.isAlive);
		Ovni ovni = initOvni();
		Asteroid asteroid = initAsteroid();
		Bullet Playerbullet = initBullet(player.x, player.y);
		Bullet Ovnibullet = initBullet(ovni.x, ovni.y);

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

			//start Draw
			BeginDrawing();

			DrawCircleLines(GetMouseX(), GetMouseY(), 5.0f, YELLOW);
			DrawCircleLines(static_cast<int>(player.x), static_cast<int>(player.y), player.r, WHITE);
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