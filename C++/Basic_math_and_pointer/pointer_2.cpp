#include <iostream>
using namespace std;

void solve(int arr[], int size) // Add size as a parameter
{
    cout << "size inside solve Function:- " << size << "Bytes" << endl;
}

int main()
{
    // int arr[4] = {12, 44, 66, 20};
    // cout << *arr << endl;
    // cout << *arr + 1 << endl;
    // cout << *arr + 2 << endl;
    // cout << *(arr + 1) << endl;
    // cout << *(arr + 2) << endl;
    // cout << *(arr + 3) << endl;
    // cout << *(arr + 4) << endl;

    int arr[10] = {1, 2, 3, 4};
    cout << "Size inside main function:- " << sizeof(arr) << "Bytes" << endl;

    // creating solve function
    solve(arr, sizeof(arr));

    return 0;
}