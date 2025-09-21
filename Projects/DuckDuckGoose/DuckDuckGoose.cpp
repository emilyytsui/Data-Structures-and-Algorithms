// DuckDuckGoose.cpp           //Author: Emily Tsui
// Prompts user, performs DuckDuckGoose algorithm

#include <fstream> //File operation
#include <iostream>
#include <string>    //String header
using namespace std; // Namespace to search in

class ListNode {
private:
  int value;          // Represents argument
  ListNode *next;     // Pointer to next

public:
  ListNode();
  ListNode(int, ListNode *);
  void setValue(int);
  int getValue();
  ListNode *getNext();
  int getLength();
  ListNode *pointerToLast(ListNode *);
  ListNode *add(ListNode *, int);
};

ListNode ::ListNode() { // Constructor
  value = 0;            // Sets value to default value of ""
  next = nullptr;       // Sets next to default value of NULL
}

ListNode ::ListNode(int x, ListNode *n) { // Constructor
  value = x;    // Sets value equal to user input
  next = n;     // Sets next equal to user input
}

void ListNode ::setValue(int x) {
  value = x; // Sets value equal to x
}

int ListNode ::getValue() { // Returns value
  return value;
}

ListNode *ListNode ::getNext() { // Returns next
  return next;
}

int ListNode ::getLength() {
  int count = 0;         // Variable for storage
  ListNode *head = this; // Creates a new ListNode equal to this
  ListNode *temp = head; // Creates a new ListNode equal to head

  if (head->next == nullptr) { // Checks if next is null
    return 1;                  // Returns 1
  }

  head = head->next; // Sets head equal to next
  count++;           // Increments count by 1

  while (head != temp) { // Loops until the end of the list
    head = head->next;   // Sets temp equal to next
    count++;             // Increments count by 1
  }
  return count; // Returns count
}

ListNode *ListNode ::pointerToLast(ListNode *head) {
  if (head == nullptr) { // Checks if list is empty
    return nullptr;      // Returns NULL
  }
  int length = head->getLength(); // Creates variable equal to length of head

  for (int i = 1; i < length; i++) { // Loops until the end of head
    head = head->next;               // Sets head equal to next
  }

  return head; // Returns head
}

ListNode *ListNode ::add(ListNode *head, int x) {
  // Creates new ListNode equal to last node of head
  ListNode *last = head->pointerToLast(head);
  // Creates.a new ListNode with x as its value, nullptr as next, and last as
  // previous
  ListNode *temp = new ListNode(x, nullptr);
  last->next = temp; // Sets next of last equal to temp
  temp->next = head; // Sets next of temp equal to head
  return head;       // Returns head
}

int josephus(int participants, int cycle) {

  ListNode *head = new ListNode(); // Creates a new ListNode

  for (int i = 0; i < participants; i++) {
    head->add(head, 1); // Inserts participant into list
  }

  ListNode *newNode = head; // Creates a new ListNode equal to head
  // Variable for counting how many participants
  int participantsLeft = participants;
  int step = 1; // Variable for counting cycle position

  // Loops while number of participants is greater than 1
  while (participantsLeft > 1) {
    if (newNode->getValue() == 1) { // Checks to see if count is equal to cycle
      if (step == cycle) {          // Checks to see if position equals cycle
        newNode->setValue(0);       // Sets value of node equal to 0
        step = 1;                   // Sets position equal to 1
        participantsLeft--;         // Decrements partcipants left by 1
        newNode = newNode->getNext(); // Sets newNode equal to next
      } else {
        step++;                       // Increments step by 1
        newNode = newNode->getNext(); // Sets newNode equal to next
      }
    } else {
      newNode = newNode->getNext(); // Sets newNode equal to next
    }
  }

  int trialWinner = 0;   // Variable for storage
  ListNode *temp = head; // Creates a new ListNode equal to head
  // Loops through until end of head
  for (int i = 0; i < head->getLength(); i++) {
    // Checks to see if value of node equals 1
    if (temp->getValue() == 1) {
      trialWinner = i; // Sets trial winner equal to i
    }
    temp = temp->getNext(); // Sets head equal to next
  }
  return trialWinner; // Returns trialWinner location
}

void printResult(istream &file) {
  string arg = "";     // Variable for storage
  int p = 0;           // Variable for counting participants
  int c = 0;           // Variable for counting cycles
  int trialNumber = 1; // Variable for counting trial number
  int lineNumber = 1;  // Variable for counting if the line represents
                       // participant or cycle number

  ofstream myfile("result.txt"); // Creates a new file, named result.txt

  // Loops while file is open and the value is a digit
  while (file && isdigit(file.peek())) {
    if (lineNumber == 1) { // Checks to see if lineNumber is equal to 1
      getline(file, arg); // Gets the current line, makes arg equal to its value
      p = stoi(arg);      // Sets p equal to int equivalent of arg
      lineNumber = 2;     // Sets lineNumber equal to 2, represents cycle
    } else {
      getline(file, arg); // Gets the current line, makes arg equal to its value
      c = stoi(arg);      // Sets c equal to int equivalent of arg
      // Outputs trial number and position of trial winner, one trial per line
      myfile << trialNumber << ": " << josephus(p, c) << endl;
      lineNumber = 1; // Sets lineNumber equal to 1
      trialNumber++;  // Increments trial number by 1
    }
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