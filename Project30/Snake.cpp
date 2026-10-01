#include "Snake.h"

Snake::Snake()
{
    x = WIDTH / 2;
    y = HEIGHT / 2;
    dir = 0;
}

void Snake::Move()
{
    if (!tail.empty())
    {
        for (size_t i = tail.size() - 1; i > 0; i--)
        {
            tail[i] = tail[i - 1];
        }
        tail[0] = { x, y };
    }
    if (dir == 1) y--;
    if (dir == 2) y++;
    if (dir == 3) x--;
    if (dir == 4) x++;
}

void Snake::Grow()
{
    tail.push_back({ -1, -1 });
}

bool Snake::CheckSelfCollision()
{
    for (auto segment : tail)
    {
        if (segment.first == x and segment.second == y)
        {
            return true;
        }
    }
    return false;
}