//Conversions.cpp             Author: Emily Tsui
//Converts argument int from base 10 to base 16, argument string from base 16 to base 10
//Converts argument int from base 10 to argument base, argument string from argument base to base 10

#include <iostream>
using namespace std; //Namespace to search in

string toBase(int decimal, int base){ //Converts the argument integer from base 10 to the argument base (base 2-9)
  int remainder; //Variable to store the remainder calculated by using the modulus
  string argumentBase = ""; //String that stores the remainder(s)
  
  while(decimal > 0){ //When converting from base 10, you divide by 16 until the quotient is 0
    remainder = decimal % base; //The remainder of the integer divided by base is the argument toBase16 value
    //Add remainder it prior to (to the left of) other remainder(s) to "reverse" the numbers
    argumentBase = std::to_string(remainder) + argumentBase;
    decimal = decimal/base; //Gets the quotient, used to get the remainder of the next digit in the argument base
  }
  return argumentBase; //Returns the number in the argument base
}

string toBase16(int decimal){ //Converts the argument integer from base 10 to base 16.
  int remainder; //Variable to store the remainder calculated by using the modulus
  string base16 = ""; //String that stores the remainder(s)
  //Since base 16 uses letters for decimal 10-15, a char array is needed to convert
  char hexadecimal[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'}; 
  
  while(decimal > 0){ //When converting from base 10, you divide by 16 until the quotient is 0
    remainder = decimal % 16; //The remainder of the integer divided by 16 is a base 16 value
    //Gets the corresponding value from the char array, adds it prior to other remainder(s) to "reverse" the numbers
    base16 = hexadecimal[remainder] + base16;
    decimal = decimal/16; //Gets the quotient which will be used to get the remainder of the next digit in base 16
  }
  return base16; //Returns the base 16 number
}

int toInteger(string number, int base){ //Converts the argument string from the argument base to base 10 (base 2-9).
  int base10 = 0; //Variable to sum all the digits, base 10 argument
  int length = number.length(); //Variable for the length of the argument string
  int multiply = 1; //If going from right to left, you start multipling with 1
  char hexadecimal[] = {'0','1','2','3','4','5','6','7','8','9'}; //Used to change the char from the argument string to int
  
  for(int i = 0; i < number.length(); i++){ //Loops for however many digits there are in the argument string
   char add = number[length - i - 1]; //Gets the digit used to sum
     for(int j = 0; j < base; j++){ //Loops until one less than the base, represents corresponding power 
       if(hexadecimal[j] == add){ //Checks to see if the digit matches the char variable
         //Adds the product of multiplying the digit by its corresponding the "power" to whatever is in the variable already, sums all the products together
         base10 = base10 + j * multiply;
         multiply = multiply * base; //Calculates what the "power" is for the next digit
         break;
       }
     }
  }
  return base10; //Returns the number in the argument base
}

int toInteger16(string number){ //Converts the argument string from base 16 to base 10
  int base10 = 0; //Variable to sum all the digits, base 10 argument
  int length = number.length(); //Variable for the length of the argument string
  int multiply = 1; //If going from right to left, you start multipling with 1
  //Since base 16 uses letters for decimal 10-15, a char array is needed to convert
  char hexadecimal[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'}; 

  for(int i = 0; i < number.length(); i++){ //Loops for however many digits there are in the argument string
   char add = number[length - i - 1]; //Gets each digit of the string argument
     for(int j = 0; j < 16; j++){ //Loops until one less than 16, represents corresponding power 
       if(hexadecimal[j] == add){ //Checks to see if the digit matches the char variable
         //Adds the product of multiplying the digit by its corresponding the "power" to whatever is in the variable already, sums all the products together
         base10 = base10 + j * multiply;
         multiply = multiply * 16; //Calculates what the "power" is for the next digit
         break;
       }
     }
  }
  return base10; //Returns the base 10 number
}

int main(){ //Used for testing the above functions

  bool rerun = true; //Varaible used to detect when the loop should run

  while(rerun == true){ //Loop to make it easier for Ms. Zinn to test our code :)
    int x, base; //Variables to store user input
    cout << "Enter a decimal: "; //Asking user for input
    cin >> x; //Retrieving user input
    cout << "Decimal: " << x << " --> " << "Hexadecimal: " << toBase16(x) << endl; //Printing the base conversion
    cout << "Enter a base to convert the prior decimal number to: "; //Asking user for input
    cin >> base; //Retrieving user input
    //Printing the base conversion
    cout << "Decimal: " << x << " --> " << "Base " << base << ": " << toBase(x, base) << endl << endl; 
    
    string z; //Variable to store user input 
    int base2; //Variable to store user input
    cout << "Enter a hexadecimal: "; //Asking user for input
    cin >> z; //Retrieving user input
    cout << "Hexadecimal: " << z << " --> " << "Decimal: " << toInteger16(z) << endl; //Printing the base conversion
    cout << "Enter a base to convert the prior hexadecimal number to: "; //Asking user for input
    cin >> base2; //Retrieving user input
    //Printing the base conversion
    cout << "Hexadecimal: " << z << " --> " << "Base " << base2 << ": " << toInteger(z, base2) << endl;
    cout << endl; //Enters another line for nice formatting
    
    cout << "Would you like to re-test? Enter 0 for no, 1 for yes. "; //Asks user if they want to rerun the testing program
    cin >> rerun; //Gets user's input
    cout << endl; //Enters another line for nice formatting
  }
  return 0;
}