ll fpow(ll x,ll y){
    ll prod = x,ans = 1;
    while(y){
        if(y&1)ans*=prod,ans%=mod;
        prod*=prod;
        prod%=mod;
        y>>=1;
    }
    return ans;
}
//modinv a/b=a*fpow(b,mod-2)%mod
