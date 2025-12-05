#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

void printPath(int v, vector<int> &parent) {
    if (v == -1) return;
    vector<int> path;
    while (v != -1) {
        path.push_back(v);
        v = parent[v];
    }
    reverse(path.begin(), path.end());

    for (int x : path) cout << x << " ";
}

void dijkstra(int n, int src, vector<vector<pair<int,int>>> &adj) {
    vector<long long> dist(n, INF);
    vector<int> parent(n, -1);

    priority_queue<pair<long long,int>,
                   vector<pair<long long,int>>,
                   greater<pair<long long,int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        pair<long long,int> top = pq.top();
        pq.pop();

        long long d = top.first;
        int u = top.second;

        if (d != dist[u]) continue;

        for (auto &edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "\nShortest distances from source " << src << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "dist[" << i << "] = " << dist[i] << "\n";
    }

    cout << "\nPaths:\n";
    for (int i = 0; i < n; i++) {
        cout << "Path to " << i << ": ";
        printPath(i, parent);
        cout << "\n";
    }
}

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n);

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int src;
    cout << "Enter source: ";
    cin >> src;

    dijkstra(n, src, adj);

    return 0;
}
