#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>
using namespace std;

// vector<int> prevSmallerElement(vector<int> &input)
// {
//     stack<int> s;
//     s.push(-1);
//     vector<int> ans(input.size());

//     // left to right -> prev smaller
//     for (int i = 0; i < input.size(); i++)
//     {
//         int curr = input[i];

//         // apka answer stack meh
//         while (s.top() >= curr)
//         {
//             s.pop();
//         }

//         // chotta element mil chuka h -> ans store
//         ans[i] = s.top();

//         // push krdo curr element ko
//         s.push(curr);
//     }
//     return ans;
// }

// vector<int> nextSmaller(vector<int> &input)
// {
//     stack<int> s;
//     s.push(-1);

//     vector<int> ans(input.size());

//     for (int i = input.size() - 1; i >= 0; i--)
//     {
//         int curr = input[i];

//         // apka answer stack meh
//         while (s.top() >= curr)
//         {
//             s.pop();
//         }

//         // chhota element mil chuka hai -> ans store
//         ans[i] = s.top();

//         // push krdo curr element ko
//         s.push(curr);
//     }
//     return ans;
// }

// int main()

// {
//     vector<int> input;
//     input.push_back(2);
//     input.push_back(1);
//     input.push_back(4);
//     input.push_back(3);

//     vector<int> ans1 = nextSmaller(input);

//     cout << "Printing ans1 is: " << endl;

//     for (int i = 0; i < input.size(); i++)
//     {
//         cout << ans1[i] << " ";
//     }
//     cout << endl;

//     vector<int> ans2 = prevSmallerElement(input);
//     cout << "Printing ans2 is: " << endl;
//     for (int i = 0; i < input.size(); i++)
//     {
//         cout << ans2[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }

// Largest Rectangle in HistoGram

vector<int> prevSmallerElement(vector<int> &input)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(input.size());

    // left to right -> prev smaller
    for (int i = 0; i < input.size(); i++)
    {
        int curr = input[i];

        // apka answer stack meh
        while (s.top() != -1 && input[s.top()] >= curr)
        {
            s.pop();
        }

        // chhota element mil chuka hai -> ans store
        ans[i] = s.top();

        // push krdo curr element ko
        s.push(i);
    }
    return ans;
}

vector<int> nextSmaller(vector<int> &input)
{
    stack<int> s;
    s.push(-1);

    vector<int> ans(input.size());

    for (int i = input.size() - 1; i >= 0; i--)
    {
        int curr = input[i];

        // apka answer stack meh
        while (s.top() != -1 && input[s.top()] >= curr)
        {
            s.pop();
        }

        // chhota element mil chuka hai -> ans store
        ans[i] = s.top();

        // push krdo curr element ko
        s.push(i);
    }
    return ans;
}

int getRectangularAreaHistogram(vector<int> &height)
{
    // step 1: prevSmaller Element
    vector<int> prev = prevSmallerElement(height);

    // step 2: nextSmaller call
    vector<int> next = nextSmaller(height);

    int maxArea = INT_MIN;
    int size = height.size();

    for (int i = 0; i < height.size(); i++)
    {
        int length = height[i];

        if (next[i] == -1)
        {
            next[i] = size;
        }

        int width = next[i] - prev[i] - 1;

        int area = length * width;
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(5);
    v.push_back(6);
    v.push_back(2);
    v.push_back(3);

    cout << "Ans is: " << getRectangularAreaHistogram(v) << endl;

    return 0;
}