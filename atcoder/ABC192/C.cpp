#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  auto inc = [&](int x) {
    string s = to_string(x);
    sort(s.begin(), s.end());
    int newx;
    stringstream st(s);
    st >> newx;
    return newx;
  };
  auto dec = [&](int x) {
    string s = to_string(x);
    sort(s.rbegin(), s.rend());
    int newx;
    stringstream st(s);
    st >> newx;
    return newx;
  };

  for (int i = 0; i < k; i++) {
    int d = dec(n);
    int in = inc(n);
    n = d - in;
  }
  cout << n << '\n';   
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


