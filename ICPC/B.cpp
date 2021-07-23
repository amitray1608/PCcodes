
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b;
  for (int &i : a) 
    cin >> i;
  b = a;
  sort (a.begin(), a.end());
  int k = 0;
  bool sorted = true;
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i])
      sorted = false, k++;
    mp[a[i]]++;
  }
  bool ok = false;
  if (sorted) {
    for (auto i : mp) {
      if (i.second >= 2) 
        ok = true;
    }
  } else {
    if (k == 2) ok = true;
    else ok = false;
  }
  cout << (ok ? "YES" : "NO") << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


