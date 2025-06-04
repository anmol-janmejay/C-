// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;

//     Node()
//     {
//         this->data = 0;
//         this->next = NULL;
//     }
//     Node(int data)
//     {
//         this->data = data;
//         thi->next = NULL;
//     }
// }

// void
// print(Node *&head)
// {
// }

// int main()
// {
//     Node *first = new Node();
//     Node *second = new Node();
//     Node *third = new Node();
//     Node *fourth = new Node();
//     Node *fifth = new Node();

//     first->next = second;
//     second->next = third;
//     third->next = fourth;
//     fourth->next = fifth;

//     return 0;
// }

// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;

//     Node()
//     {
//         this->data = 0;
//         this->next = NULL;
//     }
//     Node(int data)
//     {
//         this->data = data;
//         this->next = NULL;
//     }

//     // TODO: Write a destrcutor to delete a node
//     ~Node()
//     {
//         // write your code here
//         cout << "Node with value: " << this->data << "deleted" << endl;
//     }
// };

// // I want to insert a node right at the head of Linked List
// void insertAtHead(Node *&head, Node *&tail, int data)
// {
//     // check for Empty LL
//     if (head == NULL)
//     {
//         Node *newNode = new Node(data);
//         head = newNode;
//         tail = newNode;
//     }
//     else
//     {
//         // step1:
//         Node *newNode = new Node(data);
//         // step2:
//         newNode->next = head;
//         // step3:
//         head = newNode;
//     }
// }
// // I want to insert a node right at the end of LINKED LIST
// void insertAtTail(Node *&head, Node *&tail, int data)
// {
//     if (head == NULL)
//     {
//         Node *newNode = new Node(data);
//         head = newNode;
//         tail = newNode;
//         return;
//     }
//     // step1: creatae a node
//     Node *newNode = new Node(data);
//     // step2: connect woth tail ndoe
//     tail->next = newNode;
//     // step3: update tail;
//     tail = newNode;
// }
// void print(Node *head)
// {

//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
// }

// int findLength(Node *&head)
// {
//     int len = 0;
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         temp = temp->next;
//         len++;
//     }
//     return len;
// }

// void insertAtPosition(int data, int position, Node *&head, Node *&tail)
// {
//     if (head == NULL)
//     {
//         Node *newNode = new Node(data);
//         head = newNode;
//         tail = newNode;
//         return;
//     }
//     // step1: find the position: prev & curr;

//     if (position == 0)
//     {
//         insertAtHead(head, tail, data);
//         return;
//     }

//     int len = findLength(head);

//     if (position >= len)
//     {
//         insertAtTail(head, tail, data);
//         return;
//     }
//     // ste1:find prev and curr
//     int i = 1;
//     Node *prev = head;
//     while (i < position)
//     {
//         prev = prev->next;
//         i++;
//     }
//     Node *curr = prev->next;

//     // step2;
//     Node *newNode = new Node(data);

//     // step3:
//     newNode->next = curr;

//     // step4:
//     prev->next = newNode;
// }

// void deleteNode(int position, Node *&head, Node *&tail)
// {
//     if (head == NULL)
//     {
//         cout << "Cannot delete, LL is empty";
//         return;
//     }

//     // deleting first node
//     if (position == 1)
//     {
//         Node *temp = head;
//         head = head->next;
//         temp->next = NULL;
//         delete temp;
//         return;
//     }
//     int len = findLength(head);

//     // deleting last node
//     if (position == len)
//     {
//         // find prev
//         int i = 1;
//         Node *prev = head;
//         while (i < position - 1)
//         {
//             prev = prev->next;
//             i++;
//         }
//         // step2:
//         prev->next = NULL;
//         // step3:
//         Node *temp = tail;
//         // step4:
//         tail = prev;
//         // step5:
//         delete temp;
//         return;
//     }

//     // deleting middle node

//     // step  : find prev and curr
//     int i = 1;
//     Node *prev = head;
//     while (i < position - 1)
//     {
//         prev = prev->next;
//         i++;
//     }
//     Node *curr = prev->next;

//     // step2:
//     prev->next = curr->next;
//     // step3:
//     curr->next = NULL;
//     // step4:
//     delete curr;
// }

// int main()
// {

