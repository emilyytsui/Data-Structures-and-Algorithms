// ListLab4.cpp            //Author: Emily Tsui
// Circular doubly-linked list, adds and removes nodes, prints

#ifndef LISTLAB4_H
#define LISTLAB4_H

#include <iostream>
#include <sstream> //Has ostringstream, easy string conversion
using namespace std;

class ListNode {
private:
  string value;         // Represents argument
  ListNode *next;       // Pointer to next
  ListNode *previous;   // Pointer to previous
  string listFormatted; // Variable to store formatted list

public:
  ListNode();
  ListNode(string, ListNode *, ListNode *);
  string getValue();
  ListNode *getNext();
  ListNode *getPrevious();
  int getLength();
  ListNode *pointerToLast(ListNode *);
  ListNode *insertFirst(ListNode *, string);
  ListNode *insertLast(ListNode *, string);
  ListNode *add(ListNode *, string, int);
  ListNode *removeFirst(ListNode *);
  ListNode *removeLast(ListNode *);
  ListNode *remove(ListNode *, int);
  operator const char *();
};

ListNode ::ListNode() { // Constructor
  value = "";           // Sets value to default value of ""
  next = nullptr;       // Sets next to default value of NULL
  previous = nullptr;   // Sets previous to default value of NULL
}

ListNode ::ListNode(string arg, ListNode *n, ListNode *p) { // Constructor
  value = arg;   // Sets value equal to user input
  next = n;     // Sets next equal to user input
  previous = p; // Sets previous equal to user input
}

string ListNode ::getValue() { // Returns value
  return value;
}

ListNode *ListNode ::getNext() { // Returns next
  return next;
}

