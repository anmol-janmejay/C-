// #include <iostream>
// using namespace std;

// // Recursive function to calculate factorial
// int factorial(int n)
// {
//     // Base case: factorial of 0 or 1 is 1
//     if (n == 0 || n == 1)
//     {
//         return 1;
//     }
//     // Recursive case: n * factorial of (n-1)
//     return n * factorial(n - 1);
// }

// int main()
// {
//     int number;
//     cout << "Enter a positive integer: ";
//     cin >> number;

//     // Call the recursive function and display the result
//     cout << "Factorial of " << number << " is: " << factorial(number) << endl;

//     return 0;
// }

// #include <iostream>
// using namespace std;

// int factorial(int n)
// {
//     cout << "Function is called for n: " << n << endl;

//     // Base case
//     if (n == 1)
//         return 1;

//     int chotiProblemAns = factorial(n - 1);
//     int badiProblemAns = n * chotiProblemAns;
//     return badiProblemAns;
// }

// int main()
// {
//     int n;
//     cout << "Enter the Given value of n: " << endl;
//     cin >> n;

//     int ans = factorial(n);
//     cout << "Factorial of a Number is: " << ans << endl;
// }

// #include <iostream>
// using namespace std;

// void printCounting(int n)
// {
//     // Base case
//     if (n == 0)
//     {
//         return;
//     }

//     // Processing
//     cout << n << " ";

//     // Recursive relation
//     printCounting(n - 1);
// }

// int main()
// {
//     int n;
//     cout << "Enter the Value of n" << endl;
//     cin >> n;

//     printCounting(n);
//     return 0;
// }

// Fibonacci Sequence
#include <iostream>
using namespace std;

int fibonacciSequence(int n)
{
    // base case
    if (n == 1)
    {
        // First term
        return 0;
    }
    if (n == 2)
    {
        // Second term
        return 1;
    }

    // Recursive relation
    int ans = fibonacciSequence(n - 1) + fibonacciSequence(n - 2);

    // Processing
    return ans;
}

int main()
{
    int n;
    cout << "Enter the Value of Given Number: " << endl;
    cin >> n;

    int ans = fibonacciSequence(n);
    cout << n << "th term is: " << ans << endl;

    return 0;
}