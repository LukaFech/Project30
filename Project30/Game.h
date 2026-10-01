#pragma once

#include "Snake.h"

class Game
{
private:
    Snake snake;
    int fruitX, fruitY;
    int score;
    bool gameOver;

public:
    Game();
    void Draw();
    void Input();
    void Logic();
    void Run();
};