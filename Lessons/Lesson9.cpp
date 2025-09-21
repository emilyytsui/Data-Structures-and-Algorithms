//Lesson9.cpp             //Author: Emily Tsui
//Class that computes area and circumference using the radius that is supplied to class, main function displays information

#include <iostream>
using namespace std;
#include <math.h> //Easy for exponents to be used; contains pi constant

class Circle{
  private:
    const double pi = M_PI;
    double radius;

  public:
    Circle(){
      radius = 0;
    }
    double area(double radius){
      return pi * pow(radius, 2);
    }
    double circumference(double radius){
      return 2 * pi * radius;
    }
};

int main() {
  Circle c;
  double radius;

  for(int i = 0; i < 3; i++){
    cout << "Enter a radius for a circle: ";
    cin >> radius;

    cout << "Area of circle with a radius of " << radius << ": " << c.area(radius) << endl;
    cout << "Circumference of circle with a radius of " << radius << ": " << c.circumference(radius) << endl;
    cout << endl;
  }
  return 0;
}