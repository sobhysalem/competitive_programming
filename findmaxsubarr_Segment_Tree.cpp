#include<bits/stdc++.h>
#define  ll int long long
#define  pr priority_queue<int>
#define vll vector<ll>
#define vvll vector<vll>
#define all(vc) ((vc).begin()), ((vc).end())
#define Hakuna_Matata ios_base::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
#define  pq1  priority_queue <pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<int>>
using namespace std;
template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
    for (auto &x: v) in >> x;
    return in;
}
template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) {
    for (const T &x: v) out << x << ' ';
    return out;
}
struct Segment_Tree {
        struct Node{
            ll mx_sum,mx_pre,mx_suf,sum;
            Node(ll v=0){
                mx_sum=v;
                mx_pre=v;
                mx_suf=v;
                sum=v;
            }
        };
    vector<Node> seg;
    vector<int> nums;
    int siz=1;
    Segment_Tree(int n,vector<int>&nums){
        while (siz<=n)siz*=2;
        seg=vector<Node>(2*siz);
        this->nums=nums;
        build(1,1,siz,1,n);
    }
    Node merge(Node a,Node b) {
        Node ret;
        ret.sum=a.sum+b.sum;
        ret.mx_sum=max({a.mx_sum,b.mx_sum,a.mx_suf+b.mx_pre});
        ret.mx_pre=max({a.mx_pre,a.sum+b.mx_pre});
        ret.mx_suf=max({a.mx_suf+b.sum,b.mx_suf});
        return ret;
    }
    void build(int idx, int lx, int rx,int l,int r) {
        if (lx > r || rx < l)return;
        if (lx == rx) {
            seg[idx] = Node(nums[lx - 1]);
            return;
        }
        int mid = (lx + rx) >> 1;
        build(2 * idx, lx, mid,l,r);
        build(2 * idx + 1, mid + 1, rx,l,r);
        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    Node query(int idx, int lx, int rx, int l, int r) {
        if (lx >= l && rx <= r) {
            return seg[idx];
        }
        int mid = (lx + rx) >> 1;
        if (l <= mid && r > mid) {
            return merge(query(idx * 2, lx, mid, l, r), query(idx * 2 + 1, mid + 1, rx, l, r));
        } else if (r <= mid) {
            return query(idx * 2, lx, mid, l, r);
        } else {
            return query(idx * 2 + 1, mid + 1, rx, l, r);
        }
    }
    ll query(int l,int r){
        return query(1,1,siz,l,r).mx_sum;
    }
    void update(int idx,int lx,int rx,int i,int v){
        if(lx>i||rx<i)return;
        if(lx==rx){
            seg[idx]=v;
            return;
        }
        int mid=(lx+rx)>>1;
        update(2*idx,lx,mid,i,v);
        update(2*idx+1,mid+1,rx,i,v);
        seg[idx]= merge(seg[2 * idx], seg[2 * idx + 1]);
    }
    void update(int i,int v){
        update(1,1,siz,i,v);
    }
};

void solve(){
    int n;
     cin>>n;
     vector<int>v(n);
     cin>>v;
     Segment_Tree tr(n,v);
     ll mx=LONG_LONG_MAX;
     //mx=tr.query(1,n-1);
     for(int i=2;i<=n;i++){
        mx=min(abs(max(tr.query(1,i-1),0ll)-max(tr.query(i,n),0ll)),mx);
     }
     cout<<mx<<'\n';

}

int main()
{

    Hakuna_Matata;

   int t=1;
  cin>>t;
   //SPF();
   //pre();
   while(t--){
   solve();
   }
    return 0;
}








// 1 2



