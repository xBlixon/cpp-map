#include <iostream>
#include "include/map.h"

int main() {
    map<char, int> lol;
    lol.insert('b', 67);
    lol.remove('b');
    auto b = lol.find('b');
    if (b) {
        std::cout<<b.value()<<std::endl;
    }
    return 0;
}
