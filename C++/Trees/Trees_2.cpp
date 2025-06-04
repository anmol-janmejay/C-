#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// Problem 1: PreOrder and PostOrder Transversal
int main()
{
    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
    vector<int> postorder = {4, 5, 2, 6, 7, 3, 1};

    unordered_map<int, int> postIndexMap;

    // Create Mapping value -> index in postorder
    for (int i = 0; i < postorder.size(); ++i)
    {
        postIndexMap[postorder[i]] = i;
    }

    // Example: Print postorder index for each node in preorder
    for (int val : preorder)
    {
        cout << "Node: " << val << " is at Index: " << postIndexMap[val] << " in postorder" << endl;
    }

    return 0;
}
