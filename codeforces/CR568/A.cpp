
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  for (int tt = 1; tt <= t; ++tt) {
    ll a[3], d;
    cin >> a[0] >> a[1] >> a[2] >> d;
    sort(a, a + 3);
    ll ans = 0;
    if (abs(a[0] - a[1]) < d) {
      ans = d - abs(a[0] - a[1]);
    } 
    if (abs(a[1] - a[2]) < d) {
      ans += d - abs(a[1] - a[2]);
    }
    cout << ans << '\n';
  }	
  return 0;
} //Hajimemashite

