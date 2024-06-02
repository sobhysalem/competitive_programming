#include<bits/stdc++.h>
#define  ll  long long
#define  pr priority_queue<int>
#define vll vector<ll>
#define vvll vector<vll>
#define all(vc) ((vc).begin()), ((vc).end())
#define Hakuna_Matata ios_base::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
#define vvll vector<vll>
#define inf 1000000000000000
#define low lower_bound(arr, arr + n, x)
using namespace std;
template < typename T = int > using Pair = pair < T, T >;
const int N=1e6+7;
template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
    for (auto &x: v) in >> x;
    return in;
}
template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) {
    for (const T &x: v) out << x << ' ';
    return out;
}

vector<ll>pw1(N),pw2(N);
vector<Pair<ll>>pre(N);
ll mod1=1e9+7,mod2=2e9+11,base1=31,base2=37,inv1,inv2;
ll fpow(ll x,ll y,ll mod){
    ll prod = x,ans = 1;
    while(y){
        if(y&1)ans*=prod,ans%=mod;
        prod*=prod;
        prod%=mod;
        y>>=1;
    }
    return ans;
}
void init(){
    inv1=fpow(base1,mod1-2,mod1);
    inv2=fpow(base2,mod2-2,mod2);
    pw1[0]=pw2[0]=1;
    for(int i=1;i<N;i++){
        pw1[i]=(pw1[i-1]*base1)%mod1;
        pw2[i]=(pw2[i-1]*base2)%mod2;
    }

}
struct Hashing{
    int len;
    ll h1,h2,v;
    deque<char>d;
    Hashing(){
        h1=h2=len=0;
    }
    void push_back(char c){
        v=c-'a'+1;
        h1=(h1*base1+v)%mod1;
        h2=(h2*base2+v)%mod2;
        d.push_back(c);
        len++;
    }
    void push_front(char c){
        v=c-'a'+1;
        h1=(pw1[len]*v+h1)%mod1;
        h2=(pw2[len]*v+h2)%mod2;
        d.push_front(c);
        len++;
    }
    void pop_back(){
        if(!len)return;
        v=d.back()-'a'+1;
        h1=(h1-v+mod1)%mod1;
        h1=(h1*inv1)%mod1;
        h2=(h2-v+mod2)%mod2;
        h2=(h2*inv2)%mod2;
        len--;
        d.pop_back();
    }
    void pop_front(){
        if(!len)return;
        v=d.front()-'a'+1;
        h1=((h1-v*pw1[len-1])%mod1+mod1)%mod1;
        h2=((h2-v*pw2[len-1])%mod2+mod2)%mod2;
        len--;
        d.pop_front();
    }
    void clear(){
        h1=h2=len=0;
        d.clear();
    }
    pair<ll,ll>get(){
        return {h1,h2};
    }
    pair<ll,ll> get_sub(int l,int r){
        ll a=((pre[r].first-(pw1[r-l+1]*pre[l-1].first))%mod1+mod1)%mod1;
        ll b=((pre[r].second-(pw2[r-l+1]*pre[l-1].second))%mod2+mod2)%mod2;
        return {a,b};
    }
};

void solve(){
    init();

   //cin>>n>>m;
   string s1,s2;
   cin>>s1>>s2;int n=s1.size(),m=s2.size();
   Hashing H1,H2;
   for(int i=0;i<n;i++){
         H1.push_back(s1[i]);
         pre[i+1]=H1.get();
     }
     for(int i=0;i<m;i++){
         H2.push_back(s2[i]);

     }
     pair<int,int> vl1=H2.get();
     int ans=0;
     for(int i=1;i+m-1<=n;i++){
          pair<int,int>vl2=H1.get_sub(i,i+m-1);
          if(vl2==vl1){
              ans++;
          }
     }
     cout<<ans;

}

int main()
{

    Hakuna_Matata;
   int t=1;
   //cin>>t;
   while(t--){
   solve();
   }
    return 0;
}








// 1 2





















