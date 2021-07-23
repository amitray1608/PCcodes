
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    ll n, m;
    cin >> n >> m;
    auto check = [&](ll r) {
      ll res = n * n;
      ll f = floor(n / (double)r);
      ll fir = (n % r) * (f * f);
      ll c = ceil(n / (double)r);
      ll sec = ((r - (n % r)) * (c * c));
      res -= fir;
      res -= sec;
      res = (res / (double)2);
      return (res >= m);
    };
    ll l = 1, r = 1e10;
//    while (l <= r) {
//      ll mid = (l + r) / 2;
//      if (check(mid)) {
//        l = mid + 1;
//      } else {
//        r = mid - 1;
//      }
//    }
    for (int i = 1; i < 1000; i++) {
      if (check (i)) {
        cout << i << '\n';
        break;
      }
    }
//    cout << r << '\n';
  }	
  return 0;
} //Hajimemashite

