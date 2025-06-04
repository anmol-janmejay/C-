#include <iostream>
using namespace std;

// // Function
// int findSqrt(int n)
// {

//     int start = 0;
//     int end = n;
//     int mid = start + (end - start) / 2;
//     int target = n;
//     int ans = -1;

//     while (start <= end)
//     {
//         if (mid * mid == target)
//             return mid;

//         if (mid * mid > target)
//         {
//             // Left search
//             end = mid - 1;
//         }
//         else
//         {
//             // Answer store
//             ans = mid;
//             // /Right search/
//             start = mid + 1;
//         }

//         mid = start + (end - start) / 2;
//     }
//     return ans;
// }

// int main()
// {
//     int n;
//     cout << "Enter the Number: " << endl;
//     cin >> n;

//     int ans = findSqrt(n);
//     cout << "Answer is: " << ans << endl;

//     int precision;
//     cout << "Enter the Precision Value we want: " << endl;
//     cin >> precision;

//     double step = 0.1;
//     // step = 0.1 : A variable step is initialized to 0.1. It controls how much the algorithm adjusts finalAns during each iteration to get more precise values.
//     double finalAns = ans;
//     // finalAns = ans : Initializes finalAns with the integer square root calculated previously.

//     for (int i = 0; i < precision; i++)
//     {
//         for (double j = finalAns; j * j <= n; j = j + step)
//         {
//             finalAns = j;
//             // Adjusts j by adding step to get a more precise approximation.
//         }
//         step = step / 10;
//         // After each iteration of the outer loop, step is divided by 10, moving from 0.1 to 0.01 to 0.001, and so on.
//     }
//     cout << "Final Answer is: " << finalAns << endl;

//     return 0;
// }

// 2D Binary Search

// Function
bool binarySearch(int arr[][4], int rows, int cols, int target)
{
    int start = 0;
    int end = rows * cols - 1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        int rowIndex = mid / cols;
        // rowIndex = mid / cols: Calculates the row index by dividing mid by cols.
        int colIndex = mid % cols;
        // colIndex = mid % cols : Calculates the column index by taking the remainder when mid is divided by cols.

        if (arr[rowIndex][colIndex] == target)
        {
            cout << "Found at: {" << rowIndex << "," << colIndex << "}" << endl;
            return true;
        }
        if (arr[rowIndex][colIndex] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return false;
}

int main()
{
    int arr[5][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}, {17, 18, 19, 20}};
    int rows = 5;
    int cols = 4;

    int target = 19;

    bool ans = binarySearch(arr, rows, cols, target);

    if (ans)
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }
}