
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), f(m, 0);
  for (int &i : a) {
    cin >> i;
    f[i % m]++;
  }
  int count = (f[0] > 0);
  for (int i = 1; i <= m/2; i++) {
    if (i * 2 == m and f[i]) {
      count++;
    } else {
      if (f[i] and f[m - i]) {
        int curr = min(f[i], f[m - i]);
        int kurr = max(f[i], f[m - i]);
        count++;
        if (kurr - curr > 1) {
          count += kurr - curr - 1;
        }
      } else {
        count += f[i] + f[m - i];
      }
    }
  }
  cout << count << '\n';
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


