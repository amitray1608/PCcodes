
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
    vector<int> a(n);
    for(int &i : a) {
      cin >> i;
    }
    long long res = 0;
    map<int, set<int>> pos;
    for (int i = 0; i < n; i++) {
      pos[a[i]].insert(i);
    }
    for (auto i : pos) {
      vector<int> p(i.second.begin(), i.second.end());
      vector<int> ind;
      int N = (int)p.size();
      for (int j : p) {
        ind.push_back(n - j);
      }
      for (int j = N - 2; j >= 0; j--) {
        ind[j] += ind[j + 1];
      }
      for (int j = 0; j < N - 1; j++) {
        res += (p[j] + 1) * (ind[j + 1]);
      }
    }
    cout << res << '\n';
  }	
  return 0;
} //Hajimemashite

