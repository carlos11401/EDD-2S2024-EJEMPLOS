#include <iostream> // Tell the copiler to use I/O functions
using namespace std;

template <typename T, typename U> T max_(T x, U y);

void myswap(int &x, int &y);
struct student{
  string name;
  string lastname;
  int age;
};

enum Days {monday = 1, tuesday = 2, wensday = 3};

int main()
{  
  // MEMORY ADRESS
  cout << "MEMORY ADRESS ------------------\n";
  int age2 = 5;
  bool ok = true;
  string lastname = "Castro";

  cout << &age2 << '\n';
  cout << &ok << '\n';
  cout << &lastname << '\n';

  // SWAP VALUES - BY VALUE AND BY REFERNCE
  cout << "Parameters by value and by reference -----------------\n";
  int x = 1, y = 2;
  myswap(x,y);
  cout << "(X,Y) = " << x << ", " << y << '\n';

  // CONST PARAMETER
  // void myswap(const int x, const int &y);

  /* POINTERS 
      & address-of operator
      * dereference operator
  */
  cout << "Pointers -------------\n";

  string name2 = "Jose";
  string *pName = &name2;
  cout << *pName << '\n';

  string animals[] = {"dog", "cat", "goat", "fish"};
  string *pAnimals = animals; 

  cout << *pAnimals << '\n';
  cout << *animals << '\n';
  cout << animals[0] << '\n';

  // NULLPTR pointers
  int *pointer1; // Could point to any random memory location
  int *pointer2 = nullptr;
  int *pointer3 = NULL;
  //pointer1 = pointer2;

  //cout << *pointer1 << endl;
  cout << "Size of pointer: " << sizeof(pointer1) << endl;
  cout << "Size of pointer: " << sizeof(pointer2) << endl;
  cout << pointer1 << endl;
  cout << &pointer1 << endl;
  cout << pointer2 << endl;
  cout << &pointer2 << endl;
  
  cout << "Exit" << endl;

  // Dynamic Memory
  int amount;
  cout << "How much grades do you want? " << endl;
  // cin >> amount;
  // NEW operator is to allocate memory in the heap
  char *grades = new char[amount];

  // for (int i = 0; i < amount; i++)
  // {
  //   cout << "Enter a grade: " << endl;
  //   cin >> grades[i];
  // }
  // for (int i = 0; i < amount; i++)
  // {
  //   cout << grades[i] << " ";
  // }
  cout << "\n";
  
  // delete[] grades;

  // TEMPLATES
  cout << "TEMPLATES --------------\n";
  cout << "My max: " << max_(1,'a') << endl;

  /*STRUCTS
    A group of variables
  */ 

  cout << "STRUCTS -----------\n";
  student stdnt;
  stdnt.name = "Carlos";
  stdnt.lastname = "Castro";
  stdnt.age = 23;

  cout << stdnt.name << endl;
  cout << stdnt.lastname << endl;
  cout << stdnt.age << endl;

  // ENUM
  cout << "ENUM -----------\n";
  Days day = monday;
  switch(day){
    case monday: 
      cout << "monday\n";
      break;
    case tuesday: 
      cout << "tuesday\n";
      break;
    case wensday: 
      cout << "wensday\n";
      break;
  }

  return 0;
}

template <typename T, typename U>
T max_(T x, U y){
  return (x > y) ? x:y ;
}
void myswap(int &x, int &y){
  int temp = x;
  x = y;
  y = temp;
}