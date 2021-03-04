#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (int &i : a) cin >> i;
  for (int &i : b) cin >> i;
  vector<int> c(m, 0);
  int i = 0, j = 0;
  int count = 0;
  while (i < n and j < m) {
    if (a[i] < b[j]) count++, i++;
    else c[j] = count, j++;
  }
  while (j < m) c[j++] = count;
  for (int ii : c) cout << ii << ' ';
  cout << '\n';
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


