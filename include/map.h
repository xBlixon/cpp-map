#ifndef MAP_MAP_H
#define MAP_MAP_H
#include "map.h"
#include "pair.h"
#include "RedBlackTree.h"

template <class K, class V>
class map {
private:
    RedBlackTree<pair<K, V>> store;

public:
    map();
    void insert(K key, V value);
    pair<K, V> *find(K key);
};

#include "map.tpp"
#endif //MAP_MAP_H