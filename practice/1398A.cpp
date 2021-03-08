
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &i : a) cin >> i;
  for (int i = 0; i <= n - 3; i++) {
    int sum = a[i] + a[i + 1];
    if (a[n - 1] >= sum) {
      cout << i + 1 << ' ' << i + 2 << ' ' << n << '\n';
      return;
    }
  }
  cout << -1 << '\n';
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


