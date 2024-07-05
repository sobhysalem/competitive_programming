const int MAX = 1e6 + 5;
int parent[MAX], cnt[MAX];
void initialize(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        cnt[i] = 1;
    }
}
int find(int u) {
    if (u != parent[u]) {
        parent[u] = find(parent[u]); // Path compression
    }
    return parent[u];
}
void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        parent[v] = u;
        cnt[u] += cnt[v];
    }
}


