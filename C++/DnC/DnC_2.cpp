// #include <iostream>
// #include <vector>
// using namespace std;

// // Function to partition the array
// int partition(vector<int> &arr, int low, int high)
// {
//     int pivot = arr[high]; // Pivot element (last element)
//     int i = low - 1;       // Pointer for the smaller element

//     for (int j = low; j < high; j++)
//     {
//         // If the current element is smaller than or equal to the pivot
//         if (arr[j] <= pivot)
//         {
//             i++;                  // Increment the index for the smaller element
//             swap(arr[i], arr[j]); // Swap elements
//         }
//     }

//     // Place the pivot in its correct position
//     swap(arr[i + 1], arr[high]);
//     return i + 1; // Return the pivot index
// }

// int main()
// {
//     vector<int> arr = {10, 7, 8, 9, 1, 5};
//     int low = 0;
//     int high = arr.size() - 1;

//     int pivotIndex = partition(arr, low, high);

//     cout << "Partitioned array: ";
//     for (int num : arr)
//     {
//         cout << num << " ";
//     }
//     cout << "\nPivot index: " << pivotIndex << endl;

//     return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;

// int partition(int arr[], int s, int e)
// {
//     // step 1:- choose pivot element
//     int pivotIndex = s;
//     int pivotElement = arr[s];

//     // Step 2:- Find right position of pivot element and place it there
//     int count = 0;
//     for (int i = s + 1; i <= e; i++)
//     {
//         if (arr[i] <= pivotElement)
//         {
//             count++;
//         }
//     }
//     // jab main loop se bahar aaya toh mere pas pivot ki right position ka index ready hai
//     int rightIndex = s + count; // For example if i have 10 person who has small height then i should be standing in 11 position
//     swap(arr[pivotIndex], arr[rightIndex]);
//     pivotIndex = rightIndex;

//     // Step 3: Now we have to arrange element in right order
//     int i = s;
//     int j = e;

//     while (i < pivotIndex && j > pivotIndex)
//     {
//         while (arr[i] < pivotElement)
//         {
//             i++;
//         }
//         while (arr[j] > pivotElement)
//         {
//             j--;
//         }

//         // 2 case ho skta hai ki
//         // A. we found the element to swap
//         // B. No need to swap

//         if (i < pivotIndex && j > pivotIndex)
//             swap(arr[i], arr[j]);
//     }
//     return pivotIndex;
// }

// void quickSort(int arr[], int s, int e)
// {
//     // base case
//     // s = e then they are already sorted
//     // if s > e then that is invalid index
//     if (s >= e)
//         return;

//     // paritition logic
//     int p = partition(arr, s, e);

//     // recursive call
//     // left sort
//     quickSort(arr, s, p - 1);

//     // right sort
//     quickSort(arr, p + 1, e);
// }

// int main()
// {
//     int arr[] = {10, 1, 3, 4, 20, 50, 30};
//     int n = 7;

//     int s = 0;
//     int e = n - 1;

//     quickSort(arr, s, e);

//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

#include <iostream>
#include <vector>
using namespace std;

void printPermutation(string &str, int i)
{
    // base case
    if (i >= str.length())
    {
        cout << str << " ";
        return;
    }

    // swapping
    for (int j = i; j < str.length(); j++)
    {
        // swap
        swap(str[i], str[j]);
        // recall
        printPermutation(str, i + 1);

        // backTracking
        swap(str[i], str[j]);
    }
}

int main()
{
    string str = "abc";
    int i = 0;

    printPermutation(str, i);
    return 0;
}