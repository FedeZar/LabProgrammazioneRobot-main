#include "Maze.h"
#include "Robot.h"
#include <iostream>
#include <fstream>

Maze::Maze(std::string filename, Robot& robot) : robot(robot) {
	std::ifstream file(filename);
	
	for (int i = 0; i < Maze::LABIRINTH_HEIGHT; i++) {
		std::string line;
		getline(file, line);
		for (int j = 0; j < Maze::LABIRINTH_WIDTH; j++) {
			this->labirinth[i][j] = Tile(line[j]);
			if (this->labirinth[i][j] == Tile::START) this->robot.setCoordinates(i, j);
		}
	}
}

void Maze::print(void) {
	for (int i = 0; i < Maze::LABIRINTH_HEIGHT; i++) {
		for (int j = 0; j < Maze::LABIRINTH_WIDTH; j++) {
			if (this->robot.x == i && this->robot.y == j) std::cout << "R ";
			else std::cout << (char) this->labirinth[i][j] << " ";
		}
		
		std::cout << "\n";
	}
}

bool Maze::isTileValid(int x, int y) {
	if (x > Maze::LABIRINTH_WIDTH || y > Maze::LABIRINTH_HEIGHT || x < 0 || y < 0)
		return false;
		
	return this->labirinth[x][y] != Tile::WALL;
}