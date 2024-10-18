#include "node.h"
class SimpleList{
  private:
    Node *head;
  public:
    // DEFAULT CONSTRUCTOR
    SimpleList();
    // VARIABLES
    int size;
    // FUNCTIONS
    void push(HuffmanNode* huffNode);
    Node* pop();
    void print();
};
