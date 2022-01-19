#ifndef PI_MAZE_FACTORY_H_
#define PI_MAZE_FACTORY_H_

#include "singleton_maze_factory.h"

class PiMazeFactory : public MazeFactory{
 public:
  PiMazeFactory();
  ~PiMazeFactory() override;

  Wall* MakeWall() const override;
};

#endif
