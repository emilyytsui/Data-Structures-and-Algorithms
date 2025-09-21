// Binary Search Tree

#include <fstream> // File operation
#include <iostream>
#include <math.h>
#include <string>
using namespace std;

class TreeNode {
private:
  string value;    // Character representing current word
  TreeNode *left;  // Pointer to left child
  TreeNode *right; // Pointer to right child
  int frequency;   // Variable for counting

public:
  TreeNode();
  TreeNode(string arg, TreeNode *l, TreeNode *r, int x);
  TreeNode *insert(TreeNode *t, string s);
  void inorderTraverse(TreeNode *t, ofstream &file);
};

TreeNode ::TreeNode() {
  value = ' ';     // Default to empty
  left = nullptr;  // Default to null
  right = nullptr; // Default to null
  frequency = 0;   // Default to 0
}

TreeNode ::TreeNode(string arg, TreeNode *l, TreeNode *r, int x) {
  value = arg;   // Sets value to user input
  left = l;      // Sets value to user input
  right = r;     // Sets value to user input
  frequency = x; // Sets value to user input
}

TreeNode *TreeNode::insert(TreeNode *t, string s) {
  if (t == nullptr) { // Checks if node is empty
    // Sets value equal to user string and sets frequency to 1
    t = new TreeNode(s, nullptr, nullptr, 1);
  } else if (t->value > s) {           // Checks if node is greater than s
    t->left = t->insert(t->left, s);   // Recusive call to left child
  } else if (t->value == s) {          // Checks if node is the same word as s
    t->frequency++;                    // Increments frequency by 1
  } else if (t->value < s) {           // Checks if node is less than s
    t->right = t->insert(t->right, s); // Recusive call to right child
  }
  return t; // Returns t
}

void TreeNode ::inorderTraverse(TreeNode *t, ofstream &file) {
  if (t == nullptr) { // Checks if t is null
    return;           // Returns empty/null
  } else {
    // Recursive call to left child, root, right child
    inorderTraverse(t->left, file);
    // Outputs word, its frequency and a line to file
    file << t->value << ": " << t->frequency << endl;
    inorderTraverse(t->right, file);
  }
}