//             //    Course Schedule I
// class Solution
// {
// private:
//     bool topoSortBFS(int n, unordered_map<int, list<int>> &adjList)
//     {
//         vector<int> ans;
//         queue<int> q;
//         unordered_map<int, int> indegree;

//         // indegree calculate
//         for (auto i : adjList)
//         {
//             int src = i.first;
//             for (auto nbr : i.second)
//             {
//                 indegree[nbr]++;
//             }
//         }

//         // put all the node in the queue, which have indegree = 0
//         for (int i = 0; i < n; i++)
//         {
//             if (indegree[i] == 0)
//             {
//                 q.push(i);
//             }
//         }

//         // BFS logic
//         while (!q.empty())
//         {
//             int fNode = q.front();
//             q.pop();

//             ans.push_back(fNode);
//             // or we can do count++

//             for (auto nbr : adjList[fNode])
//             {
//                 indegree[nbr]--;
//                 // check for zero again
//                 if (indegree[nbr] == 0)
//                 {
//                     q.push(nbr);
//                 }
//             }
//         }
//         if (ans.size() == n)
//         {
//             return true;
//         }
//         else
//         {
//             return false;
//         }
//     }

// public:
//     bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
//     {
//         unordered_map<int, list<int>> adjList;

//         for (auto task : prerequisites)
//         {
//             int u = task[0];
//             int v = task[1];
//             adjList[v].push_back(u);
//         }

//         bool ans = topoSortBFS(numCourses, adjList);
//         return ans;
//     }
// };

// // Course Schedule II
// class Solution
// {
// private:
//     vector<int> topoSortBFS(int n, unordered_map<int, list<int>> &adjList)
//     {
//         vector<int> ans;
//         queue<int> q;
//         unordered_map<int, int> indegree;

//         // indegree calculate
//         for (auto i : adjList)
//         {
//             int src = i.first;
//             for (auto nbr : i.second)
//             {
//                 indegree[nbr]++;
//             }
//         }

//         // put all the node in the queue, which have indegree = 0
//         for (int i = 0; i < n; i++)
//         {
//             if (indegree[i] == 0)
//             {
//                 q.push(i);
//             }
//         }

//         // BFS logic
//         while (!q.empty())
//         {
//             int fNode = q.front();
//             q.pop();

//             ans.push_back(fNode);
//             // or we can do count++

//             for (auto nbr : adjList[fNode])
//             {
//                 indegree[nbr]--;
//                 // check for zero again
//                 if (indegree[nbr] == 0)
//                 {
//                     q.push(nbr);
//                 }
//             }
//         }
//         if (ans.size() == n)
//         {
//             return ans;
//         }
//         else
//         {
//             return {};
//         }
//     }

// public:
//     vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
//     {
//         unordered_map<int, list<int>> adjList;

//         for (auto task : prerequisites)
//         {
//             int u = task[0];
//             int v = task[1];
//             adjList[v].push_back(u);
//         }

//         vector<int> ans = topoSortBFS(numCourses, adjList);
//         return ans;
//     }
// };
// Word Ladder
// class Solution
// {
// public:
//     int ladderLength(string beginWord, string endWord, vector<string> &wordList)
//     {
//         queue<pair<string,int>> q;
//         q.push({beginWord,1});
//         unordered_set<string> st(wordList.begin(), wordList.end());

//         // jo bhi word queue meh insert krunga, toh usko set meh se remove kar dunga
//         st.erase(beginWord);

//         while(!q.empty())
//         {
//             pair<string,int> fNode = q.front();
//             q.pop();

//             string currString = fNode.first;
//             int currCount = fNode.second;

//             // check kahin destination toh nahi pahuch gye
//             if(currString == endWord)
//                 return currCount;

//             for(int index = 0; index < currString.length(); index++)
//             {
//                 // har index pr jo value hai, usko main 'a' to 'z' se replace krr do
//                 char originalCharacter = currString[index];
//                 for(char ch = 'a'; ch <= 'z'; ch++)
//                 {
//                     currString[index] = ch;
//                     // check in wordList
//                     if(st.find(currString) != st.end())
//                     {
//                         q.push({currString,currCount + 1});
//                         st.erase(currString);
//                     }
//                 }
//                 // bringing back the currString to its original state
//                 currString[index] = originalCharacter;
//             }
//         }
//         return 0;
//     }
// };

// Path With Minimum Effort
class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dist(heights.size(), vector<int>(heights[0].size(), INT_MAX));
        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        while (!pq.empty())
        {
            auto fNode = pq.top();
            pq.pop();
            int frontNodeDifference = fNode.first;
            int x = fNode.second.first;
            int y = fNode.second.second;

            // check answer tak toh nhi pahuch gye
            if (x == heights.size() - 1 && y == heights[0].size() - 1)
            {
                return dist[x][y];
            }

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if (newX >= 0 && newY >= 0 && newX < heights.size() && newY < heights[0].size())
                {
                    int currDifference = abs(heights[x][y] - heights[newX][newY]);
                    int newMax = max(frontNodeDifference, currDifference);
                    if (newMax < dist[newX][newY])
                    {
                        dist[newX][newY] = newMax;
                        pq.push({newMax, {newX, newY}});
                    }
                }
            }
        }
        return 0;
    }
};
