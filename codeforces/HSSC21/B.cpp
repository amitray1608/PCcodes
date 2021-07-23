
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
    bool ok = false;
    for (int i = 0; i < n; i++){
      if (s[i] == ss[0]) {
        int j = i;
        int k = 0;
        int count = 0;
        for (; j < n and k < m and s[j] == ss[k]; ) 
          j++, k++, count++;
        j = j - 2;
        for (; j >= 0 and k < m and s[j] == ss[k]; )
          j--, k++, count++;
        if (count == m) {
          ok = true;
          break;
        }
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }	
  return 0;
} //Hajimemashite

