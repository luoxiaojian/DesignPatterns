#ifndef UTILS_POINT_H_
#define UTILS_POINT_H_

#include <iostream>
#include "utils/coord.h"

class Point {
 public:
  static const Point Zero;
  Point(Coord x = 0.0, Coord y = 0.0) : _x(x), _y(y) {}
  Coord X() const { return _x; }
  void X(Coord x) { _x = x; }
  Coord Y() const { return _y; }
  void Y(Coord y) { _y = y; }

  friend Point operator+(const Point&, const Point&);
  friend Point operator-(const Point&, const Point&);
  friend Point operator*(const Point&, const Point&);
  friend Point operator/(const Point&, const Point&);

  Point& operator+=(const Point& rhs) {
    _x += rhs._x;
    _y += rhs._y;
    return *this;
  }
  Point& operator-=(const Point& rhs) {
    _x -= rhs._x;
    _y -= rhs._y;
    return *this;
  }
  Point& operator*=(const Point& rhs) {
    _x *= rhs._x;
    _y *= rhs._y;
    return *this;
  }
  Point& operator/=(const Point& rhs) {
    _x /= rhs._x;
    _y /= rhs._y;
    return *this;
  }

  Point operator-() {
    Point ret(*this);
    ret._x = -ret._x;
    ret._y = -ret._y;
    return ret;
  }

  friend bool operator==(const Point&, const Point&);
  friend bool operator!=(const Point&, const Point&);

  friend std::ostream& operator<<(std::ostream&, const Point&);
  friend std::istream& operator>>(std::istream&, const Point&);

 private:
  Coord _x;
  Coord _y;
};

#endif
