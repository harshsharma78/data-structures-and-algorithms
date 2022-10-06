// Cycle Detection in Undirected Graph using BFS
#include <bits/stdc++.h>
using namespace std;

// Striver's Graph Series
// BFS
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
bool cycleBFS(int src, vector<int> adj[], vector<int> &vis)
{
    queue<pair<int, int>> qp;

    vis[src] = true;
    qp.push({src, -1});
    while (!qp.empty())
    {
        int node = qp.front().first;
        int prev = qp.front().second;
        qp.pop();
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = true;
                qp.push({it, node});
            }
            else if (prev != it) // adjacent vertex is not equal to its parent node
                return true;
        }
    }
    return false;
}
bool cycleCheckBFS(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i] && cycleBFS(i, adj, vis))
            return true;
    }
    return false;
}
// GFG
// BFS
bool checkForCycle(int src, int v, vector<int> adj[], vector<bool> &vis)
{
    vector<int> parent(v, -1);
    queue<int> q;
    vis[src] = true;
    q.push(src);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto it : adj[u])
        {
            if (!vis[it])
            {
                vis[it] = true;
                q.push(it);
                parent[it] = u;   // Put the adjaceny vertex on its parent's location
            }
            else if (parent[u] != it)   // adjacent vertex is not equal to its parent node
                return true;
        }
    }
    return false;
}
bool isCycle(int V, vector<int> adj[])
{
    vector<bool> vis(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i] && checkForCycle(i, V, adj, vis))
            return true;
    }
    return false;
}
int main()
{
    // GFG
    // int v = 4;
    // vector<int> adj[v];
    // addEdge(adj, 0, 1);
    // addEdge(adj, 1, 2);
    // addEdge(adj, 2, 0);
    // addEdge(adj, 2, 3);

    // if (isCycle(v, adj))
    //     cout << "The Cycle is found in this Undirected Graph.";
    // else
    //     cout << "The Cycle is not found in this Undirected Graph.";

    int V = 4;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    // addEdge(adj, 2, 3);
    // addEdge(adj, 2, 3);
    // cout << cycleCheckBFS(V, adj) << " ";
    if (cycleCheckBFS(V, adj))
        cout << "The Cycle is found in this Undirected Graph.";
    else
        cout << "The Cycle is not found in this Undirected Graph.";
}
