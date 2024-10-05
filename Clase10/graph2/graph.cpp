#include "graph.h"

AdjacencyList::AdjacencyList() {
  head = nullptr;
}

// Insertar un nuevo nodo
void AdjacencyList::insert(int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
    } else if (value < head->value) {
        newNode->next = head;
        head = newNode;
    } else {
        auto aux = head;
        while (aux->next && aux->next->value < value) {
            aux = aux->next;
        }
        newNode->next = aux->next;
        aux->next = newNode;
    }
}

// Crear una conexión entre dos nodos
void AdjacencyList::createConnection(int origin, int destiny) {
  Node* current = head;
  while (current) {
      if (current->value == origin) {
          current->insertNeighbor(destiny);
          break;
      }
      current = current->next;
  }
}
// Generar el archivo dot y la imagen del grafo
void AdjacencyList::graph(const std::string &filename) {
    std::ofstream out(filename + ".dot");
    if (!out) {
        std::cerr << "Error al crear el archivo dot\n";
        return;
    }

    out << "digraph g {\n";
    out << "rankdir=LR;\n";

    Node* current = head;
    while (current) {
        out << "\"Nodo" << current->value << "\" [label=\"" << current->value << "\"];\n";
        current->graphNeighbors(out);
        current = current->next;
    }

    out << "}\n";
    out.close();

    // Comando para generar la imagen (solo funciona en sistemas con Graphviz instalado)
    std::string command = "dot -Tpng " + filename + ".dot -o " + filename + ".png";
    int result = system(command.c_str());

    if (result != 0) {
        std::cout << "Ocurrió un error al generar la imagen.\n";
    } else {
        std::cout << "La imagen fue generada exitosamente.\n";
    }
}