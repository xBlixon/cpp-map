# Ordered Map
This is a final project for Fundamentals of Computer Programming course at the [Silesian University of Technology](https://www.polsl.pl/en/) for the third semester 2025/2026 of Informatics.

---
## About
This project is meant to implement logic of the [std::map](https://en.cppreference.com/w/cpp/container/map.html). The containter under the hood uses Red-Black Tree for accomplishing sorting and quick access to the stored data. The Red-Black Tree itself was realized as a separate project which can be seen in [this repository](https://github.com/xBlixon/Red-Black-Tree-Cpp).

The library allows for the following:
- insertion
- deletion
- searching
- serialization
- iteration via iterators
- integrating custom types

## Intro
The ordered map works as a storage with sorted values which themselves are key-value pairs.
The key has two purposes. One is to determine the "score" of the pair and based on the score determine it's place within the storage for quick access. 
The second purpose is to be able to access the value given some key.
The value part is just to store some value accessed via the key.

## Usage
As said earlier this project uses separate repository to do its entire logic.
That said before one can use it, the Red-Black Tree repository must be cloned
to the root directory of this project.

While being in the root directory of the project execute:
```
git clone https://github.com/xBlixon/Red-Black-Tree-Cpp.git
```
This is so that the CMake can bind the Tree project with the Map project.

After that you're ready to try the library on your own!

### Creating map
```c++
#include "include/map.h"
map<keyType, valueType> myMap();
```

### Inserting values
```c++
myMap.insert(key, value);
```
The key and the value can be virtually any type as long as its [implemented](#implementing-custom-types).

### Removing values
```c++
myMap.remove(key);
```

### Searching for a pair
```c++
myMap.find(key);
```

### Serialization
The container allows to serialize/export data to a text file.
```c++
myMap.toFile("path here");
```

### Iterators
Iterators work as your regular iterators.
```c++
// Iterator of the "smallest"/first element
auto it = myMap.begin();

myMap.end(); // In practice its nullptr which 
// is meant to indicate 1 past the last element.

it++; // Post-incrementing
++it; // Pre-incrementing

it--; // Post-decrementing
--it; // Pre-decrementing

it->first // Key
it->second // Value

// Removing elements from the map using iterator
myMap.erase(it);
```

### Pair methods
```c++
pair<keyType, valueType> myPair = myMap.find(somekey);

myPair->first  // Key
myPair->second // Value

myPair->key()   // Key 
myPair->value() // Value

// Returns bool depending whether the pair was
// successfully found inside the map or no.
// If the key doesn't exist in the map.
// Then the map returns a fake pair with no values
// and the method exists() returning false.
myPair.exists() 
// On the other hand if the pair was found and returned
// the method exists() would return true.
```

For real code example look in the `main.cpp` file.

---
## Implementing custom types
In order to fully support a custom type the user is required to implement
two fairly simple structs.
### score_traits
The score_traits struct exists, so that the pair will be seated in the right spot in the map.
That's determined using the score.
```c++
template<>
struct score_traits<YOUR CUSTOM TYPE HERE> {
    static unsigned int get(const int &key) {
        // Your custom logic for determining the score.
        // ...
        return final_score;
    }
};
```
### string_traits

The string_traits struct exists so that implementing serialization is an easy process.
```c++
template <>
struct string_traits<YOUR CUSTOM TYPE HERE> {
    static std::string stringify(const std::string& value) {
        // Your logic for stringifying the type.
        // ...
        return serialized_data_text;
    }
};
```
While it is recommened to use both traits in separate files. Just for the purpose of testing
the library in local environment, I suggest trying it within the existing files: `score_traits.h` and `string_traits.h`.

---
#### &copy; 2026 Xawier Słupik - Licensed under MIT License