#ifndef MAP_PAIR_H
#define MAP_PAIR_H

template <typename K, typename V>
class pair {
private:
    K _key;
    V _value;
    bool _doesExist = true;

public:
    pair(K k, V v);

    K key() const;
    V value() const;
    unsigned int score() const;
    void _setExists(bool tf);
    bool exists();

    explicit operator bool() const;
};

#include "pair.tpp"
#endif //MAP_PAIR_H