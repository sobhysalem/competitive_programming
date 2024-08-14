
void factorial(){
    for(int i = 2; i <= 1e6; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
}
 
ll nCr(ll n, ll r){
    if(r > n) return 0;
    return (fact[n] * modinv(fact[r]) % MOD * modinv(fact[n - r]) % MOD) % MOD;
}
 
// NPR =fact(n)/fact(n-r);
ll NpR(ll n, ll r){
	ll ans = 1;
	for (ll i = (n - r) + 1; i <= n; i++){
		ans *= i;
		ans %= MOD;
	}
	return ans;
}
