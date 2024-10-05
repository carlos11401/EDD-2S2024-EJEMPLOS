#include "graph_matrix.h"

Graph::Graph(int n): numVertex(n), matrix(n, vector<int>(n,0)){}

void Graph::addEdge(int i, int j){
  matrix[i][j] = 1;
  matrix[j][i] = 1;
}
void Graph::print() {
  for (int i = 0; i < numVertex; ++i) {
      for (int j = 0; j < numVertex; ++j) {
          std::cout << matrix[i][j] << " ";
      }
      std::cout << std::endl;
  }
}