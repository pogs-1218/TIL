#ifndef MAZE_GAME_H_
#define MAZE_GAME_H_

#include "maze_factory.h"
#include "maze_builder.h"

class MazeGame {
 public:
  Maze* CreateMaze();

  Maze* CreateMaze(MazeFactory& factory);
  Maze* CreateMaze(MazeBuilder& builder);
};

#endif  // MAZE_GAME_H_
