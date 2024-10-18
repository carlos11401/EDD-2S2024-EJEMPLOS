#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

using namespace std;

// Nodo del árbol de Huffman
class HuffmanNode {
public:
    char data;
    int freq;
    HuffmanNode* left;
    HuffmanNode* right;

    // Constructor
    HuffmanNode(char data, int freq) {
        this->data = data;
        this->freq = freq;
        left = right = nullptr;
    }
};
#endif