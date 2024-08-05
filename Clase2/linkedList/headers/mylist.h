#include "./node.h"
class Mylist{
  private:
    Node *head;
  public:
    Mylist();

    int size;

    void insert(string name, int age);
    void print();
};
