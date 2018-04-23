#ifndef CREATIONAL_PATTERNS_WALL_H_
#define CREATIONAL_PATTERNS_WALL_H_

#include "creational_patterns/map_site.h"

class Wall : public MapSite {
 public:
  Wall() {}
  virtual void Enter() {}
};

#endif
