

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
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int res = 0;
    sort(a.begin(), a.end());
    vector<int> p(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      p[i] = p[i - 1] + a[i - 1];
    }
    for (int i = 3; i <= n; i++) {
      int curr = p[i - 2];
      curr -= (a[i - 1] * (i - 2));
      res += curr;
    }
    cout << res << '\n';
  }	
  return 0;
} //Hajimemashite




