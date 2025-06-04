#include <iostream>
#include <vector>
using namespace std;

// BASIC TREE
// Tree Node Structure
// struct TreeNode
// {
//     int data;
//     vector<TreeNode *> children; // Vector to store children nodes

//     TreeNode(int val)
//     {
//         data = val;
//     }
// };

// // Function to print Tree (DFS)
// void printTree(TreeNode *root, int level = 0)
// {
//     if (root == nullptr)
//         return;

//     // Indentation to show hierarchy
//     for (int i = 0; i < level; i++)
//         cout << "  ";

//     cout << root->data << endl;

//     for (TreeNode *child : root->children)
//     {
//         printTree(child, level + 1);
//     }
// }

// int main()
// {
//     // Creating a tree
//     TreeNode *root = new TreeNode(1);
//     root->children.push_back(new TreeNode(2));
//     root->children.push_back(new TreeNode(3));
//     root->children.push_back(new TreeNode(4));

//     root->children[0]->children.push_back(new TreeNode(5));
//     root->children[0]->children.push_back(new TreeNode(6));

//     root->children[2]->children.push_back(new TreeNode(7));

//     // Print the Tree
//     cout << "Tree Structure:\n";
//     printTree(root);

//     return 0;
// }

//   BINARY TREE
// Binary Tree Node Structure
// struct TreeNode
// {
//     int data;
//     TreeNode *left;
//     TreeNode *right;

//     TreeNode(int val)
//     {
//         data = val;
//         left = right = nullptr;
//     }
// };

// // Preorder Traversal (Root -> Left -> Right)
// void preorder(TreeNode *root)
// {
//     if (root == nullptr)
//         return;
//     cout << root->data << " ";
//     preorder(root->left);
//     preorder(root->right);
// }

// int main()
// {
//     // Creating a Binary Tree
//     TreeNode *root = new TreeNode(1);
//     root->left = new TreeNode(2);
//     root->right = new TreeNode(3);
//     root->left->left = new TreeNode(4);
//     root->left->right = new TreeNode(5);

//     // Traversing the tree
//     cout << "Preorder Traversal: ";
//     preorder(root);

//     return 0;
// }

//   BINARY SEARCH TREE
// #include <iostream>

// using namespace std;

// // Binary Search Tree Node
// struct TreeNode
// {
//     int data;
//     TreeNode *left;
//     TreeNode *right;

//     TreeNode(int val)
//     {
//         data = val;
//         left = right = nullptr;
//     }
// };

// // Insert into BST
// TreeNode *insert(TreeNode *root, int val)
// {
//     if (root == nullptr)
//         return new TreeNode(val);

//     if (val < root->data)
//         root->left = insert(root->left, val);
//     else
//         root->right = insert(root->right, val);

//     return root;
// }

// // Search in BST
// bool search(TreeNode *root, int val)
// {
//     if (root == nullptr)
//         return false;

//     if (root->data == val)
//         return true;
//     else if (val < root->data)
//         return search(root->left, val);
//     else
//         return search(root->right, val);
// }

// // Inorder Traversal (Left -> Root -> Right)
// void inorder(TreeNode *root)
// {
//     if (root == nullptr)
//         return;
//     inorder(root->left);
//     cout << root->data << " ";
//     inorder(root->right);
// }

// int main()
// {
//     TreeNode *root = nullptr;
//     root = insert(root, 5);
//     insert(root, 3);
//     insert(root, 7);
//     insert(root, 2);
//     insert(root, 4);
//     insert(root, 6);
//     insert(root, 8);

//     // Display Inorder (Sorted Order)
//     cout << "Inorder Traversal: ";
//     inorder(root);
//     cout << endl;

//     // Searching
//     int key = 4;
//     if (search(root, key))
//         cout << key << " found in BST.\n";
//     else
//         cout << key << " not found in BST.\n";

//     return 0;
// }

// Course Explanation
// class Node
// {
// public:
//     int data;
//     Node *left;
//     Node *right;

//     Node(int data)
//     {
//         this->data = data;
//         left = NULL;
//         right = NULL;
//     }
// };

// Node *buildTree()
// {
//     int data;
//     cout << "Enter the Data: " << endl;
//     cin >> data;

