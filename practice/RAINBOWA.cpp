
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &i : a) 
    cin >> i;

  bool ok = true;
  vector<int> res;
  res.push_back(a[0]);
  for (int i = 0; i < n; i++) {
    if (a[i] != a[n - i - 1]) 
      ok = false;
    if (i and res.back() != a[i]) 
      res.push_back(a[i]);
  }
  for (int i = 0; i < 7; i++) 
    if (res[i] != i + 1) 
      ok = false;
  cout << (ok ? "yes" : "no") << '\n';
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


