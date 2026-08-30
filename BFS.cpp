// Problem: Perform BFS from a given source using queue.

// Input:
// - n
// - adjacency list
// - source s

// Output:
// - BFS traversal order

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

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

    queue<int> q;
    q.push(source);

    vector<int> vis(n, 0);
    vis[source] = 1;

    while(!q.empty())
    {
        int current = q.front();
        cout << current << " ";
        q.pop();

        for(auto it : adjList[current])
        {
            if(vis[it] != 1)
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }

    return 0;
}