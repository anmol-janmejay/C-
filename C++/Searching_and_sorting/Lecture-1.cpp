#include <iostream>
#include <vector>
using namespace std;

// Binary Search

// int binarySearch(int arr[], int size, int target)
// {
//     int start = 0;
//     int end = size - 1;

//     int mid = start + (end - start) / 2;
//     while (start <= end)
//     {
//         int element = arr[mid];

//         if (element == target)
//         {
//             return mid;
//         }
//         else if (element > target)
//         {
//             end = mid - 1;
//         }
//         else
//         {
//             start = mid + 1;
//         }
//         mid = start + (end - start) / 2;
//     }
//     // element  not found
//     return -1;
// }

// int main()
// {
//     int arr[] = {2, 4, 6, 8, 10, 12, 16, 18};
//     int size = 8;
//     int target = 8;

//     int indexOfTarget = binarySearch(arr, size, target);

//     if (indexOfTarget == -1)
//     {
//         cout << "Target Not Found";
//     }
//     else
//     {
//         cout << "Target Found at: " << indexOfTarget << endl;
//     }
//     return 0;
// }

// Find the First Occurence Of the Element

int firstOccurence(vector<int> v, int target)
{
    int start = 0;
    int end = v.size() - 1;

    int mid = start + (end - start) / 2;
    int ans = -1;
    // int ans = -1;: Initializes ans to -1. This variable will store the index of the first occurrence of the target if found. If the target is not found, it remains -1.

    while (start <= end)
    {
        if (v[mid] == target)
        {
            // Answer store and then left
            // Store the current mid as the answer and search left for the first occurrence
            ans = mid;
            end = mid - 1;
        }
        else if (target > v[mid])
        {
            // Search on Right
            start = mid + 1;
        }
        else if (target < v[mid])
        {
            // left search
            end = mid - 1;
        }
        // mid = start + (end - start) / 2;: Recalculates the mid index based on the updated start and end. This is necessary for the next iteration of the loop.
        mid = start + (end - start) / 2;
    }
    return ans;
}

int main()
{
    vector<int> v{1, 3, 4, 4, 4, 4, 6, 7};
    int target = 4;

    int ans = firstOccurence(v, target);

    cout << "Answer is: " << ans << endl;

    return 0;
}