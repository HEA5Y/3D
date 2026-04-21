#include "Game.h"
Game::Game() : player(8.0,1.0) {}

void Game::Start() {
	while (1) {
        map.map[(int)player.y][(int)player.x] = ' ';
        player.movement(map);
        map.map[(int)player.y][(int)player.x] = '@';
		render.render(map, player);
	}
}
