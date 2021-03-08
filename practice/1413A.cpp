
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n / 2; i++) {
    int x = a[i].first, y = a[n - i - 1].first;
    if (abs(y) % abs(x) != 0) {
     a[i].first = abs(y);
     a[n - i - 1].first = abs(x);
    } else {
     a[i].first = abs(y) / abs(x);
      a[n - i - 1].first = 1;
    }
    if (y < 0) {
      if (x < 0) {
        a[i].first *= -1;
      }
    } else {
      if (x > 0) 
        a[i].first *= -1;
    }
  }
  sort (a.begin(), a.end(), 
      [](const pair<int, int> x, const pair<int, int> y) {
        return x.second < y.second;
      });
  for (int i = 0; i < n; i++) {
    cout << a[i].first << ' ';
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


