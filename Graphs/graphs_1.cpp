// Creation and Traversal of Undirected and Directed Graph
// BFS Traversal
#include <bits/stdc++.h>
using namespace std;

// class BFSOfGraph
// {
// public:
vector<int> BFS(int v, vector<int> adj[]) // Competitive Method using Queue
{
    vector<int> bfs;
    vector<int> vis(v + 1, 0);
    queue<int> q;
    for (int i = 1; i <= v; i++)
    {
        if (!vis[i])
        {
            q.push(i);
            vis[i] = 1;
        }
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for (auto it : adj[node])
            {
                if (!vis[it])
                {
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
    }
    return bfs;
}
void addEdge(int u, int v, vector<int> adj[])
{
    adj[u].push_back(v);
    // adj[v].push_back(u);
}
// };
class BFSOfGraph // using STL --> list
{
    int V;
    list<int> *adj; // Adjacency list

public:
    BFSOfGraph(int V)
    {
        this->V = V;
        adj = new list<int>[V + 1];
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }
    void BFS(int src)
    {
        bool *vis = new bool[V + 1];
        for (int i = 1; i <= V; i++)
            vis[i] = false;

        list<int> queue; // create queue of list

        vis[src] = true;
        queue.push_back(src);

        while (!queue.empty())
        {
            src = queue.front();
            cout << src << " ";
            queue.pop_front();

            for (auto it : adj[src])
            {
                if (!vis[it])
                {
                    vis[it] = true;
                    queue.push_back(it);
                }
            }
        }
    }
};

int main()
{
    int V, e; // n ---> nodes, e ----> edges
    cout << "Enter the Number of Nodes" << endl;
    cin >> V;
    cout << "Enter the Number of Edges" << endl;
    cin >> e;

    vector<int> adj[V + 1];
    // cout << "Enter the Data" << endl;
    for (int i = 1; i <= e; i++)
    {
        int u, v; // Nodes's data
        cin >> u >> v;
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }
   
    // addEdge(1, 6, adj);
    // addEdge(1, 3, adj);
    // addEdge(1, 2, adj);
    // addEdge(3, 6, adj);
    // addEdge(2, 3, adj);
    // addEdge(6, 4, adj);
    // addEdge(4, 3, adj);
    // addEdge(5, 4, adj);
    // addEdge(5, 3, adj);
    // addEdge(7, 3, adj);
    // addEdge(7, 5, adj);
    // addEdge(5, 8, adj);
    // addEdge(9, 5, adj);
    // addEdge(8, 9, adj);
    // addEdge(9, 7, adj);
    // addEdge(8, 4, adj);

    vector<int> temp = BFS(V, adj);
    for (int i = 0; i < temp.size(); i++)
        cout << temp[i] << " ";

    // BFSOfGraph bfs(9);
    // bfs.addEdge(1, 6);
    // bfs.addEdge(1, 3);
    // bfs.addEdge(1, 2);
    // bfs.addEdge(3, 6);
    // bfs.addEdge(2, 3);
    // bfs.addEdge(6, 4);
    // bfs.addEdge(4, 3);
    // bfs.addEdge(5, 4);
    // bfs.addEdge(5, 3);
    // bfs.addEdge(7, 3);
    // bfs.addEdge(7, 5);
    // bfs.addEdge(5, 8);
    // bfs.addEdge(9, 5);
    // bfs.addEdge(8, 9);
    // bfs.addEdge(9, 7);
    // bfs.addEdge(8, 4);
    // bfs.BFS(1);
}