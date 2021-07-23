
#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const ll MOD = 1.0e9 + 7;
const ll maxn = 2e6 + 1;
const ll base = 31;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  vector<ll> power(maxn, 1);
  for (int i = 1; i < maxn; i++) {
    power[i] = (power[i - 1] * base) % MOD;
  }
  for (int tt = 1; tt <= t; ++tt) {
    string s;
    cin >> s;
    s = s + s;
    int n = (int)s.size() * 2;
    vector<ll> hash(n + 1, 0);
    hash[0] = (s[0] - 'a' + 1);
    for (int i = 1; i < n; i++) {
      hash[i] = (hash[i - 1] + (s[i] - 'a' + 1) * power[i]) % MOD;
    }
    string st = string(s.rbegin(), s.rend());
    vector<ll> hashr(n + 1, 0);
    hashr[0] = (st[0] - 'a' + 1);
    for (int i = 1; i < n; i++) {
      hashr[i] = (hashr[i - 1] + (st[i] - 'a' + 1) * power[i]) % MOD;
    }
    ll count = 0;
    for (int i = 0; i < n / 2; i++) {
      ll pre = ((hash[i + n] - (!i ? 0 : hash[i - 1])) * power[i]) % MOD;
      ll suf = ((hashr[n - i] - (!i ? 0 : hashr[i - 1]) * power[i]) % MOD;
      if (pre == suf) count++;
    }
    cout << count << '\n';
  }	
  return 0;
} //Hajimemashite

