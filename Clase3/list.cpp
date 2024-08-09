#include "./headers/circleList.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib> // Para usar system()

CircleList::CircleList(){
  head = nullptr;
  tail = nullptr;
  size = 0;
}
void CircleList::insert(int age){
  Node *newNode = new Node(age);

  if(head == nullptr){
    head = newNode;
		tail = newNode;
		head->next = head;
		head->prev = tail;
    size++;
  }else{
    tail->next = newNode;
		newNode->prev = tail;
		newNode->next = head;
		tail = newNode;
		head->prev = tail;
    size++;
  }
}
void CircleList::search(int age){
  Node *current = head;
  bool found = false;

  if(head!=nullptr){
    do{
      if(current->age==age){
				cout << "\n The age is" << age << "\n\n";
				found = true;				
			}
			current = current->next;
    }while(current!=head && found != true);
    if(!found){
			cout << "\n Node not found\n\n";
		}
  }else{
    cout<< "List empty" << endl;
  }

}
void CircleList::remove(int age){
  Node *current = head;
  Node *prev = nullptr;
  bool found = false;

  if(head != nullptr){
    do{
      if(current->age == age){
        cout << "Age found" << endl;
        if(current == head){
          head = head->next;
          head->prev = tail;
          tail->next = head;
        }else if(current == tail){
          tail = prev;
					tail->next = head;
					head->prev = tail;
        }else{
          prev->next = current->next;
					current->next->prev = prev;
        }
        delete current;
        cout << "\n Node Deleted\n\n";
				found = true;	
      }
      prev = current;
			current = current->next;
    }while(current!=head && found != true);
  }else{
    cout << "List empty" << endl;
  }
}
void CircleList::print(){
  Node *current = head;
  // Check for empty list
  if(current == nullptr){
    cout << "Your list is empty :(" << endl;
  } else{
    // Traverse the list
    int position = 0;
    do{
      cout << position << ". ";
      current->print();
      current = current->next;
      position++;
    }while(current != head);
  }
}

void CircleList::generateGraph() {
    stringstream dotContent;

    dotContent << "digraph G {" << endl;
    dotContent << "\tnode [shape=record];" << endl;

    Node* current = head;
    int position = 0;

    // Crear nodos
    do {
        dotContent << "\tnode" << position << " [label=\""<< current->age << "\"];" << std::endl;
        current = current->next;
        position++;
    } while (current != head);

    // Crear conexiones
    current = head;
    position = 0;
    do {
        dotContent << "\tnode" << position;
        dotContent << " -> node" << ((position + 1) % size) << " [dir=both];" << std::endl;
        current = current->next;
        position++;
    } while (current != head);

    dotContent << "}" << std::endl;

    // Escribir el contenido acumulado en el archivo .dot
    
    fstream dotFile("myimg.dot");
    dotFile << dotContent.str();
    dotFile.close();

    // Comando para generar la imagen
    string command = "dot -Tpng myimg.dot -o myimg.png";
    system(command.c_str());
}