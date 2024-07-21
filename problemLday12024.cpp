#include<bits/stdc++.h>
#define  ll  long long
#define Hakuna_Matata ios_base::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
const int N=3e5+7;
int spf[N];
void SPF(){
    for(int i=2;i<N;i++){
        if(!spf[i]){
            for(int j=i;j<N;j+=i){
                if(!spf[j])spf[j]=i;
            }
        }
    }
}
vector<vector<int>>adj(N);
ll cnt;
vector<int>vis(N);
void dfs(int ch){
     vis[ch]=1;
     for(auto it:adj[ch]){
         if(!vis[it]){
            cnt++;
            dfs(it);
         }
     }
}
void solve(){
  ll n;
  cin>>n;
  spf[1]=0;
  ll ans=(n*(n-1))/2ll;
  for(int i=0;i<=n;i++)vis[i]=0;
  for(int i=1;i<n;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    if(spf[u]==u)vis[u]=1;
    if(spf[v]==v)vis[v]=1;
  }
  for(int i=1;i<=n;i++){
    if(!vis[i]){
        cnt=0;
        dfs(i);
        ans-=(cnt*(cnt+1))/2ll;
    }
  }
  cout<<ans;

}

int main()
{

    Hakuna_Matata;
   int t=1;
  // cin>>t;
  SPF();
   while(t--){
   solve();
   }
    return 0;
}








// 1 2



















 
