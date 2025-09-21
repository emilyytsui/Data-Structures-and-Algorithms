//ComplexNumbers.cpp        Author: Emily Tsui
//Provides user with task options, user choses desired option, inputs necessary requirements for function, sees if user wants to repeat

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
    Complex(double x, double y){ //Constructor to set values of the object
      a = x; //Sets a equal to user inputted real part value
      b = y; //Sets b equal to user inputted imaginary part value
    }

    Complex conjugate(){ //Returns the complex conjugate for the Complex
      Complex conjugate(a, b); //Creates Complex object using user inputted values
      conjugate.b = b * -1; //Multiplys imaginary part of Complex by -1 to get the conjugate
      return conjugate; //Returns the Complex object
    }

    double norm(){ //%eturns the norm of the Complex
      return sqrt(a * a + b * b); //Returns square root of real * real + imaginary * imaginary
    }

    double real(){ //Returns the real part of the Complex
      return a; //Returns user inputted value
    }

    double imag(){ //Returns the imaginary part of the Complex
      return b; //Returns user inputted value
    }

    double dotProduct(Complex other){ //Rreturns the dot product of the Complex and the parameter
       return a * other.a + b * other.b; //Returns real * other real + imaginary * other imaginary
    }

    Complex scalarProduct(double value){ //Returns the scalar product of the Complex and the parameter
      Complex scalar(a, b); //Creates Complex object using user inputted values
      scalar.a = value * a; //Sets value of real part to product of the inputted values
      scalar.b = value * b; //Sets value of imaginary part to product of the inputted values
      return scalar; //Returns the Complex object
    }

    double angleBetween(Complex other){ 
      //Returns result of the formula to find angle between, multiples by 180 and divides by pi to get degrees
      return atan2(a * other.b - b * other.a, a * other.a + b * other.b) * 180 / M_PI;
    }

    Complex operator + (Complex other){ //addition
      Complex add(a, b); //Creates Complex object using user inputted values
      add.a = a + other.a; //Sets value of real part to sum of the inputted values
      add.b = b + other.b; //Sets value of imaginary part to sum of the inputted values
      return add; //Returns the Complex object
    }

    Complex operator - (Complex other){ //subtration
      Complex sub(a, b); //Creates Complex object using user inputted values
      sub.a = a - other.a; //Sets value of real part to difference of the inputted values
      sub.b = b - other.b; //Sets value of real part to difference of the inputted values
      return sub; //Returns the Complex object
    }

    Complex operator * (Complex other){ //multiplication
      Complex mult(a, b); //Creates Complex object using user inputted values
      mult.a = a * other.a - b * other.b; //Sets value of real part to difference of the inputted values
      mult.b = a * other.b + other.a * b; //Sets value of real part to sum of the inputted values
      return mult; //Returns the Complex object
    }

    Complex operator / (Complex other){ //division
      Complex divide(a, b); //Creates Complex object using user inputted values
      //Sets value of real part to quotient of the inputted values
      divide.a = (a * other.a + b * other.b) / (other.a * other.a + other.b * other.b);
      //Sets value of imaginary part to quotient of the inputted values
      divide.b = (b * other.a - a * other.b) / (other.a * other.a + other.b * other.b);
      return divide; //Returns the Complex object
    }

    bool operator == (Complex other){ //equality
      //Checks to see if real and imaginary part of both Complex numbers are equal
      return (a == other.a) && (b == other.b);
    }

    operator const char * (){  //conversion
      ostringstream format; //Makes it easy to convert to string

      if(b < 0){ //Checks to see if imaginary is negative
        format << a << " - " << b * -1 << "i"; //Sets a - bi format
      }else{
        format << a << " + " << b << "i"; //Sets standard a + bi format
      }

      complexFormatted = format.str(); //Sets string equal to format string
      return complexFormatted.c_str(); //Returns the formatted Complex object
    }
};

