#include "Game.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <thread>
#include <chrono>

using namespace std;

Game::Game()
{
    score = 0;
    gameOver = false;
    fruitX = 1 + rand() % (WIDTH - 2);
    fruitY = 1 + rand() % (HEIGHT - 2);
}

void Game::Draw()
{
    cout << "\033[H";

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (i == 0 or i == HEIGHT - 1 or j == 0 or j == WIDTH - 1)
            {
                cout << "#";
            }
            else if (i == snake.y && j == snake.x)
            {
                cout << "O";
            }
            else if (i == fruitY && j == fruitX)
            {
                cout << "*";
            }
            else
            {
                bool isTail = false;
                for (auto seg : snake.tail)
                {
                    if (seg.first == j && seg.second == i)
                    {
                        cout << "o";
                        isTail = true;
                        break;
                    }
                }
                if (!isTail) cout << " ";
            }
        }
        cout << "\n";
    }
    cout << "Score: " << score << "\nWASD - Move | X - Exit\n";
}

void Game::Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'w':
            if (snake.dir != 2)
            {
                snake.dir = 1;
                break;
            }
        case 's': 
            if (snake.dir != 1)
            {
                snake.dir = 2;
                break;
            }
        case 'a': 
            if (snake.dir != 4)
            {
                snake.dir = 3;
                break;
            }
        case 'd': 
            if (snake.dir != 3)
            {
                snake.dir = 4;
                break;
            }
        case 'x': 
            gameOver = true;
            break;
        }
    }
}

void Game::Logic()
{
    if (snake.dir == 0) return;
    snake.Move();
    if (snake.x <= 0 or snake.x >= WIDTH - 1 or snake.y <= 0 or snake.y >= HEIGHT - 1)
    {
        gameOver = true;
    }
    if (snake.CheckSelfCollision())
    {
        gameOver = true;
    }
    if (snake.x == fruitX && snake.y == fruitY)
    {
        score += 10;
        snake.Grow();
        fruitX = 1 + rand() % (WIDTH - 2);
        fruitY = 1 + rand() % (HEIGHT - 2);
    }
}

void Game::Run()
{
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        this_thread::sleep_for(chrono::milliseconds(150));
    }
    cout << "\nGAME OVER! Score: " << score << endl;
}