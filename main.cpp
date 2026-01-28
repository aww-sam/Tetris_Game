#include <iostream>
#include <raylib.h>
#include "Game.h"
#include "colors.h"

using namespace std;

double lastUpdateTime=0;
// to automatically move the block from starting time to the bottom
bool EventTriggered(double interval)
{
    double currentTime=GetTime();
    if(currentTime-lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}
int main () {

    InitWindow(500,620,"Tetris");
    SetTargetFPS(60);//speed of the game - 60 frame/sec
    Game game=Game();

    Font font =LoadFontEx("Font/monogram.ttf",60,0,0);
    

    while(WindowShouldClose()==false)// runs until the esc key or window close key is pressed(X) 
    { 
        UpdateMusicStream(game.music);
        game.HandleInput();
        if(EventTriggered(0.3))
        {
        game.MoveBlockDown();  
        }

        BeginDrawing(); //creates the blank canvas to draw game object
        ClearBackground(darkblue); //window is cleared with blue background color and previous frame of game loop is cleared and new frames can be made
        DrawTextEx(font, "Score" ,{360,15},38,2,WHITE);
        DrawTextEx(font, "Next" ,{370,175},38,2,WHITE);
        if(game.gameover)
        {
            DrawTextEx(font, "GAME OVER" ,{320,450},38,2,WHITE);
        }
        DrawRectangleRounded({320,55,170,60},0.3,6,lightblue);

        char scoretext[10];
        sprintf(scoretext,"%d",game.score);
        Vector2 textsize= MeasureTextEx(font, scoretext,38,2);
        
        DrawTextEx(font,scoretext ,{320+(170-textsize.x)/2,140/2},38,2,WHITE);
        DrawRectangleRounded({320,215,170,180},0.3,6,lightblue);
        game.Draw();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}