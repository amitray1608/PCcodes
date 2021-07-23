
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int k, n, m;
    cin >> k >> n >> m;
    vector<int> mo(n), po(m), res;
    for (int &i : mo) cin >> i;
    for (int &i : po) cin >> i;
    int M = 0, P = 0;
    bool ok = true;
    while (true) {
      if (res.size() >= n + m) break;
      if (mo[M] > k and po[P] > k) {
        ok = false;
        break;
      }
      if (M < n and !mo[M]) {
        res.push_back(mo[M]);
        if (!mo[M++]) k++;
      } else if (P < m and !po[P]) {
        res.push_back(po[P]);
        if (!po[P++]) k++;
      } else if (P < m and po[P] <= k) {
        res.push_back(po[P]);
        P++;
      } else if (M < n and mo[M] <= k) {
        res.push_back(mo[M]);
        M++;
      } else {
        ok = false;
        break;
      }
    }
    if (!ok) {
      cout << -1 << '\n';
    } else {
      for (int i : res) cout << i << ' ';
      cout << '\n';
    }
  }	
  return 0;
} //Hajimemashite

