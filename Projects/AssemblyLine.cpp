// AssemblyLine.cpp                //Author: Emily Tsui
// Simulation of an assembly line for assembling pyramids of stacks of disks

#include <iostream>
#include <sstream>  // Has ostringstream, easy string conversion
#include <stdlib.h> // Contains rand for radii generator
#include <time.h>   // Has random seed generator
using namespace std;

class Disk {
private:
  int value;           // Represents argument
  string diskPrintted; // Variable to store Disk

public:
  Disk() {     // Constructor
    value = 0; // Sets value to default value of 0
  }

  Disk(int x) { // Constructor
    value = x;  // Sets value equal to user input
  }

  int getValue() {
    return value; // Returns value
  }

  operator const char *() {
    ostringstream format;        // Makes it easy to convert to string
    format << value;             // Adds value to format
    diskPrintted = format.str(); // Sets string equal to format string
    return diskPrintted.c_str(); // Returns the formatted Queue object
  }
};

class Pyramid {
private:
  Disk value;            // Represents argument
  Pyramid *next;         // Pointer to next
  string stackFormatted; // Variable to store formatted stack

public:
  Pyramid() {       // Constructor
    value = Disk(); // Sets value to default Disk
    next = nullptr; // Sets next to default value of NULL
  }

  Pyramid(Disk x, Pyramid *n) { // Constructor
    value = x;                  // Sets value equal to user input
    next = n;                   // Sets next equal to user input
  }

  Disk getValue() {
    return value; // Returns value
  }

  Pyramid *getNext() {
    return next; // Returns next
  }

  Pyramid *peek(Pyramid *head) {
    return head->pointerToLast(head); // Returns pointer to last node
  }

  int getLength() {
    int count = 0;               // Variable for storage
    Pyramid *current = this;     // Pointer variable for placement
    while (current != nullptr) { // Loops until the end of the list
      count++;                   // Increases count by 1
      current = current->next;   // Sets current to next
    }
    return count; // Returns count
  }

  Pyramid *pointerToLast(Pyramid *head) {
    if (head == nullptr) { // Checks to see is head is empty
      return head;         // Returns NULL
    } else {
      Pyramid *copy = head;        // Creates new node
      if (head->next == nullptr) { // Base case, checks if next is NULL
        return head;               // Returns head
      }
      // Returns value of head called to pointerToLast of next value
      return head->pointerToLast(head->next);
    }
  }

  Pyramid *push(Pyramid *head, Disk x) {
    // Creates a new node, x as value and nullptr as next
    Pyramid *node = new Pyramid(x, nullptr);
    if (head == nullptr) { // Checks to see if queue is emtpy
      return node;         // Returns NULL
    }
    // Makes next of last node equal to node
    head->pointerToLast(head)->next = node;
    return head; // Returns head
  }

  Disk pop(Pyramid *head) {
    // Stores value of last node in head
    Disk d = head->pointerToLast(head)->getValue();

    Pyramid *previousNode = head; // Creates new Pyramid equal to head
    // Loops until second last node
    for (int i = 0; i < head->getLength() - 2; i++) {
      previousNode = previousNode->next; // Sets previousNode equal to next
    }

    previousNode->next = nullptr; // Sets next of previousNode equal to null

    return d; // Returns removed node
  }

  operator const char *() {
    ostringstream format;       // Makes it easy to convert to string
    Pyramid *head = this->next; // Pointer reference equal to next of this

    format << "["; // Prints a bracket

    while (head != nullptr) {     // Loops until the end
      format << head->getValue(); // Prints value
      head = head->getNext();     // Sets head equal to next
      if (head != nullptr) {      // Checks to see if head is empty
        format << ", ";           // Prints out a comma
      }
    }

    format << "]"; // Prints out a bracket

    stackFormatted = format.str(); // Sets string equal to format string
    return stackFormatted.c_str(); // Returns the formatted Pyramid object
  }
};

