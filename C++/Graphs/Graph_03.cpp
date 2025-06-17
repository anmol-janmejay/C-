#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
using namespace std;
class Graph
{
public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, bool direction)
    {
        // direction = 0 -> Undirected Graph
        // direction = 1 -> Directed Graph
        // create an Edge from u to v
        adjList[u].push_back(v);
        if (direction == 0)
        {
            // undirected Edge
            // create an Edge from v to u
            adjList[v].push_back(u);
        }
    }

    void printAdjacencyList()
    {
        for (auto node : adjList)
        {
            cout << node.first << "->";
            for (auto neighbour : node.second)
            {
                cout << neighbour << ",";
            }
            cout << endl;
        }
    }

    bool topoSortDFS(int src, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, stack<int> &ans)
    {
        visited[src] = true;
        dfsVisited[src] = true;

        for (auto neighbour : adjList[src])
        {
            if (!visited[neighbour])
            {
                if (topoSortDFS(neighbour, visited, dfsVisited, ans))
                    return true;
            }
            else if (dfsVisited[neighbour])
            {
                // Cycle detected
                return true;
            }
        }
        dfsVisited[src] = false;
        ans.push(src);
        return false;
    }

    void topoSortBFS(int n, vector<int> &ans)
    {
        queue<int> q;
        unordered_map<int, int> indegree;

        // indegree calculate
        for (auto i : adjList)
        {
            int src = i.first;
            for (auto nbr : i.second)
            {
                indegree[nbr]++;
            }
        }

        // put all the node in the queue, which have indegree = 0
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        // BFS logic
        while (!q.empty())
        {
            int fNode = q.front();
            q.pop();

            ans.push_back(fNode);
            // or we can do count++

            for (auto nbr : adjList[fNode])
            {
                indegree[nbr]--;
                // check for zero again
                if (indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }
    }
};

int main()
{
    Graph g;
    // n = Number of Nodes in the Graph
    int n = 8;

    // g.addEdge(0, 1, 1);
    // g.addEdge(1, 2, 1);
    // g.addEdge(2, 3, 1);
    // // g.addEdge(3, 1, 1); // Uncommenting this will create a cycle

    // g.addEdge(3, 7, 1);
    // g.addEdge(6, 7, 1);
    // g.addEdge(7, 0, 1);
    // g.addEdge(7, 1, 1);

    // BFS Test Case
    g.addEdge(2, 4, 1);
    g.addEdge(2, 5, 1);
    g.addEdge(4, 6, 1);
    g.addEdge(5, 3, 1);

    g.addEdge(3, 7, 1);
    g.addEdge(6, 7, 1);
    g.addEdge(7, 0, 1);
    g.addEdge(7, 1, 1);

    g.printAdjacencyList();
    cout << endl;

    // BFS Topo sort
    vector<int> ans;
    g.topoSortBFS(n, ans);

    if (ans.size() == n)
    {
        cout << "It is a Valid Topo Sort. " << endl;
    }
    else
    {
        cout << "Cycle Present or Invalid Topo Sort. " << endl;
    }

    cout << "Printing Topological Sort using BFS: " << endl;
    for (auto i : ans)
    {
        cout << i << ",";
    }

    cout << endl;
    //     // DFS Topo Sort
    // unordered_map<int, bool> visited;
    // unordered_map<int, bool> dfsVisited;
    // stack<int> ans;
    // bool isCycle = false;

    // for (int i = 0; i < n; i++)
    // {
    //     if (!visited[i])
    //     {
    //         if (g.topoSortDFS(i, visited, dfsVisited, ans))
    //         {
    //             isCycle = true;
    //             break;
    //         }
    //     }
    // }

    // if (isCycle)
    // {
    //     cout << "Cycle detected. Topological sort not possible." << endl;
    // }
    // else
    // {
    //     cout << "Topo Sort: " << endl;
    //     while (!ans.empty())
    //     {
    //         cout << ans.top() << " ";
    //         ans.pop();
    //     }
    // }
    return 0;
}

// class Solution
// {
// public:
//     vector<int> topoSort(int V, vector<vector<int>> &edges)
//     {
//         // Step 1: Build adjacency list and indegree array
//         vector<int> adj[V];
//         vector<int> indegree(V, 0);

//         for (auto edge : edges)
//         {
//             int u = edge[0];
//             int v = edge[1];

//             adj[u].push_back(v); // directed edge u -> v
//             indegree[v]++;       // v gets one incoming edge
//         }

//         // Step 2: Push all nodes with indegree 0 into queue
//         queue<int> q;
//         for (int i = 0; i < V; i++)
//         {
//             if (indegree[i] == 0)
//             {
//                 q.push(i);
//             }
//         }

//         // Step 3: Process the queue
//         vector<int> topo;
//         while (!q.empty())
//         {
//             int node = q.front();
//             q.pop();

//             topo.push_back(node); // this node is now in topo order

//             // reduce indegree of neighbours
//             for (auto neighbour : adj[node])
//             {
//                 indegree[neighbour]--;
//                 if (indegree[neighbour] == 0)
//                 {
//                     q.push(neighbour);
//                 }
//             }
//         }

//         // If topo size < V → cycle detected
//         if (topo.size() < V)
//         {
//             // return empty vector or handle as needed
//             return {}; // Graph has a cycle
//         }

//         return topo;
//     }
// };

// #include <iostream>
// #include <unordered_map>
// using namespace std;

// int main()
// {
//     string s = "programming";
//     int freq[26] = {0};
//     for (char ch : s)
//     {
//         freq[ch - 'a']++;
//     }
//     for (int i = 0; i < 26; i++)
//     {
//         if (freq[i] > 0)
//         {
//             cout << char('a' + i) << " -> " << freq[i] << endl;
//         }
//     }
// }