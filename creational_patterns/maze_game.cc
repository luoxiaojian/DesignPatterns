#include "creational_patterns/maze_game.h"

Maze *MazeGame::CreateMaze() {
  Maze *aMaze = new Maze;
  Room *r1 = new Room(1);
  Room *r2 = new Room(2);
  Door *theDoor = new Door(r1, r2);

  aMaze->AddRoom(r1);
  aMaze->AddRoom(r2);

  r1->SetSide(North, new Wall);
  r1->SetSide(East, theDoor);
  r1->SetSide(South, new Wall);
  r1->SetSide(West, new Wall);

  r2->SetSide(North, new Wall);
  r2->SetSide(East, new Wall);
  r2->SetSide(South, new Wall);
  r2->SetSide(West, theDoor);

  return aMaze;
}

Maze *MazeGame::CreateMaze(MazeFactory &factory) {
  Maze *aMaze = factory.MakeMaze();
  Room *r1 = factory.MakeRoom(1);
  Room *r2 = factory.MakeRoom(2);
  Door *theDoor = factory.MakeDoor(r1, r2);

  aMaze->AddRoom(r1);
  aMaze->AddRoom(r2);

  r1->SetSide(North, factory.MakeWall());
  r1->SetSide(East, theDoor);
  r1->SetSide(South, factory.MakeWall());
  r1->SetSide(West, factory.MakeWall());

  r2->SetSide(North, factory.MakeWall());
  r2->SetSide(East, factory.MakeWall());
  r2->SetSide(South, factory.MakeWall());
  r2->SetSide(West, theDoor);

  return aMaze;
}

Maze *MazeGame::CreateMaze(MazeBuilder &builder) {
  builder.BuildMaze();

  builder.BuildRoom(1);
  builder.BuildRoom(2);
  builder.BuildRoom(1, 2);

  return builder.GetMaze();
}
