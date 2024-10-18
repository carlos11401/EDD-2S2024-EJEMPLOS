#include "./mylist.h"

SimpleList::SimpleList() {
  size = 0;
  head = nullptr;
}

// Method to insert a Huffman node into the list in sorted order by frequency
void SimpleList::push(HuffmanNode* huffNode) {
  Node *newNode = new Node(huffNode);
  
  // Assign new node to head if the list is empty
  if(head == nullptr) {
    head = newNode;
    size++;
    return;
  }

  // Search for the correct position to insert the new node, keeping the list ordered by frequency
  Node *current = head;
  while (current->next != nullptr && current->next->huffNode->freq <= newNode->huffNode->freq) {
    current = current->next;
  }
  // Insert the new node in the correct position
  newNode->next = current->next;
  current->next = newNode;
  size++;  
}

Node* SimpleList::pop() {
  if (head == nullptr) {
      std::cout << "The list is empty. Cannot perform pop." << std::endl;
      return nullptr;
  }

  Node* temp = head; // Save the head node
  head = head->next; // Move the head pointer to the next node
  size--;
  return temp;       // Return the removed node
}

void SimpleList::print() {
  if (head == nullptr) {
      std::cout << "The list is empty" << std::endl;
      return;
  } else {
    Node* current = head;
    // Loop through the list and print each node's data and frequency
    while(current != nullptr) {
      std::cout << current->huffNode->data << ": " << current->huffNode->freq << std::endl;
      current = current->next;
    }
  }
}
