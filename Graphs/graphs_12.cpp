// Disjoint Set -- Union by Rank and Path Compression
// Kruskal's Algorithm of MST is Implemented by Disjoint Set  -----> Must Sort Edges Acc. to weights

// Taking Many Components and each Component is A Parent of Itself and Uniting them Together (Union) and making it
// as a single component in which there can be a single parent of each and every component
// E.g., 1, 2, 3, 4, 5, 6 --->  1 - 2 - 3 and 4 - 5 - 6 -----> In this 1 is a parent of 2, 3 and 4 is a parent of
// 5, 6 and also 5 is a parent of 6 and 2 is a parent of 3
// Parent node also depends on how you connect the component because 3 can also be a parent of 2, 1
// and connecting directly 3 to 1 is a Path Compression rather than backtracking from 3 to 2 to 1 instead
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
bool comp(node a, node b)
{
    return a.wt < b.wt;
}
int findParent(int u, vector<int> &parent)
{
    if (u == parent[u])
        return u;
    return parent[u] = findParent(parent[u], parent); // Path Compression
}
void unionn(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(u, parent);
    v = findParent(v, parent);
    if (rank[u] < rank[v])
        parent[u] = v;
    else if (rank[v] < rank[u])  // Higher Ranked is A Parent
        parent[v] = u;
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}
void addEdge(int u, int v, int wt, vector<node> &edges)
{
    edges.push_back(node(u, v, wt));
}

int main()
{
    vector<node> edges;
    int N = 9;
    addEdge(0, 1, 4, edges);
    addEdge(0, 7, 8, edges);
    addEdge(1, 2, 8, edges);
    addEdge(1, 7, 11, edges);
    addEdge(2, 3, 7, edges);
    addEdge(2, 8, 2, edges);
    addEdge(2, 5, 4, edges);
    addEdge(3, 4, 9, edges);
    addEdge(3, 5, 14, edges);
    addEdge(4, 5, 10, edges);
    addEdge(5, 6, 2, edges);
    addEdge(6, 7, 1, edges);
    addEdge(6, 8, 6, edges);
    addEdge(7, 8, 7, edges);

    // Kruskal's Algorithm MST
    sort(edges.begin(), edges.end(), comp);

    vector<int> Parent(N);
    for (int i = 0; i < N; i++)
        Parent[i] = i;

    vector<int> rank(N, 0);
    int WtMst = 0;
    vector<pair<int, int>> mst;

    for (auto i : edges)
    {
        if (findParent(i.u, Parent) != findParent(i.v, Parent))
        {
            WtMst += i.wt;
            mst.push_back({i.u, i.v});
            unionn(i.u, i.v, Parent, rank);
        }
    }
    cout << "Edges of MST are --> " << endl;
    for (auto i : mst)
        cout << i.first << " - " << i.second << endl;

    cout << "Total Weight of MST is --> " << WtMst << endl;
}