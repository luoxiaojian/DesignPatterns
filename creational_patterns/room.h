#ifndef CREATIONAL_PATTERNS_ROOM_H_
#define CREATIONAL_PATTERNS_ROOM_H_

#include "creational_patterns/map_site.h"
#include "creational_patterns/spell.h"

class Room : public MapSite {
 public:
  Room(int roomNo) : _roomNumber(roomNo) {}

  MapSite* GetSide(Direction d) const { return _sides[static_cast<int>(d)]; }
  void SetSide(Direction d, MapSite* m) { _sides[static_cast<int>(d)] = m; }

  virtual void Enter() {}

  int GetRoomNumber() const { return _roomNumber; }

 private:
  MapSite* _sides[4];
  int _roomNumber;
};

class EnchantedRoom : public Room {
 public:
  EnchantedRoom(int n, Spell* spell) : Room(n), _spell(spell) {}

 private:
  Spell* _spell;
};

class RoomWithBomb : public Room {
 public:
  RoomWithBomb(int n = 0, bool bombed = false) : Room(n), _bomb(bombed) {}
  RoomWithBomb(const RoomWithBomb& other) : Room(other) { _bomb = other._bomb; }
  bool HasBomb() { return _bomb; }

 private:
  bool _bomb;
};

#endif
