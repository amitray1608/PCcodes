#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long;

void solve() {
  ll x, y;
  cin >> x >> y;
  if(x >= y) {
    cout << x - y << '\n';
  } else {
    ll count = 0, pre = x, maxi = x;
    while(x < y) {
      x = x * 2;
      pre = x;
      count++;
    }
    maxi = x * 2;
    ll count2 = count + 1;
    cout << min((maxi - y) + count2, count + (y - pre)) << '\n';
  }
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

