
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<string> s(n);
  for (auto &i : s) {
    cin >> i;
  }
  int count = 0;
  for (int i = 1; i < n; i++) {
    ll sx = s[i].size();
    ll sy = s[i - 1].size();
    ll x = stol(s[i]);
    ll y = stol(s[i - 1]);
    if (y < x) {
      continue;
    } else {
      bool ok = false;
      ll pos = -1;
      ll mini = min(sx, sy);
      ll maxi = max(sx, sy);
      ll j = 0;
      int isGreater = 0;
      while (j < mini) {
        if (s[i][j] < s[i - 1][j]) {
          ok = true;
        } 
        if (s[i][j] > s[i - 1][j]) {
          isGreater++;
        }
        j++;
      }
      if (ok) {
        while (mini < maxi + 1) {
          s[i] += '0';
          count++;
          mini++;
        }
        continue;
      }
      j = 0;
      while (mini < maxi) {
        s[i] += s[i - 1][mini];
        if (s[i - 1][mini] < '9') {
          ok = true;
          pos = mini;
        }
        count++;
        mini++;
      }
      if (ok or isGreater) {
        s[i][pos]++;
      } else {
        count++;
        s[i] += '0';
      }
    }
  }
  for (int i = 0; i < n; i++) {
     cout << s[i] << '\n';
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
    cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


