#include <bits/stdc++.h>

using namespace std;

void solve() {
  long long n, ans = 0;
  cin >> n;
  for (long long i = 1; i * i <= 2 * n; i++) {
    if ((2 * n) % i == 0) {
      if (((2 * n / i) - i + 1) % 2 == 0) 
        ans ++;
      if (i * i != 2 * n and (i - (2 * n / i) + 1) % 2 == 0) 
        ans++;
    }
  }
  cout << ans << '\n';
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


