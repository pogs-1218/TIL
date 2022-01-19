#include "pi_maze_factory.h"

PiMazeFactory::PiMazeFactory() {}

PiMazeFactory::~PiMazeFactory() = default;

Wall* PiMazeFactory::MakeWall() const { return new Wall{}; }
