#include "node.h"

Node::Node(int val){
  value = val;
  next = nullptr;
  neighbors = nullptr;
}
// Insertar vecino a este nodo
void Node::insertNeighbor(int destiny) {
    Neighbor* newNeighbor = new Neighbor(destiny);
    if (!neighbors) {
        neighbors = newNeighbor;
    } else {
        Neighbor* current = neighbors;
        while (current->next) {
            if (current->value == destiny) return; // Evita duplicados
            current = current->next;
        }
        current->next = newNeighbor;
    }
}

// Generar el archivo de vecinos de este nodo
void Node::graphNeighbors(std::ofstream &out) {
    Neighbor* aux = neighbors;
    std::stringstream origin_name;
    origin_name << "\"Nodo" << value << "\"";
    while (aux) {
        if (aux->value < value) {
            std::stringstream destiny_name;
            destiny_name << "\"Nodo" << aux->value << "\"";
            out << origin_name.str() << " -> " << destiny_name.str() << " [dir = both];\n";
        }
        aux = aux->next;
    }
}