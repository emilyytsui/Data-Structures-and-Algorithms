//Lesson7_2.cpp         //Author: Emily Tsui
//Function that takes a nonnegative int, displays true in main if the int is a perfect number

#include <iostream>
using namespace std;

void PerfectNumber(int num, bool& display){
  int sum = 0;
  
  for(int i = 1; i < num; i++){
    if(num % i == 0){
      sum = sum + i;
    }
  }

  if(num == sum){
    display = true;
  }

}

int main() {
  int x;
  cout << "Enter a nonnegative integer: ";
  cin >> x;

  bool perfect;
  PerfectNumber(x, perfect);
  
  if(perfect){
    cout << perfect << "/true";
  }

  return 0;
}