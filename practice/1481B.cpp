#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  auto check = [&]() {
    for (int i = 0; i < n - 1; i++) {
      if (a[i + 1] > a[i]) return true;
    }
    return false;
  };
  while (check()) {
    int pos = 0;
    while (a[pos] >= a[pos + 1]) pos++;
    ++a[pos];
    if (k == 1) {
      cout << pos +1 << '\n';
      return;
    }
    k--;
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


