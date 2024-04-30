#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
typedef pair<int, int> iPair;

void addEdge(vector<iPair> adj[], int u, int v, int wt) {
    adj[u].push_back(make_pair(v, wt));
}

void BellmanFord(vector<iPair> adj[], int V, int src) {
    vector<int> dist(V, INF);
    dist[src] = 0;
    
    for (int i = 0; i < V - 1; ++i) {
        for (int u = 0; u < V; ++u) {
            for (auto x : adj[u]) {
                int v = x.first;
                int weight = x.second;
                
                if (dist[u] != INF && dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }
    
    for (int u = 0; u < V; ++u) {
        for (auto x : adj[u]) {
            int v = x.first;
            int weight = x.second;
            
            if (dist[u] != INF && dist[v] > dist[u] + weight) {
                cout << "Graph contains negative weight cycle" << endl;
                return;
            }
        }
    }
    
    // Print shortest distances
    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < V; ++i) {
        cout << i << "\t\t" << dist[i] << endl;
    }
}

int main() {
    int V, a, b, c;
    cin >> V;
    vector<iPair> adj[V];
    
    while (cin >> a >> b >> c) {
        addEdge(adj, a, b, c);
    }

    BellmanFord(adj, V, 0);
    return 0;
}
