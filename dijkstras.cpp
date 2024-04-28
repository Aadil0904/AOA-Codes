#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
typedef pair<int, int> iPair;

void addEdge(vector<iPair> adj[], int u, int v, int wt) {
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

void shortestPath(vector<iPair> adj[], int V, int src) {
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vector<int> dist(V, INF);
    pq.push(make_pair(0, src));
    dist[src] = 0;
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        for (auto x : adj[u]) {
            int v = x.first;
            int weight = x.second;
            
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main() {
    int V, a, b, c;
    cin >> V;
    vector<iPair> adj[V];
    
    while (cin >> a >> b >> c) {
        addEdge(adj, a, b, c);
    }

    shortestPath(adj, V, 0);
    return 0;
}
