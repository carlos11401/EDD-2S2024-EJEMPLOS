#include <iostream>
using namespace std;

void bubble(int arr[], int size){
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = 0; j < size - i - 1; j++)
    {
      if(arr[j] > arr[j+1]){
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}
void insertion(int arr[], int size){
  for (int i = 1; i < size; i++)
  {
    int current = arr[i];
    int j = i;

    while (j > 0 && arr[j-1] > current)
    {
      arr[j] = arr[j-1];
      j--;
    }
    arr[j] = current;
  }
  
}
void selection(int arr[], int size){
  for (int i = 0; i < size - 1; i++)
  {
    int minIndex = i;
    for(int j = i+1; j < size; ++j){
      if(arr[j] < arr[minIndex]){
        minIndex = j;
      }
    }
    swap(arr[i], arr[minIndex]);
  }
}

void printArray(int arr[], int size){
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
  
}
int main(int argc, char const *argv[])
{
  int arr[] = {50, 30, 80, 10, 90};
  int size = sizeof(arr) / sizeof(arr[0]);

  cout << "Lista original: ";
  printArray(arr, size);
  cout << "Lista ordenada: ";
  selection(arr, size);
  printArray(arr, size);
  return 0;
}
