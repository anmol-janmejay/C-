#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
using namespace std;

// void printRowWiseSum(int arr[][3], int rows, int cols)
// // Row sum -> Row-wise Transversal
// {
//     for (int i = 0; i < rows; i++)
//     {
//         int sum = 0;
//         for (int j = 0; j < cols; j++)
//         {
//             sum = sum + arr[i][j];
//         }
//         cout << sum << endl;
//     }
// }

// Searching in Array
// bool findKey(int arr[][3], int rows, int cols, int key)
// {
//     for (int i = 0; i < rows; i++)
//     {
//         for (int j = 0; j < cols; j++)
//         {
//             if (arr[i][j] == key)
//                 return true;
//         }
//     }
//     return false;
// }

// Finding the Maximum Number
// int getMAX(int arr[][3], int rows, int cols)
// {
//     int maxi = INT_MIN;
//     for (int i = 0; i < rows; i++)
//     {
//         for (int j = 0; j < cols; j++)
//         {
//             if (arr[i][j] > maxi)
//             {
//                 maxi = arr[i][j];
//             }
//         }
//     }
//     return maxi;
// }

// int main()
// {
//     // Declare 2D Array
//     int arr[3][3];
//     int rows = 3;
//     int cols = 3;

//     // initialization
//     // int brr[3][3] = {{1, 2, 3}, {4, 5, 6}, {2, 4, 8}};

//     // Taking Input
//     // Row wise Input
//     for (int i = 0; i < rows; i++)
//     {
//         for (int j = 0; j < cols; j++)
//         {
//             cin >> arr[i][j];
//         }
//     }

//     // // Row Wise Print
//     // // Outer loop
//     cout << "Printing Row wise: " << endl;
//     for (int i = 0; i < rows; i++)
//     {
//         for (int j = 0; j < cols; j++)
//         {
//             cout << arr[i][j] << " ";
//         }
//         cout << endl;
//     }

// // Column Wise Print
// // Outer loop
// cout << "Printing Column wise: " << endl;
// for (int i = 0; i < 3; i++)
// {
//     for (int j = 0; j < 3; j++)
//     {
//         cout << brr[j][i] << " ";
//     }
//     cout << endl;
// }

// printRowWiseSum(arr, rows, cols);

// return 0;
// }

// int main()
// {
//     // Declare and Initialization 2D Array
//     int brr[3][3] = {{1, 2, 3}, {4, 5, 6}, {2, 4, 8}};
//     int rows = 3;
//     int cols = 3;

//     for (int i = 0; i < rows; i++)
//     {
//         for (int j = 0; j < cols; j++)
//         {
//             cout << brr[i][j] << " ";
//         }
//         cout << endl;
//     }

// Search for the key in brr
// int key = 5;
// if (findKey(brr, 3, 3, key))
// {
//     cout << "True" << endl;
// }
// else
// {
//     cout << "False" << endl;
// }

// Search the MAX
// cout << "Max Number: " << getMAX(brr, rows, cols);

//     return 0;
// }

// Making 4*3 Matrix
int main()
{
    vector<vector<int>> arr;

    vector<int> a{1, 2, 3};
    vector<int> b{2, 4, 6, 8, 9};
    vector<int> c{1, 3, 7, 5};

    arr.push_back(a);
    arr.push_back(b);
    arr.push_back(c);

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}