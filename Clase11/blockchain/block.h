#include <iostream> // Tell the copiler to use I/O functions
using namespace std;

class Block
{
private:
  // functions
  string generateHash();
public:
  Block(int data);
  void mineBlock();

  int index;
  int nonce;
  int difficulty;
  string previousHash; 
  string hash; 
  string time;
  int data;

  // pointers
  Block* next;
  Block* back; 
};

