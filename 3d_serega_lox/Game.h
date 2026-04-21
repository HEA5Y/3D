#pragma once
#include "Player.h"
#include "Map.h"
#include "Renderer.h"

class Game
{
public:
	void Start();
	Game();
	Player player;
	Map map;
	Renderer render;
};

