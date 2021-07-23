
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    vector<int> res(n, 0);
    for (int i = 1; i < n; i++) {
      int curr = a[i - 1];
      int extra = 0;
      for (int bit = 0; bit < 30; bit++) {
        int m = (1 << bit);
        if (m & curr) {
          if ((a[i] & m) == 0) extra |= m;
        }
      }
      res[i] = extra;
      a[i] |= res[i];
    }
    for (int i = 0; i < n; i++) {
      cout << res[i] << ' ';
    } cout << '\n';
  }	
  return 0;
} //Hajimemashite

