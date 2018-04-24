#ifndef STRUCTURAL_PATTERNS_ADAPTER_OBJECT_ADAPTER_TEXT_SHAPE_H_
#define STRUCTURAL_PATTERNS_ADAPTER_OBJECT_ADAPTER_TEXT_SHAPE_H_

#include "structural_patterns/adapter/shape.h"
#include "structural_patterns/adapter/text_view.h"

class TextShape : public Shape {
 public:
  TextShape(TextView* t) : _text(t) {}
  virtual void BoundingBox(Point& bottomLeft, Point& topRight) const {
    Coord bottom, left, width, height;
    _text->GetOrigin(bottom, left);
    _text->GetExtent(width, height);

    bottomLeft = Point(bottom, left);
    topRight = Point(bottom + height, left + width);
  }

  virtual void IsEmpty() const { return _text->IsEmpty(); }

  virtual Manipulator* CreateManipulator() const {
    return new TextManipulator(this);
  }

 private:
  TextView* _text;
};

#endif
