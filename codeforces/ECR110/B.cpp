
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
    vector<int> a, tmp;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (~x&1) a.push_back(x);
      else tmp.push_back(x);
    }
    for (int i : tmp) {
      a.push_back(i);
    }
    int count = 0, maxi = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (__gcd(a[i], 2 * a[j]) > 1) count++;
      }
    }

    cout << max(count, maxi) << '\n';
  }	
  return 0;
} //Hajimemashite

