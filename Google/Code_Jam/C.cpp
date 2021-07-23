
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, c;
  cin >> n >> c;
  vector<int> a(n);
  iota(a.begin(), a.end(), 1);
  vector<int> b = a;
  vector<int> B = a;
  sort(b.begin(), b.end());
  do {
    int maxi = 0;
    a = B;
    for (int i = 0; i < n - 1; i++) {
      int pos = i;
      if (a[i] != b[i]) {
        for (int j = i + 1; j < n; j++) {
          if (a[j] == b[i]) {
            pos = j;
          }
        }
      }
      maxi += pos - i + 1;
      reverse(a.begin() + i, a.begin() + pos + 1);
    }
    if (maxi == c) {
      for (int i : B)
        cout << i << ' ';
      cout << '\n';
      return;
    }
  } while (next_permutation(B.begin(), B.end()));
  cout << "IMPOSSIBLE" << '\n'; 
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


