#include "./tree/tree.h"

int main(int argc, char const *argv[])
{
  BTree btree;
  int numbers[5] = {10,20,30,40,15};
  for (int num : numbers)
  {
    btree.insert(num);
  }
  btree.graph();
  
  return 0;
}
