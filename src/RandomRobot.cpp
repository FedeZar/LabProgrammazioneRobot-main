#include "RandomRobot.h"

void RandomRobot::move(Maze& maze) {
	srand(time(NULL));
	int newX, newY;
	
	do {
		newX = this->x + (rand() % 3) - 1;
		newY = this->y + (rand() % 3) - 1;
		// std::cout << newX << ", " << newY << "\n";
	} while (!maze.isTileValid(newX, newY) || (newX == this->x && newY == this->y));
	
	this->x = newX;
	this->y = newY;
}