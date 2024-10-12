#include "blockchain.h"
#include <chrono>
#include <iomanip>  // para put_time
#include <sstream>  // para ostringstream
#include <ctime>    // para localtime

Blockchain::Blockchain(){
  first = nullptr;
  last = nullptr;
  size = 0;
}

int Blockchain::getSize(){
  return this->size;
}
string Blockchain::getPrehash(){
  if(this->size == 0){
    return "0000";
  }else{
    return this->last->hash;
  }
}

string getCurrentDate() {
    // Obtener el tiempo actual como time_t
    auto ahora = chrono::system_clock::now();
    time_t tiempo = chrono::system_clock::to_time_t(ahora);

    // Convertir a formato de tiempo local
    tm tiempoLocal = *localtime(&tiempo);

    // Convertir a string usando stringstream
    ostringstream streamFecha;
    streamFecha << put_time(&tiempoLocal, "%Y-%m-%d %H:%M:%S");
    return streamFecha.str();
}

void Blockchain::insert(int data){
  Block* newBlock = new Block(data);
  newBlock->index = getSize();
  newBlock->previousHash = getPrehash();
  newBlock->time = getCurrentDate();

  newBlock->mineBlock();

  if(this->first == nullptr){
    this->first = newBlock;
    this->last = newBlock;
  }else{
    this->last->next = newBlock;
    newBlock->back = this->last;
    this->last = newBlock;
  }
  this->size++;
}

void Blockchain::print(){
  Block* current = this->first;
  while(current != nullptr){
    cout << "---------------------------------------"<< endl;
    cout << "INDEX: " << current->index << endl;
    cout << "DATA: " << current->data << endl;
    cout << "TIME: " << current->time << endl;
    cout << "NONCE: " << current->nonce << endl;
    cout << "HASH: " << current->hash << endl;
    cout << "PREHASH: " << current->previousHash << endl;

    current = current->next;
  }
}