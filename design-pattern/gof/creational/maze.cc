#include "maze.h"

#include <iostream>

Maze::Maze()
{
  std::cout << "Maze is created\n";
}

void Maze::AddRoom(Room* room) {
  rooms_[room->room_number()] = room;
}

Room* Maze::room(int room_number) const {
  auto search = rooms_.find(room_number);
  return search == rooms_.end() ? nullptr : search->second;
}
