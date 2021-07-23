

#include<bits/stdc++.h>

using namespace std;
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    string s;
    cin >> s;
    int n = (int)s.size();
    int l = 0, r = 0;
    int count = 0;
    int pos[2];
    pos[0] = pos[1] = -1;
      cout << "ok" << '\n';
    while (l < n) {
      cout << "ok" << '\n';
      while (r < n) {
        if (s[r] != '?' and l > max(pos[0], pos[1])) {
          if (s[r] == '0') pos[0] = r;
          else pos[1] = r;
        } else if (s[r] == '0' and pos[1] >= l and pos[1]&1 != r&1) {
          pos[0] = r++;
        } else if (s[r] == '0' and pos[0] >= l and pos[0]&1 == r&1) {
          pos[0] = r++;
        } else if (s[r] == '1' and pos[1] >= l and pos[1]&1 == r&1) {
          pos[1] = r++;
        } else if (s[r] == '1' and pos[0] >= l and pos[0]&1 != r&1) {
          pos[1] = r++;
        } else if (s[r] == '?') r++;
        else break;    
      }
      count += r - l;
      l++;
    }
    cout << count << '\n';
  }	

  return 0;
} //Hajimemashite


