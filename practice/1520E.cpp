
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
    string s;
    cin >> s;
    int fir = -1, sec = -1, star = 0;
    vector<int> pos;
    for (int i = 0; i < n; i++) {
      if (s[i] == '*') pos.push_back(i);
    }
    auto get = [&](int x) {
      int count = 0;
      int p = x - 1, curr = x - 1;
      while (p >= 0) {
        if (s[p] == '*') {
          count += curr - p;
          curr--;
        }
        p--;
      }
      p = x + 1, curr = x + 1;
      while (p < n) {
        if (s[p] == '*') {
          count += p - curr;
          curr++;
        }
        p++;
      }
      return count;
    };
    int sz = pos.size();
    if (sz == 0 or sz == n) {
      cout << 0 << '\n';
    } else if (sz & 1) {
     cout << get(pos[sz / 2]) << '\n'; 
    } else {
      cout << min(get(pos[sz / 2]), get(pos[sz / 2 - 1])) << '\n';
    }
  }	
  return 0;
} //Hajimemashite

