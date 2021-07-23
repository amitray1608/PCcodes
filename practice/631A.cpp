
#include <bits/stdc++.h>

using namespace std;
#define int int64_t

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &i : a) 
    cin >> i;
  vector<int> b(n);
  for (int &i : b) 
    cin >> i;
  int maxi = 0;
  vector<int> prea(n), preb(n);
  for (int i = 0; i < n; i++) {
    if (!i) prea[i] = a[i];
    else prea[i] = (prea[i - 1] | a[i]);
    
    if (!i) preb[i] = b[i];
    else preb[i] = (preb[i - 1] | b[i]);
  }
  for (int i = 0; i < n; i++) {
    maxi = max(maxi, prea[i] + preb[i]);
    for (int j = i + 1; j < n; j++) {
      int sum = prea[i] - (!i ? 0 : prea[i - 1]);
      sum += preb[i] - (!i ? 0 : preb[i - 1]);
      maxi = max(maxi, prea[i] - (i == 0 ? 0 : prea[i - 1])); 
    
    }
  }
  cout << maxi << '\n';
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  //cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


