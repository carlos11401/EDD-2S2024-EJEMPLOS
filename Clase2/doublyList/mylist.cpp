#include "./headers/mylist.h"

Mylist::Mylist(){
  head = nullptr;
  tail = nullptr;
  size = 0;
}

void Mylist::insertAtBeginning(string name, int age){
  Node *newPerson = new Node(name, age);

  if(head == nullptr){
    head = newPerson;
    tail = newPerson;
    size++;
    return;
  }

  head->prev = newPerson;
  newPerson->next = head;
  head = newPerson;
  size++;

}
void Mylist::insertAtEnd(string name, int age){
  Node *newPerson = new Node(name, age);

  if(tail == nullptr){
    head = newPerson;
    tail = newPerson;
    size++;
    return;
  }

  tail->next = newPerson;
  newPerson->prev = tail;
  tail = newPerson;
  size++;

}
void Mylist::insertAtPosition(int givenPosition, string name, int age){
  Node *newPerson = new Node(name, age);

  if(head == nullptr){
    head = newPerson;
    tail = newPerson;
    size++;
  }else if(givenPosition == 0){
    insertAtBeginning(name, age);
    return;
  }else if(givenPosition >= size){
    insertAtEnd(name, age);
    return;
  }else{
    Node *current = head;
    for (int actualPosition = 0; actualPosition < size; actualPosition++)
    {
      if(givenPosition == actualPosition){
        newPerson->next = current;
        newPerson->prev = current->prev;
        current->prev->next = newPerson;
        current->prev = newPerson;
        size++;
        return;
      }
      current = current->next;
    }
    
  }
}

void Mylist::print(){
  Node *current = head;
  if(head = nullptr){
    cout << "The list is empty." << endl;
    return;
  }
  for (int i = 0; i < size; i++)
  {
    cout << i << " ";
    current->print();

    current = current->next;
  }
  
}