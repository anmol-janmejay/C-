// #include <iostream>
// using namespace std;

// void print(int arr[], int n, int i)
// {
//     // Base Case
//     if (i >= n)
//     {
//         return;
//     }

//     // 1 case solve krdo
//     cout << arr[i] << " ";
//     // Baaki recursion sambhal lega
//     print(arr, n, i + 1);
// }

// int main()
// {
//     int arr[5] = {10, 20, 30, 40, 50};
//     int n = 5;
//     int i = 0;

//     print(arr, n, i);
//     return 0;
// }

// #include <iostream>
// using namespace std;

// void findMax(int arr[], int n, int i, int &max)
// {
//     // Base case
//     if (i >= n)
//     {
//         return;
//     }

//     // recursive relation
//     if (arr[i] > max)
//     {
//         max = arr[i];
//     }

//     // Processing
//     findMax(arr, n, i + 1, max);
// }

// int main()
// {
//     int arr[] = {10, 30, 21, 42, 66, 54, 67, 43};
//     int n = 8;

//     int max = INT32_MIN;

//     int i = 0;
//     findMax(arr, n, i, max);

//     cout << "Maximum Value in Array is: " << max << endl;
//     return 0;
// }

// #include <iostream>
// using namespace std;

// bool findKey(string str, int n, int i, char key)
// {
//     // Base Case
//     if (i >= n)
//     {
//         return false;
//     }
//     // 1 case sambhal lena hai
//     if (str[i] == key)
//     {
//         return true;
//     }
//     // Baaki recursion sambhal lega
//     return findKey(str, n, i + 1, key);
// }

// int main()
// {
//     string str = "anmoljanmejay";
//     int n = str.length();

//     char key = 'a';
//     int i = 0;

//     bool ans = findKey(str, n, i, key);

//     cout << "Answer is: " << ans << endl;
// }

#include <iostream>
using namespace std;

void printDigits(int n)
{
    // Base case
    if (n == 0)
    {
        return;
    }

    int newValueofN = n / 10;
    // baaki recursion sambhal lega
    printDigits(n / 10);

    // 1 case khud solve krna hai
    int digit = n % 10;
    cout << digit << " ";
}

int main()
{
    int n = 647;
    printDigits(n);

    return 0;
}

// Step-by-Step Execution for 𝑛 = 647
// n = 647:
// Initial Call: printDigits(647)
// 𝑛 ≠ 0 Recursive call printDigits(64) is made.
// Second Call: printDigits(64)
// 𝑛 ≠ 0 Recursive call printDigits(6) is made.
// Third Call: printDigits(6)
// 𝑛 ≠ 0 Recursive call printDigits(0) is made.
// Fourth Call: printDigits(0)
// 𝑛 = 0
// n=0: Base case is reached, and the function returns.
// Unwinding the Recursion:
// Back in the third call : Extracts 6 using n % 10 and prints it.Back in the second call : Extracts 4 and prints it.Back in the initial call : Extracts 7 and prints it