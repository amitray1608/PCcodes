
#include<bits/stdc++.h>

using namespace std;
#define int int64_t
const int inf = 1e15;

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n, k;
    cin >> n >> k;
    vector<int> a(k), T(k);
    for (int &i : a) cin >> i;
    for (int &i : T) cin >> i;
    vector<int> pre(n + 2, inf);
    vector<int> suf(n + 2, inf);
    for (int i = 0; i < k; i++) {
      pre[a[i]] = T[i] - a[i];
      suf[a[i]] = T[i] + a[i];
    }
    for (int i = n; i >= 1; i--) { 
      suf[i] = min(suf[i], suf[i + 1]);
    }
    for (int i = 1; i <= n; i++) {
      pre[i] = min(pre[i], pre[i - 1]);
      int res = min(pre[i] + i, suf[i] - i);
      cout << res << ' ';
    } cout << '\n';
  }	
  return 0;
} //Hajimemashite

