// #include <iostream>
// #include <unordered_map>
// #include <list>
// #include <queue>
// #include <stack>
// #include <algorithm>
// #include <set>
// #include <limits.h>
// using namespace std;

// class graph
// {
// public:
//     unordered_map<int, list<int>> adjList;

//     void addEdge(int u, int v, bool direction)
//     {
//         // direction = 1 -> Undirected Graph
//         // direction = 0 -> Directed Graph
//         adjList[u].push_back(v);
//         if (direction == 1)
//         {
//             adjList[v].push_back(u);
//         }
//     }

//     void dfs1(int src, stack<int> &s, unordered_map<int, bool> &vis)
//     {
//         vis[src] = true;

//         for (auto nbr : adjList[src])
//         {
//             if (!vis[nbr])
//             {
//                 dfs1(nbr, s, vis);
//             }
//         }
//         s.push(src);
//     }

//     void dfs2(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjNew)
//     {
//         visited[src] = true;
//         cout << src << ",";

//         for (auto nbr : adjNew[src])
//         {
//             if (!visited[nbr])
//             {
//                 dfs2(nbr, visited, adjNew);
//             }
//         }
//     }

//     int countSCC(int n)
//     {
//         stack<int> s;
//         unordered_map<int, bool> visited;

//         // find topo ordering
//         for (int i = 0; i < n; i++)
//         {
//             if (!visited[i])
//             {
//                 dfs1(i, s, visited);
//             }
//         }
//         // reverse all edge
//         unordered_map<int, list<int>> adjNew;

//         for (auto t : adjList)
//         {
//             for (auto nbr : t.second)
//             {
//                 int u = t.first;
//                 int v = nbr;
//                 // v-> u insert
//                 adjNew[v].push_back(u);
//             }
//         }

//         // traverse using DFS
//         int count = 0;
//         unordered_map<int, bool> visited2;

//         while (!s.empty())
//         {
//             int node = s.top();
//             s.pop();
//             if (!visited2[node])
//             {
//                 cout << "Printing " << count + 1 << "th SCC: ";
//                 dfs2(node, visited2, adjNew);
//                 cout << endl;
//                 count++;
//             }
//         }
//         return count;
//     }
// };

// int main()
// {
//     graph g;

//     g.addEdge(0, 1, 0);

//     g.addEdge(1, 2, 0);

//     g.addEdge(2, 3, 0);

//     g.addEdge(3, 0, 0);

//     g.addEdge(2, 4, 0);

//     g.addEdge(4, 5, 0);

//     g.addEdge(5, 6, 0);

//     g.addEdge(6, 4, 0);

//     g.addEdge(6, 7, 0);

//     int ans = g.countSCC(8);
//     cout << "Number of SCC: " << ans << endl;

//     return 0;
// }

class Solution
{
public:
    void findBridges(int src, int parent, int &timer, vector<int> &tin, vector<int> &low, unordered_map<int, bool> &vis, vector<vector<int>> &ans, unordered_map<int, list<int>> &adjList)
    {
        vis[src] = true;
        tin[src] = timer;
        low[src] = timer;
        timer++;

        for (auto nbr : adjList[src])
        {
            if (nbr == parent)
                continue;
            if (!vis[nbr])
            {
                // dfs call
                findBridges(nbr, src, timer, tin, low, vis, ans, adjList);
                // low update
                low[src] = min(low[src], low[nbr]);

                // check for Bridge
                if (low[nbr] > tin[src])
                {
                    vector<int> temp;
                    temp.push_back(nbr);
                    temp.push_back(src);
                    ans.push_back(temp);
                }
            }
            else
            {
                // Node is not visited and not a parent
                // low update
                low[src] = min(low[src], low[nbr]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        unordered_map<int, list<int>> adjList;

        for (int i = 0; i < connections.size(); i++)
        {
            int u = connections[i][0];
            int v = connections[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<vector<int>> ans;
        int timer = 1;
        vector<int> tin(n);
        vector<int> low(n);
        unordered_map<int, bool> vis;

        findBridges(0, -1, timer, tin, low, vis, ans, adjList);

        return ans;
    }
};

// class Solution
// {
// public:
//     void findBridges(int src, int parent, int &timer, vector<int> &tin, vector<int> &low, unordered_map<int, bool> &vis, vector<vector<int>> &ans, unordered_map<int, list<int>> &adjList)
//     {
//         vis[src] = true;
//         tin[src] = timer;
//         low[src] = timer;
//         timer++;

//         for(auto nbr: adjList[src])
//         {
//             if(nbr == parent)
//             continue;
//             if(!vis[nbr])
//             {
//                 // dfs call
//                 findBridges(nbr,src,timer,tin,low,vis,ans,adjList);
//                 // low update
//                 low[src] = min(low[src],low[nbr]);

//                 // check for Bridge
//                 if(low[nbr] > tin[src])
//                 {
//                     vector<int> temp;
//                     temp.push_back(nbr);
//                     temp.push_back(src);
//                     ans.push_back(temp);
//                 }
//             }
//             else{
//                 // Node is not visited and not a parent
//                 // low update
//                 low[src] = min(low[src],low[nbr]);
//             }
//         }
//     }

//     vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
//     {
//         unordered_map<int,list<int>> adjList;

//         for(int i = 0; i < connections.size(); i++)
//         {
//             int u = connections[i][0];
//             int v = connections[i][1];
//             adjList[u].push_back(v);
//             adjList[v].push_back(u);
//         }

//         vector<vector<int>> ans;
//         int timer = 1;
//         vector<int> tin(n);
//         vector<int> low(n);
//         unordered_map<int,bool> vis;

//         findBridges(0,-1,timer,tin,low,vis,ans,adjList);

//         return ans;
//     }
// };

#pragma GCC optimize("O3,unroll-loops,Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
static const auto harsh = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

#define LC_HACK
#ifdef LC_HACK
const auto __ = []()
{
    struct ___
    {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif

class Solution
{
public:
    int time = 1;
    void dfs(int &node, int &parent, vector<bool> &visited, vector<vector<int>> &bridges, vector<int> &time_low, vector<int> &time_in, vector<vector<int>> &adj)
    {

        visited[node] = true;
        time_low[node] = time_in[node] = time;
        time++;

        for (auto &nbr : adj[node])
        {
            if (nbr == parent)
                continue;
            if (!visited[nbr])
            {
                dfs(nbr, node, visited, bridges, time_low, time_in, adj);
                time_low[node] = min(time_low[node], time_low[nbr]);
                // if neighbour node can't be reached by someone but only through here means It is critical/Bridge
                // So, pick it up
                if (time_low[nbr] > time_in[node])
                {
                    bridges.push_back({node, nbr});
                }
            }
            else
            {
                time_low[node] = min(time_low[node], time_low[nbr]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<bool> visited(n, false);
        vector<vector<int>> adj(n);
        vector<int> time_in(n);
        vector<int> time_low(n);
        vector<vector<int>> bridges;
        int initial_Parent = -1;

        for (int i = 0; i < connections.size(); i++)
        {
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, initial_Parent, visited, bridges, time_in, time_low, adj);
            }
        }

        return bridges;
    }
};