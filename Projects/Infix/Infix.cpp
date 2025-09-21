// Infix.cpp            //Author: Emily Tsui
// Prompts user, displays answer to expressions in infix notation

#include <fstream> //File operation
#include <iostream>
#include <math.h>    //Has power function
#include <sstream>   //Has ostringstream, easy string conversion
#include <string>    //String header
using namespace std; // Namespace to search in

class Infix {
private:
  char value;            // Represents argument
  Infix *next;           // Pointer to next
  string stackFormatted; // Variable to store formatted stack

public:
  Infix();
  Infix(char, Infix *);
  char getValue();
  Infix *getNext();
  int getLength();
  Infix *pointerToLast(Infix *);
  Infix *push(Infix *, char);
  Infix *pop(Infix *);
  Infix *peek(Infix *);
  string infixToPostfix(string);
  operator const char *();
};

Infix ::Infix() { // Constructor
  value = 0;      // Sets value to default value of 0
  next = nullptr; // Sets next to default value of NULL
}

Infix ::Infix(char arg, Infix *n) { // Constructor
  value = arg;                      // Sets value equal to user input
  next = n;                         // Sets next equal to user input
}

char Infix::getValue() {
  return value; // Returns value
}

Infix *Infix ::getNext() {
  return next; // Returns next
}

int Infix ::getLength() {
  int count = 0;            // Variable for storage
  Infix *head = this;       // Creates a new Infix equal to this
  while (head != nullptr) { // Loops until the end of the list
    count++;                // Increases count by 1
    head = head->next;      // Sets current to next
  }
  return count; // Returns count
}

Infix *Infix ::pointerToLast(Infix *head) {
  if (head == nullptr) { // Checks to see is head is empty
    return head;         // Returns NULL
  } else {
    Infix *copy = head;          // Creates new node
    if (head->next == nullptr) { // Base case, checks if next is NULL
      return head;               // Returns head
    }
    // Returns value of head called to pointerToLast of next value
    return head->pointerToLast(head->next);
  }
}

Infix *Infix ::push(Infix *head, char arg) {
  // Creates a new node, arg as value and nullptr as next
  Infix *node = new Infix(arg, nullptr);
  // Makes next of last node equal to node
  head->pointerToLast(head)->next = node;
  return head; // Returns head
}

Infix *Infix ::pop(Infix *head) {
  if (head == nullptr) { // Checks to see if list is emtpy
    return nullptr;      // Returns NULL
  }

  Infix *previousNode = head; // Creates new Infix equal to head
  // Loops until second last node of head
  for (int i = 0; i < head->getLength() - 2; i++) {
    previousNode = previousNode->next; // Sets previousNode equal to next
  }

  previousNode->next = nullptr; // Sets next of previousNode equal to null

  return head; // Returns head
}

Infix *Infix ::peek(Infix *head) {
  return head->pointerToLast(head); // Returns pointer to last node
}

bool isLower(char c1, char c2) {
  // Checks if c1 has lower or equal precedence to c2
  if (c1 == c2 || c1 == '+' && c2 == '-' || c1 == '*' && c2 == '/') {
    return true; // Returns true
  } else if (c1 == '-' && c2 == '+' || c1 == '/' && c2 == '*') {
    return true; // Returns true
  } else if (c1 == '+' && c2 == '*' || c1 == '-' && c2 == '*') {
    return true; // Returns true
  } else if (c1 == '+' && c2 == '/' || c1 == '-' && c2 == '/') {
    return true; // Returns true
  }
  return false; // Otherwise returns false
}

bool isOperator(string s) {
  // Checks if string is an operator
  if (s == "+" || s == "-" || s == "*" || s == "/") {
    return true; // Returns true
  }
  return false; // Returns false
}

