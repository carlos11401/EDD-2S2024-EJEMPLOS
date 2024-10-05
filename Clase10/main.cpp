// #include "./graph/graph_matrix.h"
// int main() {
//     Graph mygraph(5);
//     mygraph.addEdge(0, 1);
//     mygraph.addEdge(0, 4);
//     mygraph.addEdge(1, 2);
//     mygraph.addEdge(1, 3);
//     mygraph.addEdge(1, 4);
//     mygraph.addEdge(3, 4);
    
//     std::cout << "Matriz de Adyacencia:" << std::endl;
//     mygraph.print();

//     return 0;
// }

#include "./graph2/graph.h"
int main() {
    AdjacencyList mygraph;

    mygraph.insert(1);
    mygraph.insert(3);
    mygraph.insert(2);
    mygraph.insert(4);

    mygraph.createConnection(1, 2);
    mygraph.createConnection(2, 1);

    mygraph.createConnection(1, 3);
    mygraph.createConnection(3, 1);

    mygraph.createConnection(3, 4);

    //mygraph.graph("mi_grafo");

    return 0;
}