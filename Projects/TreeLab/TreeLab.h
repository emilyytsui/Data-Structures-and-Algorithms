// Name: Emily Tsui
// Date: 5/20/2022

#include <iostream>
#include <string>
using namespace std;

class TreeNode {
private:
  char value;      // Character representing current letter
  TreeNode *left;  // Pointer to left child
  TreeNode *right; // Pointer to right child

public:
  TreeNode();
  TreeNode(char arg, TreeNode *l, TreeNode *r);
  TreeNode *buildTree(string s); // takes a string parameter and builds a BST
                                 // where each letter is a node
  TreeNode *
  insert(TreeNode *t,
         char s); // inserts a node containing the character into the tree
  string display(TreeNode *t, int level);
  string preorderTraverse(TreeNode *t);
  string inorderTraverse(TreeNode *t);
  string postorderTraverse(TreeNode *t);
  int countNodes(TreeNode *t);
  int countLeaves(TreeNode *t);
  int countGrandParents(TreeNode *t);
  int countOnlyChildren(TreeNode *t);
  int height(TreeNode *t); // returns the max of the heights to the left and the
                           // heights to the right
  int longestPath(TreeNode *t); // return the max of the sum of the heights to
                                // the left and the heights to the right
  char min(TreeNode *t);
  char max(TreeNode *t);
  string displayCurrentLevel(TreeNode *t, int level);
  string displayLevelOrder(TreeNode *t);
};

TreeNode ::TreeNode() {
  value = ' ';     // Default to empty
  left = nullptr;  // Default to null
  right = nullptr; // Default to null
}

TreeNode ::TreeNode(char arg, TreeNode *l, TreeNode *r) {
  value = arg; // Sets value to user input
  left = l;    // Sets value to user input
  right = r;   // Sets value to user input
}

TreeNode *TreeNode ::buildTree(string s) {
  TreeNode *tree = new TreeNode(s[1], nullptr, nullptr); // Pointer for storage

  // Loops for however long s is
  for (int i = 2; i < s.length(); i++) {
    tree = insert(tree, s[i]); // Sets pointer equal to insert method result
  }

  return tree; // Returns tree
}

TreeNode *TreeNode::insert(TreeNode *t, char s) {
  // Checks if node is greater than or equal to s
  if (t->value >= s) {
    // Checks if left child is empty
    if (t->left == nullptr) {
      // Sets left child to a new TreeNode with s as value
      t->left = new TreeNode(s, nullptr, nullptr);
    } else {
      t->insert(t->left, s); // Recusive call to left child
    }
  }

  // Checks if node is less than s
  else if (t->value < s) {
    // Checks if rught child is empty
    if (t->right == nullptr) {
      // Sets right child to a new TreeNode with s as value
      t->right = new TreeNode(s, nullptr, nullptr);
    } else {
      t->insert(t->right, s); // Recusive call to right child
    }
  }
  return t; // Returns t
}

string TreeNode::display(TreeNode *t, int level) {
  if (t == nullptr) { // Checks if tree is emtpy
    return "";        // Returns empty string
  }

  string tree = ""; // Variable for storage

  // Recursive call to right child and next level
  tree += display(t->right, level + 1);

  for (int i = 0; i < level; i++) { // Loops through until it reaches level
    tree += "\t";                   // Apends tab to tree
  }

  tree = tree + t->value + "\n"; // Appends value and new line to tree

  // Recursive call to left child and next level
  tree += display(t->left, level + 1);

  return tree; // Returns tree
}

string TreeNode ::preorderTraverse(TreeNode *t) {
  if (t == nullptr) { // Checks if t is null
    return "";        // Returns empty string
  } else {
    // Returns recursive call to root, left child, right child
    return string(1, t->value) + preorderTraverse(t->left) +
           preorderTraverse(t->right);
  }
}

string TreeNode ::inorderTraverse(TreeNode *t) {
  if (t == nullptr) { // Checks if t is null
    return "";        // Returns empty string
  } else {
    // Returns recursive call to left child, root, right child
    return inorderTraverse(t->left) + string(1, t->value) +
           inorderTraverse(t->right);
  }
}

string TreeNode ::postorderTraverse(TreeNode *t) {
  if (t == nullptr) { // Checks if t is null
    return "";        // Returns empty string
  } else {
    // Returns recursive call to left child, right child, root
    return postorderTraverse(t->left) + postorderTraverse(t->right) +
           string(1, t->value);
  }
}

