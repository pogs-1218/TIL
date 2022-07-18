#ifndef MAZE_BUILDER_H_
#define MAZE_BUILDER_H_

#include "maze.h"

// Q: Not pure virtual functions, why?
class MazeBuilder {
 public:
  virtual void BuildMaze() {}
  virtual void BuildRoom(int room) {}
  virtual void BuildDoor(int room_from, int room_to) {}

  virtual Maze* maze() { return nullptr; }

 protected:
  MazeBuilder();
};

#endif
