// #include <iostream>
// #include <vector>
// using namespace std;

// bool checkSorted(vector<int> &arr, int &n, int i)
// {
//     // base case
//     if (i == n - 1)
//     {
//         return true;
//     }

//     // Need to solve 1 test case
//     if (arr[i + 1] < arr[i])
//     {
//         return false;
//     }

//     // baaki recursion sambhal lega
//     return checkSorted(arr, n, i + 1);
// }

// int main()
// {
//     vector<int> v{10, 20, 30, 50, 60};
//     int n = v.size();
//     int i = 0;

//     bool isSorted = checkSorted(v, n, i);

//     if (isSorted)
//     {
//         cout << "Array is Sorted" << endl;
//     }
//     else
//     {
//         cout << "Array is not sorted" << endl;
//     }
//     return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;

// int binarySearch(vector<int> arr, int s, int e, int key)
// {
//     // Base case
//     // Case 1: Key Not Found
//     if (s > e)
//     {
//         return -1;
//     }
//     int mid = s + (e - s) / 2;
//     // Case 2: Key Found
//     if (arr[mid] == key)
//         return mid;

//     // using Terniary operator
//     return (arr[mid] < key ? binarySearch(arr, mid + 1, e, key) : binarySearch(arr, s, mid - 1, key));

//     // // Solve 1 case
//     // // arr[mid] < key -> Right Search
//     // if (arr[mid] < key)
//     // {
//     //     return binarySearch(arr, mid + 1, e, key);
//     // }
//     // else
//     // {
//     //     // arr[mid] > key -> Left Search
//     //     return binarySearch(arr, s, mid - 1, key);
//     // }
// }

// int main()
// {
//     vector<int> v{10, 20, 30, 60, 70, 80, 90, 99};
//     int key = 99;

//     int n = v.size();
//     int s = 0;
//     int e = n - 1;

//     int ans = binarySearch(v, s, e, key);
//     cout << "Answer is: " << ans << endl;

//     return 0;
// }

#include <iostream>
using namespace std;

void printSubsequence(string str, string output, int i)
{
    // base case
    if (i >= str.length())
    {
        cout << output << endl;
        return;
    }

    // Exclude
    printSubsequence(str, output, i + 1);

    // Inlcude
    output.push_back(str[i]);
    printSubsequence(str, output, i + 1);
}

int main()
{
    string str = "abc";
    string output = "";

    int i = 0;
    printSubsequence(str, output, i);
    return 0;
}