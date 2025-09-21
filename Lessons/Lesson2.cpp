//Lesson2.cpp         //Author: Emily Tsui
//Creates serveral integer variables, asks user for integer inputs, tests math on integers, displays integers

#include <iostream>
using namespace std; //Namespace to search in
#include <string> //Alows strings to be sent to user

int main() {
  int x, y, z; //Variables to store three integers
  
  cout << "Enter first integer: ";
  cin >> x;

  cout << "Enter second integer: ";
  cin >> y;

  cout << "Enter third integer: ";
  cin >> z;

  cout << "Integers entered: " << x << ", " << y << ", " << z << endl; //Outputs the integers the user inputed
  cout << "Sum of integers entered: " << x + y + z << endl; //Adds all three integers
  cout << "Product of integers entered: " << x * y * z << endl; //Multiplys all three integers
  cout << "Quotient of third integer divided by first integer: " << z/x << endl; //Multiplys all three integers
  
  return 0;
}