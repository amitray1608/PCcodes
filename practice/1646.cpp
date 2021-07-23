
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int &i : a) cin >> i;
  for (int i = 1; i < n; i++) a[i] += a[i - 1];
  while (q--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    cout << a[v] - (u == 0 ? 0 : a[u - 1]) << '\n';
  }
  return 0;
} //Hajimemashite

