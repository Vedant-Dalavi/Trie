// Trie.h

#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <vector>

const int ALPHABET_SIZE = 256; // Assuming lowercase English letters

struct TrieNode
{
    char Data;
    TrieNode *children[ALPHABET_SIZE];
    bool isTerminal;
};

class Trie
{
private:
    TrieNode *root;

    void print(TrieNode *node, std::string word);
    void deleteHelper(TrieNode *node, const std::string &word, int depth);

    TrieNode *getNodeForPrefix(std::string prefix);
    void collectSuggestions(TrieNode *node, std::string prefix,
                            std::vector<std::string> &suggestions);

public:
    Trie();
    ~Trie();

    void insert(std::string word);
    bool search(std::string word);
    void deleteWord(std::string word);
    void showSuggestionsFor(std::string prefix);
    void printTrie();
};

#endif
