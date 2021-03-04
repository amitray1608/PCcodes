#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  array<int, 3> f;
  f[0] = f[1] = f[2] = 0;
  for (int &i : a) cin >> i, f[i % 3]++;
  int cub = n / 3, res = 0;
  if (f[0] >= cub) {
    res += f[0] - cub;
    f[1] = f[1] + f[0] - cub;
    if (f[1] >= f[2]) res += f[1] - cub;
    else res += (f[2] - cub) * 2;
  } else {
    res += cub - f[0];
    f[2] = f[2] - res;
    if (f[1] >= f[2]) res += f[1] - cub;
    else res += (f[2] - cub) * 2;
  }
  cout << res << '\n';
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


