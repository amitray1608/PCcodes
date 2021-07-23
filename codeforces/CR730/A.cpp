
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int a, b;
    cin >> a >> b;
    if (a == b) {
      cout << 0 << ' ' << 0 << '\n';
      continue;
    }/*
    int gc = __gcd(a, b);
    if (abs(a - b) <= gc) {
      cout << gc << ' ' << 0 << '\n';
      continue;
    }
    */
    int fir = abs(a - b);
    a %= fir;
    b %= fir;
    int ka = fir - a;
    int kb = fir - b; 
    ka = min(a, ka);
    kb = min(b, kb);
    cout << fir << ' ' << max(ka, kb) << '\n';
  }
  return 0;
} //Hajimemashite

