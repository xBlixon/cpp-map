#include <iostream>
#include "include/map.h"

int main() {
    map<char, int> lol;
    lol.insert('b', 67);
    lol.insert('z', 3);
    lol.insert('c', 21);
    // lol.remove('b');
    auto b = lol.find('b');
    if (b) {
        std::cout<<b.value()<<std::endl;
    }

    lol.toFile("C:/Users/Blixon/lol.txt");
    return 0;
}
