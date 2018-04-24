#include "card.h"

namespace FlyWeight {

std::ostream& operator<<(std::ostream& os, Card& outCard) {
  os << "[" << outCard.GetValueString() << " of " << outCard.GetSuiteString()
     << "]";
  return os;
}

bool operator==(const Card& c1, const Card& c2) {
  return (c1.GetSuite() == c2.GetSuite() && c1.GetValue() == c2.GetValue());
}

suite GenerateRandomSuite() { return (suite)(rand() % NUM_SUITES); }

value GenerateRandomValue() { return (value)(rand() % NUM_VALUES); }

}  // namespace FlyWeight
