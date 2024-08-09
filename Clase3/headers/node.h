#include <iostream>
using namespace std;

class Node{
  private:
    /* data */
  public:
    Node(int age);
    int age;
    Node *next;
    Node *prev;

    void print();
    
};
