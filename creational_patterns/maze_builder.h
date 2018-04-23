#ifndef CREATIONAL_PATTERNS_MAZE_BUILDER_H_
#define CREATIONAL_PATTERNS_MAZE_BUILDER_H_

class Maze;

class MazeBuilder {
 public:
  virtual void BuildMaze() {}
  virtual void BuildRoom(int) {}
  virtual void BuildDoor(int, int) {}

  virtual Maze* GetMaze() { return 0; }

 protected:
  MazeBuilder() {}
};

class StandardMazeBuilder : public MazeBuilder {
 public:
  StandardMazeBuilder() { _currentMaze = 0; }

  virtual void BuildMaze() { _currentMaze = new Maze; }

  virtual void BuildRoom(int n) {
    if (!_currentMaze->RoomNo(n)) {
      Room* room = new Room(n);
      _currentMaze->AddRoom(room);
      room->SetSide(North, new Wall);
      room->SetSide(South, new Wall);
      room->SetSide(East, new Wall);
      room->SetSide(West, new Wall);
    }
  }

  virtual void BuildDoor(int n1, int n2) {
    Room* r1 = _currentMaze->RoomNo(n1);
    Room* r2 = _currentMaze->RoomNo(n2);
    Door* d = new Door(r1, r2);

    r1->SetSide(CommonWall(r1, r2), d);
    r2->SetSide(CommonWall(r2, r1), d);
  }

  virtual Maze* GetMaze() { return _currentMaze; }

 private:
  Direction CommonWall(Room* r1, Room* r2) {
    if (r1->GetRoomNumber() < r2->GetRoomNumber()) {
      return East;
    } else {
      return West;
    }
  }
  Maze* _currentMaze;
};

class CountingMazeBuilder : public MazeBuilder {
 public:
  CountingMazeBuilder() {
    _rooms = 0;
    _doors = 0;
  };

  virtual void BuildMaze() {}

  virtual void BuildRoom(int) { _rooms++; }

  virtual void BuildDoor(int, int) { _doors++; }

  virtual void AddWall(int, Direction);

  void GetCounts(int& rooms, int& doors) const {
    doors = _doors;
    rooms = _rooms;
  }

 private:
  int _doors;
  int _rooms;
};

#endif
