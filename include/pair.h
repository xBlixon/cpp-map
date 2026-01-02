#ifndef MAP_PAIR_H
#define MAP_PAIR_H

template <typename K, typename V>
class pair {
private:
    K key;
    V value;

public:
    pair(K k, V v) : key(k), value(v) {};
};


#endif //MAP_PAIR_H