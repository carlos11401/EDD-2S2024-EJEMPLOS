#include "./matrix/headers/matrix.h"

int main(int argc, char const *argv[])
{
  Matrix mymatrix;
  mymatrix.insert(5, 20, 10);
  mymatrix.insert(5, 40, 20);
  mymatrix.insert(10, 10, 30);
  mymatrix.insert(10, 30, 5);
  mymatrix.insert(10, 40, 25);
  mymatrix.insert(15, 30, 5);
  mymatrix.insert(15, 40, 25);
  mymatrix.insert(20, 10, 25);
  mymatrix.insert(20, 20, 5);
  mymatrix.insert(20, 30, 25);
  mymatrix.insert(50, 30, 25);

  mymatrix.create_dot();
  return 0;
}
