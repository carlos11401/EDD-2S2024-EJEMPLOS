#include <iostream> // Tell the copiler to use I/O functions
using namespace std;

class Node {
public:
    string value;
    Node* left;
    Node* right;

    Node(string data) {
        value = data;
        left = nullptr;
        right = nullptr;
    }
};