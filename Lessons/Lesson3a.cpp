//Lesson3a.cpp            Author: Emily Tsui
//The size of an unsigned int and normal int are the same, both are smaller than a long int and long long

#include <iostream>
using namespace std; //Namespace to search in

int main() {
  cout << "Size of unsigned int: " << sizeof(unsigned) << endl;
  cout << "Size of normal int: " << sizeof(int) << endl;
  cout << "Size of long int: " << sizeof(long) << endl;
  cout << "Size of long long: " << sizeof(long long) << endl;
  cout << sizeof(unsigned) << " = " << sizeof(int) << endl;
  cout << sizeof(int) << " < " << sizeof(long) << endl;

  return 0;
}