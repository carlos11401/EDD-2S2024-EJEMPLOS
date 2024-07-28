#include <iostream> // Tell the copiler to use I/O functions
using namespace std;

void println(string text);
void println(string text, int number);
void println(string text, string text2, bool boolean);
int sum(int x, int y);
void myswap(int &x, int &y);

int main()
{
  // INTEGERS
  int myInt = 5;
  // DOUBLES
  double myDouble = 10.554;
  // CHARACTER
  char myChar = 'A';
  // BOOLEAN
  bool myBool = true;
  // STRING
  std::string myString = "Carlos";

  std::cout << myInt << std::endl;
  std::cout << myDouble << '\n';
  std::cout << myChar << '\n';
  std::cout << myString << '\n';

  // CONST
  const double pi = 3.141519;

  // ARITMETHIC OPERATION
  int result = myInt + 4;
  std::cout << result << '\n';

  result = myInt - 4;
  std::cout << result << '\n';

  double result2 = myInt / 4.1;
  std::cout << result2 << '\n';

  result = myInt * 4;
  std::cout << result << '\n';

  result ++;

  // IMPLICIT AND EXPLICIT CONVERSION
  // IMPLICIT
  myInt = 55.14;
  myChar = 100;
  std::cout << myInt << '\n';
  std::cout << myChar << '\n';
  // EXPLICIT
  int correct = 8;
  int questions = 10;
  double score = correct / (double) questions * 100;

  std::cout << score << '\n';
  
  std::cout << (char) 100 << '\n';

  // COUT >> insertion operator
  // CIN << extraction operator
  // To write on terminal go to extentions->code runner->Run in terminal
  std::cout << "What\'s your name? ";
  //std::cin >> myString; 
  std:: cout << "I\'m " << myString << '\n';

  cout << "What's your full name? ";
  //getline(cin >> ws, myString); // Write with spaces
  cout << myString << '\n';

  // IF STATEMENTS
  int age = 23;
  if(age >= 18){
    cout << "Welcome\n";
  }else if(age <=0){
    cout << "You haven't been born yet\n";
  }else{
    cout << "You are not old enough :(\n";
  }

  // SWITCH STATEMENT
  int month = 2;
  switch (month)
  {
  case 1:
    cout << "January\n";
    break;
  case 2:
    cout << "February\n";
    break;
  default:
    break;
  }

  // LOGICAL OPERATORS
  myBool = true;
  bool myBool2 = false;
  
  cout << (myBool && myBool2) << '\n';
  cout << (myBool || myBool2) << '\n';
  cout << (!myBool) << '\n';

  // STRING FUNCTIONS
  string name = "Carlos Castro";
  cout << "Size: " << name.length() << '\n';
  cout << "Is Empty: " << name.empty() << '\n';
  name.clear();
  cout << "Is Empty: " << name.empty() << '\n';

  name = "Jose";
  name.append(" Gonzalez");
  cout << name << '\n';
  cout << name.at(3) << '\n';
  cout << name.insert(4, " Javier") << '\n';
  cout << name.find(" ") << '\n';
  cout << name.erase(11, 2) << '\n';
  name.clear();
  // // LOOPS
  // while(name.empty()){
  //   cout << "What's your name? ";
  //   getline(cin, name);
  // } 

  // do
  // {
  //   cout << "What's your name? ";
  //   getline(cin, name);
  // } while (name.empty());
  // cout << "\nHello " << name << '\n';

  for (int i = 0; i > -5; i--)
  {
    if(i == -2){
      cout << "Jump number\n";
      continue;
    }else if(i == -4){
      break;
    }
    cout << i << '\n';
  }

  // FUNCTIONS

  println("This is my first function :)"); // normal
  result = sum(5,7);  // with return
  cout << result << '\n';

  println("The number is: ", 5);  // same function, differents parameters
  println("The ", "bool is: ", true);

  // ARRAYS
  string cars[3];

  cars[0] = "Mazda";
  cars[1] = "Toyota";
  cars[2] = "Honda";
  int carsSize = sizeof(cars)/sizeof(string);
  for (int i = 0; i < carsSize; i++)
  {
    println(cars[i]);
  }
  cout << "For2------------\n";
  for(string car: cars){
    println(car);
  }

  // FILL
  cout << "Multidimentional ARRAYS---------------\n";
  int matrix[3][3] = {{1,2,3},{4,5,6},{7,8,9}}; 
  cout << matrix[1][1] << '\n';

  return 0;
}

void println(string text){
  cout << text << '\n';
}
void println(string text, int number){
  cout << text << number << '\n';
}
void println(string text, string text2, bool boolean){
  cout << text << text2 << boolean << '\n';
}
int sum(int x, int y){
  return x + y;
}
