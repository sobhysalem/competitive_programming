vector < ll > fact(1e6 + 1, 1);
vector < ll > inv(1e6 + 1, 1);
ll modinv(ll a, ll m = MOD){
    ll y = 0, x = 1;
    if (m == 1) return 0;
    while (a > 1){
        ll q = a / m;
        ll t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0) x += MOD;
    return x;
}
void factorial(){
    for(int i = 2; i <= 1e6; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
    inv[1e6]=modinv(fact[1e6]);
    for(int i=1e6-1;i>=0;i--){
        (inv[i]=inv[i+1]*(i+1)%MOD);
    }
}

ll nCr(ll n, ll r){
    if(r > n) return 0;
    return (fact[n] * inv[r] % MOD * inv[n - r] % MOD) % MOD;
}
