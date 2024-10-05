#include <iostream>
#include <memory>
#include <fstream>
#include <sstream>

class Neighbor {
public:
    int value;
    Neighbor *next;

    Neighbor(int val) {
      value = val;
      next = nullptr;
    }
};

class Node {
public:
    int value;
    Node* next;
    Neighbor* neighbors;

    Node(int val);
    void insertNeighbor(int destiny);
    void graphNeighbors(std::ofstream &out);
};