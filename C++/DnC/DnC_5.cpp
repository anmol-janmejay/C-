#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    // Helper function for backtracking
    void backtrack(string digits, vector<string> &mapping, int index, string current, vector<string> &result)
    {
        // Base case: If we have processed all digits, add the current combination to the result
        if (index == digits.size())
        {
            result.push_back(current);
            return;
        }

        // Get the current digit and corresponding letters
        int digit = digits[index] - '0';
        string letters = mapping[digit];

        // Loop through each letter and make recursive calls
        for (char letter : letters)
        {
            backtrack(digits, mapping, index + 1, current + letter, result);
        }
    }

    vector<string> letterCombinations(string digits)
    {
        // Result to store all combinations
        vector<string> result;

        // Edge case: If the input is empty, return an empty result
        if (digits.empty())
            return result;

        // Digit to letters mapping as per a traditional phone keypad
        vector<string> mapping = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        // Start the backtracking process
        backtrack(digits, mapping, 0, "", result);

        return result;
    }
};

int main()
{
    Solution sol;
    string digits = "23"; // Example input
    vector<string> combinations = sol.letterCombinations(digits);

    // Output the combinations
    for (string combination : combinations)
    {
        cout << combination << " ";
    }

    return 0;
}
