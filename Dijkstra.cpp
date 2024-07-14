const int N = 1e5+5;

struct Edge {
    int node;
    ll w;
};

vector<Edge> adj1[N],adj2[N];

vector<ll> Dijkstra(int src, int n) {
    vector<ll> dist1(n + 1, -1);
    priority_queue<pair<ll, int>> pq;
    pq.push({0, src});
    while (!pq.empty()) {
        int u = pq.top().second;
        ll cost = pq.top().first;
        pq.pop();
         for (auto& e : adj1[u]) {
            int v = e.node;
            ll w = e.w;
           if (dist1[v]<cost+w ){
                dist1[v] =cost+w ;
                pq.push({cost + w, v});
             }
             }
    }
    return dist1;
}
