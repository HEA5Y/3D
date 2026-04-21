#include "Player.h"
#include <windows.h>
#include <cmath>
Player::Player(float startX, float startY)
    : x(startX), y(startY)
{
    PlayerAngle = 0.0f;
    Speed = 0.1f;
}

void Player::movement(Map& map)
{
    short wState = GetAsyncKeyState('W');
    short sState = GetAsyncKeyState('S');
    short aState = GetAsyncKeyState('A');
    short dState = GetAsyncKeyState('D');

    if (wState & 0x8000) {
        float nextX = x + cos(PlayerAngle) * Speed;
        float nextY = y + sin(PlayerAngle) * Speed;
        if (map.map[(int)nextY][(int)nextX] != '#') {
            map.map[(int)y][(int)x] = ' ';
            x = nextX; y = nextY;
        }
    }

    if (sState & 0x8000) {
        float nextX = x - cos(PlayerAngle) * Speed; 
        float nextY = y - sin(PlayerAngle) * Speed; 
        if (map.map[(int)nextY][(int)nextX] != '#') {
            map.map[(int)y][(int)x] = ' ';
            x = nextX; y = nextY;
        }
    }
  
    if (aState & 0x8000) PlayerAngle -= 0.04f;
    if (dState & 0x8000) PlayerAngle += 0.04f;
}