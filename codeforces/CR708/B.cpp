
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), f(m + 1, 0);
  for (int &i : a) {
    cin >> i;
    f[i % m]++;
  }
  int maxi = 0;
  for (int i = 0; i <= m / 2; i++) {
    int curr = min(f[i], f[m - i]);
    int kurr = max(f[i], f[m - i]);
    if (!i) {
      maxi = f[i] > 0;
    } else if (i == m / 2 and f[i]) {
      maxi++; 
    } else if (f[i] and f[m - i]) {
      maxi++;
      if (kurr - curr > 1)
        maxi += (kurr - curr - 1);
    } else {
      maxi += f[i] + f[m - i];
    }
  }
  cout << maxi << '\n';
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


