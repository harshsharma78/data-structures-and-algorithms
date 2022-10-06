// Kosaraju's Algorithm for Strongly Connected Components(SCC)
// SCC are those in which Every Vertex can be reachable by every other Vertex in Graph (Directed Graph)
// e.g.,1-->2-->4-->5
//       \ /
//        3

// Algorithm : 1.Sort all the Nodes acc. to their Finishing Time (Toposort).
//             2.Transpose the Graph.
//             3.Reverse DFS (DFS for the Transposed Graph).
#include <bits/stdc++.h>
using namespace std;
void topoDFS(int v, vector<int> adj[], vector<bool> &vis, stack<int> &st)
{
    vis[v] = true;
    for (auto it : adj[v])
    {
        if (vis[it] == false)
            topoDFS(it, adj, vis, st);
    }
    st.push(v);
}
void revDFS(int v, vector<bool> &vis, vector<int> transpose[])
{
    vis[v] = true;
    cout << v << " ";
    for (auto it : transpose[v])
    {
        if (vis[it] == false)
        {
            revDFS(it, vis, transpose);
        }
    }
}
void addEdge(int u, int v, vector<int> adj[])
{
    adj[u].push_back(v);
}
/* -------------------------------------------------------------------------------------------------------------- */
class Kosaraju
{
    list<int> *adj;
    int V;

public:
    Kosaraju(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }
    void addEdge(int m, int n)
    {
        adj[m].push_back(n);
    }
    void dfs(int n, bool vis[])
    {
        vis[n] = true;
        cout << n << " ";

        list<int>::iterator it;
        for (it = adj[n].begin(); it != adj[n].end(); it++)
        {
            if (!vis[*it])
                dfs(*it, vis);
        }
    }
    void topoDFS(int n, bool vis[], stack<int> &st)
    {
        vis[n] = true;
        list<int>::iterator it;
        for (it = adj[n].begin(); it != adj[n].end(); it++)
        {
            if (!vis[*it])
                topoDFS(*it, vis, st);
        }
        st.push(n);
    }
    Kosaraju transpose()
    {
        Kosaraju kr(V);
        for (int u = 0; u < V; u++)
        {
            list<int>::iterator it;
            for (it = adj[u].begin(); it != adj[u].end(); it++)
            {
                kr.adj[*it].push_back(u);
            }
        }
        return kr;
    }
    void SCC()
    {
        // vector<int> vis(v, 0);
        bool *vis = new bool[V];
        stack<int> st;

        for (int i = 0; i < V; i++)
            vis[i] = false;

        for (int i = 0; i < V; i++)
        {
            if (vis[i] == false)
            {
                topoDFS(i, vis, st);
            }
        }

        Kosaraju k = transpose();

        for (int i = 0; i < V; i++)
            vis[i] = false;

        while (st.empty() == false)
        {
            int node = st.top();
            st.pop();
            if (vis[node] == false)
            {
                k.dfs(node, vis);
                cout << endl;
            }
        }
    }
};
int main()
{
    int v = 5;
    vector<int> adj[v];
    vector<bool> vis(v, false);
    stack<int> st;

    addEdge(1, 0, adj);
    addEdge(0, 2, adj);
    addEdge(2, 1, adj);
    addEdge(0, 3, adj);
    addEdge(3, 4, adj);

    // Toposort
    for (int i = 0; i < v; i++)
    {
        if (vis[i] == false)
        {
            topoDFS(i, adj, vis, st);
        }
    }
    // Transpose
    vector<int> transpose[v];
    for (int i = 0; i < v; i++)
    {
        vis[i] = false;
        for (auto it : adj[i])
        {
            transpose[it].push_back(i);
        }
    }
    // Reverse DFS
    cout << "Strongly Connected Components in a Graph are --> " << endl;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (vis[node] == false)
        {
            revDFS(node, vis, transpose);
            cout << endl;
        }
    }
    // Kosaraju ko(5);
    // ko.addEdge(1, 0);
    // ko.addEdge(0, 2);
    // ko.addEdge(2, 1);
    // ko.addEdge(0, 3);
    // ko.addEdge(3, 4);
    // cout << "Strongly Connected Components in a Graph are --> " << endl;
    // ko.SCC();
}