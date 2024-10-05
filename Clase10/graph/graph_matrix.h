#include <vector>
#include <iostream>

using namespace std;

class Graph
{
private:
  int numVertex;
  vector<vector<int>> matrix;

public:
  Graph(int n);
  void addEdge(int i, int j);
  void print();
};
