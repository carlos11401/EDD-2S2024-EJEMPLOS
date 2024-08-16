#include "./headers/simpleList.h"

SimpleList::SimpleList(int typeHeader){
  this->typeHeader = typeHeader;
  size = 0;
  head = nullptr;
  tail = nullptr;
}

/* Inserting a new node if not exist, else
   just return the pointer of that node
*/
ListNode* SimpleList::insert(int positionToAdd){
  ListNode *newNode = new ListNode(positionToAdd);
  // Empty list
  if(head == nullptr){
    head = newNode;
    tail = newNode;
    size++;
    return newNode;
  // If position to add is already on head
  }else if(positionToAdd == head->position){
    return head;
  // If position to add is already on tail
  }else if(positionToAdd == tail->position){
    return tail;
  // If position to add gonna be first
  }else if(positionToAdd < head->position){
    newNode->next = head;
    head = newNode;
    size++;
    return head;
  // If position to add gonna be last
  }else if(positionToAdd > tail->position){
    tail->next = newNode;
    tail = newNode;
    size++;
    return tail;
  // Insert at middle
  }else{
    ListNode *current = head->next;
    ListNode *prev = head;
    while(current != nullptr){
      // return current
      if(positionToAdd == current->position){
        return current;
      // add and return new node
      }else if(positionToAdd < current->position){
        prev->next = newNode;
        newNode->next = current;
        size++;
        return newNode;
      }
      prev = current;
      current = current->next;
    }
  }

  return nullptr;
}

void SimpleList::print(){
  ListNode *current = head;

  // Check for empty list
  if(current == nullptr){
    cout << "Your list is empty" << endl;
  } else{
    // Traverse the list
    do{
      cout << current->position << endl;
      current = current->next;
    }while(current != nullptr);
  }
}

SimpleList::~SimpleList(){
  ListNode *current = head;
  ListNode *next = nullptr;
  int rowHeader = 0;

  /* When typeHeader is 0(row header) i'm goin to delete 
    the header nodes and the matrix nodes, else 
    if type header is 1(col header) i'm goint to delete
    just the header nodes
  */
  if(typeHeader == rowHeader){
    while(current != nullptr){
      MatrixNode *currentMatrixNode = current->access;
      MatrixNode *nextMatrixNode = nullptr;
      while(currentMatrixNode != nullptr){
        nextMatrixNode = currentMatrixNode->right;
        delete currentMatrixNode;
        currentMatrixNode = nextMatrixNode;
      }
      next = current->next;
      delete current;
      current = next;
    }
  }else{
    while(current != nullptr){
      next = current->next;
      delete current;
      current = next;
    }
  }
}