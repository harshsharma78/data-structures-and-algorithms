// DFS Traversal of Graph
#include <bits/stdc++.h>
using namespace std;

const int N = 100;
bool vis[N];
vector<int> adj[N];

// GFG
class DFS_Graph // Using map and map of list
{
public:
    map<int, bool> vis;
    map<int, list<int>> adj;
    void dfsUtil(int v)
    {
        // preorder
        vis[v] = true;
        // inorder
        list<int>::iterator it;
        for (it = adj[v].begin(); it != adj[v].end(); it++)
        {
            if (!vis[*it])
                dfsUtil(*it);
        }
        cout << v << " ";
        // postorder
    }
    void dfs()
    {
        for (auto i : adj) // For Disconnected Graph
        {
            if (vis[i.first] == false)
                dfsUtil(i.first);
        }
    }
    void addEdge(int u, int v)
    {
        adj[v].push_back(u);
    }
};

void dfs(int v) // Apni Kaksha
{
    // preorder
    vis[v] = 1;
    cout << v << " ";

    // inorder
    for (auto i : adj[v])
    {
        if (!vis[i])
            dfs(i);
    }
    // postorder
}

class DFSGraph // Striver
{
public:
    void dfsUtil(int node, vector<int> &vis, vector<int> adj[], vector<int> &storedfs)
    {
        storedfs.push_back(node);
        vis[node] = 1;
        for (auto i : adj[node])
        {
            if (!vis[i])
            {
                dfsUtil(i, vis, adj, storedfs);
            }
        }
    }
    vector<int> dfs(int V, vector<int> adj[])
    {
        vector<int> storedfs;
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfsUtil(i, vis, adj, storedfs);
            }
        }
        return storedfs;
    }
    void addEdge(int u, int v, vector<int> adj[])
    {
        adj[u].push_back(v);
    }
};
class DFS_Stack
{
    int V;
    list<int> *adj;

public:
    DFS_Stack(int V)
    {
        this->V = V;
        adj = new list<int>[V + 1];
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }
    void dfsUtil(int src, vector<bool> &vis)
    {
        stack<int> st;
        st.push(src);

        while (!st.empty())
        {
            src = st.top();
            st.pop();
            if (!vis[src])
                cout << src << " ";
            vis[src] = true;
        }
        for (auto it : adj[src])
        {
            if (!vis[src])
            {
                st.push(src);
                // vis[src] = true;
            }
        }
    }
    void dfs()
    {
        vector<bool> vis(V, false);
        for (int i = 1; i <= V; i++)
        {
            if (!vis[i])
            {
                dfsUtil(i, vis);
            }
        }
    }
};

int main()
{
    // GFG

    // DFSGraph dfs;
    // DFS.addEdge(1, 0);
    // DFS.addEdge(2, 1);
    // DFS.addEdge(3, 4);
    // DFS.addEdge(4, 0);
    // DFS.addEdge(2, 3);
    // DFS.addEdge(9, 3);
    // cout << "The Depth-First Traversal of Graph is --> ";
    // DFS.dfs();

    // Apni Kaksha

    int nodes, edges;
    // cout << "Enter Nodes" << endl;
    // cin >> nodes;
    // cout << "Enter Edges" << endl;
    // cin >> edges;

    // for (int i = 0; i < nodes; i++)
    //     vis[i] = false;

    // for (int i = 0; i < edges; i++)
    // {
    //     int u, v; // u and v are the node elements
    //     cin >> u >> v;

    //     adj[u].push_back(v);
    //     // adj[v].push_back(u);
    // }
    // dfs(0);

    // Striver's Graph Series

    // vector<int> adjl[nodes+1];
    // for (int i = 0; i < edges; i++)
    // {
    //     int u, v; // u and v are the node elements
    //     cin >> u >> v;

    //     adjl[u].push_back(v);
    //     // adj[v].push_back(u);
    // }
    // DFSGraph dfs;
    // vector<int> temp = dfs.dfs(nodes, adjl);
    // for (int i = 0; i < temp.size(); i++)
    // {
    //     cout << temp[i] << " ";
    // }

    // DFS Using Stack ---> Iterative Approach
    // DFS_Stack dfs(9);
    // dfs.addEdge(0, 1);
    // dfs.addEdge(0, 2);
    // dfs.addEdge(1, 2);
    // dfs.addEdge(2, 0);
    // dfs.addEdge(2, 3);
    // dfs.addEdge(3, 3);

    DFS_Graph dfs;
    dfs.addEdge(1, 6);
    dfs.addEdge(1, 3);
    dfs.addEdge(1, 2);
    dfs.addEdge(3, 6);
    dfs.addEdge(2, 3);
    dfs.addEdge(6, 4);
    dfs.addEdge(4, 3);
    dfs.addEdge(5, 4);
    dfs.addEdge(5, 3);
    dfs.addEdge(7, 3);
    dfs.addEdge(7, 5);
    dfs.addEdge(5, 8);
    dfs.addEdge(9, 5);
    dfs.addEdge(8, 9);
    dfs.addEdge(9, 7);
    dfs.addEdge(8, 4);
   dfs.dfs();
}
