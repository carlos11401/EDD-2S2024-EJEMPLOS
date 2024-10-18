#include "./huffman/huffman.h"

int main() {
    string text = "edd is so easy";
    cout << "Original text: " << text << endl;

    // Building tree
    Huffman huffman;
    huffman.buildHuffmanTree(text);

    // Get Huffman codes
    unordered_map<char, string> huffmanCodes = huffman.getHuffmanCodes();

    // Display Huffman codes
    cout << "Huffman codes for the characters:\n";
    for (const auto& pair : huffmanCodes) {
        cout << pair.first << ": " << pair.second << "\n";
    }

    // Compress the text
    string compressedText = huffman.compress(text, huffmanCodes);
    cout << "\nCompressed text: " << compressedText << "\n";

    // Decompress the text
    string decompressedText = huffman.decompress(compressedText);
    cout << "\nDecompressed text: " << decompressedText << "\n";

    return 0;
}
