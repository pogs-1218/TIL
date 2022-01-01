#ifndef DOOR_H_
#define DOOR_H_

#include "map_site.h"
#include <iostream>

class Door: public MapSite {
 public:
  Door(Room* room1 = nullptr, Room* room2 = nullptr)
    : room1_(room1), room2_(room2), is_open_(false) {

  }
  
  Room* OtherSideFrom(Room* other_room);

  void Enter() override {
    std::cout << "Door entered" << std::endl;
  }

 private:
  Room* room1_;
  Room* room2_;
  bool is_open_;
};

#endif  // DOOR_H_
