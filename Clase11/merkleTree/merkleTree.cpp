#include "merkleTree.h"
#include <fstream>
#include <cmath>

MerkleTree::MerkleTree(){
  root = nullptr;
}

vector<Node *> *MerkleTree::getList()
{
  vector<Node *> *newListNodes = new vector<Node *>();
  getList(newListNodes, root);

  return newListNodes;
}
// getting last nodes in tree ROAM(in_order)
void MerkleTree::getList(vector<Node *> *nodes, Node *current)
{
  if (current != nullptr)
  {
    getList(nodes, current->left);
    // verify if is the last node
    if (current->right == nullptr && current->value != "-1")
    {
      nodes->push_back(current);
    }
    getList(nodes, current->right);
  }
}

void MerkleTree::insert(string value)
{
  Node *newNode = new Node(value);
  if (this->root == nullptr)
  {
    /*
      Adding new node, 
      but like has to have parity
      add -1 
    */
    vector<Node *> *nodes = new vector<Node *>();
    nodes->push_back(newNode);
    nodes->push_back(new Node("-1"));
    buildTree(nodes);
  }
  else
  {
    vector<Node *> *nodes = new vector<Node *>();
    nodes = getList();
    nodes->push_back(newNode);
    buildTree(nodes);
  }
}

void MerkleTree::buildTree(std::vector<Node *> *nodes)
{
  float numberLeafNodes = float(nodes->size());
  int noLevels = 1;

  // Calculate number of levels
  while ((numberLeafNodes / 2) > 1)
  {
    noLevels++;
    numberLeafNodes /= 2;
  }

  // Calculate the total number of nodes based on the number of levels
  int totalLeafNodes = pow(2, noLevels);

  // Fill vector on remaining nodes with "-1"
  while (nodes->size() < totalLeafNodes)
  { 
    nodes->push_back(new Node("-1"));
  }

  /*
    Reduce the vector by half 
    until there is only one 
    node left (root)
  */
  while (nodes->size() > 1)
  {
    // Saving and erasing the 2 first nodes
    Node *leftNode = (*nodes)[0];
    Node *rightNode = (*nodes)[1];
    nodes->erase(nodes->begin());
    nodes->erase(nodes->begin());
    // Getting hash of parent
    string hash = sha256(leftNode->value + rightNode->value);
    Node* parent = new Node(hash);
    parent->left = leftNode;
    parent->right = rightNode;
    // Add parent, here is where list come to redicing in half
    nodes->push_back(parent);
  }

  // Only one node remains, which will be the root of the tree
  this->root = *(nodes->begin());
}


void MerkleTree::generateGraph(string &filename)
{
  std::ofstream file(filename + ".dot");
  file << "digraph G {" << std::endl;
  file << "node [shape=box];" << std::endl;
  writeNode(file, root);
  file << "}" << std::endl;
  file.close();

  // Comando para generar la imagen (solo funciona en sistemas con Graphviz instalado)
  std::string command = "dot -Tpng " + filename + ".dot -o " + filename + ".png";
  int result = system(command.c_str());

  if (result != 0)
  {
    std::cout << "Ocurrió un error al generar la imagen.\n";
  }
  else
  {
    std::cout << "La imagen fue generada exitosamente.\n";
  }
}

// Función recursiva para escribir los nodos en el archivo DOT
void MerkleTree::writeNode(std::ofstream &file, Node *node)
{
  if (node == nullptr)
    return;

  file << "\"" << node << "\"" << " [label=\"" << node->value << "\"];" << std::endl;

  if (node->left)
  {
    file << "\"" << node << "\" -> \"" << node->left << "\";" << std::endl;
    writeNode(file, node->left);
  }
  if (node->right)
  {
    file << "\"" << node << "\" -> \"" << node->right << "\";" << std::endl;
    writeNode(file, node->right);
  }
}
