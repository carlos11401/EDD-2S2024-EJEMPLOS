#include "./headers/mylist.h"

Mylist::Mylist(){
  head = nullptr;
  size = 0;
}

void Mylist::insert(string name, int age){
  Node *newPerson = new Node(name, age);

  if(head == nullptr){
    head = newPerson;
    size++;
    return;
  }

  Node *current = head;
  while(current->next != nullptr){
    current = current->next;
  }
  current->next = newPerson;
  size++;

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