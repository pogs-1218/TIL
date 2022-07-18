#ifndef MAZE_FACTORY_H_
#define MAZE_FACTORY_H_

#include "maze.h"
#include "room.h"
#include "wall.h"
#include "door.h"

class MazeFactory {
 public:
  MazeFactory() = default;

  virtual Maze* MakeMaze() const { return new Maze(); }
  virtual Wall* MakeWall() const { return new Wall(); }
  virtual Room* MakeRoom(int room_number) const { return new Room(room_number); }
  virtual Door* MakeDoor(Room* room1, Room* room2) const { return new Door(room1, room2); }
};

#endif // MAZE_FACTORY_H_
