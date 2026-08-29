// Problem: Perform DFS starting from a given source vertex using recursion.

// Input:
// - n
// - adjacency list
// - starting vertex s

// Output:
// - DFS traversal order

#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<int>> &adjList, int node, vector<int> &visited, vector<int>&list)
{
    visited[node] = 1;
    list.push_back(node);
    
    for(auto it : adjList[node])
    {
        if(visited[it] == 0)
        dfs(adjList, it, visited, list);
    }
}

int main()
{
    int n,m;
    cin >> n>>m;

    vector<vector<int>> adjList(n);

    for(int i=0; i<m; i++)
    {
        int u, v;
        cin >> u >> v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int vertex; 
    cout << "Enter source vertex: ";
    cin >> vertex;

    vector<int> visited(n+1,0);
    vector<int> list;

    dfs(adjList, vertex, visited, list);
    
    for(int i=0; i<list.size(); i++)
    {
        cout << list[i] << " ";
    }

    return 0;
}
