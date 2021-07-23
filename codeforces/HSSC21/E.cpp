
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n, m;
    cin >> n >> m;
    vector<int> f(1e6, 0), res;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    for (int i = 1; i <= n; i++) {
      int x = (i - a[i - 1] + n) % n;
      f[x]++;
    }
    for (int i = 0; i < (int)1e6; i++) {
      if ((m << 1) >= n - f[i])
        res.push_back(i);
    }
    cout << res.size() << ' ';
    for (int i : res) cout << i << ' ';
    cout << '\n';
  }	
  return 0;
} //Hajimemashite

