//Lesson13.cpp        //Author: Emily Tsui
//Stimulated rolling of a pair of 6-sided dice using static_cast, loops it 10,000 times, displays percentage of each result

#include <iostream>
#include <random>
using namespace std;

int main() {

  int arr[10000];
  
  double two = 0;
  double three = 0; 
  double four = 0; 
  double five = 0; 
  double six = 0; 
  double seven = 0; 
  double eight = 0; 
  double nine = 0; 
  double ten = 0; 
  double eleven = 0; 
  double twelve = 0; 

  for(int i = 0; i < 10000; i++){
    srand(time(NULL));
    arr[i] = rand() % 11 + 1;
  }

  for(int i = 0; i < 10000; i++){
    if(arr[i] == 2){
      two++;
    }
    if(arr[i] == 3){
      three++;
    }
    if(arr[i] == 4){
      four++;
    }
    if(arr[i] == 5){
      five++;
    }
    if(arr[i] == 6){
      six++;
    }
    if(arr[i] == 7){
      seven++;
    }
    if(arr[i] == 8){
      eight++;
    }
    if(arr[i] == 9){
      nine++;
    }
    if(arr[i] == 10){
      ten++;
    }
    if(arr[i] == 11){
      eleven++;
    }
    if(arr[i] == 12){
      twelve++;
    }
  }
  
  two = static_cast<double>(two) / 10000 * 100;
  three = static_cast<double>(three) / 10000 * 100;
  four = static_cast<double>(four) / 10000 * 100;
  five = static_cast<double>(five) / 10000 * 100;
  six = static_cast<double>(six) / 10000 * 100;
  seven = static_cast<double>(seven) / 10000 * 100;
  eight = static_cast<double>(eight) / 10000 * 100;
  nine = static_cast<double>(nine) / 10000 * 100;
  ten = static_cast<double>(ten) / 10000 * 100;
  eleven = static_cast<double>(ten) / 10000 * 100;
  twelve = static_cast<double>(ten) / 10000 * 100;

  cout << two << endl << three << endl << four << endl << five << endl;
  cout << six << endl << seven << endl << eight << endl << nine << endl << ten << endl << eleven << endl << twelve; 
  
} 