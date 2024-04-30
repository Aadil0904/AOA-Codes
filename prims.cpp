#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
typedef pair<int, int> iPair;

void addEdge(vector<iPair> adj[], int u, int v, int wt) {
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

void primMST(vector<iPair> adj[], int V, int src) {
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vector<int> key(V, INF); 
    vector<int> parent(V, -1); 
    vector<bool> inMST(V, false);
    pq.push(make_pair(0, src));
    key[src] = 0;
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        inMST[u] = true;
        
        for (auto x : adj[u]) {
            int v = x.first;
            int weight = x.second;
            
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
    
    printf("Edge   Weight\n");
    for (int i = 1; i < V; ++i)
        printf("%d - %d    %d \n", parent[i], i, key[i]);
}

int main() {
    int V, a, b, c;
    cin >> V;
    vector<iPair> adj[V];
    
    while (cin >> a >> b >> c) {
        addEdge(adj, a, b, c);
    }

    primMST(adj, V, 0);
    return 0;
}
