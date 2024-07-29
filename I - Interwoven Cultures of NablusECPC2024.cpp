#include<bits/stdc++.h>
#define  ll  long long
#define Hakuna_Matata ios_base::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;

void solve(){
     int  n;
     cin>>n;
     string s;
     cin>>s;
     vector<int>v(n);
     for(int i=0;i<n;i++){
        cin>>v[i];
     }
     int ans=0;
     for(int i=0;i<n;i++){
        ll sum=0,xr=0;
        for(int j=i;j<min(i+32,n);j++){
            sum+=v[j];
            xr^=v[j];
            if(sum==xr){
                int l=i,r=j;
                bool flag=1;
                while(l<=r){
                    if(s[l]!=s[r]){
                        flag=0;
                        break;
                    }
                    l++;
                    r--;
                }
                if(flag){
                    ans=max(ans,j-i+1);
                }
            }
        }
     }
     cout<<ans<<'\n';

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








// 1 2




















