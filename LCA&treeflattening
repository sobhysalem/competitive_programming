const int N = 1e5+5;  // Adjust as needed
vector<vector<int>> up(N,vector<int>(20));
vector<vector<int>> adj(N);
vector<int>depth(N), in_time(N), out_time(N);
int l=20, timer = 0;

void dfs(int u,int p){
    in_time[u]=++timer;
    for(auto i:adj[u]){
        if(i==p)continue;
        up[i][0]=u;
        for(int j=1;j<l;j++){
            up[i][j]=up[up[i][j-1]][j-1];
        }
        depth[i]=depth[u]+1;
        dfs(i,u);
    }
    out_time[u]=++timer;
}
int get_LCA(int u,int v){
    if(depth[u]<depth[v])swap(u,v);
    int k=depth[u]-depth[v];
    for(int i=0;i<l;i++){
        if(k&(1<<i)){
            u=up[u][i];
        }
    }
    if(u==v){
        return u;
    }
    for(int i=l-1;i>=0;i--){
        if(up[u][i]!=up[v][i]){
            u=up[u][i];
            v=up[v][i];
        }
    }
    return up[u][0];
}