//     Node *head = NULL;
//     Node *tail = NULL;
//     insertAtHead(head, tail, 20);
//     insertAtHead(head, tail, 50);
//     insertAtHead(head, tail, 60);
//     insertAtHead(head, tail, 90);
//     insertAtTail(head, tail, 77);

//     print(head);
//     cout << endl;
//     // cout << "head: " << head -> data << endl;
//     // cout << "tail: " << tail->data << endl;

//     // insertAtPosition(101, 5, head, tail);
//     // cout<< "Printing after insert at position call" << endl;
//     // print(head);
//     // cout << endl;
//     // cout << "head: " << head -> data << endl;
//     // cout << "tail: " << tail->data << endl;

//     deleteNode(9, head, tail);
//     cout << endl;
//     print(head);
//     cout << endl;

//     return 0;
// }
// Code for Insertion
// #include <iostream>
// using namespace std;

// // Node structure
// class Node
// {
// public:
//     int data;
//     Node *next;

//     Node(int val)
//     {
//         data = val;
//         next = nullptr;
//     }
// };

// // Function to insert a node at the beginning
// void insertAtBeginning(Node *&head, int val)
// {
//     Node *newNode = new Node(val);
//     newNode->next = head;
//     head = newNode;
// }

// // Function to insert a node at the end
// void insertAtEnd(Node *&head, int val)
// {
//     Node *newNode = new Node(val);
//     if (head == nullptr)
//     {
//         head = newNode;
//         return;
//     }

//     Node *temp = head;
//     while (temp->next != nullptr)
//     {
//         temp = temp->next;
//     }
//     temp->next = newNode;
// }

// // Function to insert a node at a given position
// void insertAtPosition(Node *&head, int val, int pos)
// {
//     if (pos == 1)
//     {
//         insertAtBeginning(head, val);
//         return;
//     }

//     Node *newNode = new Node(val);
//     Node *temp = head;
//     for (int i = 1; temp != nullptr && i < pos - 1; i++)
//     {
//         temp = temp->next;
//     }

//     if (temp == nullptr)
//     {
//         cout << "Position out of range!\n";
//         return;
//     }

//     newNode->next = temp->next;
//     temp->next = newNode;
// }

// // Function to display the linked list
// void display(Node *head)
// {
//     Node *temp = head;
//     while (temp != nullptr)
//     {
//         cout << temp->data << " -> ";
//         temp = temp->next;
//     }
//     cout << "NULL\n";
// }

// int main()
// {
//     Node *head = nullptr;

//     insertAtEnd(head, 10);
//     insertAtEnd(head, 20);
//     insertAtEnd(head, 30);
//     cout << "Linked List after insertions at end: ";
//     display(head);

//     insertAtBeginning(head, 5);
//     cout << "After inserting 5 at beginning: ";
//     display(head);

//     insertAtPosition(head, 15, 3);
//     cout << "After inserting 15 at position 3: ";
//     display(head);

//     return 0;
// }

// Code For Deletion
#include <iostream>
using namespace std;

// Function to delete the first node
void deleteFromBeginning(Node *&head)
{
    if (head == nullptr)
    {
        cout << "List is empty!\n";
        return;
    }

    Node *temp = head;
    head = head->next;
    delete temp;
}

// Function to delete the last node
void deleteFromEnd(Node *&head)
{
    if (head == nullptr)
    {
        cout << "List is empty!\n";
        return;
    }

    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }

    Node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
}

// Function to delete a node from a specific position
void deleteFromPosition(Node *&head, int pos)
{
    if (head == nullptr)
    {
        cout << "List is empty!\n";
        return;
    }

    if (pos == 1)
    {
        deleteFromBeginning(head);
        return;
    }

    Node *temp = head;
    for (int i = 1; temp != nullptr && i < pos - 1; i++)
    {
        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr)
    {
        cout << "Position out of range!\n";
        return;
    }

    Node *nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}

int main()
{
    Node *head = nullptr;

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    cout << "Original Linked List: ";
    display(head);

    deleteFromBeginning(head);
    cout << "After deleting from beginning: ";
    display(head);

    deleteFromEnd(head);
    cout << "After deleting from end: ";
    display(head);

    deleteFromPosition(head, 2);
    cout << "After deleting node at position 2: ";
    display(head);

    return 0;
}
