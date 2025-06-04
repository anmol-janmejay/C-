#include <iostream>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26]; // array of 26 pointers
    bool isTerminal;

    TrieNode(char d)
    {
        this->data = d;
        this->isTerminal = false;
        for (int i = 0; i < 26; ++i)
        {
            children[i] = nullptr; // initialize all children to nullptr
        }
    }
};

void insertWord(TrieNode *root, string word)
{
    // Base Case
    if (word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'a'; // ✅ FIXED here

    TrieNode *child;
    // present
    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        // not present
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    // recursion
    insertWord(child, word.substr(1));
}

bool searchWord(TrieNode *root, string word)
{
    if (word.length() == 0)
    {
        return root->isTerminal;
    }

    char ch = word[0];
    int index = ch - 'a'; // ✅ FIXED here

    TrieNode *child;

    // present
    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        return false;
    }
    // recursive call
    return searchWord(child, word.substr(1));
}

int main()
{
    TrieNode *root = new TrieNode('-'); // root node with dummy character

    insertWord(root, "coding");
    insertWord(root, "coder");
    insertWord(root, "codehelp");
    insertWord(root, "baba");
    insertWord(root, "baby");
    insertWord(root, "babu");
    insertWord(root, "shona");

    if (searchWord(root, "coding")) // ✅ FIXED quotes
    {
        cout << "Present" << endl;
    }
    else
    {
        cout << "Absent" << endl; // ✅ FIXED missing semicolon
    }

    return 0;
}
