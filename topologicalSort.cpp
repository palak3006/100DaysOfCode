// Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.

#include<bits/stdc++.h>
using namespace std;


bool cycle(int source, vector<vector<int>>&adjList, vector<int>&visited, vector<int>&pathVisited)
{
    visited[source] = 1;
    pathVisited[source] = 1;

    for(auto it : adjList[source])
    {
        if(visited[it] == 0)
        {
            if(cycle(it, adjList, visited, pathVisited))
            return true;
        }

        else if(pathVisited[it] == 1)
        return true;
    }

    pathVisited[source] = 0;
    return false;
}

void TopologicalSort(vector<int>indegree, vector<vector<int>>adjList)
{
    queue<int>q;
    
    for(int i=0; i<indegree.size(); i++)
    {
        if(indegree[i] == 0)
        q.push(i);
    }
    
    vector<int> ans;

    while(!q.empty())
    {
       int node = q.front();
       ans.push_back(node);
       q.pop();

       for(auto it : adjList[node])
       {
        indegree[it]--;
        if(indegree[it] ==0)
        q.push(it);
       }
    }
    for(int i=0; i<ans.size(); i++)
       {
        cout << ans[i] << " ";
       }
}


int main()
{
    int n,m;
    cin >> n >> m;

    vector<vector<int>> adjList(n);
    vector<int>indegree(n,0);

    for(int i=0; i<m; i++)
    {
        int u,v;
        cin >> u >> v;

        adjList[u].push_back(v);
        indegree[v]++;
    }

    vector<int>visited(n, 0);
    vector<int>pathVisited(n, 0);



    for(int i = 0; i < n; i++)
    {
        if(visited[i] == 0)
        {
            if(cycle(i, adjList, visited, pathVisited))
            {
                cout << "Cycle exists, No TopologicalSort";
                return 0;
            }
        }
    }

    // No cycle → perform topological sort
    TopologicalSort(indegree, adjList);

    return 0;
}