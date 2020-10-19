#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll ans = (b*d);
    ans = max(ans, b*c);
    ans = max(ans, a*c);
    ans = max(ans, b*d);
    ans = max(ans, a*d);
    cout << ans ;
  return 0;
}
