#include "./headers/circleList.h"

int main(int argc, char const *argv[])
{
  CircleList mylist;
  mylist.insert(23);
  mylist.insert(24);
  mylist.insert(25);
  mylist.insert(26);
  mylist.print();

  mylist.search(24);
  mylist.search(30);
  mylist.remove(23);
  mylist.remove(25);
  mylist.print();
  mylist.generateGraph();


  return 0;
}