int TreeNode ::countNodes(TreeNode *t) {
  if (t == nullptr) { // Checks if t is null
    return 0;         // Returns 0
  } else {
    // Returns sum of nodes for left and right child plus 1
    return countNodes(t->left) + countNodes(t->right) + 1;
  }
}

int TreeNode ::countLeaves(TreeNode *t) {
  if (t == nullptr) { // Checks if t is empty
    return 0;         // Returns 0
  }

  // Checks if both left child and right are empty
  else if (t->left == nullptr && t->right == nullptr) {
    return 1; // Returns 1
  }

  else {
    // Returns countLeaves for sum of left child and right child
    return countLeaves(t->left) + countLeaves(t->right);
  }
}

int TreeNode ::countGrandParents(TreeNode *t) {
  // Checks if height is greater than or equal to 2
  if (t->height(t) >= 3) {
    // Returns recursive call to left child and right child, adds 1
    return countGrandParents(t->left) + countGrandParents(t->right) + 1;
  }
  return 0; // Returns 0
}

int TreeNode ::countOnlyChildren(TreeNode *t) {
  int count = 0; // Variable for counting

  if (t == nullptr) { // Checks if t is empty
    return 0;         // Returns 0
  }

  // Checks if left child is empty and if right child isn't
  else if (t->left == nullptr && t->right != nullptr) {
    count++; // Increments count by 1
  }

  // Checks if right child is empty and if left child isn't
  else if (t->left != nullptr && t->right == nullptr) {
    count++; // Increments count by 1
  }

  // Returns recursive call to left and right child, and count
  return countOnlyChildren(t->left) + countOnlyChildren(t->right) + count;
}

int TreeNode ::height(TreeNode *t) {
  int leftCount = 0;  // Counter variable for left child
  int rightCount = 0; // Counter variable for right child

  if (t == nullptr) { // Checks if t is empty
    return 0;         // Returns 0
  }

  // Sets int equal to recursive call for left child
  leftCount = height(t->left);
  // Sets int equal to recursive call for right child
  rightCount = height(t->right);

  if (rightCount < leftCount) { // Checks if there are less right nodes
    return leftCount + 1;       // Returns leftCount plus 1
  }

  return rightCount + 1; // Returns leftCount plus 1
}

int TreeNode ::longestPath(TreeNode *t) {
  if (t == nullptr ||
      t->countNodes(t) == 1) {        // Checks if t is or only has a root
    return 0;                         // Returns 0
  } else if (t->countNodes(t) == 2) { // Checks if 2 only has 2 nodes
    return 1;                         // Retuns 1
  }
  int leftHeight = t->height(t->left);   // Variable for storing left height
  int rightHeight = t->height(t->right); // Variable for storing right height
  // Returns max of the sum of height for left and right child
  return ::max(leftHeight + rightHeight,
               ::max(longestPath(t->left), longestPath(t->right)));
}

char TreeNode ::min(TreeNode *t) {
  // Checks if t is empty or if left child is empty
  if (t == nullptr || t->left == nullptr) {
    return t->value; // Returns value
  } else {
    return min(t->left); // Recursive call for left child
  }
}

char TreeNode ::max(TreeNode *t) {
  // Checks if t is empty or if right child is empty
  if (t == nullptr || t->right == nullptr) {
    return t->value; // Returns value
  } else {
    return max(t->right); // Recursive call for right child
  }
}

string TreeNode ::displayCurrentLevel(TreeNode *t, int level) {
  if (t == nullptr) {           // Checks if t is empty
    return "";                  // Returns an empty string
  } else if (level == 0) {      // Checks if trying to display root
    return string(1, t->value); // Returns string of value
  } else {
    // Returns recursive call to left child and right child
    return displayCurrentLevel(t->left, level - 1) +
           displayCurrentLevel(t->right, level - 1);
  }
}

string TreeNode ::displayLevelOrder(TreeNode *t) {
  string ch = "";                          // Variable for storage
  for (int i = 0; i < t->height(t); i++) { // Loops for however high t is
    ch += displayCurrentLevel(t, i);       // Appends recursive call result
  }
  return ch; // Returns ch
}