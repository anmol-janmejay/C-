#include <iostream>
#include <vector>
using namespace std;

class TrieNode
{
public:
    char data;              // Stores the character at this node
    TrieNode *children[26]; // Pointers to child nodes (a-z)
    bool isTerminal;        // Marks the end of a word

    TrieNode(char d)
    { // Constructor
        this->data = d;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL; // Initialize all children to NULL
        }
        this->isTerminal = false; // Not a word end by default
    }
};

void insertWord(TrieNode *root, string word)
{
    if (word.length() == 0)
    { // Base case: end of word
        root->isTerminal = true;
        return;
    }

    char ch = word[0];    // First character of the word
    int index = ch - 'a'; // Convert char to index (0-25)
    TrieNode *child;

    if (root->children[index] != NULL)
    { // Child exists
        child = root->children[index];
    }
    else
    { // Child does not exist → create new node
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    insertWord(child, word.substr(1)); // Recursively insert remaining characters
}

bool searchWord(TrieNode *root, string word)
{
    if (word.length() == 0)
    {                            // Base case: end of word
        return root->isTerminal; // Return true only if it's a word end
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child;

    if (root->children[index] != NULL)
    { // Child exists
        child = root->children[index];
    }
    else
    {
        return false; // Word not found
    }

    return searchWord(child, word.substr(1)); // Recursively search next characters
}

void storeSuggestions(TrieNode *curr, vector<string> &temp, string &prefix)
{
    if (curr->isTerminal)
    {                           // If current node is a word end
        temp.push_back(prefix); // Add to suggestions
    }

    for (char ch = 'a'; ch <= 'z'; ch++)
    { // Check all possible children
        int index = ch - 'a';
        TrieNode *next = curr->children[index];

        if (next != NULL)
        {                                         // If child exists
            prefix.push_back(ch);                 // Extend prefix
            storeSuggestions(next, temp, prefix); // Recursively collect words
            prefix.pop_back();                    // Backtrack
        }
    }
}

vector<vector<string>> getSuggestions(TrieNode *root, string input)
{
    TrieNode *prev = root;
    vector<vector<string>> output;
    string prefix = "";

    for (int i = 0; i < input.length(); i++)
    {
        char lastch = input[i];
        int index = lastch - 'a';
        TrieNode *curr = prev->children[index];

        if (curr == NULL)
            break; // No further suggestions
        else
        {
            vector<string> temp;
            prefix.push_back(lastch);
            storeSuggestions(curr, temp, prefix); // Get all words from current node
            output.push_back(temp);               // Add suggestions for current prefix
            prev = curr;                          // Move to next character
        }
    }
    return output;
}
int main()
{
    vector<string> v;
    v.push_back("love");
    v.push_back("lover");
    v.push_back("loving");
    v.push_back("last");
    v.push_back("lost");
    v.push_back("lane");
    v.push_back("lord");

    string input = "lovi";

    TrieNode *root = new TrieNode('-');
    for (int i = 0; i < v.size(); i++)
    {
        insertWord(root, v[i]);
    }

    vector<vector<string>> ans = getSuggestions(root, input);

    cout << "Printing the answer: " << endl;

    for (int i = 0; i < ans.size(); i++)
    {

        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << ", ";
        }
        cout << endl;
    }

    // TrieNode* root = new TrieNode('-');

    // //root->insertWord("coding");
    // insertWord(root, "coding");
    // insertWord(root, "code");
    // insertWord(root, "coder");
    // insertWord(root, "codehelp");
    // insertWord(root, "baba");
    // insertWord(root, "baby");
    // insertWord(root, "babu");
    // insertWord(root, "shona");
    // cout << "Searching " << endl;
    // if(searchWord(root,"cod")) {
    //         cout << "present" << endl;
    // }
    // else {
    //         cout << "absent" << endl;
    // }

    return 0;
}