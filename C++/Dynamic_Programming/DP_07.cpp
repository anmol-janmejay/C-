// class Solution
// {
// public:
//     int solveUsingRecursion(vector<int> &arr, int curr, int prev)
//     {
//         // Base case
//         if (curr >= arr.size())
//         {
//             return 0;
//         }

//         // include
//         int include = 0;
//         if (prev == -1 || arr[curr] > arr[prev])
//             include = 1 + solveUsingRecursion(arr, curr + 1, curr);

//         // exclude
//         int exclude = 0 + solveUsingRecursion(arr, curr + 1, prev);

//         int ans = max(include, exclude);
//         return ans;
//     }

//     int solveUsingMem(vector<int> &arr, int curr, int prev, vector<vector<int> > &dp)
//     {
//         // Base case
//         if (curr >= arr.size())
//         {
//             return 0;
//         }

//         if(dp[curr][prev + 1] != -1)
//         return dp[curr][prev + 1];

//         // include
//         int include = 0;
//         if (prev == -1 || arr[curr] > arr[prev])
//             include = 1 + solveUsingMem(arr, curr + 1, curr,dp);

//         // exclude
//         int exclude = 0 + solveUsingMem(arr, curr + 1, prev,dp);

//         int ans = max(include, exclude);
//         dp[curr][prev + 1] = ans;
//         return dp[curr][prev + 1];
//     }

//     int solveUsingTabulation(vector<int> &arr)
//     {
//         vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
//         int n = arr.size();

//         for(int curr = n-1; curr >= 0 ; curr--){
//             for(int prev = curr - 1; prev >= -1; prev--)
//             {
//                 // include
//                 int include = 0;
//                 if (prev == -1 || arr[curr] > arr[prev])
//                     include = 1 + dp[curr + 1][curr + 1];

//                 // exclude
//                 int exclude = 0 + dp[curr + 1][prev + 1];

//                 dp[curr][prev + 1] = max(include, exclude);

//             }
//         }
//         return dp[0][0];
//     }

//     int SolveOptimal(vector<int>& arr)
//     {
//         if(arr.size() == 0)
//         return 0;
//         vector<int> ans;
//         ans.push_back(arr[0]);

//         for(int i = 1; i < arr.size(); i++)
//         {
//             if(arr[i] > ans.back())
//             {
//                 // include
//                 ans.push_back(arr[i]);
//             }
//             else
//             {
//                 // overwrite
//                 // find index of just bada element
//                 int index = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
//                 ans[index] = arr[i];
//             }
//         }
//         return ans.size();
//     }

//     int solveUsingTabSO(vector<int> &arr)
//     {
//         int n = arr.size();
//         // vector<vector<int> > dp(n+1, vector<int>(n+1, 0));
//         vector<int> currRow(n + 1, 0);
//         vector<int> nextRow(n + 1, 0);

//         for (int curr = n - 1; curr >= 0; curr--)
//         {
//             for (int prev = curr - 1; prev >= -1; prev--)
//             {
//                 // include
//                 int include = 0;
//                 if (prev == -1 || arr[curr] > arr[prev])
//                     include = 1 + nextRow[curr + 1];

//                 // excude
//                 int exclude = 0 + nextRow[prev + 1];

//                 currRow[prev + 1] = max(include, exclude);
//             }
//             // shift
//             nextRow = currRow;
//         }
//         return nextRow[0];
//     }

//         int lengthOfLIS(vector<int> &nums)
//     {
//         int curr = 0;
//         int prev = -1;
//         int n = nums.size();
//         // // int ans = solveUsingRecursion(nums, curr, prev);
//         // vector<vector<int> > dp(n, vector<int>(n+1, -1));
//         // int ans = solveUsingMem(nums, curr, prev, dp);
//         // int ans = solveUsingTabulation(nums);
//         // int ans = solveOptimal(nums);
//         int ans = solveUsingTabSO(nums);
//         return ans;
//     }
// };