#include <iostream>
#include "ListLab4.h"
using namespace std;

int main()
{
    cout << "FINALLYOMD" << endl;
    ListNode* head = new ListNode("hello", nullptr, nullptr);
    head = head->add(head, "bye", 1);
    printForward(head, 0);
    head = head->add(head, "kay", 1);
    head = head->add(head, "zello", 1);
    head = head->add(head, "jello", 0);
    printForward(head, 0);
    printForward(head, 2);
    printBackward(head, 0);
    printBackward(head, 2);


  head = head->remove(head, 0);
  printForward(head, 0);
  printForward(head, 2);
  printBackward(head, 0);
  printBackward(head, 2);
  head = head->remove(head, 3);
  printForward(head, 0);
  printForward(head, 2);
  printBackward(head, 0);
  printBackward(head, 2);

  head = head->remove(head, 1);
  printForward(head, 0);
  printBackward(head, 0);

    return 0;
}
