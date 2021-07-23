
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    string s;
    cin >> s;
    int n = (int)s.size();
    int start = 0, ends = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'a') {
        start = i;
        ends = i + 1;
        break;
      }
    }
    bool ok = true;
    int curr = 0;
    while (start >= 0 or ends < n) {
      if (start >= 0 and s[start] - 'a' == curr) start--, curr++;
      else if (ends < n and s[ends] - 'a' == curr) ends++, curr++;
      else {
        ok = false;
        break;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }	
  return 0;
} //Hajimemashite

