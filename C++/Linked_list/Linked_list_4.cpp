// #include <iostream>
// using namespace std;

// class Node{
//     public:
//     int data;
//     Node* next;

//     Node(int data)
//     {
//         this->data= data;
//         this->next = NULL;
//     }
// };

// Node* reverse(Node* head)
// {
//     Node* prev = NULL;
//     Node* curr = head;
//     Node* next = curr -> next;
//     while(curr != NULL)
//     {
//         next = curr -> next;
//         curr -> next = prev;
//         prev = curr;
//         curr = next;
//     }
//     return prev;
// }

// bool checkPalindrome(Node* &head)
// {
//     if(head == NULL)
//     {
//         cout << "Linked list is Empty" << endl;
//         return true;
//     }
//     if(head -> next == NULL)
//     {
//         // only 1 node
//         return true;
//     }
//         // 1 node in Linked list

//         // step A: One middle node in LL
//         Node *slow = head;
//         Node* fast = head -> next;

//         while(fast != NULL)
//         {
//             fast = fast -> next;
//             if(fast != NULL)
//             {
//                 fast = fast -> next;
//                 slow = slow -> next;
//             }
//         }
//     // slow pointer is pointing to the middle node

//     // step B:- Reverse LL after Middle node
//     Node* reverseLLKaHead = reverse(slow -> next);
//     // join the reversed LL into the left part
//     slow -> next = reverseLLKaHead;

//     // step C: start comparsion
//     Node* temp1 = head;
//     Node* temp2 = reverseLLKaHead;
//     while(temp2 != NULL)
//     {
//         if(temp1 -> data != temp2 -> data)
//         {
//             // not a palindrome
//             return false;
//         }
//         else
//         {
//             // if data is equal,then aage bhad jao
//             temp1 = temp1 -> next;
//             temp2 = temp2 -> next;
//         }
//     }
//     return true;
// }

// int main()
// {
//     Node* head = new Node(10);
//     Node* second = new Node(20);
//     Node* third = new Node(30);
//     Node* fourth = new Node(30);
//     Node* fifth = new Node(20);
//     Node* sixth = new Node(10);
//     head -> next = second;
//     second ->next = third;
//     third ->next = fourth;
//     fourth ->next = fifth;
//     fifth ->next = sixth;

//     bool isPalindrome = checkPalindrome(head);
//     if(isPalindrome)
//     {
//         cout <<"Linked List is a Palindrome" << endl;
//     }
//     else
//     {
//         cout << "Linked List is not a Palindrome" << endl;
//     }

//     return 0;
// }

// Remove Duplicate From Linked List
// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;

//     Node(int data)
//     {
//         this->data = data;
//         this->next = NULL;
//     }
// };

// void print(Node *head)
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// void removeDuplicates(Node *&head)
// {
//     if (head == NULL)
//     {
//         cout << "Linked list is Empty" << endl;
//         return;
//     }
//     if (head->next == NULL)
//     {
//         cout << "Single Node in Linked list" << endl;
//         return;
//     }

//     // >1 node in LL
//     Node *curr = head;

//     while (curr != NULL)
//     {
//         if ((curr->next != NULL) && (curr->data == curr->next->data))
//         {
//             // equal
//             Node *temp = curr->next;
//             curr->next = curr->next->next;
//             // delete node
//             temp->next = NULL;
//             delete temp;
//         }
//         else
//         {
//             // not equal
//             curr = curr->next;
//         }
//     }
// }

// int main()
// {
//     Node *head = new Node(1);
//     Node *second = new Node(2);
//     Node *third = new Node(2);
//     Node *fourth = new Node(3);
//     Node *fifth = new Node(4);
//     Node *sixth = new Node(4);
//     head->next = second;
//     second->next = third;
//     third->next = fourth;
//     fourth->next = fifth;
//     fifth->next = sixth;

//     cout << "Input Linked list: ";
//     print(head);

//     removeDuplicates(head);
//     cout << "Output Linked list: ";
//     print(head);

//     return 0;
// }

// Sorting zero, one and two

