#ifndef STRUCTURAL_PATTERNS_ADAPTER_TEXT_VIEW_H_
#define STRUCTURAL_PATTERNS_ADAPTER_TEXT_VIEW_H_

#include "utils/coord.h"

class TextView {
 public:
  TextView() {
    _x = 1.0;
    _y = 2.0;
    _width = 3.0;
    _height = 4.0;
  }
  void GetOrigin(Coord& x, Coord& y) const {
    x = _x;
    y = _y;
  }
  void GetExtent(Coord& width, Coord& height) const {
    width = _width;
    height = _height;
  }
  virtual bool IsEmpty() const { return _width == 0 || _height == 0; }

 private:
  Coord _x;
  Coord _y;
  Coord _width;
  Coord _height;
};

#endif
