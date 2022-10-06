#include <bits/stdc++.h>
using namespace std;

// Cycle Detection in a Directed Graph using DFS
void addEdge(int u, int v, vector<int> adj[])
{
    adj[u].push_back(v);
}
bool cycleCheckDFS(int node, vector<int> adj[], int vis[], int dfsvis[])
{
    vis[node] = 1;
    dfsvis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (cycleCheckDFS(it, adj, vis, dfsvis))
                return true;
        }
        else if (dfsvis[it])
            return true;
    }
    dfsvis[node] = 0;
    return false;
}
bool isCycle(int v, vector<int> adj[])
{
    int vis[v];
    int dfsvis[v];
    memset(vis, 0, sizeof vis);
    memset(dfsvis, 0, sizeof dfsvis);
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            if (cycleCheckDFS(i, adj, vis, dfsvis))
                return true;
        }
    }
    return false;
}
bool cycleCheckBFS(int v, vector<int> adj[]) // Kahn's Algorithm
{
    queue<int> q;
    vector<int> indegree(v, 0);
    for (int i = 0; i < v; i++)
    {
        for (auto it : adj[i])
            indegree[it]++;
    }
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    int count = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        count++;
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    if (count == v) // if the total number of nodes are equal to the count then there is no cycle bcz Kahn's Algo (for Toposort) is used only in DAG
        return false;
    return true;
}

int main()
{
    int v = 3;
    vector<int> adj[v];
    addEdge(0, 1, adj);
    addEdge(1, 2, adj);
    // addEdge(1, 2, adj);
    // addEdge(2, 0, adj);
    // addEdge(2, 3, adj);
    // addEdge(3, 0, adj);

    if (cycleCheckBFS(v, adj))
    {
        cout << "This Directed Graph contains a Cycle" << endl;
    }
    else
        cout << "This Directed Graph doesn't contain a Cycle" << endl;
}