//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve() {
  double c;
  cin >> c;
  auto check = [&](double x) {
    if(((x*x) +  sqrt(x)) >= c)
      return true;
    return false;
 
  };
  double l = 1.0, r = 10e18, ans = 0;
  for(int i = 0; i < 100; i++) {
    double mid = (l+r)/2.0;
    if(check(mid)) {
        ans = mid;
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(20);
  int t = 1;
  // cin >> t;
  for(int tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  