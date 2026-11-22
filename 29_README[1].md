# Smart City Services & Route Management System

This repository is a split, modular version of the supplied `SmartCity_Final_Basic_Libraries.cpp`.

## Concepts used
- C++ class
- Linked list for services
- Graph / adjacency matrix for roads
- Linear search
- Dijkstra's algorithm
- Manual traffic, road-condition and road-closure updates

## Route weight
`Weight = Distance + (Traffic - 1) * 3 + (Condition - 1) * 2`

Closed roads are ignored.

## Build
Compile all `.cpp` files together with C++17 or later.

Example:
`g++ -std=c++17 *.cpp -o smart_city`

The project uses sample city and road data. It does not provide live GPS, live traffic, online maps or permanent database storage.
