// Tarjan's Algorithm for Bridges and Articulation Point(AP) in Graphs

// Bridges|Cut Edge --> It is that Edge in a Graph by removal of which leads a Graph to Disintegrate into
//                      Two or More Components.

// Articulation Point|Cut Vertex --> It is the node in a Graph by removal of which Graph Disintegrate
//                                   into Two or More Components.

#include <bits/stdc++.h>
using namespace std;
// tin[] --> Time of Insertion
// lowtin[] --> Lowest(Minimal) Time of Insertion
// timer --> Storing Count of the Time

void APDfs(int V, int parent, vector<int> adj[], bool vis[], int tin[], int lowtin[], bool isAP[],
           int &timer)
{
    vis[V] = true;
    int child = 0;
    tin[V] = lowtin[V] = ++timer;
    for (auto it : adj[V])
    {
        if (it == parent)
            continue;
        if (!vis[it])
        {
            child++; // For Two or More Separated Components
            APDfs(it, V, adj, vis, tin, lowtin, isAP, timer);
            lowtin[V] = min(lowtin[V], lowtin[it]);

            if (lowtin[it] >= tin[V] && parent != -1)
            {
                isAP[V] = true;
            }
        }
        else if (it != parent)
        {
            lowtin[V] = min(lowtin[V], tin[it]);
        }
    }
    if (parent == -1 && child > 1)
    {
        isAP[V] = true;
    }
}
void AP(vector<int> adj[], int V)
{

    int timer = 0, parent = -1;
    bool vis[V] = {false};
    int tin[V] = {0};
    int lowtin[V];
    bool isAP[V] = {false};

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            APDfs(i, parent, adj, vis, tin, lowtin, isAP, timer);
        }
    }
    for (int i = 0; i < V; i++)
    {
        if (isAP[i] == true)
        {
            cout << i << " ";
        }
    }
}

void addEdge(int u, int v, vector<int> adj[])
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

class Bridges
{
    int V;
    list<int> *adj;
    void bridgeDfs(int N, vector<int> &parent, vector<bool> &vis, vector<int> &tin, vector<int> &lowtin);

public:
    Bridges(int V);
    void bridge();
    void addEdge(int u, int v);
};
Bridges::Bridges(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Bridges::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void Bridges::bridgeDfs(int N, vector<int> &parent, vector<bool> &vis,
                        vector<int> &tin, vector<int> &lowtin)
{
    static int timer = 0;
    vis[N] = true;
    tin[N] = lowtin[N] = ++timer;
    for (auto it : adj[N])
    {
        // if (it == parent[N])
        //     continue;
        if (!vis[it])
        {
            parent[it] = N;
            bridgeDfs(it, parent, vis, tin, lowtin);
            lowtin[N] = min(lowtin[N], lowtin[it]); // Pick that V which has lowest minimal time of
                                                    // insertion and replace it
            if (lowtin[it] > tin[N])                // Formula to Calculate if there is a Bridge
            {
                cout << N << " " << it << endl;
            }
        }
        else if (it != parent[N])
        {
            lowtin[N] = min(lowtin[N], tin[it]); // If the V is already Visited so it must be
                                                 // compared with tin
        }
    }
}

void Bridges::bridge()
{
    vector<int> parent(V, -1);
    vector<bool> vis(V, false);

    vector<int> tin(V, -1);
    vector<int> lowtin(V, -1);
    for (int i = 0; i < V; i++)
    {
        if (vis[i] == false)
            bridgeDfs(i, parent, vis, tin, lowtin);
    }
}
int main()
{
    int V = 7;
    vector<int> adj[V];
    addEdge(0, 1, adj);
    addEdge(1, 2, adj);
    addEdge(2, 0, adj);
    addEdge(1, 3, adj);
    addEdge(1, 4, adj);
    addEdge(1, 6, adj);
    addEdge(3, 5, adj);
    addEdge(4, 5, adj);
    cout << "Articulation Points in Graph \n";
    AP(adj, V);
    cout << endl;

    cout << "Bridges in First Graph \n";
    Bridges B0(5);
    B0.addEdge(1, 0);
    B0.addEdge(0, 2);
    B0.addEdge(2, 1);
    B0.addEdge(0, 3);
    B0.addEdge(3, 4);
    B0.bridge();

    cout << "Bridges in Second Graph \n";
    Bridges B1(4);
    B1.addEdge(0, 1);
    B1.addEdge(1, 2);
    B1.addEdge(2, 3);
    B1.bridge();

    cout << "Bridges in Third Graph \n";
    Bridges B2(7);
    B2.addEdge(0, 1);
    B2.addEdge(1, 2);
    B2.addEdge(2, 0);
    B2.addEdge(1, 3);
    B2.addEdge(1, 4);
    B2.addEdge(1, 6);
    B2.addEdge(3, 5);
    B2.addEdge(4, 5);
    B2.bridge();
}