// #include <iostream>
// using namespace std;

// class Node{
//     public:
//     int data;
//     Node* next;

//     Node(int data)
//     {
//         this->data = data;
//         this->next = NULL;
//     }
// };

// void print(Node* head)
// {
//     Node* temp = head;
//     while(temp != NULL)
//     {
//         cout << temp-> data << " ";
//         temp = temp -> next;
//     }
//     cout << endl;
// }

// void sortZeroOneTwo(Node* &head)
// {
//     // Step 1:- Find count of zeroe, ones and two
//     int zero = 0;
//     int one = 0;
//     int two = 0;

//     Node* temp = head;
//     while(temp!=NULL)
//     {
//         if(temp -> data == 0)
//         zero++;
//         else if(temp -> data == 1)
//         one++;
//         else if(temp ->data == 2)
//         two++;
//         temp = temp -> next;
//     }

//     // Step2: Fill 0,1 and 2 in the original Linked list
//     temp = head;
//     // fill zeroes
//     while(zero--)
//     {
//         temp -> data = 0;
//         temp = temp -> next;
//     }

//     // fill ones
//     while(one--)
//     {
//         temp-> data = 1;
//         temp = temp -> next;
//     }

//     // fill 2s
//     while(two--)
//     {
//         temp -> data = 2;
//         temp = temp -> next;
//     }
// }

// Node* sort2(Node* &head)
// {
//     if(head == NULL)
//     {
//         cout << "Linked list is Empty" << endl;
//         return NULL;
//     }
//     if(head -> next == NULL)
//     {
//         // single node in LL
//         return head;
//     }

//     // create dummy node
//     Node* zeroHead = new Node(-101);
//     Node* zeroTail = zeroHead;

//     Node* oneHead = new Node(-101);
//     Node *oneTail = oneHead;

//     Node* twoHead = new Node(-101);
//     Node *twoTail = twoHead;

//     // trasverse the original Linked list
//     Node* curr = head;
//     while(curr!=NULL)
//     {
//         if(curr -> data == 0)
//         {
//             // take out zero waali node
//             Node* temp = curr;
//             curr = curr -> next;
//             temp -> next = NULL;

//             // append the zero node in zeroHead LL
//             zeroTail -> next = temp;
//             zeroTail = temp;
//         }
//         else if(curr -> data == 1)
//         {
//             // take out 1 waali node
//             Node* temp = curr;
//             curr = curr -> next;
//             temp -> next = NULL;

//             // append the zero node in zeroHead LL
//             oneTail -> next = temp;
//             oneTail = temp;
//         }
//         else if(curr -> data ==2 )
//         {
//             // take out zero waali node
//             Node* temp = curr;
//             curr = curr -> next;
//             temp -> next = NULL;

//             // append the zero node in zeroHead LL
//             twoTail -> next = temp;
//             twoTail = temp;
//         }
//     }

//     // ab yaha prr, zero, one, two teeno LL ready h

//     // join them
//     // remove Dummy Nodes

//     // modify one waali list
//     Node* temp = oneHead;
//     oneHead = oneHead -> next;
//     temp -> next = NULL;
//     delete temp;

//     // modify two waali list
//     temp = twoHead;
//     twoHead = twoHead -> next;
//     temp -> next = NULL;
//     delete temp;

//     // join list
//     if(oneHead != NULL)
//     {
//         // one waali list is not empty
//         // zero waali list ko one wali list se attack krdia
//         zeroTail -> next = oneHead;

//         if(twoHead != NULL)
//         oneTail-> next = twoHead;
//     }
//     else{
//         // one waali list is empty
//         if(twoHead != NULL)
//         zeroTail -> next = twoHead;
//     }

//     // remove zerohead dummy node
//     temp = zeroHead;
//     zeroHead = zeroHead -> next;
//     temp -> next = NULL;
//     delete temp;

//     // return head of the modified linked list
//     return zeroHead;
// }

