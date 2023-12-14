#include "Robot.h"
#include "Tile.h"

bool Robot::hasReachedExit(const Maze& maze) {
	return maze.labirinth[this->x][this->y] == Tile::EXIT;
}

void Robot::setCoordinates(int newX, int newY) { 
	this-> x = newX; 
	this->y = newY; 
};