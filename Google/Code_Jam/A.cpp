
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &i : a) cin >> i;
  vector<int> b = a;
  sort(b.begin(), b.end());
  int maxi = 0;
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
//    for (int ii : a) {
//      cout << ii << ' ';
//    }
//    cout << '\n';
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
    cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


