const int SQ=175,Q=2e5+7;
struct query{
    int l,r,q_idx,block_idx;
    query(){}
    query(int L, int R, int Q_idx)
    {
        l= L , r= R , q_idx=Q_idx, block_idx= L / SQ;
    }
    bool operator<(const query&y)const{
        if(block_idx!=y.block_idx)
        {
            return block_idx<y.block_idx;
        }
        return r<y.r;
    }
};
int q_ans[Q],q;
vector<int>vis(M),a(N);
int ans;
query queries[Q];
void add(int idx)
{
    ans+=!vis[a[idx]]++;
}
void remove(int idx)
{
    ans-=!(--vis[a[idx]]);
}
void MO_process()
{
    sort(queries,queries+q);
    int l=1,r=0;
    for(int i=0;i<q;i++)
    {
        while(r<queries[i].r)add(++r);
        while(r>queries[i].r)remove(r--);
        while(l<queries[i].l)remove(l++);
        while(l>queries[i].l)add(--l);
        q_ans[queries[i].q_idx]=ans;
    }
}
void burn() {
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>q;
    for(int i=0;i<q;i++){
        int l,r;cin>>l>>r;
        queries[i]={--l,--r,i};
    }
    MO_process();
    for(int i=0;i<q;i++){
        cout<<q_ans[i]<<'\n';
    }
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T = 1;//cin>>T;
    while (T--) {
        burn();
        cout << '\n';
    }
    return 0;
}
