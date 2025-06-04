// #include <iostream>
// #include <vector>
// using namespace std;

// int solveUsingRecursion(int n, int k)
// {
//     // Base case
//     if (n == 1)
//     {
//         return k;
//     }

//     if (n == 2)
//     {
//         return (k + k * (k - 1));
//     }

//     int ans = ((solveUsingRecursion(n - 2, k) + solveUsingRecursion(n - 1, k))) * (k - 1);
//     return ans;
// }

// // Solving using 1-D DP
// int solveUsingMem(int n, int k, vector<int> &dp)
// {
//     // Base case
//     if (n == 1)
//     {
//         return k;
//     }

//     if (n == 2)
//     {
//         return (k + k * (k - 1));
//     }

//     if (dp[n] != -1)
//         return dp[n];

//     dp[n] = ((solveUsingMem(n - 2, k, dp) + solveUsingMem(n - 1, k, dp))) * (k - 1);
//     return dp[n];
// }
// int solveUsingTab(int n, int k)
// {
//     vector<int> dp(n + 1, -1);
//     dp[1] = k;
//     dp[2] = (k + k * (k - 1));

//     for (int i = 3; i <= n; i++)
//     {
//         dp[i] = (dp[i - 2] + dp[i - 1]) * (k - 1);
//     }
//     return dp[n];
// }

// int solveSO(int n, int k)
// {
//     if (n == 1)
//         return k;
//     if (n == 2)
//         return k + k * (k - 1);

//     int prev2 = k;
//     int prev1 = (k + k * (k - 1));

//     for (int i = 3; i <= n; i++)
//     {
//         int curr = (prev2 + prev1) * (k - 1);

//         // shifting logic
//         prev2 = prev1;
//         prev1 = curr;
//     }
//     return prev1;
// }

// int main()
// {
//     int n = 4;
//     int k = 3;

//     // int ans = solveUsingRecursion(n, k);

//     vector<int> dp(n + 1, -1);
//     int ans = solveUsingMem(n, k, dp);

//     // int ans = solveUsingTab(n, k);

//     // int ans = solveSO(n, k);
//     cout << "Ans: " << ans << endl;

//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

// index = index of last element
int solveUsingRecursion(int weight[], int value[], int index, int capacity)
{
    // base case -> only 1 item
    if (index == 0)
    {
        if (weight[0] <= capacity)
        {
            return value[0];
        }
        else
            return 0;
    }

    // include and exclude
    int include = 0;
    if (weight[index] <= capacity)
        include = value[index] + solveUsingRecursion(weight, value, index - 1, capacity - weight[index]);

    int exclude = 0 + solveUsingRecursion(weight, value, index - 1, capacity);

    int ans = max(include, exclude);
    return ans;
}

int solveUsingMem(int weight[], int value[], int index, int capacity, vector<vector<int>> &dp)
{
    // base case -> only 1 item
    if (index == 0)
    {
        if (weight[0] <= capacity)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }
    if (dp[index][capacity] != -1)
        return dp[index][capacity];

    // include and exclude
    int include = 0;
    if (weight[index] <= capacity)
        include = value[index] + solveUsingMem(weight, value, index - 1, capacity - weight[index], dp);

    int exclude = 0 + solveUsingMem(weight, value, index - 1, capacity, dp);

    dp[index][capacity] = max(include, exclude);
    return dp[index][capacity];
}

int solveUsingTabulation(int weight[], int value[], int n, int capacity)
{
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            dp[0][w] = value[0];
        }
        else
        {
            dp[0][w] = 0;
        }
    }

    for (int index = 1; index < n; index++)
    {
        for (int wt = 0; wt <= capacity; wt++)
        {
            // include and exclude
            int include = 0;
            if (weight[index] <= wt)
                include = value[index] + dp[index - 1][wt - weight[index]];

            int exclude = 0 + dp[index - 1][wt];

            dp[index][wt] = max(include, exclude);
        }
    }
    return dp[n - 1][capacity];
}
int solveUsingSO(int weight[], int value[], int n, int capacity)
{
    vector<int> prev(capacity + 1, 0);
    vector<int> curr(capacity + 1, 0);

    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            prev[w] = value[0];
        }
        else
        {
            prev[w] = 0;
        }
    }

    for (int index = 1; index < n; index++)
    {
        for (int wt = 0; wt <= capacity; wt++)
        {
            // include and exclude
            int include = 0;
            if (weight[index] <= wt)
                include = value[index] + prev[wt - weight[index]];

            int exclude = 0 + prev[wt];

            curr[wt] = max(include, exclude);
        }
        // shifting logic
        prev = curr;
    }
    return prev[capacity];
}

