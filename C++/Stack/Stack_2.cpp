#include <iostream>
#include <stack>
using namespace std;

// void insertAtBottom(stack<int> &s, int target)
// {
//     // base case
//     if (s.empty())
//     {
//         s.push(target);
//         return;
//     }

//     int topElement = s.top();
//     s.pop();
//     // recursive call
//     insertAtBottom(s, target);
//     // BT
//     s.push(topElement);
// }

// int main()
// {
//     stack<int> s;
//     s.push(10);
//     s.push(20);
//     s.push(30);
//     s.push(40);
//     s.push(50);
//     s.push(60);

//     if (s.empty())
//     {
//         cout << "Stack is Empty, cant insert at bottom" << endl;
//         return 0;
//     }

//     int target = s.top();
//     s.pop();
//     insertAtBottom(s, target);

//     cout << "Printing" << endl;
//     while (!s.empty())
//     {
//         cout << s.top() << " ";
//         s.pop();
//     }
//     cout << endl;
//     return 0;
// }

// Reverse at Stack
// void insertAtBottom(stack<int> &s, int target)
// {
//     // base case
//     if (s.empty())
//     {
//         s.push(target);
//         return;
//     }

//     int topElement = s.top();
//     s.pop();
//     // recursive call
//     insertAtBottom(s, target);
//     // BackTracking
//     s.push(topElement);
// }

// void reverseStack(stack<int> &s)
// {
//     // base case
//     if (s.empty())
//     {
//         return;
//     }

//     int target = s.top();
//     s.pop();

//     // reverse stack
//     reverseStack(s);
//     // insert at bottom target ko
//     insertAtBottom(s, target);
// }

// int main()
// {
//     stack<int> s;
//     s.push(10);
//     s.push(20);
//     s.push(30);
//     s.push(40);
//     s.push(50);

//     reverseStack(s);

//     cout << "Printing" << endl;
//     while (!s.empty())
//     {
//         cout << s.top() << " ";
//         s.pop();
//     }
//     cout << endl;

//     return 0;
// }

// Valid  Parenthesis Problem
// void insertSorted(stack<int> &s, int target)
// {
//     // base case
//     if (s.empty())
//     {
//         s.push(target);
//         return;
//     }

//     if (s.top() >= target)
//     {
//         s.push(target);
//         return;
//     }

//     int topElement = s.top();
//     s.pop();
//     insertSorted(s, target);

//     // BackTracking
//     s.push(topElement);
// }

// void sortStack(stack<int> &s)
// {
//     // base case
//     if (s.empty())
//     {
//         return;
//     }

//     int topElement = s.top();
//     s.pop();

//     sortStack(s);

//     insertSorted(s, topElement);
// }

// int main()
// {
//     stack<int> s;
//     s.push(7);
//     s.push(11);
//     s.push(3);
//     s.push(5);
//     s.push(9);

//     sortStack(s);

//     cout << "Printing" << endl;
//     while (!s.empty())
//     {
//         cout << s.top() << " ";
//         s.pop();
//     }
//     cout << endl;
//     return 0;
// }
