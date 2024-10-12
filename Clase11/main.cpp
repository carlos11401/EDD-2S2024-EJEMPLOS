// #include "./blockchain/blockchain.h"

// int main(int argc, char const *argv[])
// {
//   Blockchain myblockchain;
//   myblockchain.insert(4);
//   myblockchain.insert(5);
//   myblockchain.insert(6);
//   myblockchain.insert(7);
//   myblockchain.insert(8);
//   myblockchain.print();
//   return 0;
// }


#include "./merkleTree/merkleTree.h"

int main(int argc, char const *argv[])
{

  MerkleTree merkleTree;
  merkleTree.insert("hi");
  merkleTree.insert("test");
  merkleTree.insert("maria");
  merkleTree.insert("carro");
  merkleTree.insert("edd");
  merkleTree.insert("test");
  merkleTree.insert("maria");
  merkleTree.insert("carro");
  merkleTree.insert("edd");
  
  string filename = "tree";
  merkleTree.generateGraph(filename);
  return 0;
}
