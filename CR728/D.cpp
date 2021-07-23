
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<array<int, 2>> pos;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      pos.push_back({a[i], i});
    }
    int res = 0;
    vector<int> fre(1e6, 0);
    for (int i = 0; i < n; i++) {
      int curr = a[i];
      fre[curr]++;
      for (int j = curr; j < 2 * (i + 1); j += curr) {
        if (j <= i) continue;
        if ((j + 1) % a[i] == a[i]) res += fre[(j + 1) / a[i]] - 1;
        else res += fre[(j + 1) / a[i]];
      }
    }
    cout << res << '\n';
  }	
  return 0;
} //Hajimemashite





