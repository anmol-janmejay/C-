// 1143. Longest Common Subsequence

class Solution
{
public:
    int solveUsingRecursion(string text1, string text2, int i, int j)
    {
        int n = text1.length();
        int m = text2.length();
        // Base case
        if (i == n)
            return 0;
        if (j == m)
            return 0;

        // Recursion part
        int ans = 0;
        if (text[i] == text[j])
        {
            ans = 1 + solveUsingRecursion(text1, text2, i + 1, j + 1);
        }
        else
        {
            ans = 0 + max(solveUsingRecursion(text1, text2, i, j + 1), solveUsingRecursion(text1, text2, i + 1, j));
        }
        return ans;
    }

    int solveUsingMem(string &text1, string &text2, int i, int j, vector<vector<int>> &dp)
    {
        int n = text1.length();
        int m = text2.length();

        // Base case
        if (i == n)
            return 0;
        if (j == m)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        // Recursion part
        int ans = 0;
        if (text[i] == text[j])
        {
            ans = 1 + solveUsingRecursion(text1, text2, i + 1, j + 1);
        }
        else
        {
            ans = 0 + max(solveUsingRecursion(text1, text2, i, j + 1, dp), solveUsingRecursion(text1, text2, i + 1, j, dp));
        }
        dp[i][j] = ans;
        return ans;
    }

    int solveUsingTabulation(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (text1[i] == text2[j])
                {
                    // Inclusion
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                else
                {
                    // Exclusion
                    dp[i][j] = 0 + max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }
        return dp[0][0];
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        int i = 0;
        int j = 0;
        // return solveUsingRecursion(text1, text2, i, j);
        vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
        return solveUsingMem(text1, text2, i, j, dp);
        // return solveUsingTabulation(text1, text2);
    }
};