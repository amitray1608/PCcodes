
#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const ll MOD   = 1.0E10 + 9;
const ll base = 41;
const ll maxn = 1e6 + 1;
#define deb(x) cout << #x << " = " << x << endl;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  vector<ll> power(maxn, 1);
  for (int i = 1; i < maxn; i++) 
    power[i] = (power[i - 1] * base) % MOD;
  for (int tt = 1; tt <= t; ++tt) {
    string s;
    cin >> s;
    int n = (int)s.size();
    int left = 0, right = n - 1;
    while (left <= right and s[left] == s[right]) {
      left++, right--;
    }
    if (left > right) {
      cout << s << '\n';
      continue;
    }
    string tp = "";
    for (int i = 0; i < left; i++) tp += s[i];
    string res = "";
    for (int i = left; i <= right; i++) {
      res += s[i];
    }
    s = res;
    n = (int)s.size();
    res = tp;
    auto getLPF = [&](string x) {
      ll ha = 0, hr = 0;
      ll m1 = 1;
      ll pos = n - 1;
      for (int i = 0; i < n; i++) {
        ha = (ha + m1 * x[i]) % MOD;
        hr = (hr * base + x[i]) % MOD;
        m1 = (m1 * base) % MOD;
        if (ha == hr) {
          pos = i;
        }
      }
      return pos;
    };
    int posp = getLPF(s);
    string revs = s;
    reverse(revs.begin(), revs.end());
    int poss = getLPF(revs);
    if (posp < poss)
      posp = poss, s = revs;
    s.erase(posp + 1);
    s = res + s;
    reverse(res.begin(), res.end());
    s += res;
    cout << s << '\n';
  }	
  return 0;
} //Hajimemashite

