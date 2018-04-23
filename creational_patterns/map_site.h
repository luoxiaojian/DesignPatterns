#ifndef CREATIONAL_PATTERNS_MAP_SITE_H_
#define CREATIONAL_PATTERNS_MAP_SITE_H_

enum Direction { North, South, East, West };

class MapSite {
 public:
  virtual void Enter() = 0;
};

#endif
