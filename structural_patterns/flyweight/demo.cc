#include <iostream>

#include "card.h"
#include "card_cache.h"

using namespace FlyWeight;

int main(int argc, char** argv) {
  std::cout << "======================================" << std::endl;
  std::cout << "==========[FlyWeight Demo]============" << std::endl;
  std::cout << "======================================" << std::endl;

#ifdef SHOW_RANDOM_CARDS

  for (int index = 0; index < 53; ++index) {
    Card& floppedCard = CardCache::instance()->GetCard(GenerateRandomSuite(),
                                                       GenerateRandomValue());
    std::cout << floppedCard << " @ " << &floppedCard << std::endl;
  }

#else

  Card& a = CardCache::instance()->GetCard(HEARTS, QUEEN);
  Card& b = CardCache::instance()->GetCard(SPADES, JACK);
  Card& c = CardCache::instance()->GetCard(HEARTS, FIVE);
  Card& d = CardCache::instance()->GetCard(CLUBS, TWO);
  Card& e = CardCache::instance()->GetCard(DIAMONDS, QUEEN);
  Card& f = CardCache::instance()->GetCard(SPADES, ACE);
  Card& g = CardCache::instance()->GetCard(HEARTS, KING);
  Card& h = CardCache::instance()->GetCard(DIAMONDS, QUEEN);
  Card& i = CardCache::instance()->GetCard(CLUBS, TWO);
  Card& j = CardCache::instance()->GetCard(HEARTS, FIVE);
  Card& k = CardCache::instance()->GetCard(SPADES, JACK);
  Card& l = CardCache::instance()->GetCard(HEARTS, JACK);

  std::cout << a << " @ " << &a << std::endl;
  std::cout << b << " @ " << &b << std::endl;
  std::cout << c << " @ " << &c << std::endl;
  std::cout << d << " @ " << &d << std::endl;
  std::cout << e << " @ " << &e << std::endl;
  std::cout << f << " @ " << &f << std::endl;
  std::cout << g << " @ " << &g << std::endl;
  std::cout << h << " @ " << &h << std::endl;
  std::cout << i << " @ " << &i << std::endl;
  std::cout << j << " @ " << &j << std::endl;
  std::cout << k << " @ " << &k << std::endl;
  std::cout << l << " @ " << &l << std::endl;

#endif

  std::cout << std::endl;
  return 0;
}
