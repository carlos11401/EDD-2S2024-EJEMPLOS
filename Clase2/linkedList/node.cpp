#include "./headers/node.h"

Node::Node(){
  name = "";
  age = -1;
  next = nullptr;
}
Node::Node(string name, int age){
  this->name = name;
  this->age = age;
  next = nullptr;
}

void Node::print(){
  cout << "My name is " << name << " and i am " << age << "years old." << endl;
}