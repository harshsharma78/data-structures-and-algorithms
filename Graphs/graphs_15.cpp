// Bellman Ford Algorithm for Shortest Path of Negative Weighted Graphs

// ** It doesn't Work in Negative Cycles in Graph but helps in finding them.
// ** For Undirected Graphs -- Convert it to Directed Graph.
// Algorithm : 1.Relax the Graph (N-1) times.

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int u, v, wt;
    node(int first, int second, int weight)
    {
        u = first;
        v = second;
        wt = weight;
    }
};
void addEdge(int u, int v, int wt, vector<node> edges)
{
    edges.push_back(node(u, v, wt));
}
int main()
{
    // int n=5, m, src=0;
    // // cout << "Enter Nodes and Edges" << endl;
    // // cin >> n >> m;
    // vector<node> edges;
    // // cout << "Enter Elements and Weights" << endl;
    // for (int i = 0; i < m; i++)
    // {
    //     int u, v, wt;
    //     cin >> u >> v >> wt;
    //     edges.push_back(node(u, v, wt));
    // }

    // addEdge(0, 1, -1, edges);
    // addEdge(0, 2, 4, edges);
    // addEdge(1, 2, 3, edges);
    // addEdge(1, 3, 2, edges);
    // addEdge(1, 4, 2, edges);
    // addEdge(3, 2, 5, edges);
    // addEdge(3, 1, 1, edges);
    // addEdge(4, 3, -3, edges);
    // // cout << "Enter Source" << endl;
    // // cin >> src;

    // vector<int> dist(n, INT_MAX);
    // dist[src] = 0;

    // for (int i = 0; i < n - 1; i++) // Relaxing
    // {
    //     for (auto it : edges)
    //     {
    //         if (dist[it.u] != INT_MAX && (dist[it.u] + it.wt) < dist[it.v]) // Formula of Bellman Ford
    //         // if ((dist[it.u] + it.wt) < dist[it.v]) // Formula of Bellman Ford
    //         {
    //             dist[it.v] = dist[it.u] + it.wt;
    //         }
    //     }
    // }
    // // int flag = 0;
    // for (auto it : edges) // Checking Negative Cycle
    // {
    //     if ((dist[it.u] != INT_MAX && dist[it.u] + it.wt) < dist[it.v])
    //     // if ((dist[it.u] + it.wt) < dist[it.v])
    //     {
    //         cout << "Negative Cycle" << endl;
    //         // flag = 1;
    //         // break;
    //     }
    // }
    // // if (!flag)
    // // {
    //     for (int i = 0; i < n; i++) // Printing Result
    //     {
    //         cout << i << " " << dist[i] << endl;
    //     }
    // // }
    int n, m, src;
    cout << "Enter Nodes and Edges" << endl;
    cin >> n >> m;
    vector<vector<int>> edges;
    cout << "Enter Elements and Weights" << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }
    cout << "Enter Source" << endl;
    cin >> src;

    vector<int> dist(n, 1e9);
    for (int i = 1; i <= n - 1; i++)
    {
        bool flag = false;
        for (auto it : edges)
        {
            int u = it[0]; // src
            int v = it[1]; // desti
            int w = it[2]; // weight

            // if (dist[v] > dist[u] + w)
            //     flag = true;

            dist[v] = min(dist[v], w + dist[u]);
        }
    }
    for (int i = 0; i < n; i++) // Printing Result
    {
        cout << i << " " << dist[i] << endl;
    }
}