class DiskQueue {
private:
  Disk value;            // Represents argument
  DiskQueue *next;       // Pointer to next
  string queueFormatted; // Variable to store formatted queue

public:
  DiskQueue() {     // Constructor
    value = Disk(); // Sets value to default value
    next = nullptr; // Sets next to default value of NULL
  }

  DiskQueue(Disk arg, DiskQueue *n) { // Constructor
    value = arg;                      // Sets value equal to user input
    next = n;                         // Sets next equal to user input
  }

  Disk getValue() { // Returns value
    return value;
  }

  DiskQueue *getNext() { // Returns next
    return next;
  }

  int getLength() {
    int count = 0;                     // Variable for storage
    DiskQueue *current = this;         // Pointer variable for placement
    while (current->next != nullptr) { // Loops until the end of the list
      count++;                         // Increases count by 1
      current = current->getNext();    // Sets current to next
    }
    return count; // Returns count
  }

  DiskQueue *pointerToLast(DiskQueue *queue) {
    if (queue == nullptr) { // Checks to see is queue is empty
      return queue;         // Returns NULL
    } else {
      DiskQueue *copy = queue;      // Creates new node
      if (queue->next == nullptr) { // Base case, checks if next is NULL
        return queue;               // Returns queue
      }
      // Returns value of queue called to pointerToLast of next value
      return queue->pointerToLast(queue->next);
    }
  }

  DiskQueue *enqueue(DiskQueue *queue, Disk arg) {
    // Creates a new node with value equal to arg and next as NULL
    DiskQueue *node = new DiskQueue(arg, nullptr);
    if (queue == nullptr) { // Checks to see if queue is emtpy
      return node;          // Returns node
    }
    // Makes next of last node equal to node
    queue->pointerToLast(queue)->next = node;
    return queue; // Returns queue
  }

  DiskQueue *dequeue(DiskQueue *queue) {
    if (queue == nullptr) { // Checks to see if queue is emtpy
      return nullptr;       // Returns NULL
    }
    queue = queue->next; // Sets queue equal to next
    return queue;        // Returns queue
  }

  operator const char *() {
    ostringstream format;   // Makes it easy to convert to string
    DiskQueue *head = this; // Pointer reference equal to this

    format << "["; // Prints a bracket

    while (head != nullptr) {     // Loops until the end
      format << head->getValue(); // Prints value
      head = head->getNext();     // Sets head equal to next
      if (head != nullptr) {      // Checks to see if head is empty
        format << ", ";           // Prints out a comma
      }
    }

    format << "]"; // Prints a bracket

    queueFormatted = format.str(); // Sets string equal to format string
    return queueFormatted.c_str(); // Returns the formatted Queue object
  }
};

class PyramidQueue {
private:
  Pyramid *value;        // Represents argument
  PyramidQueue *next;    // Pointer to next
  string queueFormatted; // Variable to store formatted queue

public:
  PyramidQueue() {         // Constructor
    value = new Pyramid(); // Sets value to default value
    next = nullptr;        // Sets next to default value of NULL
  }

  PyramidQueue(Pyramid *arg, PyramidQueue *n) { // Constructor
    value = arg; // Sets value equal to user input
    next = n;    // Sets next equal to user input
  }

  Pyramid *getValue() { // Returns value
    return value;
  }

  PyramidQueue *getNext() { // Returns next
    return next;
  }

  int getLength() {
    int count = 0; // Variable for storage
    PyramidQueue *current =
        new PyramidQueue();         // Pointer variable for placement
    while (current != nullptr) {    // Loops until the end of the list
      count++;                      // Increases count by 1
      current = current->getNext(); // Sets current to next
    }
    return count; // Returns count
  }

  PyramidQueue *pointerToLast(PyramidQueue *queue) {
    if (queue == nullptr) { // Checks to see is queue is empty
      return queue;         // Returns NULL
    } else {
      PyramidQueue *copy = queue;   // Creates new node
      if (queue->next == nullptr) { // Base case, checks if next is NULL
        return queue;               // Returns queue
      }
      // Returns value of queue called to pointerToLast of next value
      return queue->pointerToLast(queue->next);
    }
  }

