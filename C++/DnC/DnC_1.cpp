// Merge sort in non sorted array

#include <iostream>
using namespace std;

void merge(int *arr, int s, int e)
{
    int mid = s + (e - s) / 2;

    int len1 = mid - s + 1; // 3 - 0 + 1
    int len2 = e - mid;

    // assume to create a new array
    int *left = new int[len1];
    int *right = new int[len2];

    // copy values into SubArray
    int k = s;
    for (int i = 0; i < len1; i++)
    {
        left[i] = arr[k];
        k++;
    }

    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        right[i] = arr[k];
        k++;
    }

    // merge logic(Merging of 2 SubArray)
    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = s;

    // Compares elements from left and right subarrays. The smaller element is added to the main array, and its respective index is incremented.
    while (leftIndex < len1 && rightIndex < len2)
    {
        if (left[leftIndex] < right[rightIndex])
        {
            arr[mainArrayIndex++] = left[leftIndex++];
        }
        else
        {
            arr[mainArrayIndex++] = right[rightIndex++];
        }
    }

    // copy logic for left array
    while (leftIndex < len1)
    {
        arr[mainArrayIndex++] = left[leftIndex++];
    }

    // copy logic for right array
    while (rightIndex < len2)
    {
        arr[mainArrayIndex++] = right[rightIndex++];
    }
}
// In C++, we didn't use int& arr instead of int* arr in the above code because arrays cannot be passed as references directly
void mergeSort(int *arr, int s, int e)
{
    // base case
    // s==e -> single element
    // s>e -> Invalid element
    if (s >= e)
        return;

    // middle element
    int mid = s + (e - s) / 2;

    // left part ko solve krna
    mergeSort(arr, s, mid);

    // right part ko solve krna
    mergeSort(arr, mid + 1, e);

    // now merge 2 sorted array
    merge(arr, s, e);
}

int main()
{
    int arr[] = {2, 3, 1, 66, 54, 32, 68, 55};
    int n = 8;

    int s = 0;
    int e = n - 1;
    mergeSort(arr, s, e);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}