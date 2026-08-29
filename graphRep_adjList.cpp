// Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

// Input:
// - n (vertices)
// - m (edges)
// - edges (u, v)

// Output:
// - List of adjacency lists for each vertex

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);

    for(int i=0; i<m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout <<"Matrix representation using Adjacency list: " << endl;
    for(int i=1; i<=n; i++)
    {
        cout << i << "->";
        for(int j : adj[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}