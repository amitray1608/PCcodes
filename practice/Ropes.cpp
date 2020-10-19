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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for(int &i : a) cin >> i;
  auto check = [&](double x) {
    int count = 0;
    for(int i = 0; i < n; i++) {
      count += floor(a[i] / x);
    }
    return (count >= k);
  };
  double l = 0, r = 1e8;
  for(int i = 0; i < 100; i++) {
    double mid = (r+l)/2;
    if(check(mid))
      l = mid;
    else
      r = mid;
  }
  cout << l << endl;
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