#ifndef MAZE_GAME_H_
#define MAZE_GAME_H_

#include "maze_factory.h"

class MazeGame {
 public:
  Maze* CreateMaze();

  Maze* CreateMaze(MazeFactory& factory);
};

#endif  // MAZE_GAME_H_
