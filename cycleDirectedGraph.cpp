// Problem: Detect cycle in directed graph using DFS and recursion stack.

// Output:
// - YES if cycle exists

#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>>& adjList,
         vector<int>& visited, vector<int>& pathVisited)
{
    visited[node] = 1;
    pathVisited[node] = 1;

    for(auto it : adjList[node])
    {
        // Node is not visited
        if(visited[it] == 0)
        {
            if(dfs(it, adjList, visited, pathVisited))
                return true;
        }

        // Node is already in current recursion stack
        else if(pathVisited[it] == 1)
        {
            return true;
        }
    }

    // Remove node from current recursion stack
    pathVisited[node] = 0;

    return false;
}

bool isCycle(int V, vector<vector<int>>& edges)
{
    vector<vector<int>> adjList(V);

    // Directed graph
    for(int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
    }

    vector<int> visited(V, 0);
    vector<int> pathVisited(V, 0);

    // Check all components
    for(int i = 0; i < V; i++)
    {
        if(visited[i] == 0)
        {
            if(dfs(i, adjList, visited, pathVisited))
                return true;
        }
    }

    return false;
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges;

    for(int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        edges.push_back({u, v});
    }

    if(isCycle(V, edges))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}