#include "node.h"

class AdjacencyList {
private:
    Node* head;

public:
    
  AdjacencyList();
  void insert(int value);
  void createConnection(int origin, int destiny);
  void graph(const std::string &filename);
};
