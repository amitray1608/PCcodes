#include<bits/stdc++.h>

using namespace std;
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n;
    cin >> n;
    auto check = [&](int N) {
      int k = sqrtl(n / 2);
      int j = sqrtl(n / 4);
      if (~n & 1 and k * k == n / 2) return true;
      else if (n % 4 == 0 and j * j == n / 4) return true;
      return false;
    };
    bool ok = (check(n));
    cout << (ok ? "YES" : "NO") << '\n';
  }	
  return 0;
} //Hajimemashite
