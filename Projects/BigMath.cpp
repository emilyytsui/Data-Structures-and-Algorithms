//BigMath.cpp         Author: Emily Tsui
//Provides user with task options, user choses desired option, inputs necessary requirements for function, sees if user wants to repeat 

#include <iostream>
using namespace std; //Namespace to search in
#include <string> //Has stoi which makes string to int conversion and to_string

class BigMath{
  private: //private attributes
    int digit; //Digit of a BigMath object
    BigMath* next; //Pointer to the next object in the list

  public:
    BigMath(int, BigMath*); //Constructor
    void setValue(int); //setValue
    int getLength(); //getLength
    bool greaterThanEqual(BigMath*); //Greater than or equal to
    BigMath* reverse(BigMath* arg); //Reverse
    BigMath* insertFirst(BigMath*, int); //insertFirst
    BigMath* pointerToLast(BigMath*); //pointerToLast
    BigMath* insertLast(BigMath*, int); //insertLast
    BigMath* removeLast(BigMath*); //removeLast
    BigMath* copyList(BigMath* arg); //copyList
    BigMath* operator + (BigMath*); //Addition
    BigMath* operator - (BigMath*); //Subtraction
    void printList(BigMath*); //printList
};

BigMath :: BigMath(int x, BigMath* n){ //Constructor
  digit = x; //Sets value equal to user input
  next = n; //Sets next equal to user input
}

void BigMath :: setValue(int x){ //setValue
  digit = x; //Sets digit equal to x
}

int BigMath :: getLength(){ //getLength()
  int count = 0; //Variable for storage
  BigMath* current = this; //Pointer variable for placement
  while(current != nullptr){ //Loops until the end of the list
    count++; //Increases count by 1
    current = current->next; //Sets current to next
  }
  return count; //Returns count
}

bool BigMath :: greaterThanEqual(BigMath* other){ //Greater than or equal to
  if(other->getLength() > this->getLength()){ //Checks to see if other is longer than this
    return false; //Returns false
  }else if(other->getLength() < this->getLength()){ //Checks to see if other is short than this
    return true; //Returns true
  }else{
    other = other->reverse(other); //Sets other equal to reversed
    BigMath* copy = copyList(this); //Uses copyList() to copy this
    BigMath* list = reverse(copy); //Sets list equal to reversed of copy
    while(other != nullptr){ //Loops through list
      //Checks if other->digit is greater than list->digit
      if(other->digit > list->digit){
        return false; //Returns false
      }
      other = other->next; //Sets other equal to next
      list = list->next; //Sets list equal to next
    }
    return true; //Returns true
  }
}

BigMath* BigMath :: reverse(BigMath* arg){ //Reverse
  BigMath* temp = nullptr; //Creates pointer to store values temporarily
  BigMath* previous = nullptr; //Creates pointer that represents previous
  BigMath* current = copyList(this); //Creates pointer that represents head
  while(current != nullptr){ //Loops until end of the list
    temp = current->next; //Sets temp equal to next of current
    current->next = previous; //Sets next of current equal to previous
    previous = current; //Sets previous equal to current
    current = temp; //Sets current equal to temp
  }
  arg = previous; //Sets head equal to previous
  return arg; //Returns arg
}

BigMath* BigMath :: insertFirst(BigMath* head, int x){ //insertFirst
  BigMath* node = new BigMath(0, nullptr); //Creates a new node
  node->digit = x; //Sets value of node equal to user input
  node->next = this; //Sets next equal to head
  return node; //Returns node
}

BigMath* BigMath :: pointerToLast(BigMath* head){ //pointerToLast
  if(head == nullptr){ //Checks to see is head is empty
    return head; //Returns NULL
  }else{
    BigMath* copy = head; //Creates new node
    if(head->next == nullptr){ //Base case, checks if next is NULL
      return head; //Returns head
    }
    //Returns value of head called to pointerToLast of next value
    return head->pointerToLast(head->next);
  }
}

BigMath* BigMath :: insertLast(BigMath* head, int x){ //insertLast
  BigMath* node = new BigMath(0, nullptr); //Creates a new node
  node->digit = x; //Sets value of node equal to user input
  node->next = nullptr; //Sets next equal to NULL
  head->pointerToLast(head)->next = node; //Makes previous last point to next
  return head; //Returns head
}

