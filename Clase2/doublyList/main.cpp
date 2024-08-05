#include "./headers/mylist.h"

int main(int argc, char const *argv[])
{
  Mylist list;
  list.insertAtBeginning("Carlos", 23);
  list.insertAtBeginning("Jose", 24);
  list.insertAtBeginning("Maria", 25);
  list.insertAtEnd("Pedro", 26);
  list.insertAtEnd("Ivan", 27);
  list.insertAtEnd("Luis", 28);
  list.insertAtPosition(0, "Paulo", 29);
  list.insertAtPosition(7, "Paulo2", 29);
  list.insertAtPosition(20, "Paulo3", 29);
  list.insertAtPosition(5, "Paulo3", 29);

  list.print();
  return 0;
}
