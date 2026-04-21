#pragma once
#include "Map.h"

class Player
{
public:
    float x;
    float y;
    float PlayerAngle;
    float Speed;

    Player(float startX, float startY);

    void movement(Map& map);
};