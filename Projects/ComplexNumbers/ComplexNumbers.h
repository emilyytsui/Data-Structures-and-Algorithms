//ComplexNumbers.h          //Author: Emily Tsui
//Modifies ComplexNumbers.cpp file to become a header file

#ifndef COMPLEXNUMBERS_H
#define COMPLEXNUMBERS_H

#include <iostream>
using namespace std; //Namespace to search in
#include <math.h> //Has mathematical functions (eg. atan2, sqrt, M_PI)
#include <sstream> //Has ostringstream, easy string conversion

class Complex{
  private: //Private attributes
    double a = 0; //Real part, x-value
    double b = 0; //Imaginary part, y-value
    string complexFormatted; //String variable to store formatted Complex number

  public:
    Complex(double, double);
    Complex conjugate();
    double norm();
    double real();
    double imag();
    double dotProduct(Complex);
    Complex scalarProduct(double);
    double angleBetween(Complex);
    Complex operator + (Complex);
    Complex operator - (Complex);
    Complex operator * (Complex);
    Complex operator / (Complex);
    bool operator == (Complex);
    operator const char * ();
};

Complex :: Complex(double x, double y){ //Constructor to set values of the object
  a = x; //Sets a equal to user inputted real part value
  b = y; //Sets b equal to user inputted imaginary part value
}

Complex Complex :: conjugate(){ //Returns the complex conjugate for the Complex
  Complex conjugate(a, b); //Creates Complex object using user inputted values
  conjugate.b = b * -1; //Multiplys imaginary part of Complex by -1 to get the conjugate
  return conjugate; //Returns the Complex object
}

double Complex :: norm(){ //%eturns the norm of the Complex
  return sqrt(a * a + b * b); //Returns square root of real * real + imaginary * imaginary
}

double Complex :: real(){ //Returns the real part of the Complex
  return a; //Returns user inputted value
}

double Complex :: imag(){ //Returns the imaginary part of the Complex
  return b; //Returns user inputted value
}

double Complex :: dotProduct(Complex other){ //Rreturns the dot product of the Complex and the parameter
    return a * other.a + b * other.b; //Returns real * other real + imaginary * other imaginary
}

Complex Complex :: scalarProduct(double value){ //Returns the scalar product of the Complex and the parameter
  Complex scalar(a, b); //Creates Complex object using user inputted values
  scalar.a = value * a; //Sets value of real part to product of the inputted values
  scalar.b = value * b; //Sets value of imaginary part to product of the inputted values
  return scalar; //Returns the Complex object
}

double Complex :: angleBetween(Complex other){ 
  //Returns result of the formula to find angle between, multiples by 180 and divides by pi to get degrees
  return atan2(a * other.b - b * other.a, a * other.a + b * other.b) * 180 / M_PI;
}

Complex Complex :: operator + (Complex other){ //addition
  Complex add(a, b); //Creates Complex object using user inputted values
  add.a = a + other.a; //Sets value of real part to sum of the inputted values
  add.b = b + other.b; //Sets value of imaginary part to sum of the inputted values
  return add; //Returns the Complex object
}

Complex Complex :: operator - (Complex other){ //subtration
  Complex sub(a, b); //Creates Complex object using user inputted values
  sub.a = a - other.a; //Sets value of real part to difference of the inputted values
  sub.b = b - other.b; //Sets value of real part to difference of the inputted values
  return sub; //Returns the Complex object
}

Complex Complex :: operator * (Complex other){ //multiplication
  Complex mult(a, b); //Creates Complex object using user inputted values
  mult.a = a * other.a - b * other.b; //Sets value of real part to difference of the inputted values
  mult.b = a * other.b + other.a * b; //Sets value of real part to sum of the inputted values
  return mult; //Returns the Complex object
}

Complex Complex :: operator / (Complex other){ //division
  Complex divide(a, b); //Creates Complex object using user inputted values
  //Sets value of real part to quotient of the inputted values
  divide.a = (a * other.a + b * other.b) / (other.a * other.a + other.b * other.b);
  //Sets value of imaginary part to quotient of the inputted values
  divide.b = (b * other.a - a * other.b) / (other.a * other.a + other.b * other.b);
  return divide; //Returns the Complex object
}

bool Complex :: operator == (Complex other){ //equality
  //Checks to see if real and imaginary part of both Complex numbers are equal
  return (a == other.a) && (b == other.b);
}

Complex :: operator const char * (){  //conversion
  ostringstream format; //Makes it easy to convert to string

  if(b < 0){ //Checks to see if imaginary is negative
    format << a << " - " << b * -1 << "i"; //Sets a - bi format
  }else{
    format << a << " + " << b << "i"; //Sets standard a + bi format
  }

  complexFormatted = format.str(); //Sets string equal to format string
  return complexFormatted.c_str(); //Returns the formatted Complex object
}
  
#endif