#include "./headers/node.h"

MatrixNode::MatrixNode(int col, int row, int value){
  this->col = col;
  this->row = row;
  this->value = value;
  up = nullptr;
  bottom = nullptr;
  right = nullptr;
  left = nullptr;
}