//PointerFunctions.cpp          //Author: Emily Tsui
//Provides user with task options, user choses desired option, inputs necessary requirements for function, sees if user wants to repeat

#include <iostream>
#include <string.h> //Contains strcpy
using namespace std; //Namespace to search in

void swap(int* a, int* b){ //Swaps two integers using pointers
  int temp = 0; //Temporary variable
  temp = *a; //Stores input a in the temp variable
  *a = *b; //Replaces first input with second input
  *b = temp; //Replaces second input with first input stored in temp
}

void letterCount(string s, int* numVowels, int* numConsonants){ //Counts number of vowels and consonants in given string
  char charArr[s.length()]; //Creates a char array, inputed string as length, destination array
  char* pointer = strcpy(charArr, s.c_str()); //Declares pointer using destination array and copies inputed string
  int v = 0, c = 0; //Variables to count number of vowels and consonants
  for(int i = 0; i < s.length(); i++){ //Runs until end of the inputed string
    //Check if pointer is a vowel
    if(*pointer == 'A' || *pointer == 'E' || *pointer == 'I' || *pointer == 'O' || *pointer == 'U'){
      v++; //Increments vowel counter variable
    }else{ //Otherwise a consonant
      c++; //Increments consonant counter variable
    }
    pointer++; //Increases pointer to the next character
  }
  *numVowels = v; //Sets pointer value to equal vowel counter variable
  *numConsonants = c; //Sets pointer value to equal consonant counter variable
}

void arrayInfo(int* arrPtr, int length){ //Displays each element and its memory location
  for(int i = 0; i < length; i++){ //Loops for however many elements there are, stored in variable length
      cout << *(arrPtr + i) << " " << &arrPtr + i << endl; //Prints out element value using '*' and memory location using '&'
  }
}

int main() {

  char rerun = 'y'; //Varaible used to detect when the loop should run

  while(rerun == 'y'){ //Loop to repeat process if user wants
    
    int task = 0; //Variable to store which task the user wants
    
    cout << "Task options: " << endl << "   1. Swap two ints\n"; //Displays task options
    cout << "   2. Count the number of letters in a string\n"; //Displays task options
    cout << "   3. Array info, displays each element and its memory location\n"; //Displays task options
    cout << "\nPlease enter the number corresponding to the desired task (1, 2, or 3). "; //Asks user to input desired task
    cin >> task; //Gets user's inputs

    if(task == 1){ //swap
      int a, b; //Variables to store user inputs
      cout << "Enter two ints: "; //Asks user for inputs
      cin >> a >> b; //Gets inputs
      cout << "Numbers entered in order before swapping: " << a << ", " << b << endl; //Displays numbers respectively prior to swap
      swap(&a, &b); //Calls function
      cout << "Numbers after swapping: " << a << ", " << b << endl; //Displays numbers respectively after swap
    }else if(task == 2){ //letterCount
      string str; //Variable to store user input
      cout << "\nEnter a string that has no spaces and contains only capital letters: "; //Asks user for input
      cin >> str; //Gets input
      int vowels = 0, constants = 0; //Varibale to store function outputs
      letterCount(str, &vowels, &constants); //Calls function
      cout << "\nNumber of vowels in string: " << vowels; //Prints number of vowels
      cout << "\nNumber of constants in string: " << constants << endl; //Prints number of constants
    }else if(task == 3){ //arrayInfo
      int length = 0; //Variable to store user input
      cout << "\nEnter a length for an array: "; //Asks user for input
      cin >> length; //Gets user input
      cout << endl; //Enters another line for nice formatting

      int arr[length]; //Creates arr, length is user's input
      for(int i = 0; i < length; i++){ //Loops for however long the array is
        cout << "Enter an element for the array: "; //Asks user for element inputs
        cin >> arr[i]; //Gets user inputs, fills in the array
      }
      cout << endl; //Enters another line for nice formatting

      int* pointer = arr; //Declares pointer to first element of array
      arrayInfo(pointer, length); //Calls function
    }else{ //Incase user inputs wrong number
      cout << "\nIncorrect input." << endl; //Tells user input was incorrect
    }
    cout << "\nWould you like to rerun? Enter 'n' for no, 'y' for yes. "; //Asks user if they want to rerun the testing program
    cin >> rerun; //Gets user's input
    cout << endl; //Enters another line for nice formatting
  }
  return 0;
}