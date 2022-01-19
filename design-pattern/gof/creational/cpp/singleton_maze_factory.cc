#include "singleton_maze_factory.h"

#include "pi_maze_factory.h"

MazeFactory* MazeFactory::instance_ = nullptr;

MazeFactory* MazeFactory::Instance() {
  if (instance_ == nullptr) {
    std::string name = "ohsu";  // Get it from somewhere.

    if (name == "pi") {
      instance_ = new PiMazeFactory;
    } else {
      instance_ = new MazeFactory;
    }
  }
  return instance_;
}

Maze* MazeFactory::MakeMaze() const { return new Maze{}; }

Wall* MazeFactory::MakeWall() const { return new Wall{}; }

Room* MazeFactory::MakeRoom(int room_number) const { return new Room{room_number}; }

Door* MazeFactory::MakeDoor(Room* room1, Room* room2) const {
  return new Door{room1, room2};
}
