#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *getMiddle(Node *&head)
{
    if (head == NULL)
    {
        cout << "Linked List is Empty" << endl;
        return head;
    }
    if (head->next == NULL)
    {
        // Only 1 Node in linked list
        return head;
    }

    // if Linked list has more than 1 node
    Node *slow = head;
    Node *fast = head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
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

Node *reverseKNodes(Node *&head, int k)
{
    if (head == NULL)
    {
        cout << "Linked List is Empty" << endl;
        return NULL;
    }
    int len = getLength(head);
    if (k > len)
    {
        cout << "Enter the Valid value of k" << endl;
        return head;
    }
    // it means number of Node in LL is n>=k
    // Step 1: Reverse first K node of LL
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = curr->next;
    int count = 0;

    while (count < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    // step 2: Recursive call
    if (forward != NULL)
    {
        // we still have node left to reverse
        Node *recursionKaAns = reverseKNodes(forward, k);
        head->next = recursionKaAns;
    }

    // step 3: Return head of the modified LL
    return prev;
}

bool checkForLoop(Node *&head)
{
    if (head == NULL)
    {
        cout << "LL is Empty" << endl;
        return false;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        if (slow == fast)
        {
            // Loop present
            return true;
        }
    }
    // fast NULL hogya
    return false;
}

Node *startingPointLoop(Node *&head)
{
    if (head == NULL)
    {
        cout << "LL is empty " << endl;
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        if (slow == fast)
        {
            slow = head;
            break;
        }
    }

    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

Node *removeLoop(Node *&head)
{
    if (head == NULL)
    {
        cout << "LL is empty " << endl;
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        if (slow == fast)
        {
            slow = head;
            break;
        }
    }

    Node *prev = fast;
    while (slow != fast)
    {
        prev = fast;
        slow = slow->next;
        fast = fast->next;
    }
    prev->next = NULL;
    return slow;
}
int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);
    Node *sixth = new Node(60);
    Node *seventh = new Node(70);
    Node *eighth = new Node(80);
    Node *ninth = new Node(90);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;
    eighth->next = ninth;
    ninth->next = fourth;

    // print(head);

    // cout << "Middle Node  is: " << getMiddle(head)->data << endl;

    // head = reverseKNodes(head, 2);
    // print(head);

    cout << "Loop is present or not: " << checkForLoop(head);
    cout << "Starting Point of LOOP is: " << startingPointLoop(head)->data << endl;

    removeLoop(head);
    print(head);
    cout << "Loop is Present or not " << checkForLoop(head) << endl;

    return 0;
}