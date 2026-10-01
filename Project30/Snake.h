#pragma once

#include <vector>

const int WIDTH = 20;
const int HEIGHT = 10;

using namespace std;

class Snake
{
public:
    int x, y;
    int dir; // (1:Up, 2:Down, 3:Left, 4:Right)
    vector<pair<int, int>> tail;

    Snake();
    void Move();
    void Grow();
    bool CheckSelfCollision();
};