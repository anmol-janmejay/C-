#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node()
    {
        cout << "Node with value: " << this->data << " deleted" << endl;
    }
};

void print(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int getLength(Node *head)
{
    int len = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

// I want to insert a node right at the head of Linked List
void insertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        // Linked list is empty
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        // Linked list is non Empty
        // Step:1 Create a node
        Node *newNode = new Node(data);
        // Step:2
        newNode->next = head;
        // Step:3
        head->prev = newNode;
        // step 4:
        head = newNode;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        // Linked List is empty
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        // Linked list is not Empty
        Node *newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void insertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = new Node;
        tail = new Node;
    }
    else
    {
        // Linked list is not empty
        if (position == 1)
        {
            insertAtHead(head, tail, data);
            return;
        }
        int len = getLength(head);
        if (position > len)
        {
            insertAtTail(head, tail, data);
            return;
        }
        // insertion in middle
        // Step:1 Find Prev and Currnt
        int i = 1;
        Node *prevNode = head;
        while (i < position - 1)
        {
            prevNode = prevNode->next;
            i++;
        }
        Node *curr = prevNode->next;

        // step 2: Create a Node
        Node *newNode = new Node(data);

        // step 3 :
        newNode->prev = prevNode;
        prevNode->next = newNode;
        newNode->next = curr;
        curr->prev = newNode;
    }
}

void deleteFromPos(Node *&head, Node *&tail, int position)
{
    if (head == NULL)
    {
        cout << "Linked List is Empty";
        return;
    }
    if (head->next == NULL)
    {
        // Single node
        Node *temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }
    int len = getLength(head);
    if (position > len)
    {
        cout << "Please Enter the Valid Poistion" << endl;
        return;
    }

    if (position == 1)
    {
        // Want to delete the first node
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }
    if (position == len)
    {
        // delete last node
        Node *temp = tail;
        tail = tail->prev;
        temp->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }
    // delete from middle of linked list

    // step1: find left, curr, right
    int i = 1;
    Node *left = head;
    while (i < position - 1)
    {
        left = left->next;
        i++;
    }
    Node *curr = left->next;
    Node *right = curr->next;

    // step2:
    left->next = right;
    // step3:
    right->prev = left;
    // step4:
    curr->next = NULL;
    curr->prev = NULL;
    delete curr;
}

int main()
{
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);

    Node *head = first;
    Node *tail = third;

    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;

    print(first);
    cout << endl;

    insertAtHead(head, tail, 101);

    cout << endl;
    print(head);

    insertAtTail(head, tail, 501);

    cout << endl;
    print(head);

    insertAtPosition(head, tail, 401, 3);
    cout << endl;
    print(head);

    deleteFromPos(head, tail, 10);

    cout << endl;
    print(head);

    return 0;
}
