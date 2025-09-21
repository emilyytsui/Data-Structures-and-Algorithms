//Lesson7.cpp           Author: Emily Tsui
//Fuction with a void return type, helps user calculate area and circumference of a circle when supplied the radius
//Overloaded functions that calculate the volume of a sphere and a cylinder

#include <iostream>
#include <math.h> //Has pi constant, M_PI; easy for exponents to be used
using namespace std;

void Circle(double radius, double& area, double& circumference){
  area = M_PI * pow(radius, 2);
  circumference = 2 * M_PI * radius;
  return;
}

double Volume(double radius){
  return M_PI * pow(radius, 3) * 4 / 3; //Volume of a sphere
}

double Volume(double radius, double height){
  return M_PI * pow(radius, 2) * height; //Volume of a cylinder
}

int main() {
  double r;
  cout << "Enter a radius for a circle: ";
  cin >> r;
  double getArea, getCircumference;
  Circle(r, getArea, getCircumference);
  cout << "Area of the circle: " << getArea << endl;
  cout << "Circumference of the circle: " << getCircumference << endl;

  double x;
  cout << endl << "Enter a radius for a sphere: ";
  cin >> x;
  cout << "Volume of the sphere: " << Volume(x) << endl;

  double y, h;
  cout << endl << "Enter a radius for a cylinder: ";
  cin >> y;
  cout << "Enter a height for a cylinder: ";
  cin >> h;
  cout << "Volume of the cylinder: " << Volume(y, h) << endl;

  return 0;
}