int main() { //Used for testing and displaying
  char rerun = 'y'; //Varaible used to detect when the loop should run
    
  while(rerun == 'y'){ //Loop to repeat process if user wants
    
      int task = 0; //Variable to store which task the user wants
      
      //Displays task options
      cout << "Task options: " << endl << "   1. Get the complex conjugate for the Complex\n";
      cout << "   2. Get the norm of the Complex\n";
      cout << "   3. Get the real part of the Complex\n";
      cout << "   4. Get the imaginary part of the Complex\n";
      cout << "   5. Get the dot product of the Complex and another Complex\n";
      cout << "   6. Get the scalar product of the Complex and a double\n";
      cout << "   7. Get the angle between of the Complex and another Complex\n";
      cout << "   8. Add two Complex numbers\n";
      cout << "   9. Subtract two Complex numbers\n";
      cout << "   10. Multiply two Complex numbers\n";
      cout << "   11. Divide two Complex numbers\n";
      cout << "   12. Determine if two Complex numbers are equal\n";

      //Asks user for desired task
      cout << "\nPlease enter the number corresponding to the desired task (1, 2, 3, 4, 5, 6, 7, 7, 9, 10, 11, or 12). ";
      cin >> task; //Gets user's inputs

      if(task == 1){ //conjugate
        cout << "\n*****Create a Complex number*****" << endl; //Displays prompt
        int x, y; //Variables for storage
        cout << "   Enter the real part (x-value) of the Complex: "; //Asks user for input
        cin >> x; //Gets user input
        cout << "   Enter the imaginary part (y-value) of the Complex: "; //Asks user for input
        cin >> y; //Gets user input

        Complex c(x, y); //Creates Complex object using user inputted values
        cout << "\nInputted Complex: " << c << endl; //Displays prompt

        cout << "Conjugate of " << c << ": " << c.conjugate(); //Displays prompt and calls method

      }else if(task == 2){ //norm
        cout << "\n*****Create a Complex number*****" << endl; //Displays prompt
        int x, y; //Variables for storage
        cout << "   Enter the real part (x-value) of the Complex: "; //Asks user for input
        cin >> x; //Gets user input
        cout << "   Enter the imaginary part (y-value) of the Complex: "; //Asks user for input
        cin >> y; //Gets user input

        Complex c(x, y); //Creates Complex object using user inputted values
        cout << "\nInputted Complex: " << c << endl; //Displays prompt

        cout << "Norm of " << c << ": " << c.norm(); //Displays prompt and calls method

      }else if(task == 3){ //real
        cout << "\n*****Create a Complex number*****" << endl; //Displays prompt
        int x, y; //Variables for storage
        cout << "   Enter the real part (x-value) of the Complex: "; //Asks user for input
        cin >> x; //Gets user input
        cout << "   Enter the imaginary part (y-value) of the Complex: "; //Asks user for input
        cin >> y; //Gets user input

        Complex c(x, y); //Creates Complex object using user inputted values
        cout << "\nInputted Complex: " << c << endl; //Displays prompt

        cout << "Real part of " << c << " is " << c.real(); //Displays prompt and calls method

      }else if(task == 4){ //imag
        cout << "\n*****Create a Complex number*****" << endl; //Displays prompt
        int x, y; //Variables for storage
        cout << "   Enter the real part (x-value) of the Complex: "; //Asks user for input
        cin >> x; //Gets user input
        cout << "   Enter the imaginary part (y-value) of the Complex: "; //Asks user for input
        cin >> y; //Gets user input

        Complex c(x, y); //Creates Complex object using user inputted values
        cout << "\nInputted Complex: " << c << endl; //Displays prompt

        cout << "Imaginary part of Complex" << c << ": " << c.imag(); //Displays prompt and calls method

      }else if(task == 5){ //dotProduct
        cout << "\n*****Create a Complex number*****" << endl; //Displays prompt
        int x, y; //Variables for storage
        cout << "   Enter the real part (x-value) of the Complex: "; //Asks user for input
        cin >> x; //Gets user input
        cout << "   Enter the imaginary part (y-value) of the Complex: "; //Asks user for input
        cin >> y; //Gets user input

        cout << "\n*****Create a Second Complex number*****" << endl; //Displays prompt
        int a, b; //Variables for storage
        cout << "   Enter the real part (x-value) of the Complex: "; //Asks user for input
        cin >> a; //Gets user input
        cout << "   Enter the imaginary part (y-value) of the Complex: "; //Asks user for input
        cin >> b; //Gets user input

        Complex c(x, y); //Creates Complex object using user inputted values
        Complex n(a, b); //Creates Complex object using user inputted values
        cout << "\nFirst Complex Inputted: " << c; //Displays prompt
        cout << "\nSecond Complex Inputted: " << n << endl; //Displays prompt

        //Displays prompt and calls method
        cout << "Dot Product of two Complex numbers inptted:" << c.dotProduct(n);

      }else if(task == 6){ //scalarProduct
        cout << "\n*****Create a Complex number*****" << endl; //Displays prompt
        int x, y; //Variables for storage
        cout << "   Enter the real part (x-value) of the Complex: "; //Asks user for input
        cin >> x; //Gets user input
        cout << "   Enter the imaginary part (y-value) of the Complex: "; //Asks user for input
        cin >> y; //Gets user input

        cout << "\n*****Enter parameter*****" << endl; //Displays prompt
        double a; //Variables for storage
        cout << "   Enter a double to multiply the Complex number by: "; //Asks user for input
        cin >> a; //Gets user input

        Complex c(x, y); //Creates Complex object using user inputted values
        cout << "\nComplex Inputted: " << c << endl; //Displays prompt

        //Displays prompt and calls method
        cout << "Scalar Product of two Complex numbers inptted: " << c.scalarProduct(a);

      }else if(task == 7){ //angleBetween
        cout << "\n*****Create a Complex number*****" << endl; //Displays prompt
        int x, y; //Variables for storage
        cout << "   Enter the real part (x-value) of the Complex: "; //Asks user for input
        cin >> x; //Gets user input
        cout << "   Enter the imaginary part (y-value) of the Complex: "; //Asks user for input
        cin >> y; //Gets user input

        cout << "\n*****Create a Second Complex number*****" << endl; //Displays prompt
        int a, b; //Variables for storage
        cout << "   Enter the real part (x-value) of the Complex: "; //Asks user for input
        cin >> a; //Gets user input
        cout << "   Enter the imaginary part (y-value) of the Complex: "; //Asks user for input
        cin >> b; //Gets user input

        Complex c(x, y); //Creates Complex object using user inputted values
        Complex n(a, b); //Creates Complex object using user inputted values
        cout << "\nFirst Complex Inputted: " << c; //Displays prompt
        cout << "\nSecond Complex Inputted: " << n << endl; //Displays prompt

        //Displays prompt and calls method
        cout << "Angle between the two Complex numbers inptted:" << c.angleBetween(n);

      }else if(task == 8){ //add operator
        cout << "\n*****Create a Complex number*****" << endl; //Displays prompt
        int x, y; //Variables for storage
        cout << "   Enter the real part (x-value) of the Complex: "; //Asks user for input
        cin >> x; //Gets user input
        cout << "   Enter the imaginary part (y-value) of the Complex: "; //Asks user for input
        cin >> y; //Gets user input

        cout << "\n*****Create a Second Complex number*****" << endl; //Displays prompt
        int a, b; //Variables for storage
        cout << "   Enter the real part (x-value) of the Complex: "; //Asks user for input
        cin >> a; //Gets user input
        cout << "   Enter the imaginary part (y-value) of the Complex: "; //Asks user for input
        cin >> b; //Gets user input

        Complex c(x, y); //Creates Complex object using user inputted values
        Complex n(a, b); //Creates Complex object using user inputted values
        cout << "\nFirst Complex Inputted: " << c; //Displays prompt
        cout << "\nSecond Complex Inputted: " << n << endl; //Displays prompt

        //Displays prompt and calls method
        cout << "Sum of two Complex numbers inptted:" << c + n;

      }else if(task == 9){ //subtract operator
        cout << "\n*****Create a Complex number*****" << endl; //Displays prompt
        int x, y; //Variables for storage
        cout << "   Enter the real part (x-value) of the Complex: "; //Asks user for input
        cin >> x; //Gets user input
        cout << "   Enter the imaginary part (y-value) of the Complex: "; //Asks user for input
        cin >> y; //Gets user input

        cout << "\n*****Create a Second Complex number*****" << endl; //Displays prompt
        int a, b; //Variables for storage
        cout << "   Enter the real part (x-value) of the Complex: "; //Asks user for input
        cin >> a; //Gets user input
        cout << "   Enter the imaginary part (y-value) of the Complex: "; //Asks user for input
        cin >> b; //Gets user input

        Complex c(x, y); //Creates Complex object using user inputted values
        Complex n(a, b); //Creates Complex object using user inputted values
        cout << "\nFirst Complex Inputted: " << c; //Displays prompt
        cout << "\nSecond Complex Inputted: " << n << endl; //Displays prompt

        //Displays prompt and calls method
        cout << "Difference Between the two Complex numbers inptted:" << c - n;

      }else if(task == 10){ //multiply operator
        cout << "\n*****Create a Complex number*****" << endl; //Displays prompt
        int x, y; //Variables for storage
        cout << "   Enter the real part (x-value) of the Complex: "; //Asks user for input
        cin >> x; //Gets user input
        cout << "   Enter the imaginary part (y-value) of the Complex: "; //Asks user for input
        cin >> y; //Gets user input

        cout << "\n*****Create a Second Complex number*****" << endl; //Displays prompt
        int a, b; //Variables for storage
        cout << "   Enter the real part (x-value) of the Complex: "; //Asks user for input
        cin >> a; //Gets user input
        cout << "   Enter the imaginary part (y-value) of the Complex: "; //Asks user for input
        cin >> b; //Gets user input

        Complex c(x, y); //Creates Complex object using user inputted values
        Complex n(a, b); //Creates Complex object using user inputted values
        cout << "\nFirst Complex Inputted: " << c; //Displays prompt
        cout << "\nSecond Complex Inputted: " << n << endl; //Displays prompt

        //Displays prompt and calls method
        cout << "Product of two Complex numbers inptted:" << c * n;

      }else if(task == 11){ //divide operator
        cout << "\n*****Create a Complex number*****" << endl; //Displays prompt
        int x, y; //Variables for storage
        cout << "   Enter the real part (x-value) of the Complex: "; //Asks user for input
        cin >> x; //Gets user input
        cout << "   Enter the imaginary part (y-value) of the Complex: "; //Asks user for input
        cin >> y; //Gets user input

        cout << "\n*****Create a Second Complex number*****" << endl; //Displays prompt
        int a, b; //Variables for storage
        cout << "   Enter the real part (x-value) of the Complex: "; //Asks user for input
        cin >> a; //Gets user input
        cout << "   Enter the imaginary part (y-value) of the Complex: "; //Asks user for input
        cin >> b; //Gets user input

        Complex c(x, y); //Creates Complex object using user inputted values
        Complex n(a, b); //Creates Complex object using user inputted values
        cout << "\nFirst Complex Inputted: " << c; //Displays prompt
        cout << "\nSecond Complex Inputted: " << n << endl; //Displays prompt

        //Displays prompt and calls method
        cout << "Quotient of two Complex numbers inptted:" << c / n;

      }else if(task == 12){ //equlality operator
        cout << "\n*****Create a Complex number*****" << endl; //Displays prompt
        int x, y; //Variables for storage
        cout << "   Enter the real part (x-value) of the Complex: "; //Asks user for input
        cin >> x; //Gets user input
        cout << "   Enter the imaginary part (y-value) of the Complex: "; //Asks user for input
        cin >> y; //Gets user input

        cout << "\n*****Create a Second Complex number*****" << endl; //Displays prompt
        int a, b; //Variables for storage
        cout << "   Enter the real part (x-value) of the Complex: "; //Asks user for input
        cin >> a; //Gets user input
        cout << "   Enter the imaginary part (y-value) of the Complex: "; //Asks user for input
        cin >> b; //Gets user input

        Complex c(x, y); //Creates Complex object using user inputted values
        Complex n(a, b); //Creates Complex object using user inputted values
        cout << "\nFirst Complex Inputted: " << c; //Displays prompt
        cout << "\nSecond Complex Inputted: " << n << endl; //Displays prompt

        if(c == n){ //Checks to see if the two Complex numbers are equal using operator
          cout << "The two Complex numbers inptted are equal"; //Displays prompt
        }else{
          cout << "The two Complex numbers inptted are not equal"; //Displays prompt
        }

      }else{ //Incase user inputs wrong number
        cout << "\nIncorrect input." << endl; //Tells user input was incorrect
      }
      //Asks user if they want to rerun the testing program
      cout << "\n\nWould you like to rerun? Enter 'n' for no, 'y' for yes. ";
      cin >> rerun; //Gets user's input
      cout << endl; //Enters another line for nice formatting
    }
  return 0;
} 