BigMath* BigMath :: removeLast(BigMath* head){ //removeLast
  if(head == nullptr){ //Checks to see if at end of head
    return nullptr; //Returns NULL
  }
  //Checks to see if next is last digit in head
  if(head->next == nullptr){ //Checks to see if next is NULL
    delete head; //Deletes head
    return nullptr; //Returns NULL
  }
  BigMath* temp = head; //Creates temp pointer
  while(temp->next->next != nullptr){ //Loops until second last digit
    temp = temp->next; //Sets temp equal to next
  }
  delete(temp->next); //Deletes next
  temp->next = nullptr; //Sets next equal to null
  return head; //Returns head
}

BigMath* BigMath :: copyList(BigMath* arg){ //copyList
  if(arg == nullptr){ //Checks to see if list is empty
    return nullptr; //Returns NULL
  }else{
    BigMath* copy = new BigMath(0, nullptr); //Creates new list
    copy->digit = arg->digit; //Sets data value equal to 
    copy->next = copyList(arg->next); //Recursive call to next node
    return copy; //Returns copy
  }
}

BigMath* BigMath :: operator + (BigMath* other){ //Addition
  //Creates a new list equal to first list inputted by user
  BigMath* list = copyList(this); 
  int carry = 0; //Variable for storage
  
  //Sets sum equal to new BigMath object pointed to null, remainder of the sum of digits as digit
  BigMath* sum = new BigMath((list->digit + other->digit) % 10, nullptr);
 
  //Sets carry equal to quotient of the sum of digits in the different lists divided by 10
  carry = (list->digit + other->digit) / 10;
   
  list = list->next; //Sets list equal to next
  other = other->next; //Sets other equal to next

  while(list != nullptr || other != nullptr){ //Loops until either list is empty
    if(list == nullptr){ //Checks if list is empty
      //Uses insertLast() to insert remainder of the sum of carry and digit to the end of the list
      sum = insertLast(sum, (carry + other->digit) % 10);
      //Sets carry equal to quotient of the sum of carry and digit divided by 10
      carry = (carry + other->digit) / 10; 
      other = other->next; //Sets other equal to next
    }
    else if(other == nullptr){ //Checks if other is empty
      //Uses insertLast() to insert remainder of the sum of carry and digit to the end of the list
      sum = insertLast(sum, (carry + list->digit) % 10);
      //Sets carry equal to quotient of the sum of carry and digit divided by 10
      carry = (carry + list->digit) / 10;
      list = list->next; //Sets list equal to next
    }
    else{
      //Uses insertLast() to insert remainder of the sum of carry and digits to the end of the list
      sum = insertLast(sum, (carry + list->digit + other->digit) % 10);
      //Sets carry equal to quotient of the sum of carry and digit divided by 10
      carry = (carry + list->digit + other->digit) / 10;
      list = list->next; //Sets list equal to next
      other = other->next; //Sets other equal to next
    }
  }
  if(carry == 1){ //Checks to see if carry is 1
    sum = insertLast(sum, 1); //Inserts 1 into the end of sum
  }
  return sum; //Returns sum
}

