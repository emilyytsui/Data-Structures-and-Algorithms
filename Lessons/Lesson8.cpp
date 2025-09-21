//Lesson8.cpp       //Author: Emily Tsui
//Accepts 5 ints from keyboard, stores in array using pointer, prints array starting from beginning and end using pointers

#include <iostream>
using namespace std;

int main() {
  int arr[5];
  int* pointer = arr;

  for(int i = 0; i < 5; i++){
    cout << "Enter an integer: ";
    cin >> *(pointer + i);
  }

  for(int i = 0; i < 5; i++){
    cout << *(pointer + i) << " ";
  }

  cout << endl;
  
  for(int i = 0; i < 5; i++){
    cout << *(pointer - i + 4) << " ";
  }
}