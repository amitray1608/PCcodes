
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
    int sum = accumulate(a.begin(), a.end(), 0);
    int res = 0;
    if (sum % n != 0) {
      res = -1;
    } else {
      int left = sum / n;
      int rem = 0;
      int count = 0;
      vector<int> x;
      for (int i : a) {
        if (i > left)
          x.push_back(i - left);
        if (i < left)
          rem += left - i;
      }
      for (int i : x) {
        if (count >= rem) 
          break;
        res++;
        count += i;
      }
    }
    cout << res << '\n';
  }	
  return 0;
} //Hajimemashite

