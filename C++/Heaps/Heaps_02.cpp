#include <iostream>
#include <queue>
#include <climits>
using namespace std;

// int main()
// {
//     // Max Heap
//     priority_queue<int> pq;

//     pq.push(3);
//     pq.push(6);
//     pq.push(9);
//     pq.push(4);
//     pq.push(8);

//     cout << "Top Element: " << pq.top() << endl;
//     pq.pop();

//     cout << "Top Element: " << pq.top() << endl;
//     pq.pop();

//     cout << "Top Element: " << pq.top() << endl;
//     pq.pop();

//     cout << "Top Element: " << pq.top() << endl;
//     pq.pop();

//     cout << "Top Element: " << pq.top() << endl;
//     pq.pop();

//     cout << "Size: " << pq.size() << endl;
//     if (pq.empty())
//     {
//         cout << "Max Heap is Empty " << endl;
//     }

//     else
//     {
//         cout << "Max Heap is not Empty " << endl;
//     }

//     return 0;
// }

// int main()
// {
//     // max heap
//     priority_queue<int, vector<int>, greater<int>> pq;
//     pq.push(3);
//     pq.push(6);
//     pq.push(9);
//     pq.push(4);
//     pq.push(8);

//     cout << "Top Element: " << pq.top() << endl;
//     pq.pop();
//     cout << "Size: " << pq.size() << endl;
//     cout << "Top Element: " << pq.top() << endl;
//     pq.pop();
//     cout << "Top Element: " << pq.top() << endl;
//     pq.pop();
//     cout << "Top Element: " << pq.top() << endl;
//     pq.pop();
//     cout << "Top Element: " << pq.top() << endl;
//     pq.pop();

//     if (pq.empty())
//     {
//         cout << "Min Heap is Empty" << endl;
//     }
//     else
//     {
//         cout << "Min Heap is not Empty" << endl;
//     }

//     return 0;
// }

//     int getKthSmallestElement(int arr[], int n, int k)
//     {
//         priority_queue<int> pq; // Max-heap for smallest k elements

//         for (int i = 0; i < n; i++)
//         {
//             pq.push(arr[i]);
//             if (pq.size() > k)
//             {
//                 pq.pop(); // Remove the largest element
//             }
//         }
//         return pq.top(); // k-th smallest
//     }

// int getKthLargestElement(int arr[], int n, int k)
// {
//     priority_queue<int, vector<int>, greater<int>> pq; // Min-heap for largest k elements

//     for (int i = 0; i < n; i++)
//     {
//         pq.push(arr[i]);
//         if (pq.size() > k)
//         {
//             pq.pop(); // Remove the smallest element
//         }
//     }
//     return pq.top(); // k-th largest
// }

// int main()
// {
//     int arr[] = {10, 5, 20, 4, 15};
//     int n = 5;
//     int k = 5;

//     int smallest = getKthSmallestElement(arr, n, k);
//     cout << "K-th smallest element is: " << smallest << endl;

//     int largest = getKthLargestElement(arr, n, k);
//     cout << "K-th largest element is: " << largest << endl;

//     return 0;
// }
struct Node
{
    int data;
    Node *left;
    Node *right;
};

pair<bool, int> solve(Node *root)
{
    // Base case: empty tree is a max-heap with INT_MIN
    if (root == NULL)
    {
        return make_pair(true, INT_MIN);
    }
    // Leaf node: trivially a max-heap with its own value
    if (root->left == NULL && root->right == NULL)
    {
        return make_pair(true, root->data);
    }

    pair<bool, int> leftAns = solve(root->left);
    pair<bool, int> rightAns = solve(root->right);

    // Check if current subtree is a max-heap:
    // 1. Both left and right subtrees must be max-heaps.
    // 2. Current node's value must be >= left and right subtree's max values.
    if (leftAns.first && rightAns.first &&
        root->data >= leftAns.second &&
        root->data >= rightAns.second)
    {
        return make_pair(true, root->data);
    }
    else
    {
        // If not a max-heap, return false and the max value in the subtree
        int maxVal = max(root->data, max(leftAns.second, rightAns.second));
        return make_pair(false, maxVal);
    }
}

int main()
{
    // Example usage (construct a tree and call solve())
    Node *root = new Node{10, new Node{9, NULL, NULL}, new Node{8, NULL, NULL}};
    pair<bool, int> result = solve(root);
    cout << "Is Max-Heap? " << (result.first ? "Yes" : "No") << endl;
    cout << "Max value in tree: " << result.second << endl;
    return 0;
}