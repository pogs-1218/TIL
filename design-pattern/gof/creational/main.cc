#include "maze_game.h"
#include "maze_factory.h"

int main() {
  MazeGame game;
  MazeFactory default_factory;

  game.CreateMaze(default_factory);

  return 0;
}
