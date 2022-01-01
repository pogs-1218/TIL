#include "maze_game.h"

// Q: What's the problem?
Maze* MazeGame::CreateMaze() {
  Maze* maze = new Maze();
  Room* room1 = new Room(1);
  Room* room2 = new Room(2);
  Door* door = new Door(room1, room2);

  maze->AddRoom(room1);
  maze->AddRoom(room2);

  room1->set_side(Direction::North, new Wall());
  room1->set_side(Direction::East, door);
  room1->set_side(Direction::South, new Wall());
  room1->set_side(Direction::West, new Wall());

  room2->set_side(Direction::North, new Wall());
  room2->set_side(Direction::East, new Wall());
  room2->set_side(Direction::South, new Wall());
  room2->set_side(Direction::West, door);

  return maze;
}

// Q: What's the pros and the cons
Maze* MazeGame::CreateMaze(MazeFactory& factory) {
  auto maze = factory.MakeMaze();
  auto room1 = factory.MakeRoom(1);
  auto room2 = factory.MakeRoom(2);
  auto door = factory.MakeDoor(room1, room2);

  maze->AddRoom(room1);
  maze->AddRoom(room2);
 
  room1->set_side(Direction::North, factory.MakeWall());
  room1->set_side(Direction::East, door);
  room1->set_side(Direction::South, factory.MakeWall());
  room1->set_side(Direction::West, factory.MakeWall());

  room2->set_side(Direction::North, factory.MakeWall());
  room2->set_side(Direction::East, factory.MakeWall());
  room2->set_side(Direction::South, factory.MakeWall());
  room2->set_side(Direction::West, door);

  return maze;
}
