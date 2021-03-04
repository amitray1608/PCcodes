
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (int &i : a) cin >> i;
  for (int &i : b) cin >> i;
  vector<int> c;
  int i = 0, j = 0;
  while (i < n and j < m) {
    if (a[i] < b[j]) c.push_back(a[i++]);
    else c.push_back(b[j++]);
  }
  while (i < n) c.push_back(a[i++]);
  while (j < m) c.push_back(b[j++]);
  for (auto ii : c) cout << ii << ' ';
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


