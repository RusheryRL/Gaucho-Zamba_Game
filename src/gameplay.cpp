#include "gameplay.h"

#include "raylib.h"

#include "windowManagment.h"
#include "player.h"
#include "ovni.h"
#include "asteroid.h"
#include "ship.h"
#include "bullet.h"

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
            //Update
            playerMovment(player);
            playerScreenCollision(player);

            //start Draw
            BeginDrawing();

            DrawCircleLines(player.x, player.y, player.r, WHITE);

            ClearBackground(BLACK);

            //end Draw
            EndDrawing();
        }

        //De-Init
        CloseWindow();
    }
}