// SortedFile.cpp           //Author: Emily Tsui
// Reads a user created text file, stores and orders words in a BST
// Outputs the words and their frequencies in a file (each separated by a line)

#include "TreeLab.h" // Binary Search Tree class
#include <fstream>   // File operation
#include <iostream>
#include <string>    // String header
using namespace std; // Namespace to search in

// Method that retrieves the strings from user inputted file
string getWords(istream &file) {
  string word; // Variable for storage
  char ch;     // Variable for storage
  // Loops through file while open and while character isn't a digit or a letter
  while (file && !isalnum(file.peek())) {
    file.get(ch); // Gets the character located in file
  }
  // Makes word empty, skips over the characters if it isn't a digit or letter
  word = "";
  // Loops through file while open and while character is a digit or a letter
  while (file && isalnum(file.peek())) {
    file.get(ch); // Gets the character located in file
    word += ch;   // Adds the character to word
  }
  return word; // Returns word
}

int main() {
  ifstream userfile("input.txt"); // Opens the user's file

  string arg = ""; // Variable for storage

  if (userfile.is_open()) { // Checks to see if file is open

    arg = getWords(userfile); // Sets arg equal to result of getWords()

    // Creates a new TreeNode with arg as value
    TreeNode *tree = new TreeNode(arg, nullptr, nullptr, 0);

    // Loops while able to get string from file
    while (arg != "") {
      tree->insert(tree, arg);  // Inserts string into the tree
      arg = getWords(userfile); // Sets arg equal to result of getWords()
    }

    ofstream myfile("result.txt"); // Creates a new file, named result.txt

    // Outputs one word and its frequency per line
    // Recursive inorderTraverse: left child, root, right child
    tree->inorderTraverse(tree, myfile);

    myfile.close();   // Closes result file
    userfile.close(); // Closes user file
  } else {
    cout << "Unable to open file"; // Displays prompt
  }

  return 0; // Returns 0
}