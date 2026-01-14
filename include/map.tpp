#pragma once
#include "pair.h"
#include "Node.h"

#include <iostream>
#include <ostream>

template<class K, class V>
map<K, V>::map() = default;

template<class K, class V>
void map<K, V>::insert(K key, V value) {
    store.insert(pair<K, V>(key, value));
}

template<class K, class V>
pair<K, V> map<K, V>::find(K key) {
    auto temp = pair<K, V>(key, V());
    auto node = store.find(temp);
    if (node) {
        return node->value;
    }

    auto fake = pair<K, V>(K(), V());
    fake._setExists(false);
    return fake;
}

template<class K, class V>
void map<K, V>::remove(K key) {
    auto temp = pair<K, V>(key, V());
    store.remove(temp);
}
