#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void dijkstra(int V, vector<pair<int,int>> adj[], int src)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    vector<int> dist(V, 1e9);

    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty())
    {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it : adj[node])
        {
            int adjNode = it.first;
            int wt = it.second;

            if(d + wt < dist[adjNode])
            {
                dist[adjNode] = d + wt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    for(int i = 0; i < V; i++)
    cout << dist[i] << " ";
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<pair<int,int>> adj[V];

    for(int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int src;
    cin >> src;

    dijkstra(V, adj, src);

    return 0;
}
