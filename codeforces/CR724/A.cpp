
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
    vector<int> a;
    map<int, int> mp;
    bool neg = false;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      neg |= (x < 0);
      a.push_back(x);
      mp[x] = 1;
    }
    if (neg) {
      cout << "NO" << '\n';
      continue;
    }
    bool ok = true;
    while (true) {
      ok = true;
      n = a.size();
      for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          int val = abs(a[i] - a[j]);
          if (mp.find(val) != mp.end()) continue;
          mp[val] = 1;
          ok = false;
        }
      }
      if (ok) break;
      if (mp.size() > 300) {
        break;
      }
      a.clear();
      for (auto i : mp)
        a.push_back(i.first);
    }
    cout << "YES" << '\n';
    cout << n << '\n';
    for (int i : a) {
      cout << i << ' ';
    }
    cout << '\n';
  }	
  return 0;
} //Hajimemashite

