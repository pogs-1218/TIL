#ifdef ENCHANTED_MAZE_FACTORY_H_
#define ENCHANTED_MAZE_FACTORY_H_

#include "maze_factory.h"

class EnchantedMazeFactory : public MazeFactory {
 public:
  EnchantedMazeFactory();

  Room* MakeRoom(int room_number) const override {
    return new EnchantedRoom(n, CastSpell());
  }

  Door* MakeDoor(Room* room1, Room* room2) const override {
    return new DoorNeedingSpell(room1, room2);
  }

 protected:
  Spell* CastSpell() const; 
};

#endif  // ENCHANTED_MAZE_FACTORY_H_
