//ListLab3.cpp            //Author: Emily Tsui
//Demonstrates a doubly-linked list, adds and removes nodes

#ifndef LISTLAB3_H
#define LISTLAB3_H

#include <iostream>
#include <sstream> //Has ostringstream, easy string conversion
using namespace std;

class ListNode{
  private:
    string value; //Represents user input
    ListNode* next; //Represents user input
    ListNode* previous; //Represents user input
    string listFormatted; //String variable to store formatted ListNode

  public:
    ListNode();
    ListNode(string, ListNode*, ListNode*);
    string getValue();
    ListNode* getNext();
    ListNode* getPrevious();
    int getLength();
    ListNode* pointerToLast(ListNode* head);
    ListNode* add(ListNode*, string);
    ListNode* add(ListNode*, string, int);
    ListNode* remove(ListNode*);
    ListNode* remove(ListNode*, int);
    operator const char * ();
};

ListNode :: ListNode(){ //Constructor
  value = ""; //Sets value to default value of ""
  next = nullptr; //Sets next to default value of NULL
  previous = nullptr; //Sets previous to default value of NULL
}

ListNode :: ListNode(string str, ListNode* n, ListNode* p){ //Constructor
  value = str; //Sets value equal to user input
  next = n; //Sets next equal to user input
  previous = p;
}

string ListNode :: getValue(){ //Returns value
  return value;
}

ListNode* ListNode :: getNext(){ //Returns next
  return next;
}

ListNode* ListNode :: getPrevious(){ //Returns previous
  return previous;
}

int ListNode :: getLength(){
  int count = 0; //Variable for storage
  ListNode* current = this; //Pointer variable for placement
  while(current != nullptr){ //Loops until the end of the list
    count++; //Increases count by 1
    current = current->next; //Sets current to next
  }
  return count; //Returns count
}

//returns a reference to the last node in the list, or NULL if the list is empty
ListNode* ListNode :: pointerToLast(ListNode* head){
  if(head == nullptr){ //Checks to see is head is empty
    return head; //Returns NULL
  }else{
    ListNode* copy = head; //Creates new node
    if(head->next == nullptr){ //Base case, checks if next is NULL
      return head; //Returns head
    }
    //Returns value of head called to pointerToLast of next value
    return head->pointerToLast(head->next);
  }
}

ListNode* ListNode :: add(ListNode* head, string arg){
  ListNode* node = new ListNode(arg, head, nullptr);
  head->previous = node; //Sets previous of head equal to node
  return node; //Returns node
}

ListNode* ListNode :: add(ListNode* head, string arg, int x){
  if(head == nullptr){ //Checks to see if list is emtpy
    return nullptr; //Returns NULL
  }
  
  ListNode* current = head; //Reference that points to first node of list 

  //Checks to see if user inputted position is greater than list size
  if(x > head->getLength()){
    //Creates a new node with arg as value, nullptr as previous and next
    ListNode* node = new ListNode(arg, nullptr, nullptr);
    head->pointerToLast(head)->next = node; //Makes previous last point to next
  }else if(x == 0){ //Checks to see if user wants to add at position 0
    head = head->add(head, arg); //Inserts the node at the front of the list
  }else{
    //Loops until one node before position specified by user
    for(int i = 0; i < x - 1; i++){
      current = current->next; //Sets current equal to next
    }
    
    //Creates new node, arg as value, next of current as next and current as previous 
    ListNode* newNode = new ListNode(arg, current->next, current);
    //Sets nextNode reference of current to point to newNode
    current->next = newNode;
    
    if(newNode->next != nullptr){ //Checks to see if next value of newNode is NUll
      newNode->next->previous = newNode; //Sets the previous value of next equal to newNode
    }
  }
  return head; //Returns head
}

ListNode* ListNode :: remove(ListNode* head){
  head = head->next; //Sets head equal to next
  head->previous = nullptr; //Sets previous of head equal to null
  return head; //Returns head
}

ListNode* ListNode :: remove(ListNode* head, int x){
  if(head == nullptr){ //Checks to see if list is emtpy
    return nullptr; //Returns NULL
  }

  ListNode* previousNode = head; //Reference that points to first node of list
  ListNode* currentNode = head; //Reference that points to first node of list

  //Checks to see if user inputted position is greater than list size
  if(x > head->getLength()){
    cout << "Position entered is out of bounds"; //Displays prompt
  }else if(x == 0){ //Checks to see if user wants to remove at position 0
    head = head->remove(head); //Sets head equal to next
  }else{
    //Traverses list until previousNode is node before the node to be deleted
    for(int i = 0; i < x - 1; i++){
      previousNode = previousNode->next; //Sets previousNode equal to next
    }

    //Traverses list until currentNode is the node to be deleted
    for(int j = 0; j < x; j++){
      currentNode = currentNode->next; //Sets currentNode equal to next
    }

    //Changes nextNode pointer of previousNode to point to node after currentNode
    previousNode->next = currentNode->next;
    
    currentNode->previous->next = currentNode->next; //Sets previous of next equal to next
    if(currentNode->next != nullptr){ //Checks to see if empty
      currentNode->next->previous = currentNode->previous; //Sets previous of next equal to previous
    }
  }
  
  return head; //Returns head
}

ListNode :: operator const char * (){
  ostringstream format; //Makes it easy to convert to string
  ListNode* head = this; //Creates a pointer reference equal to the ListNode
  
  cout << "["; //Prints a bracket

  while(head != nullptr){ //Loops until the end
    cout << head->getValue(); //Prints value
    head = head->getNext(); //Sets head equal to next
    if(head != nullptr){ //Checks to see if head is empty
      cout << ", "; //Prints out a comma
    }
  }
  cout << "]" << endl; //Prints out a bracket and a line
  
  listFormatted = format.str(); //Sets string equal to format string
  return listFormatted.c_str(); //Returns the formatted Complex object
}

#endif