#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class NodeData
{
public:
    int size;
    int minVal;
    int maxVal;
    bool validBST;

    NodeData(int size, int max, int min, bool valid)
    {
        this->size = size;
        minVal = min;
        maxVal = max;
        validBST = valid;
    }
};

int minVal(Node *root)
{
    Node *temp = root;
    if (temp == NULL)
    {
        return -1;
    }

    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}

int maxVal(Node *root)
{
    Node *temp = root;
    if (temp == NULL)
    {
        return -1;
    }

    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->data;
}
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    // initially
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        // A
        Node *temp = q.front();
        // B
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            // C
            cout << temp->data << " ";
            // D
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

// Helper function to insert into BST (corrected)
Node *insertIntoBST(Node *root, int data)
{
    if (root == NULL)
    {
        return new Node(data);
    }
    if (data < root->data)
    {
        root->left = insertIntoBST(root->left, data);
    }
    else
    {
        root->right = insertIntoBST(root->right, data);
    }
    return root;
}

// Corrected DLL conversion (ascending order)
void convertIntoSortedDLL(Node *root, Node *&head, Node *&prev)
{
    if (root == NULL)
        return;

    // 1. Left subtree
    convertIntoSortedDLL(root->left, head, prev);

    // 2. Current node
    if (prev == NULL)
    {
        head = root; // First node in inorder traversal
    }
    else
    {
        prev->right = root;
        root->left = prev;
    }
    prev = root;

    // 3. Right subtree
    convertIntoSortedDLL(root->right, head, prev);
}

void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->right;
    }
    cout << endl;
}

Node *sortedLinkedListIntoBST(Node *&head, int n)
{
    // base case
    if (n <= 0 || head == NULL)
        return NULL;

    Node *leftSubTree = sortedLinkedListIntoBST(head, n - 1 - n / 2);

    Node *root = head;
    root->left = leftSubTree;

    head = head->right;

    // right part solve krna hai
    root->right = sortedLinkedListIntoBST(head, n / 2);
    return root;
}

NodeData *findLargestBST(Node *root, int &ans)
{
    if (root == NULL)
    {
        return new NodeData(0, INT_MIN, INT_MAX, true);
    }

    NodeData *leftAns = findLargestBST(root->left, ans);
    NodeData *rightAns = findLargestBST(root->right, ans);

    // Create current node's data
    NodeData *currNode = new NodeData(
        leftAns->size + rightAns->size + 1,
        max(root->data, rightAns->maxVal),
        min(root->data, leftAns->minVal),
        true);

    // Check BST validity
    if (!(leftAns->validBST && rightAns->validBST &&
          root->data > leftAns->maxVal &&
          root->data < rightAns->minVal))
    {
        currNode->validBST = false;
    }

    if (currNode->validBST)
    {
        ans = max(ans, currNode->size);
    }

    return currNode;
}

int main()
{
    // Corrected: Use a sorted array for BST construction
    // int inOrder[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // int n = sizeof(inOrder) / sizeof(inOrder[0]);

    // // Build BST from sorted array
    // Node *root = NULL;
    // for (int i = 0; i < n; i++)
    // {
    //     root = insertIntoBST(root, inOrder[i]);
    // }

    // cout << "BST Level Order Traversal:" << endl;
    // // (You can add your levelOrderTraversal function here)

    // cout << "Converting BST to Sorted DLL:" << endl;
    // Node *head = NULL;
    // Node *prev = NULL; // Track previous node
    // convertIntoSortedDLL(root, head, prev);

    // cout << "Sorted DLL: ";
    // printLinkedList(head);

    // Node *root1 = NULL;
    // root1 = sortedLinkedListIntoBST(head, 9);
    // cout << "Doping Level order Traversal for Root 1" << endl;
    // levelOrderTraversal(root1);

    Node *root = new Node(50);
    Node *first = new Node(30);
    Node *second = new Node(60);
    Node *third = new Node(5);
    Node *fourth = new Node(20);
    Node *fifth = new Node(45);
    Node *sixth = new Node(70);
    Node *seventh = new Node(65);
    Node *eight = new Node(80);

    root->left = first;
    root->right = second;
    first->left = third;
    first->right = fourth;
    second->left = fifth;
    second->right = sixth;
    sixth->left = seventh;
    sixth->right = eight;

    cout << "Printing the Tree: " << endl;
    levelOrderTraversal(root);

    int ans = 0;
    findLargestBST(root, ans);
    cout << "Largest BST ka Size: " << ans << endl;

    return 0;
}