#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<string> s(n);
  for (auto &i : s) cin >> i;
  bool ok = true, status = false;
  for (auto i : s) {
    if (status == false) {
      if (i == "start") {
        status = true;
      } else if (i == "restart") {
        status = true;
      } else {
        ok = false;
        break;
      }
    } else {
      if (i == "stop") 
        status = false;
    }
  }
  cout << (ok ? "200" : "404") << '\n';
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


