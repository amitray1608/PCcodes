
#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const ll MOD = 1.0e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    string s, p;
    cin >> s >> p;
    int n, m;
    n = (int)s.size();
    m = (int)p.size();
    vector<ll> power(max(n, m), 1);
    for (int i = 1; i < max(n, m); i++) {
      power[i] = (power[i - 1] * 31) % MOD;
    }
    auto get = [&](string x) {
      int N = (int)x.size();
      vector<ll> a(N + 1);
      for (int i = 0; i < N; i++) {
        a[i + 1] = (a[i] + (x[i] - 'a') * power[i]) % MOD;
      }
      return a;
    };
    vector<ll> hash = get(s);
    vector<ll> pat = get(p);
    vector<int> pos;
    ll req = pat.back();
    for (int i = 0; i + m - 1 < n; i++) {
      ll now = (hash[i  + m] + MOD - hash[i]) % MOD;
      if (now == req * power[i] % MOD)
        pos.push_back(i);
    }
    if (pos.size() == 0) {
      cout << "Not Found" << '\n';
    } else {
      cout << pos.size() << '\n';
      for (int &i : pos) {
        cout << i + 1 << ' ';
      }
      cout << '\n';
    } cout << '\n';
  }	
  return 0;
} //Hajimemashite

