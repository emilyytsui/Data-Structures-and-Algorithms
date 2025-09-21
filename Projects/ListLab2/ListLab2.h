//ListLab2.h            //Author: Emily Tsui
//Creates header file to work with ListLab2.cpp

#ifndef LISTLAB2_H
#define LISTLAB2_H

#include <iostream>
using namespace std;

class ListNode{
  private: //private attributes
    string value; //Represents user input
    ListNode* next; //Represents user input

  public:
    ListNode();
    ListNode(string str, ListNode* n);
    string getValue();
    ListNode* getNext();
    ListNode* copyNode(ListNode* arg);
    ListNode* copyList(ListNode* arg);
    ListNode* rest(ListNode* h);
    string first(ListNode* head);
    string second(ListNode* head);
    ListNode* pointerToLast(ListNode* head);
    ListNode* copyOfLast(ListNode* head);
    ListNode* insertFirst(ListNode* head, string arg);
    ListNode* insertLast(ListNode* head, string arg);
    int getLength();
    ListNode* insertMiddle(ListNode*, string, int);
    ListNode* remove(ListNode*, int);
};

ListNode :: ListNode(){ //Constructor
  value = ""; //Sets value to default value of ""
  next = nullptr; //Sets next to default value of NULL
}

ListNode :: ListNode(string str, ListNode* n){ //Constructor
  value = str; //Sets value equal to user input
  next = n; //Sets next equal to user input
}

string ListNode :: getValue(){ //Returns value
  return value;
}

ListNode* ListNode :: getNext(){ //Returns next
  return next;
}

//returns a new node that is a copy of the argument node
ListNode* ListNode :: copyNode(ListNode* arg){ 
  if(arg == nullptr){ //Checks to see if list is empty
    return nullptr; //Returns NULL
  }else{
    ListNode* copy = new ListNode(); //Creates new node
    copy->value = arg->value; //Sets data value equal to arg value
    copy->next = arg->next; //Sets next value to next arg
    return copy; //Returns copy node
  }
}

//returns a new list that is a copy of the original list
ListNode* ListNode :: copyList(ListNode* arg){
  if(arg == nullptr){ //Checks to see if list is empty
    return nullptr; //Returns NULL
  }else{
    ListNode* copy = new ListNode(); //Creates new list
    copy->value = arg->value; //Sets data value equal to 
    copy->next = copyList(arg->next); //Recursive call to next node
    return copy; //Returns copy list
  }
}

//returns a new linked list containing copies of each node in the original list except the first node, maintaining the order of the original list
ListNode* ListNode :: rest(ListNode* h){
  return copyList(h->next); //Calls copyList() with next as its argument
}

//returns the value of the first node, or NULL if the list is empty
string ListNode :: first(ListNode* head){
  if(head == nullptr){ //Checks to see is head is empty
    return nullptr; //Returns NULL
  }else{
    return head->value; //Returns the value of first node using getValue()
  }
}

//returns the value of the second node, or NULL if the list is empty or if there is only one node
string ListNode :: second(ListNode* head){
  //Checks to see is head is empty or if there's only one node
  if(head == nullptr || head->next == nullptr){
    return nullptr; //Returns NULL
  }else{
    ListNode* r = new ListNode(); //Create new node
    r = head->rest(head); //Sets r equal to value of rest(head)
    return r->first(r); //Returns value of second node using getValue()
  }
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

//returns a copy of the last node
ListNode* ListNode :: copyOfLast(ListNode* head){
  ListNode* copy = new ListNode(); //Creates new node
  //Sets value of copy equal to the value of pointerToLast()
  copy->value = head->pointerToLast(head)->value;
  copy->next = nullptr; //Sets next equal to NULL
  return copy; //Returns copy
}

//returns a reference to a list whose first node's value is specified by the argument, and the first node's next links to the original list
ListNode* ListNode :: insertFirst(ListNode* head, string arg){
  ListNode* node = new ListNode(); //Creates a new node
  node->value = arg; //Sets value of node equal to user input
  node->next = head; //Sets next equal to head
  return node; //Returns node
}

//returns a reference to a list whose last node's value is specified by the argument, such that this last node has been appended to the original list and had its next is set to NULL
ListNode* ListNode :: insertLast(ListNode* head, string arg){
  ListNode* node = new ListNode(); //Creates a new node
  node->value = arg; //Sets value of node equal to user input
  node->next = nullptr; //Sets next equal to NULL
  head->pointerToLast(head)->next = node; //Makes previous last point to next
  return head; //Returns node
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

ListNode* ListNode :: insertMiddle(ListNode* head, string arg, int x){
  if(head == nullptr){ //Checks to see if list is emtpy
    return nullptr; //Returns NULL
  }
  
  ListNode* current = head; //Reference that points to first node of list 

  //Checks to see if user inputted position is greater than list size
  if(x > head->getLength()){
    head = head->insertLast(head, arg); //Inserts the node at the end of the list
  }else if(x == 0){ //Checks to see if user wants to remove at position 0
    head = head->insertFirst(head, arg); //Inserts the node at the front of the list
  }else{
    //Loops until one node before position specified by user
    for(int i = 0; i < x - 1; i++){
      current = current->next; //Sets current equal to next
    }
    //Creates newNode with string inputted by user, points to NULL
    ListNode* newNode = new ListNode(arg, nullptr);
    //Sets nextNode reference of new node to point to node following current
    newNode->next = current->next;
    //Sets nextNode reference of current to point to newNode
    current->next = newNode;
  }
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
    //Displays prompt
    cout << "Position entered is out of bounds, list without removal: ";
  }else if(x == 0){ //Checks to see if user wants to remove at position 0
    head = head->next; //Sets head equal to next
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
  }
  return head; //Returns head
}

#endif