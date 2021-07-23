
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &i : a) cin >> i;
  bool ok = false;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[j] == a[i] or abs(a[i] - a[j]) > 2) continue;
      for (int k = j + 1; k < n; k++) {
        if (a[j] == a[k] or a[k] == a[i]) 
          continue;
        if (abs(a[i] - a[k]) > 2) continue;
        if (abs(a[j] - a[k]) > 2) continue;
        ok = true;
      }
    }
  } 
  cout << (ok ? "YES" : "NO") << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  //cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


