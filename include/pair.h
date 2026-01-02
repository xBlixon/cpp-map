#ifndef MAP_PAIR_H
#define MAP_PAIR_H

template <typename K, typename V>
class pair {
private:
    K _key;
    V _value;

public:
    pair(K k, V v);

    K key();
    V value();
};

#include "pair.tpp"
#endif //MAP_PAIR_H