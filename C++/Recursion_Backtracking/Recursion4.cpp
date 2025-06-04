// #include <iostream>
// #include <vector>
// #include <limits.h>
// using namespace std;

// int solve(vector<int> &arr, int target)
// {
//     // base case
//     if (target == 0)
//     {
//         return 0;
//     }
//     if (target < 0)
//     {
//         return INT_MAX;
//     }
//     // Lets solve 1 case
//     int mini = INT_MAX;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         int ans = solve(arr, target - arr[i]);
//         if (ans != INT_MAX)
//             mini = min(mini, ans + 1);
//     }
//     return mini;
// }

// int main()
// {
//     vector<int> arr{1, 2};
//     int target = 5;

//     int ans = solve(arr, target);
//     cout << "Answer is: " << ans << endl;
//     return 0;
// }

// #include <iostream>
// #include <limits.h>
// using namespace std;

// // Function to find the maximum number of segments
// int solve(int n, int x, int y, int z)
// {
//     // Base case: If the length is exactly 0, we need 0 segments
//     if (n == 0)
//     {
//         return 0;
//     }

//     // Base case: If the length becomes negative, it's not a valid solution
//     if (n < 0)
//     {
//         return INT_MIN; // Representing an invalid state
//     }

//     // Recursive calls for each segment
//     int a = solve(n - x, x, y, z);
//     int b = solve(n - y, x, y, z);
//     int c = solve(n - z, x, y, z);

//     // Compute the maximum of the three results
//     int max_segments = max(a, max(b, c));

//     // If the maximum is still invalid, return INT_MIN; otherwise, add 1 to count this segment
//     return max_segments == INT_MIN ? INT_MIN : max_segments + 1;
// }

// int main()
// {
//     int n = 7;
//     int x = 5;
//     int y = 2;
//     int z = 2;

//     // Solve function -> returns maximum number of segments
//     int ans = solve(n, x, y, z);

//     // If ans is INT_MIN, it means no valid segmentation is possible
//     if (ans == INT_MIN)
//     {
//         cout << "Answer is: 0" << endl;
//     }
//     else
//     {
//         cout << "Answer is: " << ans << endl;
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

void solve(vector<int> &arr, int i, int sum, int &maxi)
{
    // base case
    if (i >= arr.size())
    {
        // maxi update
        maxi = max(sum, maxi);
        return;
    }

    // include
    solve(arr, i + 2, sum + arr[i], maxi);
    // exclude
    solve(arr, i + 1, sum, maxi);
}

int main()
{
    vector<int> arr{2, 1, 4, 9};
    int sum = 0;
    int maxi = INT_MIN;
    int i = 0;

    solve(arr, i, sum, maxi);
    cout << "Answer is: " << maxi << endl;

    return 0;
}
