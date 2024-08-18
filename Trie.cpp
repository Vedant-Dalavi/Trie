#include "Trie.h"
#include <iostream>

// Constructor: Initializes the root node
Trie::Trie()
{
    root = new TrieNode();
    root->Data = '-';
}

// Destructor: Frees the allocated memory
Trie::~Trie() { deleteHelper(root, "", 0); }

// Recursive helper function for memory deallocation
void Trie::deleteHelper(TrieNode *node, const std::string &word, int depth)
{
    if (!node)
        return;

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        deleteHelper(node->children[i], word, depth + 1);
    }
    delete node;
}

// Insert a word into the Trie
void Trie::insert(std::string word)
{
    TrieNode *newRoot = root;

    for (char ch : word)
    {
        int idx = ch;
        if (newRoot->children[idx] == nullptr)
        {
            newRoot->children[idx] = new TrieNode();
            newRoot->children[idx]->Data = ch;
        }
        newRoot = newRoot->children[idx];
    }
    newRoot->isTerminal = true;
}

// Search for a word in the Trie
bool Trie::search(std::string word)
{
    TrieNode *newRoot = root;

    for (char ch : word)
    {
        int idx = ch;
        if (newRoot->children[idx] == nullptr)
        {
            return false;
        }
        newRoot = newRoot->children[idx];
    }
    return newRoot != nullptr && newRoot->isTerminal;
}

// Delete a word from the Trie (unmarks the end node)
void Trie::deleteWord(std::string word)
{
    TrieNode *newRoot = root;

    for (char ch : word)
    {
        int idx = ch;
        if (newRoot->children[idx] == nullptr)
        {
            std::cout << "Word not present in Trie" << std::endl;
            return;
        }
        newRoot = newRoot->children[idx];
    }
    if (newRoot->isTerminal)
    {
        newRoot->isTerminal = false;
    }
    else
    {
        std::cout << "Word not present in Trie" << std::endl;
    }
}

// Print the contents of the Trie starting from a given node
void Trie::print(TrieNode *node, std::string word)
{
    if (!node)
        return;

    if (node->isTerminal)
    {
        std::cout << word << std::endl;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (node->children[i] != nullptr)
        {
            print(node->children[i], word + node->children[i]->Data);
        }
    }
}

// Print all words stored in the Trie
void Trie::printTrie()
{
    std::string word;
    print(root, word);
}

TrieNode *Trie::getNodeForPrefix(std::string prefix)
{
    TrieNode *currentNode = root;
    for (char ch : prefix)
    {
        int index = ch;
        if (currentNode->children[index] == nullptr)
        {
            return nullptr; // Prefix not found
        }
        currentNode = currentNode->children[index];
    }
    return currentNode; // Return node representing the end of the prefix
}

void Trie::collectSuggestions(TrieNode *node, std::string prefix,
                              std::vector<std::string> &suggestions)
{
    if (node->isTerminal)
    {
        suggestions.push_back(prefix);
    }
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (node->children[i] != nullptr)
        {
            char ch = i;
            collectSuggestions(node->children[i], prefix + ch, suggestions);
        }
    }
}

void Trie::showSuggestionsFor(std::string prefix)
{
    TrieNode *node = getNodeForPrefix(prefix);
    if (node == nullptr)
    {
        std::cout << "No suggestions available." << std::endl;
        return;
    }

    std::vector<std::string> suggestions;
    collectSuggestions(node, prefix, suggestions);

    if (suggestions.empty())
    {
        std::cout << "No suggestions available." << std::endl;
    }
    else
    {
        std::cout << "Suggestions for \"" << prefix << "\":" << std::endl;
        for (const std::string &suggestion : suggestions)
        {
            std::cout << suggestion << std::endl;
        }
    }
}