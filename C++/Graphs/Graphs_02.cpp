#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
using namespace std;

template <typename T>
class Graph
{
    unordered_map<T, list<T>> adjList;

public:
    void addEdge(T u, T v, bool directed)
    {
        adjList[u].push_back(v);
        if (!directed)
        {
            adjList[v].push_back(u);
        }
    }

    bool checkCyclicUsingBFS(int src, unordered_map<int, bool> &visited)
    {
        queue<int> q;
        unordered_map<int, int> parent;

        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            for (auto nbr : adjList[frontNode])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = frontNode;
                }
                else if (nbr != parent[frontNode])
                {
                    // cycle present
                    return true;
                }
            }
        }
        return false;
    }

    bool checkCyclicUsingDFS(int src, unordered_map<int, bool> &visited, int parent)
    {
        visited[src] = true;

        for (auto nbr : adjList[src])
        {
            if (!visited[nbr])
            {
                bool checkAageKaAns = checkCyclicUsingDFS(nbr, visited, src);
                if (checkAageKaAns == true)
                    return true;
            }
            if (visited[nbr] && nbr != parent)
            {
                // cycle present
                return true;
            }
        }
        return false;
    }

    bool checkCyclicDirectedGraphUsingDfs(int src, unordered_map<int, bool> &visited, unordered_map<int, bool> dfsVisited)
    {
        visited[src] = true;
        dfsVisited[src] = true;

        for (auto nbr : adjList[src])
        {
            if (!visited[nbr])
            {
                bool aageKaAnswer = checkCyclicDirectedGraphUsingDfs(nbr, visited, dfsVisited);
                if (aageKaAnswer == true)
                    return true;
            }
            if (visited[nbr] == true && dfsVisited[nbr] == true)
            {
                return true;
            }
        }
        // yaha hi galti hoti hai
        dfsVisited[src] = false;
        return false;
    }
};

int main()
{
    Graph<int> g;
    // n = number of node in graph
    int n = 5;
    g.addEdge(0, 1, false);
    g.addEdge(1, 2, false);
    g.addEdge(2, 3, false);
    g.addEdge(3, 4, false);
    g.addEdge(4, 0, false);

    bool ans = false;
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            ans = g.checkCyclicDirectedGraphUsingDfs(i, visited, dfsVisited);
            if (ans == true)
                break;
        }
    }

    if (ans == true)
        cout << "Cycle is Present." << endl;
    else
        cout << "Cycle is Absent." << endl;

    // bool ans = false;
    // unordered_map<int, bool> visited;
    // for (int i = 0; i < n; i++)
    // {
    //     if (!visited[i])
    //     {
    //         ans = g.checkCyclicUsingBFS(i, visited);
    //         if (ans == true)
    //             break;
    //     }
    // }
    // if (ans == true)
    //     cout << "Cycle is Present." << endl;
    // else
    //     cout << "Cycle is Absent." << endl;

    // bool ansDFS = false;
    // unordered_map<int, bool> visitedDFS;
    // for (int i = 0; i < n; i++)
    // {
    //     if (!visitedDFS[i])
    //     {
    //         ansDFS = g.checkCyclicUsingDFS(i, visitedDFS, -1);
    //         if (ansDFS == true)
    //             break;
    //     }
    // }
    // if (ans == true)
    //     cout << "Cycle is Present." << endl;
    // else
    //     cout << "Cycle is Absent." << endl;

    return 0;
}