
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
    string ss;
    cin >> ss;
    int n = (int)s.size();
    int m = (int)ss.size();
    reverse(s.begin(), s.end());
    reverse(ss.begin(), ss.end());
    int i = 0, j = 0;
    while (i < n) {
      if (j == m) break;
      if (s[i] == ss[j]) j++;
      else i++;
      i++;
    }
    cout << (j == m ? "YES" : "NO") << '\n';
  }	
  return 0;
} //Hajimemashite

