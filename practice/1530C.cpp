
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
    vector<int> a(n), b(n);
    int suma = 0, sumb = 0;
    for (int i = 0; i < n; i++) {
      int x; cin >> x;
      a.push_back(x);
    }

    for (int i = 0; i < n; i++) {
      int x; cin >> x;
      sumb += x;
      b.push_back(x);
    }
    sort(a.begin(), a.end());
    for (int i = 1; i < n; i++) {
      a[i] += a[i - 1];
    }
    
    auto check = [&](int x) {
      int k = (n + x);
      k -= k / 4;
      suma = 0;
      
      return suma >= sumb;
    };

    int l = 0, r = 1e5;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (check(mid)) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    cout << l << '\n';
  }	
  return 0;
} //Hajimemashite

