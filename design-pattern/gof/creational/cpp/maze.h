#ifndef MAZE_H_
#define MAZE_H_

#include "room.h"

#include <map>

class Maze {
 public:
  Maze();

  void AddRoom(Room* room);
  Room* room(int room_number) const;

 private:
  std::map<int, Room*> rooms_;
  
};

#endif  // MAZE_H_
