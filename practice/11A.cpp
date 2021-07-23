
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, d;
  cin >> n >> d;
  vector<int> a(n);
  for (int &i : a) cin >> i;
  int count = 0;
  for (int i = 1; i < n; i++) {
    if (a[i - 1] >= a[i]) {
      int res = a[i - 1] - a[i] + 1;
      int x = (res + (d - 1)) / d;
      a[i] += x * d;
      count += x;
    }
  }
  cout << count << '\n';
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


