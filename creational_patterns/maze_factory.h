#ifndef CREATIONAL_PATTERNS_MAZE_FACTORY_H_
#define CREATIONAL_PATTERNS_MAZE_FACTORY_H_

class MazeFactory {
 public:
  MazeFactory() {}

  virtual Maze* MakeMaze() const { return new Maze; }

  virtual Wall* MakeWall() const { return new Wall; }

  virtual Room* MakeRoom(int n) const { return new Room(n); }

  virtual Door* MakeDoor(Room* r1, Room* r2) const { return new Door(r1, r2); }
};

class EnchantedMazeFactory : public MazeFactory {
 public:
  EnchantedMazeFactory();

  virtual Room* MakeRoom(int n) const {
    return new EnchantedRoom(n, CastSpell());
  }

  virtual Door* MakeDoor(Room* r1, Room* r2) const {
    return new DoorNeedingSpell(r1, r2);
  }

 protected:
  Spell* CastSpell() const { return new Spell; }
};

class MazePrototypeFactory : public MazeFactory {
 public:
  MazePrototypeFactory(Maze* m, Wall* w, Room* r, Door* d) {
    _prototypeMaze = m;
    _prototypeWall = w;
    _prototypeRoom = r;
    _prototypeDoor = d;
  }

  virtual Maze* MakeMaze() const { return _prototypeMaze->Clone(); }
  virtual Room* MakeRoom(int) const { return _prototypeRoom->Clone(); }
  virtual Wall* MakeWall() const { return _prototypeWall->Clone(); }
  virtual Door* MakeDoor(Room* r1, Room* r2) const {
    Door* door = _prototypeDoor->Clone();
    door->Initialize(r1, r2);
    return door;
  }

 private:
  Maze* _prototypeMaze;
  Room* _prototypeRoom;
  Wall* _prototypeWall;
  Door* _prototypeDoor;
};

#endif
