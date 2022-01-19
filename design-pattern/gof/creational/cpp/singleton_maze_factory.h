#ifndef SINGLETON_MAZE_FACTORY_H_
#define SINGLETON_MAZE_FACTORY_H_

#include "door.h"
#include "maze.h"
#include "room.h"
#include "wall.h"

class MazeFactory {
 public:
  static MazeFactory* Instance();

  virtual Maze* MakeMaze() const;
  virtual Wall* MakeWall() const;
  virtual Room* MakeRoom(int room_number) const;
  virtual Door* MakeDoor(Room* room1, Room* room2) const;

 protected:
  MazeFactory() = default;
  virtual ~MazeFactory() = default;

 private:
  static MazeFactory* instance_;
};

#endif
