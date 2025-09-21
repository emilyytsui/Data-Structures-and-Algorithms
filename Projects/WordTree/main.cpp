// WordTree.cpp           //Author: Emily Tsui
// Reads a user created text file, stores and orders words in a Trie
// Outputs alphabetized words to result.txt
// Displays file information in standard output

#include "WordNode.h" // Binary Search Tree class
#include <fstream>    // File operation
#include <iostream>
#include <string>    // String header
using namespace std; // Namespace to search in

int main() {
  ifstream userfile("input.txt"); // Opens the user's file

  if (userfile.is_open()) { // Checks to see if file is open

    WordNode *root = new WordNode(); // Creates a new WordNode
    int listTotal = 0;               // Variable for counting

    // Creates the Trie using the words from input.txt
    root = root->buildTree(userfile, listTotal);

    // Variable for keeping track of how many nodes
    int countNodes = root->countNodes(root);

    // Print the statistics: total letters, total nodes, %
    cout << "List total: " << listTotal << endl;
    cout << "Tree total: " << countNodes << endl;
    cout << "Savings: " << (1 - (float)(countNodes) / (float)(listTotal)) * 100
         << "%" << endl;

    ofstream myfile("result.txt"); // Creates a new file, named result.txt

    // Outputs list in result.txt in alphabetical order
    root->traverse("", root, myfile);

    // Outputs the statistics to the end of result.txt
    myfile << endl;
    myfile << "List total: " << listTotal << endl;
    myfile << "Tree total: " << countNodes << endl;
    myfile << "Savings: "
           << (1 - (float)(countNodes) / (float)(listTotal)) * 100 << "%"
           << endl;

    myfile.close();   // Closes result file
    userfile.close(); // Closes user file
  } else {
    cout << "Unable to open file"; // Displays prompt
  }

  return 0; // Returns 0
}