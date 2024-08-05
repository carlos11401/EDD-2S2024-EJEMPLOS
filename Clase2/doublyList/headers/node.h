#include <iostream>
using namespace std;

class Node{
  private:
    /* data */
  public:
    Node();
    Node(string name, int age);

    string name;
    int age;
    Node *next;
    Node *prev;

    void print();
    
};