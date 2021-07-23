
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
    for (int &i : a) {
      cin >> i;
    }
    vector<int> pre(n, 0);
    vector<int> suf(n, 0);
    for (int i = 1; i < n; i++) {
      pre[i] = pre[i - 1];
      if (a[i] <= a[i - 1]) {
        pre[i] += (a[i - 1] + 1 - a[i]);
      }
    }
    for (int i = n - 2; i >= 0; i--) {
      suf[i] = suf[i + 1];
      if (a[i] <= a[i + 1]) {
        suf[i] += a[i + 1] + 1 - a[i];
      }
    }
    int mini = 1e18;
    for (int i = 1; i < n - 2; i++) {
      mini = min(mini, pre[i] + suf[i + 1]);
    }
    cout << mini << '\n';
  }	
  return 0;
} //Hajimemashite

