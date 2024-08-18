#include "Trie.h"
#include <iostream>

using namespace std;

int main()
{
    Trie t;

    t.insert("vedant");
    t.insert("dalavi");
    t.insert("234fasdfa");
    t.insert("#$%dalavi");
    t.insert(".fasd");

    t.insert("Dalavi");
    cout << "Printing Tree:" << endl;
    t.printTrie();
    cout << endl;

    // 1: found, 0: not found
    bool found = t.search("vedant");
    if (found) {
    cout << "Word found!" << std::endl;
    } else {
    cout << "Word not found!" << std::endl;
    }

    t.showSuggestionsFor("#");

    t.deleteWord("vedant");

    cout << "Search for 'vedant' after deletion: " << t.search("vedant") << endl;

    return 0;
}
