
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
    int countD = 0, countK = 0;
    int res[n], curr = 1;
    for (int i = 0; i < n; i++) {
      res[i] = 1;
    }
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
      (s[i] == 'K' ? countK++ : countD++);
      int com = __gcd(countK, countD);
      if (com > 1) {
        int currD = countD / com;
        int currK = countK / com;
        com--;
        int have = ((currD * com) * n) + (currK * com);
        if (mp.find(have) != mp.end()) 
          res[i] = mp[have] + 1;
      }
      mp[(countD * n) + countK] = res[i];
    }
    for (int i = 0; i < n; i++) {
      cout << res[i] << ' ';
    } cout << '\n';
  }	
  return 0;
} //Hajimemashite


