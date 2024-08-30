#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
#include <iomanip>
using namespace std;

class Node
{
private:
  tm *value;
  Node *right, *left;
public:
  Node(tm *value);
  tm* getValue();
  Node* getRight();
  Node* getLeft();

  void setValue(tm *value);
  void setRight(Node *right);
  void setLeft(Node *left);
};

