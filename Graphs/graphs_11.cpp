// Prim's Algorithm [Minimum Spanning Tree (MST)] -->
// A Graph which contains N number of Nodes and n-1 number of Edges. A Graph should not contain a cycle.

// Brute Force --> It uses three different arrays -- MSTSet[], keywt[], parent[]
// Efficient Approach --> It uses Priority Queue

/*
Algorithm -->

Initially take that node from keywt array which is not a part of mstSet[] i.e. node 0 initially and 

then make it true in the mstSet[] and then check its adjacent nodes and 

in the keywt[] marks the indexes as the size of the weights of adj nodes and mark the parent of those adj nodes in parent[] and 

again traverse through the keywt array to find the minimum weight and 

again repeat the process of finding adj nodes and marking their weights and their parents in keywt[] and parent[] respectively.
*/
#include <bits/stdc++.h>
using namespace std;

// Initially by Brute Force
void addEdge(int a, int b, int wt, vector<pair<int, int>> adj[])
{
    adj[a].push_back(make_pair(b, wt));
    adj[b].push_back(make_pair(a, wt));
}
void mst(int N, vector<pair<int, int>> adj[]) // TC : > O(N^2)
{
    bool mstSet[N]; // its a flag array that tells whether the node is a pat of MST or not
    int keywt[N];   // contains Edge Weights
    int parent[N];  // contains the Parent/Previous node of its adjacent nodes
    for (int i = 0; i < N; i++)
        mstSet[i] = false, keywt[i] = INT_MAX;

    keywt[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < N - 1; count++) // edges are n-1
    {
        // we find the minimal index in the keywt[],
        // miniNode is also behaving as temporary container for keywt[]
        int miniNode = INT_MAX, u;
        // (node value), (index)

        for (int v = 0; v < N; v++) // traversing through the nodes
            if (mstSet[v] == false && keywt[v] < miniNode)
                // here we find the minimum keywt/node index and checks if it is present in mstSet or not
                miniNode = keywt[v], u = v;

        mstSet[u] = true;

        for (auto it : adj[u]) // traversing the keywt arrays' adj nodes having minimum wt
        {
            int v = it.first;                        // adj node
            int wt = it.second;                      // weight of adj nodes
            if (mstSet[v] == false && wt < keywt[v]) // keywt[] is containing wts
            {
                parent[v] = u; // assigning the parent of the adj nodes in the parent array
                keywt[v] = wt;
            }
        }
    }
    cout << "Edge"
         << "\t"
         << "Weight" << endl;
    for (int i = 1; i < N; i++)
    {
        cout << parent[i] << " - " << i << " \t" << keywt[i] << endl;
    }
}
void mstPQ(int N, vector<pair<int, int>> adj[]) // TC : O(Nlogn)
{
    bool mstSet[N]; // its a flag array that tells whether the node is a pat of MST or not
    int keywt[N];   // contains Edge Weights
    int parent[N];  // contains the Parent/Previous node of its adjacent nodes
    for (int i = 0; i < N; i++)
        mstSet[i] = false, keywt[i] = INT_MAX;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    keywt[0] = 0;
    parent[0] = -1;
    pq.push({0, 0}); // key,index
    for (int count = 0; count < N - 1; count++)
    {
        int u = pq.top().second; // the index at which minimal value is placed
        pq.pop();
        mstSet[u] = true;
        for (auto it : adj[u])
        {
            int v = it.first;
            int wt = it.second;
            if (mstSet[v] == false && keywt[v] > wt)
            {
                parent[v] = u;
                pq.push({keywt[v], v});
                keywt[v] = wt;
            }
        }
    }
    cout << "Edge"
         << "\t"
         << "Weight" << endl;
    for (int i = 1; i < N; i++)
    {
        cout << parent[i] << " - " << i << " \t" << keywt[i] << endl;
    }
}
int main()
{
    int v = 5;
    vector<pair<int, int>> adj[v];
    addEdge(0, 1, 2, adj);
    addEdge(1, 2, 3, adj);
    addEdge(0, 3, 6, adj);
    addEdge(1, 3, 8, adj);
    addEdge(1, 4, 5, adj);
    addEdge(2, 4, 7, adj);

    // Brute Force
    mst(v, adj);

    // Efficient
    mstPQ(v, adj);
}