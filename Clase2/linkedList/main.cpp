#include "./headers/mylist.h"

int main(int argc, char const *argv[])
{
  Mylist list;
  list.insert("Carlos", 23);
  list.insert("Jose", 24);
  list.insert("Maria", 25);
  list.insert("Priscila", 26);

  list.print();
  return 0;
}
