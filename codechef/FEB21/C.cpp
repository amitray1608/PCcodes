#include <bits/stdc++.h>

using namespace std;
#define deb(x) cout << #x << " = " << x << endl;

void solve() {
  int n;
  cin >> n;
  vector<array<int, 3>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i][0];
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i][1];
  }
  for (int i = 0; i < n; i++) {
    a[i][2] = i;
  }
  int count = 0, k = 0;
  while (k++ < 10) {
    for (int i = 0; i < n; i++) {
      int pos = 0;
      bool ok = false;
      for (int j = 0; j < n; j++) {
        if (i == j) continue;
        if (a[i][0] > a[j][0]) {
          if (a[i][2] <= a[j][2]) {
            pos = j;
            ok = true;
          }
        }
      }
      if (!ok) continue;
      int dist = a[pos][2] - a[i][2] + 1;
      int x = (dist) / a[i][1] + (dist % a[i][1] != 0);
      count += x;
      a[i][2] += (a[i][1] * x);
    }
  }
  cout << count << '\n';
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


