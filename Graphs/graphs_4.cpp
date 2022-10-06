// Cycle Detection in Undirected Graph using BFS and DFS
#include <bits/stdc++.h>
using namespace std;

// Striver's Graph Series
// BFS
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    // adj[v].push_back(u);
}
bool checkForDFS(int node, int parent, vector<int> adj[], vector<int> &vis)
{
    vis[node] = true;
    for (auto it : adj[node]) // 'it' is adjacent vertex
    {
        if (!vis[it])
        {
            if (checkForDFS(it, node, adj, vis))
                return true;
        }
        else if (parent != it)
            return true;
    }
    return false;
}

bool isCycle(int v, vector<int> adj[])
{
    vector<int> vis(v, 0);
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            if (checkForDFS(i, -1, adj, vis))
                return true;
        }
    }
    return false;
}
int main()
{
    int V = 3;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    // addEdge(adj, 2, 0);
    // addEdge(adj, 2, 3);
    // cout << cycleCheckBFS(V, adj) << " ";
    if (isCycle(V, adj))
        cout << "The Cycle is found in this Undirected Graph.";
    else
        cout << "The Cycle is not found in this Undirected Graph.";
}
