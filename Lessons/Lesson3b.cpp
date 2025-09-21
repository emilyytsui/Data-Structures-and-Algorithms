//Lesson3b.cpp          //Author: Emily Tsui
//Program that calculates the area and circumference of a circle, the user inputs a radius

#include <iostream>
using namespace std; //Namespace to search in
#include <math.h> //Has pi constant

int main() {
  float r; //To store the user's radius import

  cout << "Enter a radius: ";
  cin >> r;

  cout << "Circumference of the circle: " << 2 * r * M_PI << endl;
  cout << "Area of the circle: " << r * r * M_PI;

  return 0;
}