
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n;
    cin >> n;
    int N = n + 2, total  = 0;
    map<int, int> mp;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
      cin >> a[i];
      mp[a[i]]++;
      total += a[i];
    }
    auto check = [&]() {
      for (int i = 0; i < N; i++) {
        mp[a[i]]--;
        total -= a[i];
        if (~total & 1 and mp.find(total >> 1) != mp.end()) {
          if (mp[total >> 1] > 0) {
            mp[total >> 1]--;
            return true;
          }
        }
        mp[a[i]]++;
        total += a[i];
      }
      return false;
    };
    bool ok = check();
    if (ok) {
      for (auto i : mp) {
        for (int j = 0; j < i.second; j++)
          cout << i.first << ' ';
      } cout << '\n';
    } else {
      cout << -1 << '\n';
    }
  }
  return 0;
} //Hajimemashite

