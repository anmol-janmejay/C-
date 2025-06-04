// Check if Number is Prime or Not

// class Solution
// {
// public:
//     bool isPrime(int n)
//     {
//         if (n <= 1)
//             return false;

//         for (int i = 2; i < n; i++)
//         {
//             if (n % i == 0)
//             {
//                 return false;
//             }
//         }
//         return true;
//     }

//     int countPrimes(int n)
//     {
//         int c = 0;
//         for (int i = 0; i < n; i++)
//         {
//             if (isPrime(i))
//             {
//                 ++c;
//             }
//         }
//         return c;
//     }
// };

// class Solution
// {
// public:

//     int countPrimes(int n)
//     {
//         // Sieve of Erathosthenes
//         if (n == 0)
//             return 0;

//         vector<bool> prime(n, true); // All are marked as prime already.
//         prime[0] = prime[1] = false;

//         int ans = 0;
//         for (int i = 2; i < n; i++)
//         {
//             if (prime[i])
//             {
//                 ans++;

//                 int j = 2 * i;
//                 while (j < n)
//                 {
//                     prime[j] = false;
//                     j += i;
//                 }
//             }
//         }
//         return ans;
//     }
// };

// GCD of two Number

// class Solution
// {
// public:
//     int gcd(int a, int b)
//     {
//         // code here
//         if (a == 0)
//             return b;
//         if (b == 0)
//             return a;
// If one of the numbers is 0, the GCD is the other number(since any number divides 0)
//         while (a > 0 && b > 0)
//         {
//             if (a > b)
//             {
//                 a = a - b;
//             }
//             else
//             {
//                 b = b - a;
//             }
//         }
//         return a == 0 ? b : a;
// When one of the numbers becomes zero, return the other number as the GCD.
//     }
// };

// Fast Exponentation
// #include <iostream>
// using namespace std;

// int fastExplonentation(int a, int b)
// {
//     int ans = 1;
//     while (b > 0)
//     {
//         if (b & 1) // Using BitWise AND Operator to depict if least significant Bit of b is 1...If b&1 evaluate to true, it means b is odd
//                    // odd
//         {
//             ans = ans * a;
//         }
//         a = a * a;
//         b >>= 1;
//         // Right - shift the binary representation of b by 1 bit, effectively dividing it by 2.
//     }
//     return ans;
// } // o(logb)

// // int slowExplonentation(int a, int b)
// // {
// //     int ans = 1;
// //     for (int i = 0; i < b; i++)
// //     {
// //         ans = ans * a;
// //     }
// //     return ans;
// // } //o(b)

// int main()
// {
//     // cout << slowExplonentation(5, 4) << endl;
//     cout << fastExplonentation(5, 4) << endl;
//     return 0;
// }

class Solution
{
public:
    long long int PowMod(long long int x, long long int n, long long int M)
    {
        // Code here
        long long int ans = 1;

        while (n > 0)
        {
            if (n & 1)
            {
                ans = (ans * x) % M;
            }
            x = (x * x) % M;
            n >>= 1;
        }
        return ans % M;
    }
};
