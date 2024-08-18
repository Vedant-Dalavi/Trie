# Trie Data Structure Library in C++

## Overview

This project provides a basic implementation of a Trie data structure in C++. A Trie is a tree-like data structure used for efficient retrieval of strings. This library supports operations such as inserting, searching, deleting words, and showing suggestions based on a prefix.

## Files

- **Trie.h**: Contains declarations for the Trie class and its methods.
- **Trie.cpp**: Contains the definitions for the Trie class methods.
- **main.cpp**: Contains example usage of the Trie class.
- **README.md**: This documentation file.

## Trie Class Methods

### 1. `Trie()`

**Description**: Constructor that initializes the Trie. It sets up the root node of the Trie and initializes its children pointers to `NULL`.

**How to Use**:
To create an instance of the `Trie` class, simply call the constructor:
```
Trie t;
```

### 2. void insert(std::string word)
Description: Inserts the specified word into the Trie. It traverses the Trie according to the characters of the word, creating new nodes as needed. Marks the end of the word as a terminal node.

**How to Use:
To insert a word into the Trie, use the insert method:
```
t.insert("example");
```
This adds the word "example" to the Trie. You can call insert multiple times to add multiple words.

### 3. bool search(std::string word)
Description: Checks if the specified word exists in the Trie. Returns true if the word is found and is marked as a terminal node; otherwise, returns false.

**How to Use:
To search for a word in the Trie, use the search method:
```
bool found = t.search("example");
if (found) {
    std::cout << "Word found!" << std::endl;
} else {
    std::cout << "Word not found!" << std::endl;
}
```
This checks if the word "example" is present in the Trie.

### 4. void showSuggestionsFor(std::string prefix)
Description: Displays all words in the Trie that start with the given prefix. If no words match the prefix, it prints "No suggestions available."

**How to Use:
To get suggestions based on a prefix, use the showSuggestionsFor method:
```
t.showSuggestionsFor("ex");
```
This will display all words in the Trie that begin with the prefix "ex".


###5. void deleteWord(std::string word)
Description: Removes the specified word from the Trie. It traverses the Trie to find the word and marks its terminal node as false. If the word does not exist, it prints a message indicating that the word is not present.

**How to Use:
To delete a word from the Trie, use the deleteWord method:
```
t.deleteWord("example");
```
This removes the word "example" from the Trie if it exists.

### 6. void printTrie()
Description: Prints all words stored in the Trie. It uses the print method to recursively traverse and print each word.

**How to Use:
To print all words in the Trie, use the printTrie method:
```
t.printTrie();
```
This prints all words that have been inserted into the Trie.

************************************************************************************************************************
************************************************************************************************************************

Example Usage
Here’s an example of how to use the Trie library:
```
#include "Trie.h"
#include <iostream>

int main() {
    Trie t;

    // Insert words
    t.insert("apple");
    t.insert("app");
    t.insert("applet");

    // Search for words
    std::cout << "Search results:\n";
    std::cout << "apple: " << t.search("apple") << std::endl; // true
    std::cout << "app: " << t.search("app") << std::endl;     // true
    std::cout << "appl: " << t.search("appl") << std::endl;   // false

    // Show suggestions for a prefix
    std::cout << "Suggestions for 'app':\n";
    t.showSuggestionsFor("app"); // Shows: apple, app, applet

    // Print all words in the Trie
    std::cout << "All words in the Trie:\n";
    t.printTrie(); // Shows all words

    // Delete a word
    t.deleteWord("app");
    std::cout << "After deleting 'app':\n";
    t.printTrie(); // Shows remaining words

    return 0;
}
```

### Building and Using the Library
Building the Library
    - 1. Compile the Code:
         To compile the project, use the following command:
     ```
     g++ src/main.cpp src/Trie.cpp -o trie
     ```
    - 2. Run the Program:
     Execute the compiled program with:
```
./trie
```

### Using the Library in Your Project
- 1. Include the Header File:
In your C++ code, include the Trie.h file:
```
#include "Trie.h"
```

- 2. Compile with Source Files:
Ensure that the Trie.cpp file is compiled and linked with your project:

```
g++ your_code.cpp Trie.cpp
```

Use the Trie Methods:
Create an instance of the Trie class and use its methods as shown in the examples above.




