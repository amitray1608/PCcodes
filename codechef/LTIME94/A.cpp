
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    ll a, y, x;
    cin >> a >> y >> x;
    ll res = 0;
    if (a >= y) {
      int s = (a - y + 1);
      res = s * x;
    } else {
      res = a * x;
    }
    cout << res << '\n';
  }
  return 0;
} //Hajimemashite

