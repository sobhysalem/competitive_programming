const int N = 1e5+5;  
vector<pair<int, int>> adj[N]; 

vector<long long> Dijkstra(int src, int n) {
    vector<long long> dist(n + 5, -1);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> q;
    q.push({0, src});
    while (!q.empty()) {
        int u = q.top().second;
        long long cost = q.top().first;
        q.pop();
        if (dist[u] != -1) continue;
        dist[u] = cost;
        for (auto &[v, w] : adj[u]) {
            if (dist[v] == -1) {
                q.push({cost + w, v});
            }
        }
    }
    return dist;
}
