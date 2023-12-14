#ifndef ROBOT_H
#define ROBOT_H

#include "Maze.h"

class Robot {
	protected:
		int x;
		int y;
		
	public:
		virtual void move(Maze& maze) = 0;
		void setCoordinates(int newX, int newY);
		bool hasReachedExit(const Maze& maze);
		friend class Maze;
};

#endif