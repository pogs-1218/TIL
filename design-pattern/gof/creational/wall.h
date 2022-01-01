#ifndef WALL_H_
#define WALL_H_

#include "map_site.h"

class Wall : public MapSite {
 public:
  Wall() = default;

  void Enter() override {}
};

#endif  // WALL_H_
