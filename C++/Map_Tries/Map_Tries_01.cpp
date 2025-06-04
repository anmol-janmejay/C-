#include <iostream>
#include <unordered_map>
using namespace std;

// int main()
// {
//     // creation
//     unordered_map<string, int> m;

//     // insertion
//     pair<string, int> p = make_pair("Scorpio", 9);
//     m.insert(p);

//     pair<string, int> p2("alto", 2);
//     m.insert(p2);

//     m["Fortuner"] = 10;

//     // access
//     cout << m.at("alto") << endl;
//     // cout << m.at("Scorpio") << endl;

//     cout << m["Fortuner"] << endl;

//     // search
//     cout << m.count("Fortuner") << endl;

//     if (m.find("Fortuner") != m.end())
//     {
//         cout << "Fortuner Found " << endl;
//     }
//     else
//     {
//         cout << "Fortuner not Found " << endl;
//     }

//     cout << m.size() << endl;
//     cout << m["hummer"] << endl;
//     cout << m.size() << endl;

//     return 0;
// }

struct Node
{
    int data;
    Node *next;
};

bool checkCircular(Node *head)
{
    unordered_map<Node *, bool> vis;
    Node *temp = head;

    while (temp != NULL)
    {
        if (vis.find(temp) != vis.end())
        {
            return true; // Found a visited node, so it's circular
        }
        vis[temp] = true; // Mark current node as visited
        temp = temp->next;
    }
    return false; // Reached end of list without finding a cycle
}

// // Alternative better approach (Floyd's Cycle-Finding Algorithm):
// bool checkCircularBetter(Node *head)
// {
//     if (head == NULL)
//         return false;

//     Node *slow = head;
//     Node *fast = head;

//     while (fast != NULL && fast->next != NULL)
//     {
//         slow = slow->next;
//         fast = fast->next->next;

//         if (slow == fast)
//         {
//             return true; // Cycle detected
//         }
//     }
//     return false; // No cycle found
// }

int main()
{
    // Example usage:
    Node *head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};
    head->next->next->next = head; // Make it circular

    if (checkCircular(head))
    {
        cout << "Linked list is circular" << endl;
    }
    else
    {
        cout << "Linked list is not circular" << endl;
    }

    // The character frequency code (unrelated to linked list check)
    string str = "Thiruvanthampuram";
    unordered_map<char, int> freq;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        freq[ch]++;
    }
    for (auto i : freq)
    {
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}