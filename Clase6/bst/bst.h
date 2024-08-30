#include "node.h"

class BST
{
private:
  Node* root;

  Node* insert(Node* root, tm *value);
  bool parseDateString(string &date, tm *time);
  void graph(Node *root, ofstream &content);
public:
  BST(/* args */);

  void insert(string *value);
  void graph();
  //~BST();
};

