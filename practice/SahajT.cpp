
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int T = 1;
  cin >> T;
  for (int tt = 1; tt <= T; ++tt) {
    vector<int> f(26, 0), h(26, 0);
    string s, ss; 
    cin >> s >> ss;
    for(auto c : s) {
      f[c - 'A']++;
    }
    for(auto c : ss) {
      h[c - 'A']++;
    }
    bool ok = true;
    for(int i = 0; i < 26; ++i) {
      if(h[i] and !f[i]) {
        ok = false;
        break;
      }
    }
    vector<int> fx, fy;
    for(int i = 0; i < 26; ++i) {
      if(f[i]) {
        fx.push_back(f[i]);
        fy.push_back(h[i]);
      }
    }
    sort(fx.begin(), fx.end());
    sort(fy.begin(), fy.end());
    if(fx != fy) {
      ok = false;
    }
    vector<int> mp(26, 0);
    for(int i = 0; i < 26; ++i) {
      if(f[i]) {
        mp[f[i]]++;
      }
    }
    for(int i = 0; i < 26; ++i) {
      if(f[i]) {
        if(h[i] == f[i] and mp[f[i]] == 1) {
          ok = false;
          break;
        }
      }
    }
    cout << (ok ? "Agent" : "Spy") << '\n';  
  } 	
  return 0;
} 

