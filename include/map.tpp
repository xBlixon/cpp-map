#pragma once
#include "pair.h"
#include "Node.h"

#include <iostream>
#include <string>
#include <fstream>
#include "string_traits.h"

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

template<class K, class V>
void map<K, V>::toFile(const std::string& file) {
    if (!store._getRoot()) {
        std::cerr << "Empty map.\n";
        exit(1);
    }

    std::ofstream output(file);
    if (!output) {
        std::cerr << "Couldn't open file ( " << file << " )\n";
        exit(1);
    }

    toFileSubtree(store._getRoot(), output);

    output.close();
}

template<class K, class V>
void map<K, V>::toFileSubtree(Node<pair<K, V> > *node, std::ofstream &stream) {
    if (node->left) {
        toFileSubtree(node->left, stream); // Print left subtree
    }
    stream << string_traits<pair<K, V>>::stringify(node->value) << std::endl; // Print parent of subtrees (left, right)
    if (node->right) {
        toFileSubtree(node->right, stream); // Print right subtree
    }
}

template<class K, class V>
map<K, V>::iterator map<K, V>::begin() {
    return store.begin();
}

template<class K, class V>
map<K, V>::iterator map<K, V>::end() {
    return store.end();
}

template<class K, class V>
void map<K, V>::erase(iterator it) {
    store.erase(it);
}