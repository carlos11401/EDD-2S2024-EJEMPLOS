#include <iostream>
using namespace std;
/* OBJECT ORIENTED PROGRAMMING(OOP) - (POO)
  A collection of variables and functions
*/

class Human{
  private:
    int id;
  public:
    string name;
    int age;

    void eat(){
      cout << "I'm eating\n";
    }
    void sleep(){
      cout << "I'm sleeping\n";
    }
    void getInfo(){
      cout << "Age: " << age << endl;
      cout << "Name: " << name << endl;
    }
    void showId(){
      cout << id << endl;
    }
    void setId(int id){
      this->id = id;
    }
  
  Human(string name, int age){
    this->name = name;
    this->age = age;
  }
  
};

int main()
{
  Human human1("Carlos", 23);
  human1.eat();
  human1.getInfo();
  human1.setId(43);
  human1.showId();
  
  return 0;
}
