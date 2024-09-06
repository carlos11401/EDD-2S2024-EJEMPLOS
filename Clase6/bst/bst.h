#include "node.h"

class BST
{
private:
  Node* root;

  Node* insert(Node* root, tm *value);
  bool parseDateString(string &date, tm *time);
  void preorder(Node *root);
  void deleteTree(Node* root);
  void graph(Node *root, ofstream &content);
public:
  BST(/* args */);

  void insert(string *value);
  void preorder();
  void deleteTree();
  void graph();
  ~BST();
};

