#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  int res = (n - k) + (k / 2);
  cout << res << '\n';
  int fir = k / 2, sec = k + 1;
  for (int curr = k - fir; curr < k; curr++) 
    cout << curr << ' ';
  for (int curr = sec; curr <= n; curr++)
    cout << curr << ' ';
  if (res)
    cout << '\n';
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

