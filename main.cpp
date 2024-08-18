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
    cout << "Search for 'dalavi': " << t.search("dalavi") << endl;

    cout << "Search for 'vedant': " << t.search("vedant") << endl;

    cout << "Search for 'ved': " << t.search("ved") << endl;
    // returns false
    t.showSuggestionsFor("#");

    t.deleteWord("vedant");

    cout << "Search for 'vedant' after deletion: " << t.search("vedant") << endl;

    return 0;
}
