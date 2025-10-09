#include "gameplay.h"

#include "raylib.h"

#include "windowManagment.h"

namespace gauchoZambaGame
{
    void GameRun()
    {
        InitWindow(screenWidth, screenHeight, "Gaucho Zamba");
        //Inits

        while (!WindowShouldClose())
        {
            //start Draw
            BeginDrawing();

            ClearBackground(BLACK);

            //end Draw
            EndDrawing();
        }

        //De-Init
        CloseWindow();
    }
}