#include "./node.h"
// Default constructor
Node::Node(){
  // ch = '\0';
  // freq = -1;
  huffNode = nullptr;
  next = nullptr;
}
// Parameterised constructor
Node::Node(HuffmanNode* huffNode){
  // this->ch = ch;
  // this->freq = freq;
  this->huffNode = huffNode;
  this->next = nullptr;
}
