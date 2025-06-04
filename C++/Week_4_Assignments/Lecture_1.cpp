// class Solution
// {
// public:
//     vector<int> findClosestElements(vector<int> &arr, int k, int x)
//     {
//         int n = arr.size(); // Get the size of the array.
//         vector<int> ans;    // Vector to store the result elements.

//         // If `x` is larger than the last element, the closest elements are the last `k` elements.
//         if (x > arr[n - 1])
//         {
//             for (int i = n - 1; i > n - 1 - k; i--)
//             {
//                 ans.push_back(arr[i]); // Add elements from the end of the array.
//             }
//             reverse(ans.begin(), ans.end()); // Reverse `ans` to maintain increasing order.
//             return ans;
//         }

//         // If `x` is smaller than the first element, the closest elements are the first `k` elements.
//         if (x < arr[0])
//         {
//             for (int i = 0; i < k; i++)
//             {
//                 ans.push_back(arr[i]); // Add first `k` elements to `ans`.
//             }
//             return ans;
//         }

//         // Binary search for the closest element to `x`.
//         int lo = 0;
//         int hi = n - 1;
//         while (lo <= hi)
//         {
//             int mid = lo + (hi - lo) / 2; // Calculate mid to avoid overflow.

//             // If `x` is found, add it to `ans` and prepare to find `k-1` more elements around it.
//             if (arr[mid] == x)
//             {
//                 ans.push_back(x);
//                 k--; // Decrement `k` as we found one element.
//                 lo = mid + 1;
//                 hi = mid - 1;
//                 break;
//             }
//             else if (arr[mid] < x)
//             { // Move search window right if `mid` is less than `x`.
//                 lo = mid + 1;
//             }
//             else
//             { // Move search window left if `mid` is greater than `x`.
//                 hi = mid - 1;
//             }
//         }

//         // Collect the `k` closest elements around `x`.
//         for (int i = 0; i < k && hi >= 0 && lo <= n - 1;)
//         {
//             // Compare the absolute differences on each side of `x`.
//             if (abs(arr[hi] - x) > abs(arr[lo] - x))
//             {
//                 ans.push_back(arr[lo]); // `lo` is closer to `x`, add `arr[lo]`.
//                 lo++;
//                 k--;
//             }
//             else if (abs(arr[hi] - x) < abs(arr[lo] - x))
//             {
//                 ans.push_back(arr[hi]); // `hi` is closer to `x`, add `arr[hi]`.
//                 hi--;
//                 k--;
//             }
//             else
//             { // If distances are equal, choose the element on the left (or lower index).
//                 if (hi > lo)
//                 {
//                     ans.push_back(arr[lo]);
//                     lo++;
//                     k--;
//                 }
//                 else
//                 {
//                     ans.push_back(arr[hi]);
//                     hi--;
//                     k--;
//                 }
//             }
//         }

//         // If `lo` goes out of bounds, but `k` elements are still needed, add remaining `hi` elements.
//         if ((lo == n) && (k != 0) && (hi != -1))
//         {
//             for (int i = 0; i < k; i++)
//             {
//                 ans.push_back(arr[hi]);
//                 hi--;
//             }
//         }
//         // If `hi` goes out of bounds, add remaining `lo` elements.
//         else if ((hi == -1) && (k != 0) && (lo != n))
//         {
//             for (int i = 0; i < k; i++)
//             {
//                 ans.push_back(arr[lo]);
//                 lo++;
//             }
//         }

//         // Sort `ans` in ascending order before returning as the result.
//         sort(ans.begin(), ans.end());
//         return ans;
//     }
// };

#include <iostream>
using namespace std;

int bs(int a[], int start, int end, int x)
// helper function bs, which implements a Binary Search on a subarray of a[] between indices start and end.
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (a[mid] == x)
        {
            return mid;
        }
        else if (x >= a[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int ExpSearch(int a[], int n, int x)
{
    if (a[0] == x)
        return 0;
    // ExpSearch function searches for x in array a[] of size n.

    int i = 1;
    while (i < n && a[i] <= x)
    {
        i = i * 2; // i*=2 // i << 1;
    }
    // exponential search phase starts with i = 1 and increases i exponentially (i *= 2)
    // This phase finds a range [i/2, i] where x might be located or stops when i exceeds n
    return bs(a, i / 2, min(i, n - 1), x);
    // binary search is performed within the determined range [i/2, min(i, n - 1)] using the bs function.
}

int main()
{
    int a[] = {3, 4, 5, 6, 11, 13, 14, 15, 56, 70};
    int n = sizeof(a) / sizeof(int);
    int x = 13;

    int ans = ExpSearch(a, n, x);
    cout << "Index is at: " << ans << endl;
    cout << "value is: " << a[ans] << endl;
    return 0;
}