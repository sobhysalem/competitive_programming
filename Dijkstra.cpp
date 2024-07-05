#define  ll  long long
const int N = 1e5+5;  
vector<pair<int, int>> adj[N]; 

vector<long long> Dijkstra(int src, int n) {
    vector<ll> dist(n + 5, -1);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> q;
    q.push({0, src});
    while (!q.empty()) {
        int u = q.top().second;
       ll cost = q.top().first;
        q.pop();
        if (~dist[u]  continue;
        dist[u] = cost;
        for (auto &[v, w] : adj[u]) {
            if (~dist[v]) {
                q.push({cost + w, v});
            }
        }
    }
    return dist;
}
