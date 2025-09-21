//WordCount.cpp           //Author: Emily Tsui
//Prompts user, displays the list of words and its count in new text file

#include <iostream>
#include <fstream> //File operation
#include <ctype.h> //Contains toLower()
#include <string> //String header
using namespace std; //Namespace to search in

class ListNode{
  private: //private attributes
    string value; //Represents user input
    ListNode* next; //Represents user input
    int frequency; //Variable for counting

  public:
    ListNode();
    ListNode(string str, ListNode* n, int x);
    string getValue();
    ListNode* getNext();
    int getFrequency();
    ListNode* insertNode(ListNode* head, string arg);
    string toLowerCase(string);
};

ListNode :: ListNode(){ //Constructor
  value = ""; //Sets value to default value of ""
  next = nullptr; //Sets next to default value of NULL
  frequency = 0; //Sets frequency to default value of 0
}

ListNode :: ListNode(string str, ListNode* n, int x){ //Constructor
  value = str; //Sets value equal to user input
  next = n; //Sets next equal to user input
  frequency = x; //Sets frequency equal to user input
}

string ListNode :: getValue(){ //Returns value
  return value;
}

ListNode* ListNode :: getNext(){ //Returns next
  return next;
}

int ListNode :: getFrequency(){ //Returns frequency
  return frequency;
}

//Returns a reference to node inserted
ListNode* ListNode :: insertNode(ListNode* head, string arg){
  //Checks to see if list is empty or if arg is smaller than value (comes first in the alphabet)
  if(head == nullptr || arg < head->value){
    ListNode* node = new ListNode(); //Creates a new node
    node->value = arg; //Sets value of node equal to user input
    node->frequency = 1; //Sets frequency equal to 1
    node->next = head; //Sets next equal to head
    head = node; //Sets head equal to node
  }else{
    ListNode* temp = head->next; //Reference that points to next node of list 
    ListNode* previous = head; //Reference that points to first node of list 
    //Loops until the end of list as long as arg is larger (later in alphabet) than value
    while(temp != nullptr && arg > temp->value){
      previous = temp; ///Sets previous equal to temp
      temp = temp->next; //Sets temp equal to next
    }
    //Checks to see if temp is not at the end of the list and arg is equal to value
    if(temp != nullptr && arg == temp->value){
      temp->frequency++; //Increases frequency by 1
    }else{
      ListNode* node2 = new ListNode(); //Creates new ListNode
      node2->value = arg; //Sets value equal to arg
      node2->frequency = 1; //Sets frequency = 1
      node2->next = temp; //Sets next of node2 equal to temp
      previous->next = node2; //Sets next of previous equal to node2
    }
  }
  return head; //Returns head
}

string toLowerCase(string str){ //Converts string to lower case
  for(int i = 0; i < str.length(); i++){ //Loops through string
    str[i] = tolower(str[i]); //Sets character equal to lowercase using tolower()
  }
  return str; //Returns str
}

//Method that retrieves the strings from user inputted file
string getWords(istream& file){
  string word; //Variable for storage
  char ch; //Variable for storage
  //Loops through file while it's open and while character isn't a digit or a letter
  while(file && !isalnum(file.peek())){
    file.get(ch); //Gets the character located in file
  }
  word = ""; //Makes word empty, skips over the characters if it isn't a digit or letter
  //Loops through file while it's open and while character is a digit or a letter
  while(file && isalnum(file.peek())){
    file.get(ch); //Gets the character located in file
    word += ch; //Adds the character to word
  }
  return word; //Returns word
}

//Prints the list node value and its frequency in the file
void printResult(ListNode* head){
  ofstream myfile ("result.txt"); //Creates a new file, named it result.txt
  if(myfile.is_open()){ //Checks to see if file is open
    head = head->getNext(); //Sets head equal to next
    while(head != nullptr){ //Loops through list until NULL
      //Displays head, one word and its frequency per line (separated by a single space)
      myfile << head->getValue() << " " << head->getFrequency() << endl;
      head = head->getNext(); //Sets head equal to next using getNext()
    }
    myfile.close(); //Closes the file
  }else{
    cout << "Unable to open file"; //Displays prompt
  }
}

int main() {
  string fileName; //Variable for storage
  cout << "Please enter the name of a file: "; //Displays Prompt
  cin >> fileName; //Gets user input

  ifstream myfile(fileName); //Opens the user's file

  ListNode* list = new ListNode(); //Pointer for storage
  string word = ""; //Variable for storage

  if(myfile.is_open()){ //Checks to see if file is open
    word = getWords(myfile); //Sets word equal to result of getWords()
    while(word != "") { //While word is not empty
      word = toLowerCase(word); //Sets word equal to result of toLowerCase()
      list->insertNode(list, word); //Inserts word to list using insertNode()
      word = getWords(myfile); //Sets word equal to result of getWords()
    }
    myfile.close(); //Closes file
  }else{
    cout << "Unable to open file"; //Displays prompt
  }

  printResult(list); //Calls printResult() to display the results in a new file
  
  return 0; //Returns 0
}