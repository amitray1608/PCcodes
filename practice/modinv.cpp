#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;


void Modinv(int n) {
  vector<int>inv(n+1, 0);
  inv[0] = inv[1] = 1;
  for(int i = 2; i <= n; ++i)
    inv[i] = MOD - (MOD/i) * inv[MOD%i] % MOD;
  for(int i : inv)
    cout << i%MOD <<  ' ';
  cout << endl;
}

void modularInverse(ll n) { 
  ll dp[n + 1]; 
  dp[0] = dp[1] = 1; 
  for (ll i = 2; i <= n; i++)  
    dp[i] = dp[MOD % i] * (MOD - MOD / i) % MOD;     
} 

ll modinv(ll b, ll n) {
  ll ans = 1;
  while(n > 0) {
    if(n&1) ans = ans * b % MOD; 
    b = b * b % MOD;
    n >>= 1;
  }
  return ans%MOD;
} 

int main() {
  int n;
  cin >> n;
  ll ans = modinv(n, MOD-2);
  cout << ans << endl;
  Modinv(n);
  modularInverse(n, MOD);
  return 0;
}