// int main()
// {
//     Node *head = new Node(2);
//     Node *second = new Node(2);
//     Node *third = new Node(1);
//     Node *fourth = new Node(1);
//     Node *fifth = new Node(0);
//     Node *sixth = new Node(0);
//     head->next = second;
//     second->next = third;
//     third->next = fourth;
//     fourth->next = fifth;
//     fifth->next = sixth;

//     cout << "Input LL: ";
//     print(head);

//     // sortZeroOneTwo(head);
//     // print(head);

//     cout << "Printing the sorted list" << endl;
//     Node* temp = NULL;
//     head = sort2(head);
//     // cout << "Came out sort function" << endl;
//     print(head);

//     return 0;
// }

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

void sortZeroOneTwo(Node *&head)
{
    // step1: find count of zeroes, ones and twos
    int zero = 0;
    int one = 0;
    int two = 0;

    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
            zero++;
        else if (temp->data == 1)
            one++;
        else if (temp->data == 2)
            two++;
        temp = temp->next;
    }

    // step2: fill 0, 1 and 2s in the original ll
    temp = head;
    // fill zeroes
    while (zero--)
    {
        temp->data = 0;
        temp = temp->next;
    }

    // fill ones
    while (one--)
    {
        temp->data = 1;
        temp = temp->next;
    }

    // fill 2s
    while (two--)
    {
        temp->data = 2;
        temp = temp->next;
    }
}

Node *sort2(Node *&head)
{
    if (head == NULL)
    {
        cout << "LL is empty " << endl;
        return NULL;
    }
    if (head->next == NULL)
    {
        // sngle node in LL
        return head;
    }

    // create dummy nodes
    Node *zeroHead = new Node(-101);
    Node *zeroTail = zeroHead;

    Node *oneHead = new Node(-101);
    Node *oneTail = oneHead;

    Node *twoHead = new Node(-101);
    Node *twoTail = twoHead;

    // traverse the original LL
    Node *curr = head;
    while (curr != NULL)
    {

        if (curr->data == 0)
        {
            // take out the zero wali node
            Node *temp = curr;
            curr = curr->next;
            temp->next = NULL;

            // append the zero node in zeroHead LL
            zeroTail->next = temp;
            zeroTail = temp;
        }
        else if (curr->data == 1)
        {
            // take out the one wali node
            Node *temp = curr;
            curr = curr->next;
            temp->next = NULL;

            // append the zero node in zeroHead LL
            oneTail->next = temp;
            oneTail = temp;
        }
        else if (curr->data == 2)
        {
            // take out the zero wali node
            Node *temp = curr;
            curr = curr->next;
            temp->next = NULL;

            // append the zero node in zeroHead LL
            twoTail->next = temp;
            twoTail = temp;
        }
    }

    // ab yha pr, zero , one, two, teeno LL readyv h

    // join them
    // remove dummmy nodes

    // modify one wali list
    Node *temp = oneHead;
    oneHead = oneHead->next;
    temp->next = NULL;
    delete temp;

    // modify two wali list
    temp = twoHead;
    twoHead = twoHead->next;
    temp->next = NULL;
    delete temp;

    // join list
    if (oneHead != NULL)
    {
        // one wali list is non empty
        // zero wali list ko one wali list se attach krdia
        zeroTail->next = oneHead;

        if (twoHead != NULL)
            oneTail->next = twoHead;
    }
    else
    {
        // one wali list is empty
        if (twoHead != NULL)
            zeroTail->next = twoHead;
    }

    // remove zerohead dummy Node
    temp = zeroHead;
    zeroHead = zeroHead->next;
    temp->next = NULL;
    delete temp;

    // return head of the modified linked list
    return zeroHead;
}

int main()
{
    Node *head = new Node(2);
    Node *second = new Node(2);
    Node *third = new Node(1);
    Node *fourth = new Node(1);
    Node *fifth = new Node(0);
    Node *sixth = new Node(0);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    cout << "input LL: ";
    print(head);

    //   sortZeroOneTwo(head);
    //   print(head);

    cout << "printing the sorted list " << endl;
    Node *temp = NULL;
    head = sort2(head);
    // cout << "Came out of sort function" << endl;
    print(head);

    return 0;
}