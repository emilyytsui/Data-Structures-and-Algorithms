//Lesson5.cpp           Author: Emily Tsui
//Uses bitwise operators on two boolean values inputed by the user

#include <iostream>
using namespace std;
#include <bitset>

int main() {
  
  bool x = false, y = false; //0-false, 1-true
  
  cout << "Enter false or true, 0 for false, 1 for true: ";
  cin >> x;

  cout << "Enter false or true, 0 for false, 1 for true: ";
  cin >> y;

  //Bitwise not, ~
  bitset<8> bitwiseNotx = (~x);
  bitset<8> bitwiseNoty = (~y);
  cout << "~" << x << " = " << bitwiseNotx << endl;
  cout << "~" << y << " = " << bitwiseNoty << endl;

  //Bitwise and, &
  bitset<8> bitwiseAnd = (x & y);
  cout << x << " & " << y << " = " << bitwiseAnd << endl;

  //Bitwise or, |
  bitset<8> bitwiseOr = (x | y);
  cout << x << " | " << y << " = " << bitwiseOr << endl;

  //Bitwise xor, ^
  bitset<8> bitwiseXor = (x ^ y);
  cout << x << " ^ " << y << " = " << bitwiseXor << endl;

  return 0;
}