#ifndef ROOM_H_
#define ROOM_H_

#include "map_site.h"

#include <iostream>

class Room : public MapSite {
 public:
  Room(int room_number) : room_number_(room_number) {

  }

  MapSite* side(Direction direction) const {
    return sides_[static_cast<int>(direction)];
  }

  void set_side(Direction direction, MapSite* map_site) {
    sides_[static_cast<int>(direction)] = map_site;
  }

  void Enter() override {}

  int room_number() const { return room_number_; }

 private:
  MapSite* sides_[4];
  int room_number_;
};

#endif  // ROOM_H_
