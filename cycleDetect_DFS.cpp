// Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

// Output:
// - YES or NO

#include<bits/stdc++.h>
using namespace std;

bool dfs(int source, int parent, vector<vector<int>> &adjList, vector<int>&visited)
{
    visited[source] = 1;

    for(auto it : adjList[source])
    {
        if(visited[it] == 0)
        {
            if(dfs(it, source, adjList, visited) == true)
            return true;
        }

        else if(parent != it)
        return true;
    }

    return false;
}

int main()
{
    int n,m;
    cin >>n >> m;

    vector<vector<int>> adjList(n);

    for(int i=0; i<m; i++)
    {
        int u,v;
        cin >> u >> v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int source;
    cin >> source;
    
    vector<int>visited(n,0);

    if(dfs(source, -1, adjList, visited))
    cout << "YES THERE IS CYCLE";

    else
    cout << "NO THERE IS NO CYCLE";

    return 0;

}