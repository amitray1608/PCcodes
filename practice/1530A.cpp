
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
    int maxi = 0;
    for (char c : s) {
      maxi = max(maxi, (int)c - '0');
    }
    cout << maxi << '\n';
  }
  return 0;
} //Hajimemashite

