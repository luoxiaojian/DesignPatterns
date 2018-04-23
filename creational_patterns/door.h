#ifndef CREATIONAL_PATTERNS_DOOR_H_
#define CREATIONAL_PATTERNS_DOOR_H_

#include "creational_patterns/map_site.h"
#include "creational_patterns/room.h"

class Door : public MapSite {
 public:
  Door();
  Door(Room *r1, Room *r2) : _room1(r1), _room2(r2), {}
  Door(const Door &other) {
    _room1 = other._room1;
    _room2 = other._room2;
  }

  virtual void Initialize(Room *r1, Room *r2) {
    _room1 = r1;
    _room2 = r2;
  }
  virtual Door *Clone() const { return new Door(*this); }

  virtual void Enter() {}

  Room *OtherSideFrom(Room *r1) {
    if (r1 == _room1) {
      return _room2;
    }
    if (r1 == _room2) {
      return _room1;
    }
    return NULL;
  }

 private:
  Room *_room1;
  Room *_room2;
};

class DoorNeedingSpell : public Door {
 public:
  DoorNeedingSpell(Room *r1, Room *r2) : Door(r1, r2) {}
};

#endif
