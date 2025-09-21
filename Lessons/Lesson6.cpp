//Lesson6.cpp           Author: Emily Tsui
//Adds corresponding elements in two same-sized arrays in reverse order

#include <iostream>
#include <stdlib.h> //Includes rando() for random number generation
using namespace std;

int main() {
  int size;
  cout << "Enter the size of your arrays: ";
  cin >> size;

  int arr[size], arr2[size], sum[size], result[size];
  
  for(int i = 0; i < size; i++){
    arr[i] = rand() % 100; //Randomly generates elements of the array
  }

  for(int i = 0; i < size; i++){
    arr2[i] = rand() % 100; //Randomly generates elements of the array
  }

  for(int i = 0; i < size; i++){ //Calculates the sums of the corresponding elements
    sum[i] = arr[i] + arr2[i];
  }

  for(int i = 0; i < size; i++){ //Copies the sums in reverse order
    result[i] = sum[size - i - 1];
  }
  
  cout << "First array: ";
  for(int i = 0; i < size; i++){ //Prints the first array
    cout << arr[i] << " ";
  }
  cout << endl;

  cout << "Second array: ";
  for(int i = 0; i < size; i++){ //Prints the second array
    cout << arr2[i] << " ";
  }
  cout << endl;

  cout << "Result array: ";
  for(int i = 0; i < size; i++){ //Prints result array
    cout << result[i] << " ";
  }
  
  return 0;
}