#ifndef MAP_SCORE_TRAITS_H
#define MAP_SCORE_TRAITS_H
#include <string>

template <class K>
struct score_traits {
    static unsigned int get(const K &key);
};

template<>
struct score_traits<int> {
    static unsigned int get(const int &key) {
        return key;
    }
};

template<>
struct score_traits<char> {
    static unsigned int get(const char &key) {
        return key;
    }
};

template<>
struct score_traits<std::string> {
    static unsigned int get(const std::string &key) {
        return key[0];
    }
};

#endif //MAP_SCORE_TRAITS_H