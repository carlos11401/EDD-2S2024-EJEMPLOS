#include "./headers/node.h"

Node::Node(int age){
  this->age = age;
  next = nullptr;
  prev = nullptr;
}

void Node::print(){
  cout << "I have " << age << " years" << endl;
}