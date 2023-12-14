#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <string>
#include "Tile.h"

class Robot;
class Maze {
	public:
		constexpr static int LABIRINTH_WIDTH = 9;
		constexpr static int LABIRINTH_HEIGHT = 9;
		friend class Robot;

	private:
		Robot& robot;
		Tile labirinth[LABIRINTH_WIDTH][LABIRINTH_HEIGHT];

	public: 
		Maze(std::string inputFile, Robot& robot);
		void print(void);
		bool isTileValid(int x, int y);
};

#endif