int main()
{
    int weight[] = {4, 5, 1};
    int value[] = {1, 2, 3};
    int n = 3;
    int capacity = 4;

    // int ans = solveUsingRecursion(weight, value, n - 1, capacity);

    // vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
    // int ans = solveUsingMem(weight, value, n - 1, capacity, dp);

    // int ans = solveUsingTabulation(weight, value, n, capacity);

    int ans = solveUsingSO(weight, value, n, capacity);

    cout << "Ans: " << ans << endl;
    return 0;
}

// GFG code using recursion Knapsack problem
// class Solution
// {
// public:
//     int knapsack(int capacity, vector<int> &value, vector<int> &weight)
//     {
//         // code here
//         int index = value.size();
//         return helper(capacity, value, weight, index - 1);
//     }

// private:
//     int helper(int capacity, vector<int> &value, vector<int> &weight, int index)
//     {
//         // base case
//         if (index == 0)
//         {
//             if (weight[0] <= capacity)
//                 return value[0];
//             else
//                 return 0;
//         }

//         // include and exclude
//         int include = 0;
//         if (weight[index] <= capacity)
//             include = value[index] + helper(capacity - weight[index], value, weight, index - 1);

//         int exclude = helper(capacity, value, weight, index - 1);

//         int ans = max(include, exclude);
//         return ans;
//     }
// };

// GFG problem solveUsingMem
// class Solution
// {
// public:
//     int knapsack(int capacity, vector<int> &value, vector<int> &weight)
//     {
//         // code here
//         int index = value.size();
//         vector<vector<int>> dp(index, vector<int>(capacity + 1, -1));
//         return helper(capacity, value, weight, index - 1, dp);
//     }

// private:
//     int helper(int capacity, vector<int> &value, vector<int> &weight, int index, vector<vector<int>> &dp)
//     {
//         // base case
//         if (index == 0)
//         {
//             if (weight[0] <= capacity)
//                 return value[0];
//             else
//                 return 0;
//         }

//         if (dp[index][capacity] != -1)
//             return dp[index][capacity];

//         // include and exclude
//         int include = 0;
//         if (weight[index] <= capacity)
//             include = value[index] + helper(capacity - weight[index], value, weight, index - 1, dp);

//         int exclude = helper(capacity, value, weight, index - 1, dp);

//         dp[index][capacity] = max(include, exclude);
//         return dp[index][capacity];
//     }
// };

// GFG using solveUsingTabulation
// int knapsack(int capacity, vector<int> &value, vector<int> &weight)
// {
//     //     int n = value.size();
//     //     vector<vector<int>> dp(n,vector<int>(capacity + 1,0));

//     //     for(int w = weight[0]; w <= capacity; w++)
//     //         {
//     //             if (weight[0] <= capacity)
//     //         {
//     //             dp[0][w] = value[0];
//     //         }
//     //         else
//     //         {
//     //             dp[0][w] = 0;
//     //         }
//     //     }
//     //     for(int index = 1; index < n; index++)
//     //     {
//     //         for(int wt = 0; wt<=capacity; wt++)
//     //         {
//     //             // include and exclude
//     //         int include = 0;
//     //         if (weight[index] <= wt)
//     //             include = value[index] + dp[index - 1][wt - weight[index]];

//     //         int exclude = 0 + dp[index - 1][wt];

//     //         dp[index][wt] = max(include, exclude);
//     //         }
//     //     }
//     //     return dp[n - 1][capacity];
//     // }

// using solveUsingSO
// int knapsack(int capacity, vector<int> &value, vector<int> &weight)
// {
//     vector<int> prev(capacity + 1, 0);
//     vector<int> curr(capacity + 1, 0);
//     int n = value.size();

//     // Base case: only the 0th item
//     for (int w = 0; w <= capacity; w++)
//     {
//         if (weight[0] <= w)
//             prev[w] = value[0];
//     }

//     // Build the dp table row by row
//     for (int index = 1; index < n; index++)
//     {
//         for (int wt = 0; wt <= capacity; wt++)
//         {
//             int include = 0;
//             if (weight[index] <= wt)
//                 include = value[index] + prev[wt - weight[index]];

//             int exclude = prev[wt];
//             curr[wt] = max(include, exclude);
//         }
//         prev = curr; // move to next item
//     }

//     return prev[capacity];
// }