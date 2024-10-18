#include "./huffman.h"
#include "../linkedList/mylist.h"


unordered_map<char, int> Huffman::countFrequencies(const string &text)
{
  unordered_map<char, int> freqMap;
  for (char ch : text)
  {
    freqMap[ch]++;
  }
  return freqMap;
}

void Huffman::buildHuffmanTree(string text)
{
  SimpleList priorityQueue;
  
  unordered_map<char, int> freqMap = countFrequencies(text);

  // Create a leaf node for each character and add it to the priority queue
  for (const auto &pair : freqMap)
  {
    priorityQueue.push(new HuffmanNode(pair.first, pair.second));
  }
  
  priorityQueue.print();
   cout << endl;
  // Iterate until only one node remains in the priority queue
  while (priorityQueue.size != 1)
  {
    
    
    // Extract the two nodes with the lowest frequencies
    HuffmanNode *left = priorityQueue.pop()->huffNode;
    HuffmanNode *right = priorityQueue.pop()->huffNode;

    // Create a new node that combines them
    int sum = left->freq + right->freq;
    HuffmanNode *newNode = new HuffmanNode('\0', sum); // '\0' indicates an internal node
    newNode->left = left;
    newNode->right = right;

    priorityQueue.push(newNode);
  }

  // The last remaining node is the root of the Huffman tree
  root = priorityQueue.pop()->huffNode;
}

unordered_map<char, string> Huffman::getHuffmanCodes()
{
  unordered_map<char, string> huffmanCode;
  generateCodes(root, "", huffmanCode);
  return huffmanCode;
}

void Huffman::generateCodes(HuffmanNode *node, string code, unordered_map<char, string> &huffmanCode)
{
  if (!node)
    return;

  // If it’s a leaf node, assign the code
  if (!node->left && !node->right)
  {
    huffmanCode[node->data] = code;
  }

  generateCodes(node->left, code + "0", huffmanCode);
  generateCodes(node->right, code + "1", huffmanCode);
}

string Huffman::compress(const string &text, unordered_map<char, string> &huffmanCodes)
{
  string compressedText = "";
  for (char ch : text)
  {
    compressedText += huffmanCodes[ch];
  }
  return compressedText;
}

string Huffman::decompress(const string &compressedText)
{
  string decompressedText = "";
  HuffmanNode *currentNode = root;
  for (char bit : compressedText)
  {
    if (bit == '0')
    {
      currentNode = currentNode->left;
    }
    else
    {
      currentNode = currentNode->right;
    }

    // If it’s a leaf node, we’ve found a character
    if (!currentNode->left && !currentNode->right)
    {
      decompressedText += currentNode->data;
      currentNode = root; // Go back to the root
    }
  }
  return decompressedText;
}
