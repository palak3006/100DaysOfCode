#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u;
    int v;
    int weight;
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<Edge> edges;

    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        edges.push_back({u, v, w});
    }

    int source;
    cin >> source;

    vector<int> dist(n, INT_MAX);
    dist[source] = 0;

    // Relax all edges n-1 times
    for(int i = 1; i <= n - 1; i++)
    {
        for(auto edge : edges)
        {
            int u = edge.u;
            int v = edge.v;
            int weight = edge.weight;

            if(dist[u] != INT_MAX &&
               dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative weight cycle
    for(auto edge : edges)
    {
        int u = edge.u;
        int v = edge.v;
        int weight = edge.weight;

        if(dist[u] != INT_MAX &&
           dist[v] > dist[u] + weight)
        {
            cout << "NEGATIVE CYCLE";
            return 0;
        }
    }

    // Print shortest distances
    for(int i = 0; i < n; i++)
    {
        cout << "Distance from " << source
             << " to " << i
             << " = " << dist[i] << endl;
    }

    return 0;
}