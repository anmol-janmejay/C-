// Code to Find the Unique Element
#include <iostream>
#include <vector>
using namespace std;

// int findUnique(vector<int> arr) {
//     int ans = 0;
//     for (int i = 0; i < arr.size(); i++) {
//         ans = ans ^ arr[i];  // XOR operation to find the unique element
//     }
//     return ans;
// }

// int main() {
//     int n;
//     cout << "Enter the Size of an Array: " << endl;
//     cin >> n;

//     vector<int> arr(n);
//     cout << "Enter the Elements: " << endl;

//     // Taking input for the array
//     for (int i = 0; i < arr.size(); i++) {
//         cin >> arr[i];
//     }

//     int uniqueElement = findUnique(arr);

//     cout << "Unique Element is " << uniqueElement << endl;

//     return 0;
// }

// Union Of Two Array

// int main()
// {

//     int arr[] = {1, 3, 5, 7, 9};
//     int sizea = 5;
//     int brr[] = {2, 4, 6, 8};
//     int sizeb = 4;

//     vector<int> ans;

//     // push all the elements of Vector arr
//     for (int i = 0; i < sizea; i++)
//     {
//         ans.push_back(arr[i]);
//     }

//     // push all the elements of Vector brr
//     for (int i = 0; i < sizeb; i++)
//     {
//         ans.push_back(brr[i]);
//     }

//     for (int i = 0; i < ans.size(); i++)
//     {
//         cout << ans[i] << endl;
//     }

//     return 0;
// }

// Intersection of an Array

// int main()
// {
//     vector<int> arr{1, 3, 4, 5, 6, 8};
//     vector<int> brr{3, 4, 8};

//     vector<int> ans;

//     for (int i = 0; i < arr.size(); i++)
//     {
//         int element = arr[i];
//         // for every element, run loop on brr
//         for (int j = 0; j < brr.size(); j++)
//         {
//             if (element == brr[j])
//             {
//                 ans.push_back(element);
//             }
//         }
//     }

//     // print answer
//     for (auto value : ans)
//     {
//         cout << value << " ";
//     }
// }

// Pair sum
// int main()
// {
//     vector<int> arr{10, 20, 30, 40, 50, 60, 70};
//     int sum = 80;

//     //  Print all the Pairs
//     // outer loop will transverse to each element

//     for (int i = 0; i < arr.size(); i++)
//     {
//         int element = arr[i];

//         // for every element transverse to next element
//         for (int j = i + 1; j < arr.size(); j++)
//         {
//             if (element + arr[j] == sum)
//             {
//                 cout << "Pair Found: " << "(" << element << "," << arr[j] << ")" << endl;
//             }
//             // cout << "(" << element << "," << arr[j] << ")" << endl;
//         }
//     }
//     return 0;
// }

// Triplet Sum
// int main()
// {
//     vector<int> arr{10, 20, 30, 40, 50, 60, 70};
//     int sum = 80;

//     for (int i = 0; i < arr.size(); i++)
//     {
//         int element = arr[i];
//         for (int j = i + 1; j < arr.size(); j++)
//         {
//             int element1 = arr[j];
//             for (int k = j + 1; k < arr.size(); k++)
//             {
//                 if (element1 + element + arr[k] == sum)
//                 {
//                     cout << "Triplet Found: ( " << element << "," << element1 << "," << arr[k] << ")" << endl;
//                 }
//             }
//         }
//     }
//     return 0;
// }

// sort 0 and 1

int main()
{
    vector<int> arr{0, 1, 0, 1, 1, 0, 1, 0, 0, 1};

    int start = 0;
    int end = arr.size() - 1;
    int i = 0;

    while (start <= end)
    {
        if (arr[i] == 0)
        {
            // Swap from left
            swap(arr[start], arr[i]);
            i++;
            start++;
        }
        else
        {
            // Swap from Right
            swap(arr[i], arr[end]);
            end--;
        }
    }
    for (auto value : arr)
    {
        cout << value << " ";
    }
}