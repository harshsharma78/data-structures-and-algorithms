// Bipartite Graph using BFS and DFS
// Bipartite Graph ----> No two adjacent node should have same color and odd numbered circle nodes is not bipartite
//                       any circle or nodes are bipartite other than odd
#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Using BFS
bool bipartiteBFS(int src, vector<int> adj[], int color[])
{
    queue<int> q;
    q.push(src);
    color[src] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[node];
                q.push(it);
            }
            else if (color[it] == color[node])
                return false;
        }
    }
    return true;
}
bool checkBipartiteBFS(int n, vector<int> adj[])
{
    int color[n];
    memset(color, -1, sizeof(color));
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (!bipartiteBFS(i, adj, color))
                return false;
        }
    }
    return true;
}
// Using DFS
bool bipartiteDFS(int src, vector<int> adj[], int color[])
{
    if (color[src] == -1)
        color[src] = 1;
    for (auto it : adj[src])
    {
        if (color[it] == -1)
        {
            color[it] = 1 - color[src];
            if (!bipartiteDFS(it, adj, color))
                return false;
        }
        else if (color[it] == color[src])
            return false;
    }
    return true;
}
bool checkBipartiteDFS(int n, vector<int> adj[])
{
    int color[n];
    memset(color, -1, sizeof(color));
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (!bipartiteDFS(i, adj, color))
                return false;
        }
    }
    return true;
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
    if (checkBipartiteDFS(V, adj))
        cout << "This Graph is Bipartite.";
    else
        cout << "This Graph is not Bipartite.";
}
