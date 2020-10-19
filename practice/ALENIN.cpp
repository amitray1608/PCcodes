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
  int n, d;
  cin >> n >> d;
  vector<double> c(n);
  for(double &i : c) cin >> i;
  sort(c.begin(), c.end());
  auto check = [&](double x) {
    double  curr = 0;
    for(int i = 0; i < n; i++) {
      if(c[i]+d < curr) return false;   
      else curr = max(c[i], curr) + x;
    }
    return true;
  };
  double l = 0, h = 1e9;
  for(int i = 0; i < 100; i++) {
    double mid = (l+h)/2.0;
    // deb(mid);
    check(mid) ? l = mid : h = mid;
  }
  cout << l << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  cin >> t;
  for(int tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  