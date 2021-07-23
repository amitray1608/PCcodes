
#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  string s, t;
  cin >> s >> t;
  int n = s.size();
  int m = t.size();
  vector<ll> power(max(n, m));
  power[0] = 1;
  for (ll i = 1; i < (int) power.size(); i++) {
      power[i] = (power[i - 1] * 31) % MOD;
  }
  auto get_hash = [&](string x) {
    ll p = 1;
    int N = x.size();
    vector<ll> h(N + 1, 0);
    for (int i = 0; i < N; i++) {
      h[i + 1] = (h[i] + (x[i] - 'a' + 1) * power[i]) % MOD;
    }
    return h;
  };

  vector<ll> hash = get_hash(s);
  vector<ll> pat = get_hash(t);
  ll p_has = pat.back();

  int count = 0;
  for (int i = 0; i + m - 1 < n; i++) {
    ll now = (hash[i + m] + MOD - hash[i]) % MOD;
      if (now == p_has * power[i] % MOD) count++; 
  }
  cout << count << '\n';
  return 0;
} //Hajimemashite

