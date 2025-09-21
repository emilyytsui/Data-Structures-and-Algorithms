#include <iostream>
#include "ListLab3.h"
using namespace std;

void printMeBack(ListNode* head)
{
    cout << "[";
  head = head->pointerToLast(head);
    while(head != NULL)
    {
         cout << head->getValue();
         head = head->getPrevious();
         if(head != NULL)
             cout << ", ";
    }
    cout << "]" << endl;
}

void printMe(ListNode* head)
{
    cout << "[";

    while(head != NULL)
    {
         cout << head->getValue();
         head = head->getNext();
         if(head != NULL)
             cout << ", ";
    }
    cout << "]" << endl;
}

int main()
{
  cout << "hheeh" << endl;
  ListNode* head = new ListNode("hello", head, nullptr);
  head = head->add(head, "bye", 1);
  head = head->add(head, "kay", 1);
  head = head->add(head, "zello", 1);
  head = head->add(head, "jello", 0);
  printMe(head);
  printMeBack(head);
  cout << *head << endl;

  head = head->remove(head, 0);
 
  printMe(head);
  printMeBack(head);
  cout << *head << endl;
 
  head = head->remove(head, 3);

  printMe(head);
  printMeBack(head);
  cout << *head << endl;

  head = head->remove(head, 1);
  printMe(head);
  printMeBack(head);
  cout << *head << endl;

  return 0;
}