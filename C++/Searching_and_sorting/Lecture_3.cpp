#include <iostream>
#include <vector>
using namespace std;

// Function
// int binarySearch(vector<int> arr, int target)
// {
//     int start = 0;
//     int end = arr.size() - 1;

//     int mid = start + (end - start) / 2;

//     while (start <= end)
//     {
//         if (arr[mid] == target)
//             return mid;
//         if (mid + 1 <= end && arr[mid + 1] == target)
//             return mid + 1;
//         if (mid - 1 >= start && arr[mid - 1] == target)
//             return mid - 1;
//         if (arr[mid] > target)
//         {
//             // left search
//             end = mid - 2;
//         }
//         else
//         {
//             // right search
//             start = mid + 2;
//         }
//         mid = start + (end - start) / 2;
//     }
//     return -1;
// }

// int main()
// {
//     vector<int> arr{10, 3, 40, 20, 50, 80, 70};
//     int target;
//     cout << "Enter the Number: " << endl;
//     cin >> target;

//     // int target = 40;

//     int ans = binarySearch(arr, target);
//     cout << "Index of " << target << " is: " << ans << endl;

//     return 0;
// }

// int findDivision(int dividend, int divisor)
// {
//     int start = 0;
//     int end = dividend;
//     int store = -1;

//     int mid = start + (end - start) / 2;

//     while (start <= end)
//     {
//         // Perfect solution
//         if (mid * divisor == dividend)
//         {
//             return mid;
//         }
//         if (mid * divisor > dividend)
//         {
//             end = mid - 1;
//         }
//         else
//         {
//             store = mid;
//             start = mid + 1;
//         }
//         mid = start + (end - start) / 2;
//     }
//     return store;
// }

// int main()
// {
//     int dividend = 22;
//     int divisor = 11;

//     int store = findDivision(dividend, divisor);
//     cout << "Answer is: " << store << endl;
// }

// Find Odd Occuring element in an Array(Using XOR)

int solve(vector<int> arr)
{
    int start = 0;
    int end = arr.size() - 1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (start == end)
        {
            // Single element
            return start;
        }
        // if start equals end. This condition means that only one element is left in the search range, implying it’s the unique element. The function returns this index.

        // 2 cases -> mid - even or mid - odd
        if (mid % 2 == 0)
        {
            if (arr[mid] == arr[mid + 1])
            {
                start = mid + 2;
            }
            // For even mid, it checks if arr[mid] equals arr[mid + 1] (the next element). If true, it means the unique element is further right, so start is set to mid + 2 to continue the search on the right half.
            else
            {
                end = mid;
            }
        }
        else
        {
            if (arr[mid] == arr[mid - 1])
            {
                start = mid + 1;
            }
            // For odd mid, it checks if arr[mid] equals arr[mid - 1](the previous element).If true, the unique element must be further right, so start is set to mid + 1.
            else
            {
                end = mid - 1;
            }
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}

int main()
{
    vector<int> arr{1, 1, 2, 2, 3, 3, 4, 4, 3, 600, 600, 4, 4};
    int ans = solve(arr);

    cout << "Index is: " << ans << endl;
    cout << "Value is: " << arr[ans] << endl;
}
