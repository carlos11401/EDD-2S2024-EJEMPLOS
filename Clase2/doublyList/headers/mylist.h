#include "./node.h"
class Mylist{
  private:
    Node *head;
    Node *tail;
  public:
    Mylist();

    int size;

    void insertAtBeginning(string name, int age);
    void insertAtEnd(string name, int age);
    void insertAtPosition(int position, string name, int age);
    void print();
};
