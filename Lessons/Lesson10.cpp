//Lesson10.cpp          //Author: Emily Tsui
//Classes Polygon, Triangle, and Shape using inheritance, methods in each class that relate to themselves

#include <iostream>
using namespace std;

class Shape{
  protected:
   bool is2D; // accessible only to derived classes
   
  public:
    void TwoDimensional(){
      if(is2D){
         cout << "Your shape is 2 dimensional" << endl;
      }else{
         cout << "Your shape is not 2 dimensional" << endl;
      }
    }
};

class Polygon : public Shape{
  public:
    Polygon(){
      is2D = true;
    }
    int interiorDegrees(int sides){
      return (sides - 2) * 180;
    }
    int diagonals(int sides){
      return sides * (sides - 3) / 2;
    }
};

class Triangle : public Polygon{
  public:
    Triangle(){
      is2D = true;
    }
    double area(double base, double height){
      return base * height / 2;
    }
    double perimeter(double side, double base, double side2){
      return side + base + side2;
    }
};

int main() {

  Triangle tri;

  tri.TwoDimensional();
  cout << endl;

  int side;
  cout << "Enter number of sides in your polygon: ";
  cin >> side;
  cout << "Number of distinct diagonals in the polygon ";
  cout << tri.diagonals(side) << endl << endl;

  int sides;
  cout << "Enter number of sides in your regular polygon: ";
  cin >> sides;
  cout << "Sum of interior angles (in degrees) of your regular polygon: ";
  cout << tri.interiorDegrees(sides) << " degrees" << endl;

  double base, height;
  cout << "\nEnter base length of a triangle: ";
  cin >> base;
  cout << "Enter height of a triangle: ";
  cin >> height;
  cout << "Area of triangle: ";
  cout << tri.area(base, height) << " square units" << endl;

  double s, s1, b;
  cout << "\nEnter side length of a triangle: ";
  cin >> s;
  cout << "Enter other side length of a triangle: ";
  cin >> s1;
  cout << "Enter base length of a triangle: ";
  cin >> b;
  cout << "Perimeter of triangle: ";
  cout << tri.perimeter(s, s1, b) << " units";

  return 0;
}