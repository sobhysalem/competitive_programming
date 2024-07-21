#include<bits/stdc++.h>
#define  ll  long long

#define Hakuna_Matata ios_base::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;

const int mod=1e9+7;
struct Node{
    int ind;
    int l;
    int r;
};
struct Segment_Tree {
    vector<int>seg;
    int siz=1;
    Segment_Tree(int n){
        while(siz<=n)siz*=2;
        seg=vector<int>(siz*2,0);
    }
     int merge(ll a, ll b) {
        return ((a%mod) *(b%mod))%mod;
    }

    int query(int idx, int lx, int rx, int l, int r) {
        if (lx >= l && rx <= r) {
            return seg[idx]%mod;
        }
        int mid = (lx + rx) >> 1;
        if (l <= mid && r > mid) {
            return merge(query(idx * 2, lx, mid, l, r), query(idx * 2ll + 1, mid + 1, rx, l, r))%mod;
        } else if (r <= mid) {
            return query(idx * 2, lx, mid, l, r);
        } else {
            return query(idx * 2 + 1, mid + 1, rx, l, r);
        }
    }
    int query(int l,int r){
        return query(1,1,siz,l,r);
    }
   void update(int idx,int lx,int rx,int i,int v){
    if(lx>i||rx<i)return;
    if(lx==rx){
        seg[idx]+=v;
        seg[idx]%=mod;
        return;
    }
    int mid=(lx+rx)>>1;
    update(2ll*idx,lx,mid,i,v);
    update(2ll*idx+1,mid+1,rx,i,v);
    seg[idx]= merge(seg[2 * idx], seg[2 * idx + 1]);
}
    void update(int i,int v){
        update(1,1,siz,i,v);
    }
};
const int N=3e5+5;
vector<int>v(N);

void solve(){


   int n,q;
   cin>>n>>q;
   Segment_Tree se(N);
   vector<int>ans;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        ans.push_back(v[i]);

    }
    vector<Node>qu(q);
    int j=0;
    while(j<q){
        int op;
        cin>>op;
        qu[j].ind=(op);
        if(op==1){
            int ind,vl2;
            cin>>ind>>vl2;
            qu[j].l=(ind);
            qu[j].r=(vl2);
            ans.push_back(vl2);
        }
        else{
            int l,r;
            cin>>l>>r;
           qu[j].l=(l);
           qu[j].r=(r);

        }
        j++;
    }
    map<int,int>mp;
    sort(ans.begin(),ans.end());
    int x=1;
    mp[ans[0]]=x++;
    for(int i=1;i<ans.size();i++){
        if(ans[i]!=ans[i-1])mp[ans[i]]=x++;
    }
    for(int i=1;i<=n;i++){
        se.update(mp[v[i]],1);
    }
    //cout<<se.query(1,3)<<'\n';
    for(int i=0;i<q;i++){
        if(qu[i].ind==1){
            int ind=qu[i].l,vl=qu[i].r;
            if(v[ind]==vl)continue;
            se.update(mp[v[ind]],-1);
            se.update(mp[vl],1);
            v[ind]=vl;
        }
        else{
            int l=qu[i].l,r=qu[i].r;
            if(mp[r]-mp[l]<r-l){
                cout<<0<<'\n';
                continue;
            }
            cout<<se.query(mp[l],mp[r])<<'\n';
        }
    }

}

int main()
{

    Hakuna_Matata;
   int t=1;
   cin>>t;

   while(t--){
   solve();
   }
    return 0;
}