//     if (data == -1)
//     {
//         return NULL;
//     }

//     // Step A, B, C
//     Node *root = new Node(data);

//     cout << "Enter data for Left part of" << data << "Node" << endl;
//     root->left = buildTree();

//     cout << "Enter data for Right part of" << data << "Node" << endl;
//     root->right = buildTree();

//     return root;
// }

// int main()
// {
//     Node *root = NULL;

//     root = buildTree();

//     return 0;
// }

// class Node
// {
// public:
//     int data;
//     Node *left;
//     Node *right;

//     Node(int data)
//     {
//         this->data = data;
//         left = NULL;
//         right = NULL;
//     }
// };

// Node *buildTree()
// {
//     int data;
//     cout << "Enter the Data: " << endl;
//     cin >> data;

//     if (data == -1)
//     {
//         return NULL;
//     }

//     // Step A, B, C
//     Node *root = new Node(data);

//     cout << "Enter data for Left part of" << data << "Node" << endl;
//     root->left = buildTree();

//     cout << "Enter data for Right part of" << data << "Node" << endl;
//     root->right = buildTree();

//     return root;
// }

// In-Order/Pre-Order/Post-Order
// class Node
// {
// public:
//     int data;
//     Node *left;
//     Node *right;

//     Node(int data)
//     {
//         this->data = data;
//         left = NULL;
//         right = NULL;
//     }
// };

// Node *buildTree()
// {
//     int data;
//     cout << "Enter the Data: " << endl;
//     cin >> data;

//     if (data == -1)
//     {
//         return NULL;
//     }

//     // Step A, B, C
//     Node *root = new Node(data);

//     cout << "Enter data for Left part of" << data << "Node" << endl;
//     root->left = buildTree();

//     cout << "Enter data for Right part of" << data << "Node" << endl;
//     root->right = buildTree();

//     return root;
// }

// void inOrderTransversal(Node *root)
// {
//     // Base case
//     if (root == NULL)
//     {
//         return;
//     }

//     // LNR
//     inOrderTransversal(root->left);
//     cout << root->data << " ";
//     inOrderTransversal(root->right);
// }

// void preOderTransversal(Node *root)
// {
//     // Base case
//     if (root == NULL)
//     {
//         return;
//     }

//     // NLR
//     cout << root->data << " ";
//     preOderTransversal(root->left);
//     preOderTransversal(root->right);
// }

// void postOrderTransversal(Node *root)
// {
//     if (root == NULL)
//         return;

//     // LRN
//     postOrderTransversal(root->left);
//     postOrderTransversal(root->right);
//     cout << root->data << " ";
// }

// int main()
// {
//     Node *root = NULL;
//     root = buildTree();

//     inOrderTransversal(root);
//     // preOderTransversal(root);
//     // postOrderTransversal(root);

//     return 0;
// }

// Definition of the Node class
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor to initialize a node with given data
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Function to build the binary tree recursively
Node *buildTree()
{
    int data;
    cout << "Enter the Data: ";
    cin >> data;

    // If user inputs -1, it means no node should be created (base case)
    if (data == -1)
    {
        return NULL;
    }

    // Create a new node
    Node *root = new Node(data);

    // Recursively build the left subtree
    cout << "Enter data for Left part of " << data << " Node: ";
    root->left = buildTree();

    // Recursively build the right subtree
    cout << "Enter data for Right part of " << data << " Node: ";
    root->right = buildTree();

    return root;
}

// Function for Inorder Traversal (Left -> Node -> Right)
void inOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

// Function for Preorder Traversal (Node -> Left -> Right)
void preOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// Function for Postorder Traversal (Left -> Right -> Node)
void postOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

// Function to deallocate memory and prevent memory leaks
void deleteTree(Node *&root)
{
    if (root == NULL)
    {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = NULL; // Set pointer to NULL to avoid dangling pointers
}

// Main function
int main()
{
    Node *root = NULL;

    // Build the binary tree
    root = buildTree();

    // Print different tree traversals
    cout << "\nInorder Traversal: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postOrderTraversal(root);
    cout << endl;

    // Deallocate memory
    deleteTree(root);

    return 0;
}
