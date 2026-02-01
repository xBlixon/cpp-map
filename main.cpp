#include <iostream>
#include "include/map.h"

int main() {
    map<char, int> myMap;
    myMap.insert('b', 67);
    myMap.insert('z', 3);
    myMap.insert('c', 21);
    auto b = myMap.find('b');
    if (b) {
        std::cout<<b.value()<<std::endl;
    }

    std::cout<< "Key : Value\n";
    for (auto pair : myMap) {
        std::cout<< pair.first << " : " << pair.second << std::endl;
    }

    auto i = myMap.begin();
    ++i;
    myMap.erase(i);
    // myMap.erase(myMap.begin());
    // myMap.erase(myMap.begin());

    std::cout<< "Value : Key\n";
    for (auto it = myMap.begin(); it != myMap.end(); ++it) {
        const auto pair = *it;
        std::cout<< pair.second << " : " << pair.first << std::endl;
    }

    // myMap.toFile("Your Path here");
    return 0;
}
