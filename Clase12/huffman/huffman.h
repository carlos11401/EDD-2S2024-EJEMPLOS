#include "./node.h"
#include <string>
#include <iostream>
#include <unordered_map>

// Clase Huffman para la construcción del árbol y codificación
class Huffman
{
private:
  HuffmanNode *root;
  void generateCodes(HuffmanNode *node, string code, std::unordered_map<char, std::string> &huffmanCode);

public:
  Huffman() : root(nullptr) {}
  void buildHuffmanTree(string text);
  unordered_map<char, string> getHuffmanCodes();
  string compress(const string& text, unordered_map<char, string>& huffmanCodes);
  string decompress(const string& compressedText);
  unordered_map<char, int> countFrequencies(const string& text);
};