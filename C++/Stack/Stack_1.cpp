#include <iostream>
#include <stack>
using namespace std;

// int main()
// {
//     // creation
//     stack<int> st;

//     // insertion
//     st.push(10);
//     st.push(20);
//     st.push(30);
//     st.push(40);

//     // remove
//     st.pop();

//     // check element on top
//     cout << "Element on Top is: " << st.top() << endl;

//     // size
//     cout << "Size of Stack is: " << st.size() << endl;

//     if (st.empty())
//     {
//         cout << "Stack is Empty" << endl;
//     }
//     else
//     {
//         cout << "stack is not Empty" << endl;
//     }
//     return 0;
// }

// Creating class of stack
// class stack
// {
// public:
//     int *arr;
//     int top;
//     int size;

//     stack(int size)
//     {
//         arr = new int[size];
//         this->size = size;
//         top = -1;
//     }

//     ~stack()
//     {
//         delete[] arr;
//     }

//     // function
//     void push(int data)
//     {
//         if (top < size - 1)
//         {
//             // space available
//             // insert
//             top++;
//             arr[top] = data;
//         }
//         else
//         {
//             // space not available
//             cout << "Stack Overflow" << endl;
//         }
//     }

//     void pop()
//     {
//         if (top == -1)
//         {
//             // stack is Empty
//             cout << "Stack Underflow, can't delete Element" << endl;
//         }
//         else
//         {
//             // stack is not empty
//             top--;
//         }
//     }

//     int getTop()
//     {
//         if (top == -1)
//         {
//             cout << "There is no Element in stack" << endl;
//             return -1;
//         }
//         else
//         {
//             return arr[top];
//         }
//     }
//     // return number of valid element present in stack
//     int getSize()
//     {
//         return top + 1;
//     }
//     bool isEmpty()
//     {
//         return top == -1;
//     }
// };

// int main()
// {
//     // creation
//     stack s(5);

//     // insertion
//     s.push(10);
//     s.push(20);
//     s.push(30);
//     s.push(40);
//     s.push(50);

//     while (!s.isEmpty())
//     {
//         cout << s.getTop() << " ";
//         s.pop();
//     }
//     cout << endl;

//     cout << "Size of Stack " << s.getSize() << endl;

//     s.pop();

//     return 0;
// }

// Creating two stack
// class Stack
// {
// public:
//     int *arr;
//     int size;
//     int top1;
//     int top2;

//     // Constructor
//     Stack(int size)
//     {
//         arr = new int[size]; // Allocate memory dynamically
//         this->size = size;
//         top1 = -1;   // Stack 1 starts from left
//         top2 = size; // Stack 2 starts from right
//     }

//     // Push into Stack 1
//     void push1(int data)
//     {
//         if (top2 == top1 + 1)
//         { // Stack is full
//             cout << "Stack Overflow in Stack 1" << endl;
//         }
//         else
//         {
//             top1++; // Move top1 up
//             arr[top1] = data;
//         }
//     }

//     // Push into Stack 2
//     void push2(int data)
//     {
//         if (top2 == top1 + 1)
//         { // Stack is full
//             cout << "Stack Overflow in Stack 2" << endl;
//         }
//         else
//         {
//             top2--; // Move top2 down
//             arr[top2] = data;
//         }
//     }

//     // Pop from Stack 1
//     void pop1()
//     {
//         if (top1 == -1)
//         {
//             cout << "Stack Underflow in Stack 1" << endl;
//         }
//         else
//         {
//             top1--; // Move top1 down
//         }
//     }

//     // Pop from Stack 2
//     void pop2()
//     {
//         if (top2 == size)
//         {
//             cout << "Stack Underflow in Stack 2" << endl;
//         }
//         else
//         {
//             top2++; // Move top2 up
//         }
//     }

//     // Print the stack
//     void print()
//     {
//         cout << "\nTop1: " << top1 << " | Top2: " << top2 << endl;
//         for (int i = 0; i < size; i++)
//         {
//             cout << arr[i] << " ";
//         }
//         cout << endl;
//     }

//     // Destructor to free memory
//     ~Stack()
//     {
//         delete[] arr;
//     }
// };

// int main()
// {
//     Stack s(10);

//     // Pushing elements into stack 1
//     s.push1(10);
//     s.print();
//     s.push1(20);
//     s.print();
//     s.push1(30);
//     s.print();
//     s.push1(40);
//     s.print();
//     s.push1(50);
//     s.print();

//     // Pushing elements into stack 2
//     s.push2(100);
//     s.print();
//     s.push2(110);
//     s.print();
//     s.push2(120);
//     s.print();
//     s.push2(130);
//     s.print();
//     s.push2(140);
//     s.print();

//     // Popping elements from stack 1
//     s.pop1();
//     s.print();
//     s.pop1();
//     s.print();
//     s.pop1();
//     s.print();
//     s.pop1();
//     s.print();
//     s.pop1();
//     s.print();

//     // Pushing into stack 2 after popping from stack 1
//     s.push2(1000);
//     s.print();

//     s.pop1(); // Should print "Stack Underflow in Stack 1"
//     s.print();

//     return 0;
// }

// Find the Middle Element in a Stack

int main()
{
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);

    int totalSize = s.size();
    printMiddle(s, totalSize);

    return 0;
}