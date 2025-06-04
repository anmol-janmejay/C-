#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// // reverse Queue

// void reverseQueue(queue<int> &q)
// {
//     stack<int> s;

//     // step 1: Put all the elements of q into s
//     while (!q.empty())
//     {
//         int element = q.front();
//         q.pop();

//         s.push(element);
//     }

//     // Step 2: Put all element from stack into q
//     while (!s.empty())
//     {
//         int element = s.top();
//         s.pop();

//         q.push(element);
//     }
// }

// // Using Recursion
// void reverseQueueRecursion(queue<int> &q)
// {
//     // Base case
//     if (q.empty())
//         return;

//     // Step A:
//     int temp = q.front();
//     q.pop();

//     // Step B:
//     reverseQueueRecursion(q);

//     // Step C:
//     q.push(temp);
// }

// void reverseK(queue<int> &q, int k)
// {
//     // Step A: Queue ->k elements -> stack

//     stack<int> s;
//     int count = 0;
//     int n = q.size();

//     if (k <= 0 || k > n)
//         return;

//     while (!q.empty())
//     {
//         int temp = q.front();
//         q.pop();
//         s.push(temp);
//         count++;

//         if (count == k)
//             break;
//     }

//     // Step B: Stack -> q me wapas
//     while (!s.empty())
//     {
//         int temp = s.top();
//         s.pop();
//         q.push(temp);
//     }

//     // Step C: Push n-k element from q front to back
//     count = 0;
//     while (!q.empty() && n - k != 0)
//     {
//         int temp = q.front();
//         q.pop();
//         q.push(temp);
//         count++;

//         if (count == n - k)
//             break;
//     }
// }

// void interleaveQueue(queue<int> &q)
// {
//     // Step A: Seperate both Halves
//     int n = q.size();
//     if (q.empty())
//         return;
//     int k = n / 2;
//     int count = 0;
//     queue<int> q2;

//     while (!q.empty())
//     {
//         int temp = q.front();
//         q.pop();
//         q2.push(temp);
//         count++;

//         if (count == k)
//             break;
//     }

//     // Step B: InterLeaving start krdo
//     while (!q.empty() && !q2.empty())
//     {
//         int first = q2.front();
//         q2.pop();

//         q.push(first);

//         int second = q.front();
//         q.pop();

//         q.push(second);
//     }

//     // Odd Wala Case
//     if (n & 1)
//     {
//         int element = q.front();
//         q.pop();
//         q.push(element);
//     }
// }
// int main()
// {
//     queue<int> q;
//     q.push(1);
//     q.push(2);
//     q.push(3);
//     q.push(4);
//     q.push(5);
//     q.push(6);
//     q.push(7);
//     q.push(8);
//     q.push(9);

//     // Before Recursion
//     // reverseQueue(q);

//     // After Recursion
//     // reverseQueueRecursion(q);

//     // reverseK(q, 3);

//     interleaveQueue(q);

//     cout << "Printing Queue after reversing recursively" << endl;

//     while (!q.empty())
//     {
//         cout << q.front() << " ";
//         q.pop();
//     }
//     cout << endl;
//     return 0;
// }

// Sliding Window to Find first Negative Number

void solve(int arr[], int n, int k)
{
    deque<int> q;
    // process first window of size k
    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            q.push_back(i);
        }
    }

    // remaning window ko process kro
    for (int i = k; i < n; i++)
    {
        // answer dedo purani window ko
        if (q.empty())
        {
            cout << 0 << " ";
        }
        else
        {
            cout << arr[q.front()] << " ";
        }

        // out of window elements ko remove kro
        while ((!q.empty()) && (i - q.front() >= k))
        {
            q.pop_front();
        }

        // check current element for insertion
        if (arr[i] < 0)
            q.push_back(i);
    }

    // answer print karon for last window
    if (q.empty())
    {
        cout << 0 << " ";
    }
    else
    {
        cout << arr[q.front()] << " ";
    }
}

int main()
{
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int size = 8;

    int k = 3;

    solve(arr, size, k);

    return 0;
}