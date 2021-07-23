
#include<bits/stdc++.h>

using namespace std;
#define int int64_t
const int MOD = 1e9 + 7;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) {
      cin >> i;
    }
    int zero = -1, times = 0, res = 0; 
    for (int i = 0; i < n; i++) {
      zero &= a[i];
    }
    for (int i = 0; i < n; i++) {
      times += (a[i] == zero);
    }
    if (times < 2) {
      res = 0;
    } else {
      res = times * (times - 1);
      res %= MOD;
      for (int i = 1; i < n - 1; i++) {
        res = (res * i) % MOD;
      }
    }
    cout << res << '\n';
  }
  return 0;
} //Hajimemashite

