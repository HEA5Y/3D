#include "Renderer.h"
#include <cmath>

void Renderer::render(Map& map, Player& player)
{

	map.GoToTop(0, 0);
	std::string mapStr = map.Draw();
	std::string frame = ""; // кадр

	for (int y = 0; y < screenHeight; y++) {

		if (y < map.Height) { //подгрузка миникарты в кадр(добавка к стрингу кадра)
			for (int x = 0; x < map.Weight; x++) {
				frame += map.map[y][x];
			}
		}
		else {                //
			frame += std::string(map.Weight, ' ');
		}

		frame += "  |  ";
		std::string wallPart = "";
		std::string floorPart = "";
		
		for (int x = 0; x < screenWidth; x++) {
			bool hitWall = false;
			float distance = 0.0f;
			float rayAngle = (player.PlayerAngle - fov / 2.0f) + ((float)x / (float)screenWidth) * fov * 1.8f;
			float eyeX = cos(rayAngle);
			float eyeY = sin(rayAngle);

			while (!hitWall) {
				distance += 0.15f; // оптимально

				int testX = (int)(player.x + eyeX * distance);
				int testY = (int)(player.y + eyeY * distance);

				if (testX < 0 || testX >= map.Weight || testY < 0 || testY >= map.Height) {
					hitWall = true;
					distance = depth;
				}
				else if (map.map[testY][testX] == '#') {
					hitWall = true;
				}
			}
			int ceiling = (float)(screenHeight / 2.0) - screenHeight / distance;
			int floorr = screenHeight - ceiling;
			float intersectionX = player.x + eyeX * distance;
			float intersectionY = player.y + eyeY * distance;
			float tx = intersectionX - floor(intersectionX);
			float ty = intersectionY - floor(intersectionY);

			if (y < ceiling) {
				frame += " ";
			}
			else if (y >= ceiling && y <= floorr) {
				/*if (tx < 0.005 || tx > 0.995 || ty < 0.005 || ty > 0.995) { //  не очень красиво и минус фпс (ртикальные полосочки)
					frame += "|";
				}
				else */if (distance <= 4.0f)      frame += "█";
				else if (distance <= 7.0f) frame += "▓";
				else if (distance <= 10.0f) frame += "▒";
				else frame += "░";
			}
			else {
				frame += "~";
			}
		}
		frame += "\n";
	}
	std::cout << frame;
	frame.clear();
}