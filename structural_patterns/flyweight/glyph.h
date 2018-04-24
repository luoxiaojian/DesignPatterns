#ifndef GLYPH_H_
#define GLYPH_H_

#include <iostream>

class Window;

class BTree;
class Font {
 public:
  Font(char* name) : _name(name) {}

 private:
  char* _name;
};

class GlyphContext {
 public:
  GlyphContext() {}
  virtual ~GlyphContext() {}

  virtual void Next(int step = 1);
  virtual void Insert(int quantity = 1);

  virtual Font* GetFont() { return 0; }
  virtual void SetFont(Font*, int span = 1) {}

 private:
  int _index;
  BTree* _fonts;
};

class Glyph {
 public:
  Glyph() { std::cout << "Glyph::Glyph()" << std::endl; }
  virtual ~Glyph() { std::cout << "Glyph::~Glyph()" << std::endl; }

  virtual void Draw(Window*, GlyphContext&) {
    std::cout << "Glyph::Draw" << std::endl;
  }

  virtual void SetFont(Font*, GlyphContext&) {
    std::cout << "Glyph::SetFont" << std::endl;
  }
  virtual Font* GetFont(GlyphContext&) {
    std::cout << "Glyph::GetFont" << std::endl;
    return 0;
  }

  virtual void First(GlyphContext&) {
    std::cout << "Glyph::First" << std::endl;
  }
  virtual void Next(GlyphContext&) { std::cout << "Glyph::Next" << std::endl; }
  virtual bool IsDone(GlyphContext&) {
    std::cout << "Glyph::IsDone" << std::endl;
    return 0;
  }
  virtual Glyph* Current(GlyphContext&) {
    std::cout << "Glyph::Current" << std::endl;
    return 0;
  }

  virtual void Insert(Glyph*, GlyphContext&) {
    std::cout << "Glyph::Insert" << std::endl;
  }
  virtual void Remove(GlyphContext&) {
    std::cout << "Glyph::Remove" << std::endl;
  }

 protected:
  Glyph();
};

class Character : public Glyph {
 public:
  Character(char charcode) : _charcode(charcode) {}
  virtual void Draw(Window*, GlyphContext&) {}

 private:
  char _charcode;
};

class Column {};
class Row {};

#endif
