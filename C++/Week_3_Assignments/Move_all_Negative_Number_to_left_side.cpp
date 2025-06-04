#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void moveAllNegToLeft(int *a, int n)
{
    // Dutch Flag Problem
    int start = 0;
    int end = n - 1;
    while (start < end)
    {
        if (a[start] < 0)
        {
            start++;
        }
        else if (a[end] >= 0)
        {
            end--;
        }
        else
        {
            std::swap(a[start], a[end]);
            start++;
            end--;
        }
    }
}

int main()
{
    int a[] = {1, 2, -3, 4, -5, 6};
    int n = sizeof(a) / sizeof(int);
    moveAllNegToLeft(a, n);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}