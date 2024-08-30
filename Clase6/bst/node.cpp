#include "node.h"

Node::Node(tm *value){
    this->value = value;
    right = nullptr;
    left = nullptr;
}


std::tm* Node::getValue(){
    return value;
}

Node* Node::getRight(){
    return right;
}

Node* Node::getLeft(){
    return left;
}

void Node::setValue(std::tm *value){
    this->value = value;
}

void Node::setRight(Node *right){
    this->right = right;
}

void Node::setLeft(Node *left){
    this->left = left;
}