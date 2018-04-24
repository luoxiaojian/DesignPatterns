#ifndef STRUCTURAL_PATTERNS_ADAPTER_SHAPE_H_
#define STRUCTURAL_PATTERNS_ADAPTER_SHAPE_H_

class Manipulator {};

class Shape {
 public:
  Shape();
  virtual void BoundingBox(Point& bottomLeft, Point& topRight) const;
  virtual Manipulator* CreateManipulator() const;
};

class TextShape;

class TextManipulator : public Manipulator {
 public:
  TextManipulator(const TextShape* s) : _textShape(s) {}

 private:
  const TextShape* _textShape;
};

#endif
