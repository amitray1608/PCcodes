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
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for(auto &i : a) cin >> i.first >> i.second;
    
  auto check = [&](double x) {
    double aa = -1e18, bb = 1e18;
    for(int i = 0; i < n; i++) {
      aa = max(aa, a[i].first - x * a[i].second);
      bb = min(bb, a[i].first + x * a[i].second);
    }
    return aa <= bb;
  };
  double l = -1e18, h = 1e18;
  for(int i = 0; i < 100; i++) {
    double mid = (l+h)/2;
    if(check(mid))
      h = mid;
    else
      l = mid;
  }
  cout << h << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  // cin >> t;
  for(int tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  