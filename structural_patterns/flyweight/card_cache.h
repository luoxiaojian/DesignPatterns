#ifndef CARD_CACHE_H_
#define CARD_CACHE_H_

#include <map>
#include <utility>

#include "card.h"

namespace FlyWeight {
class CardCache {
 public:
  static CardCache* instance() {
    static CardCache instance;
    return &instance;
  }

  Card& GetCard(suite s, value v) {
    if (pool_.find(std::pair<suite, value>(s, v)) != pool_.end()) {
      return pool_[std::pair<suite, value>(s, v)];
    } else {
      return (pool_[std::pair<suite, value>(s, v)] = Card(s, v));
    }
  }

 private:
  CardCache() {}
  CardCache(const CardCache&) {}
  CardCache& operator=(const CardCache&);

  std::map<std::pair<suite, value>, Card> pool_;
};
}  // namespace FlyWeight

#endif
