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
    pair<K, V> find(K key);
    void insert(K key, V value);
    void remove(K key);
};

#include "map.tpp"
#endif //MAP_MAP_H