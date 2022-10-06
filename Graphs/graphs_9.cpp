#include <bits/stdc++.h>
using namespace std;

// Shortest Path in a Graph ( Weighted DAG) from a given source which is usually '0th node'
// using Toposort initially then finding the Distance using dist[]

#define INF INT_MAX
void addEdge(int u, int v, int wt, vector<pair<int, int>> adj[])
{
    adj[u].push_back({v, wt});
}
void findTopoSort(int v, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &st)
{
    vis[v] = 1;
    for (auto it : adj[v])
    {
        if (vis[it.first] == 0)
        {
            findTopoSort(it.first, adj, vis, st);
        }
    }
    st.push(v);
}
void shortestPathDAG(int src, int v, vector<pair<int, int>> adj[])
{
    stack<int> st;
    vector<int> vis(v, 0);
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
            findTopoSort(i, adj, vis, st);
    }
    // Shortest Path
    int dist[v]; // This contains the total weights or total added weights of the adjacent node too
    for (int i = 0; i < v; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (dist[node] != INF)
        {
            for (auto it : adj[node])
            {
                if ((dist[node] + it.second) < dist[it.first])
                    dist[it.first] = dist[node] + it.second;
                /* 
                 first = node element second = weight of that node
                 suppose '0s' adj node are 1 and 3 and their wts are 1, 2 respectively and after
                 adding the wts --> '1s' wt = 1 and 3s wt = 2 so dist[node] = '1' and
                 wt of its adj node is 'it.second' and dist[it.first] is the added wt of the adj node of '1'
                 and if dist[it.first] has contained a previous value from another node then it won't be replaced. 
               
                Graph e.g., only dotted is wt and with arrow is the node 
                0--1 -->1--2 -->2--1 -->6
                |                       |
                2 -->3--3 -->4--4 -->5--1
                */
            }
        }
    }
    cout << "Shortest Path from the Source to every other Node of a Graph in DAG:" << endl;
    for (int i = 0; i < v; i++)
        (dist[i] == INF) ? cout << "Infinity " : cout << dist[i] << " ";
}

// Shortest Path in Undirected Unweighted Graph
void add_Edge(int u, int v, vector<int> adj[])
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void shortestPath(int src, int v, vector<int> adj[]) // Using modified BFS
{
    int dist[v];
    for (int i = 0; i < v; i++)
        dist[i] = INF;

    queue<int> q;
    dist[src] = 0;
    q.push(src);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if ((dist[node] + 1) < dist[it]) // +1 bcz unweighted graph
            {
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }
    cout << "Shortest Path from the Source to every other Node of a Undirected Unweighted Graph:" << endl;
    for (int i = 0; i < v; i++)
        cout << dist[i] << " ";
}
int main()
{
    int v = 6;
    // vector<pair<int, int>> adj[v];
    // addEdge(0, 1, 5, adj);
    // addEdge(0, 2, 3, adj);
    // addEdge(1, 3, 6, adj);
    // addEdge(1, 2, 2, adj);
    // addEdge(2, 4, 4, adj);
    // addEdge(2, 5, 2, adj);
    // addEdge(2, 3, 7, adj);
    // addEdge(3, 4, -1, adj);
    // addEdge(4, 5, -2, adj);
    // shortestPathDAG(1, v, adj);
    
    vector<int> adj[v];
    add_Edge(0, 1, adj);
    add_Edge(0, 2, adj);
    add_Edge(1, 3, adj);
    add_Edge(1, 2, adj);
    add_Edge(2, 4, adj);
    add_Edge(2, 5, adj);
    add_Edge(2, 3, adj);
    add_Edge(3, 4, adj);
    add_Edge(4, 5, adj);
    shortestPath(0, v, adj);
}
