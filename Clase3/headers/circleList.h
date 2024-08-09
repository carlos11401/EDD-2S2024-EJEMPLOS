#include "./node.h"

class CircleList{
  private:
    Node *head;
    Node *tail;
  public:
    CircleList(/* args */);
    int size = 0;

    void insert(int age);
    void search(int age);
    void remove(int age);
    void print();
    void generateGraph();
};  
