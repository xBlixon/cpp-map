#pragma once
#include "score_traits.h"

template <typename K, typename V>
pair<K, V>::pair(K k, V v) : first(k), second(v) {};

template<typename K, typename V>
K pair<K, V>::key() const {
    return first;
}

template<typename K, typename V>
V pair<K, V>::value() const {
    return second;
}

template<typename K, typename V>
unsigned int pair<K, V>::score() const {
    return score_traits<K>::get(this->first);
}

template<typename K, typename V>
void pair<K, V>::_setExists(const bool tf) {
    _doesExist = tf;
}

template<typename K, typename V>
bool pair<K, V>::exists() {
    return _doesExist;
}

template<typename K, typename V>
pair<K, V>::operator bool() const {
    return _doesExist;
}
