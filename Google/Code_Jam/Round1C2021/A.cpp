
#include <bits/stdc++.h>

using namespace std;
#define int int64_t
#define deb(x) cout << #x << " = " << x << endl;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<double> a;
  for (int i = 0; i < n; i++) {
    double x;
    cin >> x;
    a.push_back(x);
  }
  sort(a.begin(), a.end());
  vector<double> d;
  double res = 0;
  for (int i = 0; i <= n; i++) {
    if (i == n and k - a[i] > 0) {
      d.push_back(k - a[n - 1]);
    } else if (i == 0 and a[i] - 1 > 0) {
      d.push_back(a[i] - 1);
    } else if (i > 0 and i < n and (a[i] - a[i - 1] - 1) > 0) {
      d.push_back((a[i] - a[i - 1]) / 2);
    }
  }
  sort(d.rbegin(), d.rend());
  int siz = (long long)d.size();
  int x = 2;
  siz = min(x, siz);
  for (int i = 0; i < siz; i++) {
    res += d[i];
  }
  res /= (k * 1.0);
  cout << fixed << setprecision(12);
  cout << res << '\n';
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


