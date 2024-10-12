#include "node.h"
#include <vector>
#include "../sha256/sha256.h"

class MerkleTree
{
private:
  vector<Node*> *getList();
  void getList(vector<Node*> *nodes, Node* current);
  void buildTree(vector<Node*> *nodes);
  string getRootHash();

  void writeNode(ofstream &file, Node *node);
public:
  MerkleTree(/* args */);

  Node* root;
  void insert(string value);
  void generateGraph(string &filename);
};

