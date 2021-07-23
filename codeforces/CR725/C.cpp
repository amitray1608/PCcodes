
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n, L, R;
    cin >> n >> L >> R;
    vector<int> a(n);
    for (int &i : a) {
      cin >> i;
    }
    sort(a.begin(), a.end());
    int res = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] < R) {
        auto start = a.begin() + i + 1;
        int x = L - a[i];
        auto left = lower_bound(start, a.end(), x);
        x = R - a[i];
        auto right = upper_bound(start, a.end(), x);
        right--;
        int l = left - a.begin();
        int r = right - a.begin();
        if (left != a.end() and right != a.end()) {
          if (l <= r) res += r - l + 1;
        }
      } else {
        break;
      }
    }
    cout << res << '\n';
  }	
  return 0;
} //Hajimemashite

