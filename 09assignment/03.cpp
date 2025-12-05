#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (1LL<<60);

struct Edge {
    int u, v;
    ll w;
    Edge(int _u=0,int _v=0,ll _w=0): u(_u), v(_v), w(_w) {}
};

struct DSU {
    vector<int> parent, rankv;
    DSU(int n=0){ parent.resize(n); rankv.assign(n,0); iota(parent.begin(), parent.end(), 0); }
    int find(int x){ return parent[x]==x ? x : parent[x]=find(parent[x]); }
    bool unite(int a, int b){
        a = find(a); b = find(b);
        if(a==b) return false;
        if(rankv[a] < rankv[b]) swap(a,b);
        parent[b] = a;
        if(rankv[a]==rankv[b]) rankv[a]++;
        return true;
    }
};

pair<vector<Edge>, ll> kruskal(int n, vector<Edge> &edges) {
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b){
        if(a.w != b.w) return a.w < b.w;
        if(a.u != b.u) return a.u < b.u;
        return a.v < b.v;
    });

    DSU dsu(n);
    vector<Edge> mstEdges;
    ll total = 0;
    for(const Edge &e : edges){
        if(dsu.unite(e.u, e.v)){
            mstEdges.push_back(e);
            total += e.w;
        }
    }
    return {mstEdges, total};
}

ll prim_from(int start,
             const vector<vector<pair<int,ll>>> &adj,
             vector<int> &parent,
             vector<ll> &key,
             vector<char> &inMST)
{
    int n = (int)adj.size();
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    key[start] = 0;
    pq.push({0, start});
    ll total = 0;

    while(!pq.empty()){
        pair<ll,int> top = pq.top(); pq.pop();
        ll w = top.first;
        int u = top.second;
        if(inMST[u]) continue;
        inMST[u] = 1;
        total += w;

        for(const auto &pr : adj[u]){
            int v = pr.first;
            ll wt = pr.second;
            if(!inMST[v] && wt < key[v]){
                key[v] = wt;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }
    return total;
}

pair<vector<Edge>, ll> prim_all(int n, const vector<vector<pair<int,ll>>> &adj) {
    vector<int> parent(n, -1);
    vector<ll> key(n, INF);
    vector<char> inMST(n, 0);
    vector<Edge> chosen;
    ll total = 0;

    for(int i = 0; i < n; ++i){
        if(!inMST[i]){
            ll compSum = prim_from(i, adj, parent, key, inMST);
            total += compSum;
        }
    }

    for(int v = 0; v < n; ++v){
        if(parent[v] != -1){
            chosen.emplace_back(parent[v], v, key[v]);
        }
    }
    return {chosen, total};
}

void printEdges(const vector<Edge> &edges) {
    for(const auto &e : edges){
        cout << (e.u + 1) << " -> " << (e.v + 1) << " : " << e.w << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if(!(cin >> n >> m)){
        cerr << "Failed to read n and m\n";
        return 1;
    }

    vector<Edge> edges;
    edges.reserve(m);
    vector<vector<pair<int,ll>>> adj(n);

    for(int i = 0; i < m; ++i){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        --u; --v;
        if(u < 0 || u >= n || v < 0 || v >= n){
            cerr << "Vertex index out of range\n";
            return 1;
        }
        edges.emplace_back(u, v, w);
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    auto prim_res = prim_all(n, adj);
    cout << "Prim's algorithm (Minimum Spanning Forest) edges:\n";
    printEdges(prim_res.first);
    cout << "Total weight (Prim): " << prim_res.second << "\n\n";

    auto edges_copy = edges;
    auto kruskal_res = kruskal(n, edges_copy);
    cout << "Kruskal's algorithm (Minimum Spanning Forest) edges:\n";
    printEdges(kruskal_res.first);
    cout << "Total weight (Kruskal): " << kruskal_res.second << "\n\n";

    if(prim_res.second == kruskal_res.second){
        cout << "Note: Total weights match (" << prim_res.second << ").\n";
    } else {
        cout << "Warning: Total weights differ (Prim: " << prim_res.second
             << ", Kruskal: " << kruskal_res.second << "). This can happen if graph is disconnected\n"
             << "and different valid minimum spanning forests (same total weight normally for same components) or due to numeric issues.\n";
    }

    return 0;
}
