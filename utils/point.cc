#include "utils/point.h"

const Point Point::Zero(0, 0);

Point operator+(const Point &lhs, const Point &rhs) {
  Point ret(lhs);
  ret += rhs;
  return ret;
}

Point operator-(const Point &lhs, const Point &rhs) {
  Point ret(lhs);
  ret -= rhs;
  return ret;
}

Point operator*(const Point &lhs, const Point &rhs) {
  Point ret(lhs);
  ret *= rhs;
  return ret;
}

Point operator/(const Point &lhs, const Point &rhs) {
  Point ret(lhs);
  ret /= rhs;
  return ret;
}

bool operator==(const Point &lhs, const Point &rhs) {
  return lhs._x == rhs._x && lhs._y == rhs._y;
}

bool operator!=(const Point &lhs, const Point &rhs) {
  return lhs._x != rhs._x || lhs._y != rhs._y;
}

std::ostream operator<<(std::ostream &out, const Point &p) {
  out << "(" << p._x << ", " << p._y << ")";
  return out;
}

std::istream operator>>(std::istream &in, Point &p) {
  in >> p._x >> p._y;
  if (!in) {
    p = Point();
  }
  return in;
}
