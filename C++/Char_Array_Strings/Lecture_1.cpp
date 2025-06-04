#include <iostream>
#include <cstring>
using namespace std;

// int main()
// {
// char name[100];
// cout << "Enter Your Name: " << endl;
// cin >> name;

// int n = strlen(name); // read the entire line including spaces

// for (int i = 0; i < n; i++)
// {
//     cout << "Character at Index " << i << " :" << name[i] << endl;
// }

// int value = (int)name[2];
// cout << "Value is: " << value << endl;
// if (value == 0)
// {
//     cout << "Null Character";
// }
// else
// {
//     cout << "Not a Null Character";
// }

// char arr[100];
// cin.getline(arr, 100);

// cout << "Output is: " << arr << endl;

// return 0;
// }

// Reverse a string

// Function
// void reverseString(char name[], int n)
// {
//     int start = 0;
//     int end = n - 1;
//     while (start < end)
//     {
//         swap(name[start], name[end]);
//         start++;
//         end--;
//     }
// }
// void palindrome(char name[], int n)
// {
//     int start = 0;
//     int end = n - 1;
//     bool isPalindrome = true;

//     while (start < end)
//     {
//         if (name[start] != name[end])
//         {
//             isPalindrome = false;
//             break;
//         }
//         start++;
//         end--;
//     }
//     if (isPalindrome)
//     {
//         cout << "It is a Palindrome" << endl;
//     }
//     else
//     {
//         cout << "It is not a Palindrome" << endl;
//     }
// }

// int main()
// {
//     char name[100];
//     cout << "Enter the Value: " << endl;
//     cin >> name;
//     int n = strlen(name);

//     // reverseString(name, n);
//     // cout << "Reverse String is:" << name << endl;
//     palindrome(name, n);
//     return 0;
// }

// Convert a string to Upper case

// void convertUpperCase(char arr[])
// {
//     int n = strlen(arr);
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] >= 'a' && arr[i] <= 'z') // Check if the character is lower case character
//         {
//             arr[i] = arr[i] - 'a' + 'A'; // convert to Upper Case
//         }
//     }
// }

// int main()
// {

//     char arr[100] = "anmoz";
//     convertUpperCase(arr);
//     cout << arr << endl;

//     return 0;
// }

int main()
{
    // create string
    string str;
    // input in string
    // cin >> str;
    // input of spaces
    getline(cin, str);
    // print
    cout << "String: " << str << endl;

    cout << "Length: " << str.length() << endl;
    cout << "isEmpty: " << str.empty() << endl;
    cout << "Substring: " << str.substr(0, 5) << endl;
    return 0;
}