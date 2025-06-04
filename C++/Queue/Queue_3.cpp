#include <iostream>
#include <queue>
using namespace std;

// string solve(string str)
// {
//     int freq[26] = {0};
//     queue<char> q;

//     string ans = "";

//     for (int i = 0; i < str.length(); i++)
//     {
//         char ch = str[i];

//         // increment frequency
//         freq[ch - 'a']++;
//         q.push(ch);

//         while (!q.empty())
//         {
//             if (freq[q.front() - 'a'] > 1)
//             {
//                 q.pop();
//             }
//             else
//             {
//                 ans.push_back(q.front());
//                 break;
//             }
//         }

//         if (q.empty())
//         {
//             ans.push_back('#');
//         }
//     }

//     // cout << "Final Answer: " << ans << endl;
//     return ans;
// }

// int main()
// {
//     string str = "zarcaazrd";
//     cout << "Final Answer is: " << solve(str) << endl;

//     return 0;
// }

// Maximum Sliding Window
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> dq;
        vector<int> ans;

        // first window of k size
        for (int i = 0; i < k; i++)
        {
            // chote element remove krdo,
            while (!dq.empty() && nums[i] >= nums[dq.back()])
            {
                dq.pop_back();
            }
            // inserting index, so tht we can checkout of window element
            dq.push_back(i);
        }

        // store answer for first window
        ans.push_back(nums[dq.front()]);

        // remaining windows ko process
        for (int i = k; i < nums.size(); i++)
        {
            // out of window element ko remove krdia
            if (!dq.empty() && i - dq.front() >= k)
            {
                dq.pop_front();
            }

            // ab ferse current element k liyue chotte element
            // ko remove krna h
            while (!dq.empty() && nums[i] >= nums[dq.back()])
            {
                dq.pop_back();
            }
            // inserting index, so tht we can checkout of window element
            dq.push_back(i);

            // current window ka answer store krna h
            ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};