string Infix ::infixToPostfix(string infix) {
  string result = "";         // Blank result string for postfix expression
  Infix *stack = new Infix(); // Creates a new empty stack
  string delimiter = " ";     // Delimiter for finding whitespace
  int position = 0;           // Variable for storing position

  // Loops over input string until last whitespace to process characters
  while ((position = infix.find(delimiter)) != string::npos) {

    // Checks if character is left parentheses
    if (infix.substr(0, position) == "(") {
      stack->push(stack, '('); // Pushes it on the stack
    }

    // Checks if character is right parentheses
    else if (infix.substr(0, position) == ")") {
      // Loops until a left parenthesis is popped
      while (stack->peek(stack)->getValue() != '(') {
        // Appends character and whitespaceto the postfix string
        result = result + stack->peek(stack)->getValue() + " ";
        stack->pop(stack); // Pops operator off the stack
      }
      stack->pop(stack); // Discards the left parenthesis
    }

    // Checks if character is an operator
    else if (isOperator(infix.substr(0, position))) {

      for (;;) { // Loops until one of the conditions is met

        // Checks if top of stack is of lower or equal precedence than character
        if (!isLower(infix.substr(0, position)[0],
                     stack->peek(stack)->getValue())) {
          stack->push(
              stack,
              infix.substr(0, position)[0]); // Pushes the operator on the stack
          break; // Breaks the loop since condition is met
        }

        // Checks if length of stack is less than or equal to 1
        else if (stack->getLength() <= 1) {
          stack->push(
              stack,
              infix.substr(0, position)[0]); // Pushes the operator on the stack
          break; // Breaks the loop since condition is met
        }

        // Checks if top of stack is a left parentheses
        else if (stack->peek(stack)->getValue() == '(') {
          stack->push(
              stack,
              infix.substr(0, position)[0]); // Pushes the operator on the stack
          break; // Breaks the loop since condition is met
        }

        else {
          // Appends operator and whitespace to the postfix string
          result = result + stack->peek(stack)->getValue() + " ";
          stack->pop(stack); // Pops operator off the stack
        }
      }
    }

    else { // Character is a number
      // Appends character and whitespace to the postfix string
      result = result + infix.substr(0, position) + " ";
    }

    // Removes the part of the string
    infix.erase(0, position + delimiter.length());
  }

  // Checks if character is right parentheses
  if (infix == ")") {
    // Loops until a left parenthesis is popped
    while (stack->peek(stack)->getValue() != '(') {
      // Appends character and whitespaceto the postfix string
      result = result + stack->peek(stack)->getValue() + " ";
      stack->pop(stack); // Pops operator off the stack
    }
    stack->pop(stack); // Discards the left parenthesis
  }

  // Checks if character is an operator
  else if (isOperator(infix)) {

    for (;;) { // Loops until one of the conditions is met

      // Checks if top of stack is of lower precedence than character
      if (!isLower(infix[0], stack->peek(stack)->getValue())) {
        stack->push(stack, infix[0]); // Pushes the operator on the stack
        break;                        // Breaks the loop since condition is met
      }

      // Checks if length of stack is less than or equal to 1
      else if (stack->getLength() <= 1) {
        stack->push(stack, infix[0]); // Pushes the operator on the stack
        break;                        // Breaks the loop since condition is met
      }

      // Checks if top of stack is a left parentheses
      else if (stack->peek(stack)->getValue() == '(') {
        stack->push(stack, infix[0]); // Pushes the operator on the stack
        break;                        // Breaks the loop since condition is met
      }

      // Appends operator and whitespace to the postfix string
      result = result + stack->peek(stack)->getValue() + " ";
      stack->pop(stack); // Pops operator off the stack
    }

  }

  else { // Character is a number
    // Appends character and whitespace to the postfix string
    result = result + infix + " ";
  }

  // After infix string ends, loops through stack looking for operators
  while (stack->getLength() > 1) {
    // Appends character and whitespace to the postfix string
    result = result + stack->peek(stack)->getValue() + " ";
    stack->pop(stack); // Pops operator off the stack
  }

  return result; // Returns the postfix string
}

Infix ::operator const char *() {
  ostringstream format; // Makes it easy to convert to string
  Infix *head = this;   // Creates a pointer reference equal to the Infix

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
  return stackFormatted.c_str(); // Returns the formatted Infix object
}

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
  int eval(string);
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

  Postfix *stack = new Postfix(); // Creates a new empty Postfix
  string delimiter = " ";         // Delimiter for finding whitespace
  int position = 0;               // Variable for storing position

  // Loops through string until last whitespace
  while ((position = s.find(delimiter)) != string::npos) {

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

  // Final result, the only number left in the stack
  return stack->peek(stack)->getValue();
}

Postfix ::operator const char *() {
  ostringstream format; // Makes it easy to convert to string
  Postfix *head = this; // Creates a pointer reference equal to the Postfix

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
  return stackFormatted.c_str(); // Returns the formatted Postfix object
}

void printResult(istream &file) {
  string arg = ""; // Variable for storage

  ofstream myfile("result.txt"); // Creates a new file, named result.txt

  // Outputs header to myfile
  myfile << "Infix    -->   Postfix    -->   Evaluate" << endl;

  // Loops while able to get string from file
  while (getline(file, arg)) {
    // Creates an empty Infix and an empty Postfix
    Infix *stack = new Infix();
    Postfix *stack2 = new Postfix();
    // Sets string posfix equal to result of infixToPostfix
    string postfix = stack->infixToPostfix(arg);
    myfile << arg << "         " << postfix << "       "
           << stack2->eval(postfix) << endl;
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