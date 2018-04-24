#ifndef STRUCTURAL_PATTERNS_ADAPTER_CLASS_ADAPTER_TEXT_SHAPE_H_
#define STRUCTURAL_PATTERNS_ADAPTER_CLASS_ADAPTER_TEXT_SHAPE_H_

#include "structural_patterns/adapter/shape.h"
#include "structural_patterns/adapter/text_view.h"

class TextShape : public Shape, private TextView {
 public:
  TextShape() {}
  virtual void BoundingBox(Point& bottomLeft, Point& topRight) const {
    Coord bottom, left, width, height;
    GetOrigin(bottom, left);
    GetExtent(width, height);

    bottomLeft = Point(bottom, left);
    topRight = Point(bottom + height, left + width);
  }

  virtual void IsEmpty() const {
    return TextView::IsEmpty();
  }

  virtual Manipulator* CreateManipulator() const {
    return new TextManipulator(this);
  }
};

#endif
