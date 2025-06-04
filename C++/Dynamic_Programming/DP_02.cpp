// class Solution
// {
// public:
//     int solveUsingRecursion(vector<int> &coins, int amount)
//     {
//         // base case
//         if (amount == 0)
//         {
//             return 0;
//         }
//         if (amount < 0)
//         {
//             return INT_MAX;
//         }

//         int mini = INT_MAX;
//         for (int i = 0; i < coins.size(); i++)
//         {
//             int ans = solveUsingRecursion(coins, amount - coins[i]);
//             if (ans != INT_MAX)
//             {
//                 mini = min(mini, 1 + ans);
//             }
//         }
//         return mini;
//     }

//     int solveMem(vector<int> &coins, int amount, vector<int> &dp)
//     {
//         // base case
//         if (amount == 0)
//         {
//             return 0;
//         }
//         if (amount < 0)
//         {
//             return INT_MAX;
//         }
//         // ans already exists
//         if (dp[amount] != -1)
//         {
//             return dp[amount];
//         }

//         int mini = INT_MAX;
//         for (int i = 0; i < coins.size(); i++)
//         {
//             int ans = solveMem(coins, amount - coins[i], dp);
//             if (ans != INT_MAX)
//             {
//                 mini = min(mini, 1 + ans);
//             }
//         }
//         dp[amount] = mini;
//         return dp[amount];
//     }

//     int solveTab(vector<int> &coins, int amount)
//     {
//         // step1: create dp array
//         vector<int> dp(amount + 1, INT_MAX);
//         // step2: base case dekho
//         dp[0] = 0;
//         // step3: check the range and flow of top down approach and code accordingly
//         for (int target = 1; target <= amount; target++)
//         {
//             int mini = INT_MAX;
//             for (int i = 0; i < coins.size(); i++)
//             {
//                 if (target - coins[i] >= 0)
//                 {
//                     int ans = dp[target - coins[i]];
//                     if (ans != INT_MAX)
//                     {
//                         mini = min(mini, 1 + ans);
//                     }
//                 }
//             }
//             dp[target] = mini;
//         }
//         return dp[amount];
//     }

//     int coinChange(vector<int> &coins, int amount)
//     {
//         // int ans = solveUsingRecursion(coins, amount);
//         // if(ans == INT_MAX)
//         //     return -1;
//         // else
//         //     return ans;

//         // vector<int> dp(amount+1, -1);
//         // int ans = solveMem(coins,amount, dp);
//         // if(ans == INT_MAX)
//         //     return -1;
//         // else
//         //     return ans;

//         int ans = solveTab(coins, amount);
//         if (ans == INT_MAX)
//             return -1;
//         else
//             return ans;
//     }
// };

// class Solution
// {
// public:
//     // n -> represents the index of current house
//     int solveUsingRecursion(vector<int> &nums, int n)
//     {
//         if (n < 0)
//             return 0;
//         if (n == 0)
//         {
//             return nums[0];
//         }

//         // include
//         int include = solveUsingRecursion(nums, n - 2) + nums[n];
//         int exclude = solveUsingRecursion(nums, n - 1) + 0;

//         return max(include, exclude);
//     }

//     int solveUsingMem(vector<int> &nums, int n, vector<int> &dp)
//     {
//         if (n < 0)
//             return 0;
//         if (n == 0)
//         {
//             return nums[0];
//         }

//         if (dp[n] != -1)
//         {
//             return dp[n];
//         }

//         // include
//         int include = solveUsingMem(nums, n - 2, dp) + nums[n];
//         int exclude = solveUsingMem(nums, n - 1, dp) + 0;

//         dp[n] = max(include, exclude);
//         return dp[n];
//     }

//     int solveUsingTabulation(vector<int> &nums, int n)
//     {

//         vector<int> dp(n + 1, 0);
//         dp[0] = nums[0];

//         for (int i = 1; i <= n; i++)
//         {

//             int temp = 0;
//             if (i - 2 >= 0)
//                 temp = dp[i - 2];

//             int include = temp + nums[i];
//             int exclude = dp[i - 1] + 0;

//             dp[i] = max(include, exclude);
//         }

//         return dp[n];
//     }

//     int spaceOptimisedSolution(vector<int> &nums, int n)
//     {

//         int prev2 = 0;
//         int prev1 = nums[0];
//         // vector<int> dp(n+1, 0);
//         // dp[0] = nums[0];
//         int curr = 0;
//         for (int i = 1; i <= n; i++)
//         {

//             int temp = 0;
//             if (i - 2 >= 0)
//                 temp = prev2;

//             int include = temp + nums[i];
//             int exclude = prev1 + 0;

//             curr = max(include, exclude);
//             prev2 = prev1;
//             prev1 = curr;
//         }

//         return prev1;
//     }

//     int rob(vector<int> &nums)
//     {
//         int n = nums.size() - 1;
//         // return solveUsingRecursion(nums, n);

//         // vector<int> dp(n+1, -1);
//         // return solveUsingMem(nums, n, dp);
//         // return solveUsingTabulation(nums, n);
//         return spaceOptimisedSolution(nums, n);
//     }
// };
// code solved by me
class Solution
{
public:
    int solveUsingRecursion(vector<int> &nums, int n)
    {
        if (n < 0)
        {
            return 0;
        }
        if (n == 0)
        {
            return nums[0];
        }

        // include
        int include = solveUsingRecursion(nums, n - 2) + nums[n];
        int exclude = solveUsingRecursion(nums, n - 1) + 0;

        return max(include, exclude);
    }

    int solveUsingMems(vector<int> &nums, int n, vector<int> &dp)
    {
        if (n < 0)
        {
            return 0;
        }
        if (n == 0)
        {
            return nums[0];
        }

        if (dp[n] != -1)
        {
            return dp[n];
        }

        // include
        int include = solveUsingMems(nums, n - 2, dp) + nums[n];
        int exclude = solveUsingMems(nums, n - 1, dp) + 0;

        dp[n] = max(include, exclude);
        return dp[n];
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size() - 1;
        // return solveUsingRecursion(nums,n);

        vector<int> dp(n + 1, -1);
        return solveUsingMems(nums, n, dp);
    }
};