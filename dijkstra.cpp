// Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>>adjList(n);

    for(int i=0; i<m; i++)
    {
        int u,v,weight;
        cin >> u >> v >> weight;

        adjList[u].push_back({v,weight});
        adjList[v].push_back({u,weight});
    }

    int source;
    cin >> source;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

    vector<int>dist(n, INT_MAX);
    dist[source] = 0;

    pq.push({0,source});

    while(!pq.empty())
    {
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it : adjList[node])
        {
            int neighbour = it.first;
            int weight = it.second;

            if(dist[neighbour] > weight + distance)
            {
                dist[neighbour] = weight + distance;
                pq.push({dist[neighbour], neighbour});
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        cout << "Distance from " << source << " to " << i<< " = " << dist[i] << endl;
    } 
    
    return 0;
}