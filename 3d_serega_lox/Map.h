#pragma once
#include <vector>
#include <Windows.h>
#include <string>

class Map
{
public:
    int Height, Weight;
    std::vector<std::vector<char>> map;
    Map();
    std::string Draw();
    void GoToTop(int x, int y);
};