
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n;
    cin >> n;
    string s, res = "";
    cin >> s;
    bool ok = true;
    map<char, bool> mp;
    for (char c : s) {
      if (res.back() == c) continue;
      if (mp[c] == true) {
        ok = false;
        break;
      }
      mp[c] = true;
      res.push_back(c);
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }	
  return 0;
} //Hajimemashite

