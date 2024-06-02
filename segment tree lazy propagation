#include<bits/stdc++.h>
#define  ll  long long int
#define  pr priority_queue<int>
#define vll vector<ll>
#define vvll vector<vll>
#define all(vc) ((vc).begin()), ((vc).end())
#define Hakuna_Matata ios_base::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
#define PI acos(-1)
#define inf 1000000000000000
#define low lower_bound(arr, arr + n, x)
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
void solve(){
}
int main() {
Hakuna_Matata;
   int t=1;
  //cin>>t;

   while(t--){
    solve();
   }

    return 0;
}

