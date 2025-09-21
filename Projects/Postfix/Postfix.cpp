// Postfix.cpp            //Author: Emily Tsui
// Prompts user, displays answer to mathematical expressions in postfix notation

#include <fstream> //File operation
#include <iostream>
#include <math.h>    //Has power function
#include <sstream>   //Has ostringstream, easy string conversion
#include <string>    //String header
using namespace std; // Namespace to search in

class Postfix {
private:
  int value;             // Represents argument
  Postfix *next;         // Pointer to next
  string stackFormatted; // Variable to store formatted stack

public:
  Postfix();
  Postfix(int, Postfix *);
  int getValue();
  Postfix *getNext();
  int getLength();
  Postfix *pointerToLast(Postfix *);
  Postfix *push(Postfix *, int);
  Postfix *pop(Postfix *);
  Postfix *peek(Postfix *);
  int eval(string s);
  operator const char *();
};

Postfix ::Postfix() { // Constructor
  value = 0;          // Sets value to default value of 0
  next = nullptr;     // Sets next to default value of NULL
}

Postfix ::Postfix(int x, Postfix *n) { // Constructor
  value = x;                           // Sets value equal to user input
  next = n;                            // Sets next equal to user input
}

int Postfix::getValue() {
  return value; // Returns value
}

Postfix *Postfix ::getNext() {
  return next; // Returns next
}

int Postfix ::getLength() {
  int count = 0;            // Variable for storage
  Postfix *head = this;     // Creates a new Postfix equal to this
  while (head != nullptr) { // Loops until the end of the list
    count++;                // Increases count by 1
    head = head->next;      // Sets current to next
  }
  return count; // Returns count
}

Postfix *Postfix ::pointerToLast(Postfix *head) {
  if (head == nullptr) { // Checks to see is head is empty
    return head;         // Returns NULL
  } else {
    Postfix *copy = head;        // Creates new node
    if (head->next == nullptr) { // Base case, checks if next is NULL
      return head;               // Returns head
    }
    // Returns value of head called to pointerToLast of next value
    return head->pointerToLast(head->next);
  }
}

Postfix *Postfix ::push(Postfix *head, int x) {
  // Creates a new node, x as value and nullptr as next
  Postfix *node = new Postfix(x, nullptr);
  // Makes next of last node equal to node
  head->pointerToLast(head)->next = node;
  return head; // Returns head
}

Postfix *Postfix ::pop(Postfix *head) {
  if (head == nullptr) { // Checks to see if list is emtpy
    return nullptr;      // Returns NULL
  }

  Postfix *previousNode = head; // Creates new Postfix equal to head
  // Loops until second last node of head
  for (int i = 0; i < head->getLength() - 2; i++) {
    previousNode = previousNode->next; // Sets previousNode equal to next
  }

  previousNode->next = nullptr; // Sets next of previousNode equal to null

  return head; // Returns head
}

Postfix *Postfix ::peek(Postfix *head) {
  return head->pointerToLast(head); // Returns pointer to last node
}

int factorial(int x) {
  int result = 1;                // Variable for storage
  for (int i = 1; i <= x; i++) { // Loops up until number
    result *= i; // Sets result equal to product of i times result
  }
  return result; // Returns result
}

