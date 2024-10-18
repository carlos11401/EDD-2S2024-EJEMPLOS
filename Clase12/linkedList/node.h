#include <iostream> // Tell the copiler to use I/O functions
#include "../huffman/node.h"
using namespace std;

class Node{
  private:
  public:
    // CONSTRUCTORS 
    Node();   // Default constructor
    Node(HuffmanNode* huffNode);  //Parameterised Constructor

    Node *next;
    HuffmanNode* huffNode;

};
