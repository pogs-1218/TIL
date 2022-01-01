#ifndef MAP_SITE_H_
#define MAP_SITE_H_

enum class Direction {
  North, South, East, West
};

class MapSite {
 public:
  virtual void Enter() = 0;
};

#endif // MAP_SITE_H_
