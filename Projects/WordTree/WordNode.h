// Stores a char value and an array of WordNodes

#include <fstream> // File operation
#include <iostream>
#include <string>
using namespace std;

class WordNode {
private:
  WordNode *children[26];
  bool endOfWord; // To check if end of word has been reached

public:
  WordNode();
  WordNode *buildTree(ifstream &file, int &count);
  void insert(WordNode *w, string s);
  void traverse(string prefix, WordNode *w, ofstream &file);
  int countNodes(WordNode *w);
};

WordNode ::WordNode() {
  for (int i = 0; i < 26; i++) { // Loops through the entire array
    children[i] = nullptr;       // Sets to default value
  }
  endOfWord = false; // Sets to default value
}

WordNode *WordNode ::buildTree(ifstream &file, int &count) {
  WordNode *trie = new WordNode(); // New WordNode for storage
  string word = "";                // Variable for storage

  while (!file.eof()) {     // Loops while able to retrieve strings
    file >> word;           // Reads the word from file
    count += word.length(); // Counts the total number of letters
    insert(trie, word);     // Inserts string into the tree
  }
  return trie; // Returns trie
}

void WordNode ::insert(WordNode *w, string s) {
  for (int i = 0; i < s.length(); i++) { // Loops for each letter in the word
    // Checks if a letter isn't there for position in children array
    if (w->children[s[i] - 'a'] == nullptr) {
      w->children[s[i] - 'a'] = new WordNode(); // Adds a node
    }
    w = w->children[s[i] - 'a']; // Gets the next level of the trie
  }
  w->endOfWord = true; // Adds the node for end-of-word marker
}

void WordNode ::traverse(string prefix, WordNode *w, ofstream &file) {
  if (w->endOfWord) {       // Checks to see if the end of word has been
    file << prefix << endl; // Outputs string to file
  }

  for (int i = 0; i < 26; i++) { // Loops through the entire array of children
    // Checks to see if child at position i exists
    if (w->children[i] != nullptr) {
      // Adds the character value of child at position to prefix
      string word = prefix + (char)(i + 'a');
      // Recursive call to the children at position
      traverse(word, w->children[i], file);
    }
  }
}

int WordNode ::countNodes(WordNode *w) {
  int count = 1; // Variable for counting, includes root

  if (w == nullptr) { // Checks if node is empty
    return 0;         // Returns 0
  }

  for (int i = 0; i < 26; i++) { // Loops through all the children
    // Recursive call to children, adds it to count
    count += countNodes(w->children[i]);
  }

  return count; // Returns count
}