//Lesson4b.cpp            Author: Emily Tsui
//Asks user for three strings and makes two 2-D arrays
//One array has each row contaning the given string once, another where each column has the given string once

#include <iostream>
using namespace std;
#include <string>

int main() {
  string x, y, z;

  cout << "Please enter a string: ";
  getline(cin, x);

  cout << "Please enter another string: ";
  getline(cin, y);
  
  cout << "Please enter a third string: ";
  getline(cin, z);

  //Array where each row contains the given string once
  string row[3][3];
  for(int i = 0; i < 3; i++){
    row[i][0] = x;
    row[i][1] = y;
    row[i][2] = z;
  }
  
  //Array where each column contains the given string once
  string col[3][3];
  for(int j = 0; j < 3; j++){
    col[0][j] = x;
    col[1][j] = y;
    col[2][j] = z;
  }

  //Print out arrays
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      cout << row[i][j];
    }
    cout << endl;
  }
  
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      cout << col[i][j];
    }
    cout << endl;
  }

  return 0;
}