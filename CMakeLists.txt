cmake_minimum_required(VERSION 3.5)
project(Robot)

include_directories(include)

add_executable(main 
	src/main.cpp
	src/Robot.cpp
	src/RandomRobot.cpp
	src/RightHandRuleRobot.cpp
	src/Maze.cpp
)
