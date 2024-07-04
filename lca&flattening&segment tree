#include<bits/stdc++.h>
#define  ll  long long
#define Hakuna_Matata ios_base::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
    for (auto &x: v) in >> x;
    return in;
}
template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) {
    for (const T &x: v) out << x << ' ';
    return out;
}
struct Lazy_propagate{
            vector<ll>seg,lazy;
            vector<int>nums;
            int size=1;
        Lazy_propagate(int n,vector<int>&nums){
            while (size<=n)size*=2;
            this->nums=nums;
            seg=lazy=vector<ll>(2*size);
            build(1,size,1,n);
        }
        ll merge(ll a,ll b){
            return a+b;
        }
        void build(int lx,int rx,int idx,int n){
            if(lx>n)return;
            if(lx==rx){
                seg[idx]=nums[lx-1];
                return;
            }
            int mid=(lx+rx)>>1;
            build(lx,mid,2*idx,n);
            build(mid+1,rx,2*idx+1,n);
            seg[idx]=merge(seg[2*idx],seg[2*idx+1]);
        }
        void propagate(int idx,int lx,int rx){
            if(!lazy[idx])return;
            seg[idx]+=(rx-lx+1)*lazy[idx];
            if(lx!=rx){
                lazy[2*idx]+=lazy[idx];
                lazy[2*idx+1]+=lazy[idx];
            }
            lazy[idx]=0;
        }
        void update(int lx,int rx,int idx,int l,int r,int v){
            propagate(idx,lx,rx);
            if(lx>=l&&rx<=r){
                lazy[idx]+=v;
                propagate(idx,lx,rx);
                return;
            }
            int mid=(lx+rx)>>1;
            if(mid>=l &&r > mid){
                update(lx,mid,2*idx,l,r,v);
                update(mid+1,rx,2*idx+1,l,r,v);
            }
            else if(mid>=r){
                update(lx,mid,2*idx,l,r,v);
            }
            else{
                update(mid+1,rx,2*idx+1,l,r,v);
            }
            seg[idx]= merge(seg[2*idx],seg[2*idx+1]);
        }
        ll query(int lx,int rx,int idx,int l,int r){
            propagate(idx,lx,rx);
            if(lx>=l&&rx<=r){
                return seg[idx];
            }
            int mid=(lx+rx)>>1;
            if(mid>=l &&r > mid){
                return merge(query(lx,mid,2*idx,l,r), query(mid+1,rx,2*idx+1,l,r));
            }
            else if(mid>=r){
                return query(lx,mid,2*idx,l,r);
            }
            else{
                return query(mid+1,rx,2*idx+1,l,r);
            }
        }
        ll query(int l,int r){
            return query(1,size,1,l,r);
        }
        void update(int l,int r,int v){
            update(1,size,1,l,r,v);
        }
    };
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
void solve(){
     int n,q;cin>>n>>q;
  for(int i=1;i<n;i++){
    int u,v;cin>>u>>v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1,-1);
  vector<int>vec(n*2);
  Lazy_propagate lz(n*2,vec);
  while(q--){
    int u,v,x;
    cin>>u>>v>>x;

       int p=get_LCA(u,v);
        lz.update(in_time[p],in_time[v],x);
        lz.update(in_time[p],in_time[u],x);
        lz.update(in_time[p],in_time[p],-x);
  }
    for(int i=1;i<=n;i++){
        cout<<lz.query(in_time[i],in_time[i])-lz.query(out_time[i],out_time[i])<<' ';
    }

}



int main()
{

    Hakuna_Matata;
   int t=1;
  // cin>>t;
   while(t--){
   solve();
   }
    return 0;
}
