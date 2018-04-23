#ifndef CREATIONAL_PATTERNS_MAZE_GAME_H_
#define CREATIONAL_PATTERNS_MAZE_GAME_H_

#include "creational_patterns/door.h"
#include "creational_patterns/maze.h"
#include "creational_patterns/room.h"
#include "creational_patterns/wall.h"

class MazeFactory;
class MazeBuilder;

class MazeGame {
 public:
  Maze* CreateMaze();

  Maze* CreateMaze(MazeFactory& factory);

  Maze* CreateMaze(MazeBuilder& builder);

  virtual Maze* MakeMaze() const { return new Maze; }

  virtual Wall* MakeWall() const { return new Wall; }

  virtual Room* MakeRoom(int n) const { return new Room(n); }

  virtual Door* MakeDoor(Room* r1, Room* r2) const { return new Door(r1, r2); }
};

class BombedMazeGame : public MazeGame {
 public:
  BombedMazeGame() {}

  virtual Wall* MakeWall() const { return new BombedWall; }

  virtual Room* MakeRoom(int n) const { return new RoomWithBomb(n); }
};

class EnchantedMazeGame : public MazeGame {
 public:
  EnchantedMazeGame() {}

  virtual Room* MakeRoom(int n) const {
    return new EnchantedRoom(n, CastSpell());
  }

  virtual Door* MakeDoor(Room* r1, Room* r2) const {
    return new DoorNeedingSpell(r1, r2);
  }

 protected:
  Spell* CastSpell() const;
};

#endif