int Postfix ::eval(string s) {
  
  Postfix *stack = this; // Creates a Postfix equal to this
  string delimiter = " "; // Delimiter for finding whitespace
  int position = 0; //Variable for storing position

  //Loops through string until last whitespace
  while((position = s.find(delimiter)) != string::npos) {
    
    // Checks if string is an operator
    if (s.substr(0, position) == "+") {
      // Sets num equal to value of the top node of the stack
      int num = stack->peek(stack)->getValue();
      stack->pop(stack); // Pops the stack

      // Sets num2 equal to value of the top node of the stack
      int num2 = stack->peek(stack)->getValue();
      stack->pop(stack); // Pops the stack

      // Pushes sum into stack
      stack->push(stack, num2 + num);
    }

    // Checks if string is an operator
    else if (s.substr(0, position) == "-") {
      // Sets num equal to value of the top node of the stack
      int num = stack->peek(stack)->getValue();
      stack->pop(stack); // Pops the stack

      // Sets num2 equal to value of the top node of the stack
      int num2 = stack->peek(stack)->getValue();
      stack->pop(stack); // Pops the stack

      // Pushes difference into stack
      stack->push(stack, num2 - num);
    }

    // Checks if string is an operator
    else if (s.substr(0, position) == "*") {
      // Sets num equal to value of the top node of the stack
      int num = stack->peek(stack)->getValue();
      stack->pop(stack); // Pops the stack

      // Sets num2 equal to value of the top node of the stack
      int num2 = stack->peek(stack)->getValue();
      stack->pop(stack); // Pops the stack

      // Pushes product into stack
      stack->push(stack, num2 * num);
    }

    // Checks if string is an operator
    else if (s.substr(0, position) == "/") {
      // Sets num equal to value of the top node of the stack
      int num = stack->peek(stack)->getValue();
      stack->pop(stack); // Pops the stack

      // Sets num2 equal to value of the top node of the stack
      int num2 = stack->peek(stack)->getValue();
      stack->pop(stack); // Pops the stack

      // Pushes quotient into stack
      stack->push(stack, num2 / num);
    }

    // Checks if string is an operator
    else if (s.substr(0, position) == "^") {
      // Sets num equal to value of the top node of the stack
      int num = stack->peek(stack)->getValue();
      stack->pop(stack); // Pops the stack

      // Sets num2 equal to value of the top node of the stack
      int num2 = stack->peek(stack)->getValue();
      stack->pop(stack); // Pops the stack

      // Pushes result of num2 raised to the num into stack
      stack->push(stack, pow(num2, num));
    }

    // Checks if string is an operator
    else if (s.substr(0, position) == "%") {
      // Sets num equal to value of the top node of the stack
      int num = stack->peek(stack)->getValue();
      stack->pop(stack); // Pops the stack

      // Sets num2 equal to value of the top node of the stack
      int num2 = stack->peek(stack)->getValue();
      stack->pop(stack); // Pops the stack

      // Pushes product into stack
      stack->push(stack, num2 % num);
    }

    // Checks if string is an operator
    else if (s.substr(0, position) == "!") {
      // Sets num equal to value of the top node of the stack
      int num = stack->peek(stack)->getValue();
      stack->pop(stack); // Pops the stack

      // Pushes product into stack
      stack->push(stack, factorial(num));
    }

    else { // Otherwise, string is a number
      // Pushes the number, converts string to int in order to fit parameter
      stack->push(stack, stoi(s.substr(0, position)));
    }
    // Removes the part of the string
    s.erase(0, position + delimiter.length());
  }

  // Checks if string is an operator
  if (s == "+") {
    // Sets num equal to value of the top node of the stack
    int num = stack->peek(stack)->getValue();
    stack->pop(stack); // Pops the stack

    // Sets num2 equal to value of the top node of the stack
    int num2 = stack->peek(stack)->getValue();
    stack->pop(stack); // Pops the stack

    // Pushes sum into stack
    stack->push(stack, num2 + num);
  }

  // Checks if string is an operator
  else if (s == "-") {
    // Sets num equal to value of the top node of the stack
    int num = stack->peek(stack)->getValue();
    stack->pop(stack); // Pops the stack

    // Sets num2 equal to value of the top node of the stack
    int num2 = stack->peek(stack)->getValue();
    stack->pop(stack); // Pops the stack

    // Pushes difference into stack
    stack->push(stack, num2 - num);
  }

  // Checks if string is an operator
  else if (s == "*") {
    // Sets num equal to value of the top node of the stack
    int num = stack->peek(stack)->getValue();
    stack->pop(stack); // Pops the stack

    // Sets num2 equal to value of the top node of the stack
    int num2 = stack->peek(stack)->getValue();
    stack->pop(stack); // Pops the stack

    // Pushes product into stack
    stack->push(stack, num2 * num);
  }

  // Checks if string is an operator
  else if (s == "/") {
    // Sets num equal to value of the top node of the stack
    int num = stack->peek(stack)->getValue();
    stack->pop(stack); // Pops the stack

    // Sets num2 equal to value of the top node of the stack
    int num2 = stack->peek(stack)->getValue();
    stack->pop(stack); // Pops the stack

    // Pushes quotient into stack
    stack->push(stack, num2 / num);
  }

  // Checks if string is an operator
  else if (s == "^") {
    // Sets num equal to value of the top node of the stack
    int num = stack->peek(stack)->getValue();
    stack->pop(stack); // Pops the stack

    // Sets num2 equal to value of the top node of the stack
    int num2 = stack->peek(stack)->getValue();
    stack->pop(stack); // Pops the stack

    // Pushes result of num2 raised to the num into stack
    stack->push(stack, pow(num2, num));
  }

  // Checks if string is an operator
  else if (s == "%") {
    // Sets num equal to value of the top node of the stack
    int num = stack->peek(stack)->getValue();
    stack->pop(stack); // Pops the stack

    // Sets num2 equal to value of the top node of the stack
    int num2 = stack->peek(stack)->getValue();
    stack->pop(stack); // Pops the stack

    // Pushes product into stack
    stack->push(stack, num2 % num);
  }

  // Checks if string is an operator
  else if (s == "!") {
    // Sets num equal to value of the top node of the stack
    int num = stack->peek(stack)->getValue();
    stack->pop(stack); // Pops the stack
    
    // Pushes product into stack
    stack->push(stack, factorial(num));
  }

  // Final result, the only number left in the stack
  return stack->peek(stack)->getValue();
}

Postfix ::operator const char *() {
  ostringstream format; // Makes it easy to convert to string
  Postfix *head = this; // Creates a pointer reference equal to the ListNode

  cout << "["; // Prints a bracket

  while (head != nullptr) {   // Loops until the end
    cout << head->getValue(); // Prints value
    head = head->getNext();   // Sets head equal to next
    if (head != nullptr) {    // Checks to see if head is empty
      cout << ", ";           // Prints out a comma
    }
  }

  cout << "]" << endl; // Prints out a bracket and a line

  stackFormatted = format.str(); // Sets string equal to format string
  return stackFormatted.c_str(); // Returns the formatted ListNode object
}

void printResult(istream &file) {
  string arg = ""; // Variable for storage

  ofstream myfile("result.txt"); // Creates a new file, named result.txt

  // Loops while able to get string from file
  while (getline(file, arg)) {
    Postfix *stack = new Postfix(); // Creates a new Postfix
    // Outputs trial expression and result of eval, one trial per line
    myfile << arg << ": " << stack->eval(arg) << endl;
  }
  myfile.close(); // Closes the file
}

int main() {
  string fileName;                             // Variable for storage
  cout << "Please enter the name of a file: "; // Displays Prompt
  cin >> fileName;                             // Gets user input

  ifstream myfile(fileName); // Opens the user's file

  if (myfile.is_open()) { // Checks to see if file is open
    printResult(myfile);  // Calls printResult method
    myfile.close();       // Closes file
  } else {
    cout << "Unable to open file"; // Displays prompt
  }

  return 0; // Returns 0
}