  PyramidQueue *enqueue(PyramidQueue *queue, Pyramid *arg) {
    // Creates a new node with value equal to arg and next as NULL
    PyramidQueue *node = new PyramidQueue(arg, nullptr);
    if (queue == nullptr) { // Checks to see if queue is emtpy
      return node;          // Returns node
    }
    // Makes next of last node equal to node
    queue->pointerToLast(queue)->next = node;
    return queue; // Returns queue
  }

  PyramidQueue *dequeue(PyramidQueue *queue) {
    if (queue == nullptr) { // Checks to see if queue is emtpy
      return nullptr;       // Returns NULL
    }
    queue = queue->next; // Sets queue equal to next
    return queue;        // Returns queue
  }

  operator const char *() {
    ostringstream format;      // Makes it easy to convert to string
    PyramidQueue *head = this; // Pointer reference equal to this

    format << "["; // Prints a bracket

    while (head != nullptr) {      // Loops until the end
      format << *head->getValue(); // Prints value
      head = head->getNext();      // Sets head equal to next
      if (head != nullptr) {       // Checks to see if head is empty
        format << ", ";            // Prints out a comma
      }
    }

    format << "]"; // Prints out a bracket

    queueFormatted = format.str(); // Sets string equal to format string
    return queueFormatted.c_str(); // Returns the formatted Queue object
  }
};

class AssemblyLine {
private:
  DiskQueue *assemblyLineIn;     // Queue of Disks
  PyramidQueue *assemblyLineOut; // Queue of Pyramids
  Pyramid *robotArm;             // A Pyramid

public:
  AssemblyLine(int nDisks) {
    srand(time(NULL)); // Random time seed

    // Loops for many Disks there are
    for (int i = 0; i < nDisks; i++) {
      // Enqueues new Disk of random radii between 1-100 to assemblyLineIn
      assemblyLineIn =
          assemblyLineIn->enqueue(assemblyLineIn, rand() % 100 + 1);
    }

    assemblyLineOut = new PyramidQueue(); // Initialized to an empty Queue
    robotArm = new Pyramid();             // Initialized to an empty Pyramid
  }

  void unloadRobot() {
    // Flips over the pyramid in the robotArm, adds it to assemblyLineOut queue
    Pyramid *temp = new Pyramid();      // Pointer Pyramid for reference
    while (robotArm->getLength() > 1) { // Loops while robotArm isn't empty
      // Pops off and pushes top node of robotArm onto temp
      temp->push(temp, robotArm->pop(robotArm));
    }
    // Enqueues temp to assemblyLineOut
    assemblyLineOut->enqueue(assemblyLineOut, temp);
  }

  void process() { // Processes all disks from assemblyLineIn
    // Loops while assemblyLineIn isn't empty
    while (assemblyLineIn != nullptr) {

      // Dequeues assemblyLineIn, creates a Disk with removed Disk value
      Disk temp = assemblyLineIn->getValue();
      assemblyLineIn = assemblyLineIn->dequeue(assemblyLineIn);

      // If robotArm isn't empty and next disk doesn't fit on robotArm (smaller)
      if (robotArm->getLength() > 0 &&
          temp.getValue() < robotArm->peek(robotArm)->getValue().getValue()) {
        unloadRobot(); // Unloads robotArm
      }

      // Adds disk from assemblyLineIn to robotArm
      robotArm = robotArm->push(robotArm, temp);
    }

    // All disks have been retrievd from assemblyLineIn
    unloadRobot(); // Unloads robotArm
    // Dequeues extra empty set of brackets
    assemblyLineOut = assemblyLineOut->dequeue(assemblyLineOut);
  }

  void inputQueue() {
    cout << *assemblyLineIn << endl; // Prints Queue of Disks and a line
  }

  void outputQueue() {
    cout << *assemblyLineOut << endl; // Prints Queue of Pyramids and a line
  }
};

int main() {
  AssemblyLine *a = new AssemblyLine(10);
  cout << "Input Queue: ";
  a->inputQueue();
  a->process();
  cout << "Output Queue: ";
  a->outputQueue();

  return 0;
}