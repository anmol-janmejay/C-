#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <limits.h>
using namespace std;

class graph
{
public:
    unordered_map<int, list<pair<int, int>>> adjlist;

    void addEdge(int u, int v, int wt, bool direction)
    {
        //     direction = 1 -> Undirected Graph
        //     direction = 0 -> Directed Graph
        adjlist[u].push_back({v, wt});
        if (direction == 1)
        {
            adjlist[v].push_back({u, wt});
        }
    }

    void printAdjList()
    {
        for (auto i : adjlist)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << "(" << j.first << "," << j.second << "), ";
            }
            cout << endl;
        }
    }

    void shortestPathBfs(int src, int dest)
    {
        queue<int> q;
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;

        // initial steps for src
        q.push(src);
        visited[src] = 1;
        parent[src] = -1;

        while (!q.empty())
        {
            int fNode = q.front();
            q.pop();

            for (auto nbr : adjlist[fNode])
            {
                if (!visited[nbr.first])
                {
                    q.push(nbr.first);
                    visited[nbr.first] = 1;
                    parent[nbr.first] = fNode;
                }
            }
        }

        // store path in ans, after traversing in the parent array
        vector<int> ans;
        int node = dest;
        while (node != -1)
        {
            ans.push_back(node);
            node = parent[node];
        }

        reverse(ans.begin(), ans.end());

        cout << "Printing Answers: " << endl;
        for (auto i : ans)
        {
            cout << i << ",";
        }
        cout << endl;
    }

    void topoSortDfs(int src, unordered_map<int, bool> &visited, stack<int> &ans)
    {
        visited[src] = true;

        for (auto neighbour : adjlist[src])
        {
            if (!visited[neighbour.first])
            {
                topoSortDfs(neighbour.first, visited, ans);
            }
        }

        // while returning, store the node in the stack
        cout << "Pushing" << src << endl;
        ans.push(src);
    }

    void shortestPathDfs(int dest, stack<int> topoOrder, int n)
    {
        vector<int> dist(n, INT_MAX);

        int src = topoOrder.top();
        topoOrder.pop();
        dist[src] = 0;

        for (auto nbr : adjlist[0])
        {
            if (dist[0] + nbr.second < dist[nbr.first])
            {
                dist[nbr.first] = dist[0] + nbr.second;
            }
        }

        while (!topoOrder.empty())
        {
            int topElement = topoOrder.top();
            topoOrder.pop();

            if (dist[topElement] != INT_MAX)
            {
                for (auto nbr : adjlist[topElement])
                {
                    if (dist[topElement] + nbr.second < dist[nbr.first])
                    {
                        dist[nbr.first] = dist[topElement] + nbr.second;
                    }
                }
            }
        }

        cout << "Printing Ans: " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << i << "->" << dist[i] << endl;
        }
    }

    void shortestDistDijkstra(int src, int n)
    {
        vector<int> dist(n, INT_MAX);
        set<pair<int, int>> st;
        // initial steps
        dist[src] = 0;
        st.insert(make_pair(0, src));

        while (!st.empty())
        {
            // fetch the smallest or first element from set
            auto topElement = *(st.begin());
            int nodeDistance = topElement.first;
            int node = topElement.second;

            // pop from set
            st.erase(st.begin());

            // Neighbour Traverse
            for (auto nbr : adjlist[node])
            {
                if (nodeDistance + nbr.second < dist[nbr.first])
                {
                    // mujhe distance update krna hai
                    // finding entry in set
                    auto result = st.find(make_pair(dist[nbr.first], nbr.first));
                    // if found, then remove
                    if (result != st.end())
                    {
                        st.erase(result);
                    }
                    // updation in dist array and set
                    dist[nbr.first] = nodeDistance + nbr.second;
                    st.insert(make_pair(dist[nbr.first], nbr.first));
                }
            }
        }
        cout << "printing ans:" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << dist[i] << ", ";
        }
        cout << endl;
    }
};

int main()
{
    graph g;

    // Test Case for Shortest Path BFS
    // g.addEdge(0, 1, 1, 1);
    // g.addEdge(1, 2, 1, 1);
    // g.addEdge(2, 3, 1, 1);

    // g.addEdge(3, 4, 1, 1);
    // g.addEdge(0, 5, 1, 1);
    // g.addEdge(5, 4, 1, 1);

    // g.addEdge(0, 6, 1, 1);
    // g.addEdge(6, 7, 1, 1);
    // g.addEdge(7, 8, 1, 1);
    // g.addEdge(8, 4, 1, 1);

    // Topo Sort DFS
    // g.addEdge(0, 1, 5, 0);
    // g.addEdge(0, 2, 3, 0);
    // g.addEdge(2, 1, 2, 0);
    // g.addEdge(1, 3, 3, 0);
    // g.addEdge(2, 3, 5, 0);
    // g.addEdge(2, 4, 6, 0);
    // g.addEdge(4, 3, 1, 0);

    // Sorting DFS
    g.addEdge(6, 3, 2, 1);
    g.addEdge(6, 1, 14, 1);
    g.addEdge(3, 1, 9, 1);
    g.addEdge(3, 2, 10, 1);
    g.addEdge(1, 2, 7, 1);
    g.addEdge(2, 4, 15, 1);
    g.addEdge(4, 3, 11, 1);

    g.addEdge(6, 5, 9, 1);
    g.addEdge(4, 5, 6, 1);

    g.printAdjList();

    g.shortestDistDijkstra(6, 7);

    stack<int> topoOrder;
    unordered_map<int, bool> visited;
    g.topoSortDfs(0, visited, topoOrder);

    g.shortestPathDfs(3, topoOrder, 5);

    // int src = 0;
    // int dest = 4;

    // g.shortestPathBfs(src, dest);

    return 0;
}