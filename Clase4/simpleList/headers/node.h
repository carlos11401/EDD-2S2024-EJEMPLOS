#include <iostream> // Tell the copiler to use I/O functions
#include "../../matrix/headers/node.h"
using namespace std;

class ListNode{
  private:
    /* data */
  public:
    // CONSTRUCTORS 
    ListNode();   // Default constructor
    ListNode(int position);  //Parameterised Constructor
    // VARIABLES
    int position;
    ListNode *next;
    MatrixNode *access;
};
