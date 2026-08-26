// Problem: Build a graph with n vertices and m edges using adjacency matrix representation.
// The graph may be directed or undirected.

// Input:
// - n (vertices)
// - m (edges)
// - m pairs (u, v)

// Output:
// - n x n adjacency matrix

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    // 0 = directed, 1 = undirected
    int type;
    cin >> type;

    vector<vector<int>> matrix(n, vector<int>(n, 0));

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        // Edge u -> v
        matrix[u][v] = 1;

        // If undirected, also add v -> u
        if(type == 1)
            matrix[v][u] = 1;
    }

    // Print adjacency matrix
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}