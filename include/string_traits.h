#ifndef MAP_STRING_TRAITS_H
#define MAP_STRING_TRAITS_H
#include <string>

template <typename T>
struct string_traits {
    static std::string stringify(const T& value) {
        return std::to_string(value);
    }
};

template <>
struct string_traits<int> {
    static std::string stringify(int value) {
        return std::to_string(value);
    }
};

template <>
struct string_traits<char> {
    static std::string stringify(char value) {
        std::string s = "'";
        s += value;
        s += "'";
        return s;
    }
};

template <>
struct string_traits<std::string> {
    static std::string stringify(const std::string& value) {
        return value;
    }
};

template <>
struct string_traits<bool> {
    static std::string stringify(bool value) {
        return value ? "true" : "false";
    }
};

template <typename K, typename V> struct pair;
template <typename K, typename V>
struct string_traits<pair<K, V>> {
    static std::string stringify(const pair<K, V> p) {
        return "{" + string_traits<K>::stringify(p.key()) +
               ": " + string_traits<V>::stringify(p.value()) + "}";
    }
};

#endif //MAP_STRING_TRAITS_H