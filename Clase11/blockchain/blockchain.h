#include "block.h"

class Blockchain
{
private:
  Block* first;
  Block* last;
  int size;

  int getSize();
  string getPrehash();
public:
  Blockchain(/* args */);

  void insert(int data);
  void print();
};
