#include "./avl/avl.h"

int main(int argc, char const *argv[])
{
  AVL mytree;
  mytree.insert(25);
  mytree.insert(50);
  mytree.insert(75);
  mytree.insert(10);
  mytree.insert(60);
  mytree.insert(65);
  mytree.insert(100);
  mytree.insert(200);
  mytree.insert(300);
  // mytree.insert(55);
  // mytree.insert(43);
  // mytree.insert(58);
  // mytree.insert(11);
  // mytree.insert(32);
  // mytree.insert(9);
  // mytree.insert(8);
  //mytree.insert(5);
  //mytree.insert(15);
  

  mytree.graph();
  return 0;
}
