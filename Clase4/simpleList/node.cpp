#include "./headers/node.h"
// Default constructor
ListNode::ListNode(){
  next = nullptr;
  position = -1;
  access = nullptr;
}
// Parameterised constructor
ListNode::ListNode(int position){
  this->position = position;
  this->next = nullptr;
  this->access = nullptr;
}