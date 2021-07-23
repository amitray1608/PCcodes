
#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const ll MOD = 1.0E9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  string s;
  cin >> s;
  int n = s.length();
  vector<ll> pre(n + 1, 0);
  vector<ll> power(n, 1);
  for (int i = 1; i < n; i++) {
    power[i] = (power[i - 1] * 31) % MOD;
  }
  pre[0] = s[0] - 'a' + 1;
  for (int i = 1; i < n; i++) {
    pre[i] = (pre[i - 1] + (s[i] - 'a' + 1) * power[i]) % MOD;
  }
  for (int i = 0; i < n; ++i) {
    if (pre[i] * power[n - i - 1] % MOD == (pre[n - 1] - pre[n - i - 2]) % MOD) {
      cout << i + 1 << ' ';
    }
  }
  return 0;
} //Hajimemashite

