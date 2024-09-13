#include "node.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#define LEFT_HEAVY -1
#define BALANCED 0
#define RIGHT_HEAVY 1
class AVL{
private:
  Node *root;

  Node* insert(Node* root, int value, bool &increase);
  Node* l_rotation(Node* n, Node* n1);
  Node* r_rotation(Node* n, Node* n1);
  Node* lr_rotation(Node* n, Node* n1);
  Node* rl_rotation(Node* n, Node* n1);
  void graph(Node *root, ofstream &content);
public:
  AVL(/* args */);
  //~AVL();

  void insert(int value);
  void graph();
};
