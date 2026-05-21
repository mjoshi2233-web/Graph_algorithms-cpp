#include<iostream>
#include<vector>
using namespace std;

struct Edge
{
    int u, v, w;
};

void bellmanFord(int V, int E, vector<Edge>& edges, int src)
{
    vector<int> dist(V, 1e9);

    dist[src] = 0;

    for(int i = 0; i < V - 1; i++)
    {
        for(int j = 0; j < E; j++)
        {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if(dist[u] != 1e9 && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    for(int j = 0; j < E; j++)
    {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if(dist[u] != 1e9 && dist[u] + w < dist[v])
        {
            cout << "Negative Weight Cycle";
            return;
        }
    }

    for(int i = 0; i < V; i++)
        cout << dist[i] << " ";
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<Edge> edges(E);

    for(int i = 0; i < E; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    int src;
    cin >> src;

    bellmanFord(V, E, edges, src);

    return 0;
}
