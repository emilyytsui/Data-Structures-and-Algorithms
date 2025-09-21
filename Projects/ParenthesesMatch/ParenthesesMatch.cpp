// ParenthesesMatch.cpp           //Author: Emily Tsui
// Prompts user, checks mathematical expressions

#include <fstream> //File operation
#include <iostream>
#include <sstream>   //Has ostringstream, easy string conversion
#include <string>    //String header
using namespace std; // Namespace to search in

class ParenMatch {
private:
  char value;            // Represents argument
  ParenMatch *next;      // Pointer to next
  string stackFormatted; // Variable to store formatted stack

public:
  string LEFT = "([{<";
  string RIGHT = ")]}>";
  ParenMatch();
  ParenMatch(char, ParenMatch *);
  char getValue();
  ParenMatch *getNext();
  int getLength();
  ParenMatch *pointerToLast(ParenMatch *);
  ParenMatch *push(ParenMatch *, char);
  ParenMatch *pop(ParenMatch *);
  ParenMatch *peek(ParenMatch *);
  bool checkParen(string s);
  operator const char *();
};

ParenMatch ::ParenMatch() { // Constructor
  value = ' ';              // Sets value to default value of ""
  next = nullptr;           // Sets next to default value of NULL
}

ParenMatch ::ParenMatch(char arg, ParenMatch *n) { // Constructor
  value = arg; // Sets value equal to user input
  next = n;    // Sets next equal to user input
}

char ParenMatch::getValue() {
  return value; // Returns value
}

ParenMatch *ParenMatch ::getNext() {
  return next; // Returns next
}

int ParenMatch ::getLength() {
  int count = 0;               // Variable for storage
  ParenMatch *current = this;  // Pointer variable for placement
  while (current != nullptr) { // Loops until the end of the list
    count++;                   // Increases count by 1
    current = current->next;   // Sets current to next
  }
  return count; // Returns count
}

ParenMatch *ParenMatch ::pointerToLast(ParenMatch *head) {
  if (head == nullptr) { // Checks to see is head is empty
    return head;         // Returns NULL
  } else {
    ParenMatch *copy = head;     // Creates new node
    if (head->next == nullptr) { // Base case, checks if next is NULL
      return head;               // Returns head
    }
    // Returns value of head called to pointerToLast of next value
    return head->pointerToLast(head->next);
  }
}

ParenMatch *ParenMatch ::push(ParenMatch *head, char arg) {
  // Creates a new node, arg as value and nullptr as next
  ParenMatch *node = new ParenMatch(arg, nullptr);
  // Makes next of last node equal to node
  head->pointerToLast(head)->next = node;
  return head; // Returns head
}

ParenMatch *ParenMatch ::pop(ParenMatch *head) {
  if (head == nullptr) { // Checks to see if list is emtpy
    return nullptr;      // Returns NULL
  }

  ParenMatch *previousNode = head; // Creates new ParenMatch equal to head
  // Loops until second last node
  for (int i = 0; i < head->getLength() - 2; i++) {
    previousNode = previousNode->next; // Sets previousNode equal to next
  }

  previousNode->next = nullptr; // Sets next of previousNode equal to null

  return head; // Returns head
}

ParenMatch *ParenMatch::peek(ParenMatch *head) {
  return head->pointerToLast(head); // Returns pointer to last node
}

ParenMatch ::operator const char *() {
  ostringstream format;    // Makes it easy to convert to string
  ParenMatch *head = this; // Creates a pointer reference equal to the ListNode

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

bool ParenMatch ::checkParen(string s) {

  ParenMatch *stack = this; // Creates a ParenMatch
  int countLeft = 0;        // Variable for counting number of left symbols
  int countRight = 0;       // Variable for counting number of right symbols

  for (int i = 0; i < s.length(); i++) { // Loops for until end of string
    // Checks if symbol is on the left side and string isn't null position
    if (LEFT.find(s[i]) != string ::npos) {
      stack->push(stack, s[i]); // Push left-grouping symbols
      countLeft++;              // Increments left symbol count by 1
    }
    // Checks if symbol is on the right side and string isn't null position
    else if (RIGHT.find(s[i]) != string ::npos) {
      countRight++; // Increments right symbol count by 1

      if (stack == nullptr) { // Checks if stack is empty
        return false;         // Returns false
      }

      // Checks if value of top node is equal to '('
      if (stack->peek(stack)->getValue() == '(') {
        // Checks if character at i is equal to right hand symbol
        if (s[i] == ')') {
          stack->pop(stack); // Pops stack
        } else {
          return false; // Don't match, returns false
        }
      }
      // Checks if value of top node is equal to '['
      else if (stack->peek(stack)->getValue() == '[') {
        // Checks if character at i is equal to right hand symbol
        if (s[i] == ']') {
          stack->pop(stack); // Pops stack
        } else {
          return false; // Don't match, returns false
        }
      }
      // Checks if value of top node is equal to '{'
      else if (stack->peek(stack)->getValue() == '{') {
        // Checks if character at i is equal to right hand symbol
        if (s[i] == '}') {
          stack->pop(stack); // Pops stack
        } else {
          return false; // Don't match, returns false
        }
      }
      // Checks if value first node is equal to '<'
      else if (stack->peek(stack)->getValue() == '<') {
        // Checks if character at i is equal to right hand symbol
        if (s[i] == '>') {
          stack->pop(stack); // Pops stack
        } else {
          return false; // Don't match, returns false
        }
      }
    }
  }
  // Checks if length of stack is greater than 1
  // Checks if number of symbols on the left isn't equal to the right
  if (stack->getLength() > 1 || countLeft != countRight) {
    return false; // Returns false
  }
  return true; // Returns true, passes all the matches
}

void printResult(istream &file) {
  string arg = "";     // Variable for storage
  int trialNumber = 1; // Variable for counting trial number

  ofstream myfile("result.txt"); // Creates a new file, named result.txt

  // Loops while able to get string from file
  while (getline(file, arg)) {
    ParenMatch *stack = new ParenMatch(); // Creates a new ParenMatch
    // Outputs trial number and result of checkParen, one trial per line
    myfile << trialNumber << ": " << stack->checkParen(arg) << endl;
    trialNumber++; // Increments trial number by 1
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