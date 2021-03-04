
#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e6 + 1;

void solve() {
  int n, q, m;
  cin >> n >> q >> m;
  vector<int> a(n), res(maxn, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int count = 0;
  map<array<int, 2>, int> check;
  
  auto update = [&](int l, int r) {
    if (a[l] > m) return false;
    res[a[l]]++, res[m + 1]--;
    if (a[l] <= m and a[r] > m) 
      return false;
    array<int, 2> x = {a[l], a[r]};
    check[x] += 1;
    return true;
  };
  
  auto multiple = [&]() {
    for (auto ii : check) {
      array<int, 2> t = ii.first;
      res[t[1] + t[0]]--;
      res[t[1] + 2 * t[0]]++;
      int i = t[1] + 2 * t[0];
      for (;i + t[0] <= m;) {
        i += t[1];
        res[i]--;
        res[i + t[0]]++;
        i += t[0];
      }
    }
  }; 

  while (q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    update(l, r);
  }
  multiple();
  for (int i = 1; i <= m; i++) {
    res[i] += res[i - 1];
    count = max(count, res[i]);
  } 
  cout << count << '\n'; 
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


