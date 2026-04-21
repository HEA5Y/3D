#pragma once
#include "Player.h"	
#include "Map.h"
#include <string>
#include <iostream>
class Renderer
{
public:
	size_t screenWidth = 300;
	size_t screenHeight = 100;
	float fov = 3.14159f / 4.5f;
	float depth = 16.0f;
	
	void render(Map& map, Player& player);
};