BigMath* BigMath :: operator - (BigMath* other){ //Subtraction
  BigMath* list = copyList(this); //Uses copyList() to copy this
  BigMath* sub = nullptr; //Pointer for storage
  BigMath* difference = nullptr; //Pointer for storage
  int carry = 0; //Variable for storage
  BigMath* origList = copyList(list); //Pointer to store copied list
  BigMath* origOther = copyList(other); //Pointer to store copied other

  if(!list->greaterThanEqual(other)){ //Checks to see if other is greater than list
    list = copyList(other); //Sets list equal to copy of other
    other = copyList(origList); //Sets other equal to copy of list
  }

  while(list != nullptr){ //Loops until end of list
    //Sets digit of list equal to sum of carry and digit
    list->digit = carry + list->digit;
    carry = 0; //Sets carry equal to 0
    int diff = 0; //Variable for storage
    if(other != nullptr){ //Checks to see if at end of other
      //Checks to see if digit of list is smaller than other
      if(list->digit < other->digit){
        list->digit = list->digit + 10; //Adds 10 to the value of digit 
        carry = -1; //Sets carry equal to -1
      }
      //Sets diff equal to difference of the digits
      diff = list->digit - other->digit;
      other = other->next; //Sets other equal to next
    }else{
      //Checks to see if digit is greater than or equal to 0
      if(list->digit >= 0){
        diff = list->digit; //Sets diff equal to digit
      }else{
        list->digit = list->digit + 10; //Adds 10 to the value of digit 
        carry = -1; //Sets carry equal to -1
        diff = list->digit; //Sets diff equal to digit
      }
    }
    list = list->next; //Sets list equal to next

    //Creates new BigMath pointed to NULL, diff as its digit value
    BigMath* diffList = new BigMath(diff, nullptr);
    if(sub == nullptr){ //Checks to see if sub is NULL
      sub = diffList; //Sets sub equal to diffNode
      difference = diffList; //Sets difference equal to diffNode
    }else{
      sub->next = diffList; //Sets next equal to diffNode
      sub = sub->next; //Sets sub equal to next
    }
  }

  //Checks to see if last digit is equal to 0 and list is longer than 1
  while(pointerToLast(difference)->digit == 0 && difference->getLength() > 1){
    difference->removeLast(difference); //Calls removeLast() to remove the 0
  }

  if(!origList->greaterThanEqual(origOther)){ //Checks to see if other is greater than list
    //Sets last digit equal to negative value
    pointerToLast(difference)->digit = -pointerToLast(difference)->digit;
  }
  
  return difference; //Returns difference
}

void BigMath :: printList(BigMath* head){ //Print
  string print = ""; //Variable for storage
  BigMath* temp = head; //Creates temp pointer equal to head
  while(temp != nullptr){ //Loops until the end of the list
    print = to_string(temp->digit) + print; //Uses to_string to convert each node
    temp = temp->next; //Sets temp equal to next
  }
  cout << print << endl; //Prints out print and extra line
}

BigMath* convertReverse(string arg){ //Convert & Reverse
  BigMath* list = new BigMath(0, nullptr); //Creates BigMath object
  //Uses setValue() to set the value equal to the int at arg[0]
  list->setValue(stoi(string(1, arg[0])));
  for(int i = 1; i < arg.length(); i++){ //Loop through string
    //Uses stoi() to convert the string at arg[i] and inserts it into list
    list = list->insertFirst(list, stoi(string(1, arg[i])));
  }
  return list; //Returns list
}

int main(){ //Used for testing and displaying
  char rerun = 'y'; //Varaible used to detect when the loop should run
    
  while(rerun == 'y'){ //Loop to repeat process if user wants
    
      int task = 0; //Variable to store which task the user wants
      
      //Displays task options
      cout << "Task options: " << endl << "   1. Add two BigMath objects together\n";
      cout << "   2. Subtract two BigMath objects\n";

      //Asks user for desired task
      cout << "\nPlease enter the number corresponding to the desired task (1 or 2). ";
      cin >> task; //Gets user's inputs

      if(task == 1){ //add
        string s, s2; //Variables for storage
        cout << "   Enter first positive integer: "; //Asks user for input
        cin >> s; //Gets user input
        cout << "   Enter second positive integer: "; //Asks user for input
        cin >> s2; //Gets user input

        BigMath* first = convertReverse(s); //Creates BigMath using convertReverse
        BigMath* second = convertReverse(s2); //Creates BigMath using convertReverse
        
        cout << "   Sum = "; //Displays prompt
        //Uses operator and printList() to output results
        (*first + second)->printList(*first + second);

      }else if(task == 2){ //subtract
        string s, s2; //Variables for storage
        cout << "   Enter first positive integer: "; //Asks user for input
        cin >> s; //Gets user input
        cout << "   Enter second positive integer : "; //Asks user for input
        cin >> s2; //Gets user input

        BigMath* first = convertReverse(s); //Creates BigMath using convertReverse
        BigMath* second = convertReverse(s2); //Creates BigMath using convertReverse
        
        cout << "   Difference = ";//Displays prompt
        //Uses operator and printList() to output results
        (*first - second)->printList(*first - second);

      }else{ //Incase user inputs wrong number
        cout << "\nIncorrect input." << endl; //Tells user input was incorrect
      }
      //Asks user if they want to rerun the testing program
      cout << "\nWould you like to rerun? Enter 'n' for no, 'y' for yes. ";
      cin >> rerun; //Gets user's input
      cout << endl; //Enters another line for nice formatting
    }
  return 0;
}