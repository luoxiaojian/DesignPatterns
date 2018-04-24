#ifndef CARD_H_
#define CARD_H_

#include <iostream>
#include <string>
#include <cstdlib>

namespace FlyWeight {
#define NUM_SUITES 4
#define NUM_VALUES 12

typedef enum suite { HEARTS, CLUBS, DIAMONDS, SPADES };
typedef enum value {
  TWO,
  THREE,
  FOUR,
  FIVE,
  SIX,
  SEVEN,
  EIGHT,
  NINE,
  TEN,
  JACK,
  QUEEN,
  KING,
  ACE
};

class Card {
 public:
  Card() {}
  Card(suite is, value iv) : suite_(is), value_(iv) {}
  ~Card();

  suite GetSuite() const { return suite_; }
  value GetValue() const { return value_; }

  const std::string GetSuiteString() const {
    switch (suite_) {
      case DIAMONDS:
        return "DIAMONDS";
      case CLUBS:
        return "CLUBS";
      case HEARTS:
        return "HEARTS";
      case SPADES:
        return "SPADES";
    }
    return "";
  }
  const std::string GetValueString() const {
    switch (value_) {
      case ACE:
        return "ACE";
      case KING:
        return "KING";
      case QUEEN:
        return "QUEEN";
      case JACK:
        return "JACK";
      case TEN:
        return "10";
      case NINE:
        return "9";
      case EIGHT:
        return "8";
      case SEVEN:
        return "7";
      case SIX:
        return "6";
      case FIVE:
        return "5";
      case FOUR:
        return "4";
      case THREE:
        return "3";
      case TWO:
        return "2";
    }
    return "";
  }

 private:
  void SetSuite(suite is) { suite_ = is; }
  void SetValue(value iv) { value_ = iv; }

  suite suite_;
  value value_;
};

std::ostream& operator<<(std::ostream&, Card&);
bool operator==(const Card& c1, const Card& c2);
suite GenerateRandomSuite();
value GenerateRandomValue();

};  // namespace FlyWeight

#endif
