#include <bits/stdc++.h>
using namespace std;

// Topological Sort ------> This is a technique where the node u should come befor node v i.e. u -> v
//                          and this can be done only in DAG (Directed Acyclic Graphs)
// One Graph Component can have many Topo Sort orders

void addEdge(int u, int v, vector<int> adj[])
{
    adj[u].push_back(v);
}
void findTopoSort(int v, vector<int> adj[], vector<int> &vis, stack<int> &st)
{
    vis[v] = 1;
    for (auto it : adj[v])
    {
        if (vis[it] == 0)
        {
            findTopoSort(it, adj, vis, st);
        }
    }
    st.push(v);
}
vector<int> topoSortDFS(int v, vector<int> adj[])
{
    vector<int> vis(v, 0);
    stack<int> st;
    for (int i = 0; i < v; i++)
    {
        if (vis[i] == 0)
        {
            findTopoSort(i, adj, vis, st);
        }
    }
    vector<int> topo;
    while (!st.empty())
    {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}
/*
Function to check if the elements returned are in topological sorted form or not
topo is the array containing elements in topological sorted form
*/
int check(int v, vector<int> &topo, vector<int> adj[])
{
    vector<int> arr(v, -1);
    for (int i = 0; i < v; i++)
        arr[topo[i]] = i;

    for (int i = 0; i < v; i++)
    {
        for (int v : adj[i])
        {
            if (arr[i] > arr[v])
                return 0;
        }
    }
    return 1;
}

vector<int> topoSortBFS(int v, vector<int> adj[]) // Kahn's Algorithm
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
    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    return topo;
}
int main()
{
    int v = 6;
    vector<int> adj[v];
    addEdge(5, 0, adj);
    addEdge(5, 2, adj);
    addEdge(4, 0, adj);
    addEdge(4, 1, adj);
    addEdge(2, 3, adj);
    addEdge(3, 1, adj);

    // vector<int> topoDFS = topoSortDFS(v, adj);
    // cout << "One of the Topological Sort Orders --> " << endl;
    // for (int i = 0; i < topoDFS.size(); i++)
    //     cout << topoDFS[i] << " ";
    // cout << endl;

    vector<int> topoBFS = topoSortBFS(v, adj);
    cout << "One of the Topological Sort Orders --> " << endl;
    for (int i = 0; i < topoBFS.size(); i++)
        cout << topoBFS[i] << " ";
    cout << endl;
}