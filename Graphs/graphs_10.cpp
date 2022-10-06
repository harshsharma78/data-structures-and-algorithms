/*
** Dijkstra's Algorithm for Shortest Path in Weighted Undirected Graph using Priority Queue and Set STL
*/
#include <bits/stdc++.h>
using namespace std;
void addEdge(int u, int v, int wt, vector<pair<int, int>> adj[])
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}
void dijkstras_Shortest_Path(int src, int v, vector<pair<int, int>> adj[]) // Using Priority Queue
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // min-heap --> Shortest Distance should be on the Top of the Priority Queue.
    vector<int> distTo(v, INT_MAX); // Distance Array
    distTo[src] = 0;
    // dist,from(node) --> Initially, the distance from the source node to itself is 0 and push it in the PQ.
    pq.push(make_pair(0, src)); // dist, node
    while (!pq.empty())
    {
        int distOfNode = pq.top().first; // dist
        int parNode = pq.top().second;   // node
        pq.pop();
        for (auto it : adj[parNode])
        {
            int nextChildNode = it.first;   // adjacent Node
            int nextDistOfNode = it.second; // Distance of adjacent Node

            if (distTo[nextChildNode] > distTo[parNode] + nextDistOfNode)
            {
                distTo[nextChildNode] = distTo[parNode] + nextDistOfNode;
                pq.push(make_pair(distTo[nextChildNode], nextChildNode));
            }
        }
    }
    cout << "Vertex(node) \tDistance from Source" << endl;
    for (int i = 0; i < v; i++)

        cout << i << "\t\t" << distTo[i] << endl;
}

void dijkstras_ShortestPath(int src, int v, vector<pair<int, int>> adj[]) // Using Set STL
{
    set<pair<int, int>> s;
    vector<int> dist(v, INT_MAX);

    s.insert(make_pair(0, src)); // wt,node
    dist[src] = 0;

    while (!s.empty())
    {
        auto u = *(s.begin());
        s.erase(u);
        for (auto it : adj[u.second])
        { // parent node's distance > adj node's dist + adj node's wt
            if (dist[it.first] > dist[u.second] + it.second)
            {
                s.erase({dist[it.first], it.first}); // Updating the values
                dist[it.first] = dist[u.second] + it.second;
                s.insert({dist[it.first], it.first}); // Inserting the Updated value
            }
        }
    }
    cout << "Vertex(node) \tDistance from Source" << endl;
    for (int i = 0; i < v; i++)
    {
        if (dist[i] < INT_MAX)
            cout << i << "\t\t" << dist[i] << endl;
    }
}

int main()
{
    int v = 9;
    vector<pair<int, int>> adj[v];
    addEdge(0, 1, 4, adj);
    addEdge(0, 7, 8, adj);
    addEdge(1, 2, 8, adj);
    addEdge(1, 7, 11, adj);
    addEdge(2, 3, 7, adj);
    addEdge(2, 8, 2, adj);
    addEdge(2, 5, 4, adj);
    addEdge(3, 4, 9, adj);
    addEdge(3, 5, 14, adj);
    addEdge(4, 5, 10, adj);
    addEdge(5, 6, 2, adj);
    addEdge(6, 7, 1, adj);
    addEdge(6, 8, 6, adj);
    addEdge(7, 8, 7, adj);

    dijkstras_Shortest_Path(0, v, adj);
}