ListNode *ListNode ::getPrevious() { // Returns previous
  return previous;
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

ListNode *ListNode ::insertFirst(ListNode *head, string arg) {
  // Creates new ListNode equal to last node of head
  ListNode *last = head->pointerToLast(head);
  // Creates a new ListNode with arg as its value, head as next, and temp as
  // previous
  ListNode *newNode = new ListNode(arg, head, last);
  head->previous = newNode; // Sets previous of head equal to newNode
  last->next = newNode;     // Sets next of last equal to newNode
  return newNode;           // Returns newNode
}

ListNode *ListNode ::insertLast(ListNode *head, string arg) {
  // Creates new ListNode equal to last node of head
  ListNode *last = head->pointerToLast(head);
  // Creates a new ListNode with arg as its value, nullptr as next, and last as
  // previous
  ListNode *temp = new ListNode(arg, nullptr, last);
  last->next = temp; // Sets next of last equal to temp
  temp->next = head; // Sets next of temp equal to head
  return head;       // Returns head
}

ListNode *ListNode ::add(ListNode *head, string arg, int x) {
  // Checks to see if head is empty or if x is 0
  if (head == nullptr || x == 0) {
    head = head->insertFirst(head, arg); // Returns result of insertFirst
  }
  // Checks if x is greater than or equal to length
  else if (x >= head->getLength()) {
    head = head->insertLast(head, arg); // Returns result of insertLast
  } else {
    // Creates a new ListNode with arg as value, nullptr as next a previous
    ListNode *newNode = new ListNode(arg, nullptr, nullptr);
    ListNode *currentNode = head;  // Creates a new ListNode equal to head
    ListNode *previousNode = head; // Creates a new ListNode equal to head

    for (int i = 0; i < x; i++) { // Loops until i equals one before x
      // Sets currentNode equal to next of currentNode
      currentNode = currentNode->next;
    }

    for (int i = 0; i < x - 1; i++) { // Loops until i equals one before x
      // Sets previousNode equal to next of previousNode
      previousNode = previousNode->next;
    }

    currentNode->previous = newNode;  // Sets previous equal to newNode
    newNode->next = currentNode;      // Sets next equal to currentNode
    newNode->previous = previousNode; // Sets previous equal to previousNode
    previousNode->next = newNode;     // Sets next equal to newNode
  }
  return head; // Returns head
}

ListNode *ListNode ::removeFirst(ListNode *head) {
  ListNode *temp = head->previous; // Sets temp equal to previous of head
  ListNode *temp2 = head->next;    // Sets temp2 equal to next of head
  temp2->previous = temp;          // Sets previous of temp2 equal to temp
  temp->next = temp2;              // Sets next of temp equal to temp2
  head = nullptr;                  // Sets head equal to nullptr
  return temp2;                    // Returns temp2
}

ListNode *ListNode ::removeLast(ListNode *head) {
  ListNode *temp = head; // Creates new ListNode equal to next of head
  while (temp->next->next != head) { // Loops until two nodes before end of list
    temp = temp->next;               // Sets temp equal to next of temp
  }
  temp->next = head;     // Sets next of temp equal to head
  head->previous = temp; // Sets previous of head equal to temp
  return head;           // Returns head
}

ListNode *ListNode ::remove(ListNode *head, int x) {
  if (x == 0) {                     // Checks if x is 0
    head = head->removeFirst(head); // Returns result of removeFirst
  } else if (x == head->getLength()) {
    head = head->removeLast(head); // Returns result of removeLast
  } else {
    ListNode *previousNode = head; // Creates a new ListNode equal to head
    ListNode *afterNode = head;    // Creates a new ListNode equal to head

    // Loops until position before node to be deleted
    for (int i = 0; i < x - 1; i++) {
      previousNode = previousNode->next; // Sets previousNode equal to next
    }

    // Loops until position after node to be deleted
    for (int j = 0; j < x + 1; j++) {
      afterNode = afterNode->next; // Sets afterMpde equal to next
    }

    // Sets next of previousNode equal to afterNode
    previousNode->next = afterNode;
    // Sets previous of afterNode equal to previousNode
    afterNode->previous = previousNode;
  }
  return head; // Returns head
}

ListNode ::operator const char *() {
  ostringstream format;  // Makes it easy to convert to string
  ListNode *head = this; // Creates a pointer reference equal to the ListNode

  cout << "["; // Prints bracket

  for (int j = 1; j < head->getLength(); j++) { // Loops until end of list
    cout << head->getValue();                   // Prints value of head
    head = head->getNext();                     // Sets head equal to next
    if (head != nullptr) {                      // Checks to see if temp is NULL
      cout << ", ";                             // Prints a comma
    }
  }
  cout << head->getValue(); // Prints value of head
  cout << "]" << endl;      // Prints out a bracket and a line

  listFormatted = format.str(); // Sets string equal to format string
  return listFormatted.c_str(); // Returns the formatted ListNode object
}

void printForward(ListNode *head, int x) {
  for (int i = 0; i < x; i++) { // Loops until position
    head = head->getNext();     // Sets head equal to next
  }

  cout << "["; // Prints bracket

  for (int j = 1; j < head->getLength(); j++) { // Loops until end of list
    cout << head->getValue();                   // Prints value of head
    head = head->getNext();                     // Sets head equal to next
    if (head != nullptr) {                      // Checks to see if temp is NULL
      cout << ", ";                             // Prints a comma
    }
  }
  cout << head->getValue(); // Prints value of head
  cout << "]" << endl;      // Prints out a bracket and a line
}

void printBackward(ListNode *head, int x) {
  for (int i = 0; i < x; i++) { // Loops until position
    head = head->getNext();     // Sets head equal to next
  }

  cout << "["; // Prints bracket

  for (int j = 1; j < head->getLength(); j++) { // Loops until end of list
    cout << head->getValue();                   // Prints value of head
    head = head->getPrevious();                 // Sets head equal to previous
    if (head != nullptr) {                      // Checks to see if temp is NULL
      cout << ", ";                             // Prints a comma
    }
  }
  cout << head->getValue(); // Prints value of head
  cout << "]" << endl;      // Prints out a bracket and a line
}

#endif