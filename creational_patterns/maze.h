#ifndef CREATIONAL_PATTERNS_MAZE_H_
#define CREATIONAL_PATTERNS_MAZE_H_

#include <vector>

#include "creational_patterns/room.h"

class Maze {
 public:
  Maze();

  Room* RoomNo(int n) const {
    std::vector<Room*>::const_iterator it = mRoomVec->begin();
    for (; it != mRoomVec->end(); ++it) {
      if ((*it)->GetRoomNumber() == n) {
        return (*it);
      }
    }
    return NULL;
  }

  void AddRoom(Room* room) { mRoomVec->push_back(room); }

 private:
  std::vector<Room*> mRoomVec;
};

#endif
