#include "./block.h"
#include "../sha256/sha256.h"
#include <sstream>
#include <iomanip>

Block::Block(int data){
  this->data = data;
  index = 0;
  nonce = 0;
  previousHash = "";
  hash = "";
  time = "";
  difficulty = 4;
}

string Block::generateHash(){
  string all = to_string(index) + to_string(nonce) + to_string(data) + previousHash + time;
  return sha256(all);
}

void Block::mineBlock(){
  string blockHash = generateHash();
  string target(this->difficulty, '0'); // If difficulty = 4 then target = "0000"
  
  // blockHash = erty...
  // erty == 0000
  // nonce = 2
  while(blockHash.substr(0, this->difficulty) != target){
    this->nonce++;
    blockHash = generateHash();
  }
  this->hash = blockHash;
}