
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n; cin >> n;
  vector<int> a(n), b(n), c(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  vector<int> p(n, 0);
  p[0] = a[0];
  for (int i = 1; i < n; i++) {
    if (p[i - 1] != a[i] and a[i] != p[i + 1])
      p[i] = a[i];
    else if (p[i - 1] != b[i] and b[i] != p[i + 1])
      p[i] = b[i];
    else 
      p[i] = c[i];
  }
  for (int i  = 0; i < n; i++) {
    cout << p[i] << ' ';
  }
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


