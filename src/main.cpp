#include "Maze.h"
#include "RandomRobot.h"
#include <cstdlib>
#include <thread>
#include <chrono>

int main(void) {
	int numOfMoves;
	char choice;
 	RandomRobot robot = RandomRobot();
	Maze maze1 = Maze("labyrinth1.txt", robot);
	Maze maze2 = Maze("labyrinth2.txt", 
	
	robot);

	std::cout <<"Choose the labyrinth you're trying to escape! 1 - Labyrinth 1, 2 Labyrinth 2" << std::endl;
	std::cout << "\n Labyrinth 1:" << std::endl;
	maze1.print();
	std::cout << "\n Labyrinth 2:" << std::endl;
	maze2.print();
	
	do{
		std::cout <<"\nYour choice: ";
		std::cin >> choice;
	}while(choice != '1' && choice != '2');

	switch (choice)
	{
	case '1':
		while(!robot.hasReachedExit(maze1)){
		system("cls"); // Pulisce la console in Windows
		robot.move(maze1);
		maze1.print();
		numOfMoves++;
		std::this_thread::sleep_for(std::chrono::milliseconds(33));

	}	
		break;
	
	case '2':
		while(!robot.hasReachedExit(maze2)){
		system("cls"); // Pulisce la console in Windows
		robot.move(maze2);
		maze2.print();
		numOfMoves++;
		std::this_thread::sleep_for(std::chrono::milliseconds(33));
	}
	default:
		break;
	}

	
	
	if(robot.hasReachedExit(maze1) || robot.hasReachedExit(maze2)){
		std::cout << "The robot escaped with " << numOfMoves << " moves!" <<std::endl;
	}


	return 0;
}