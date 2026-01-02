template <typename K, typename V>
pair<K, V>::pair(K k, V v) : _key(k), _value(v) {};

template<typename K, typename V>
K pair<K, V>::key() {
    return _key;
}

template<typename K, typename V>
V pair<K, V>::value() {
    return _value;
}