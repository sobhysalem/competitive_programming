#include<bits/stdc++.h>
#define  ll  long long

#define Hakuna_Matata ios_base::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;

const int mod=1e9+7;

struct Segment_Tree {
    map<int,int>seg;
    int siz=1;
    Segment_Tree(int n){
        while(siz<=n)siz*=2;
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
const int N=1e5+5;
vector<int>v(N);

void solve(){


   int n,q;
   cin>>n>>q;
   Segment_Tree se((int)1e9);
    for(int i=1;i<=n;i++){
        cin>>v[i];
        se.update(v[i],1);

    }
    while(q--){
        int op;
        cin>>op;
        if(op==1){
            int ind,vl2;
            cin>>ind>>vl2;
            if(v[ind]==vl2)continue;
            se.update(v[ind],-1);
            se.update(vl2,1);
            v[ind]=vl2;
        }
        else{
            int l,r;
            cin>>l>>r;
            if(r-l+1>n){
                cout<<0<<'\n';
                continue;
            }
            cout<<se.query(l,r)<<'\n';
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



