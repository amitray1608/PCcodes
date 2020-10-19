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
  for(int i = 0; i < n; i++) cin >> a[i];
  auto  check  = [&](int m) {
    int count = 1, next = a[0];
    for(int i = 1; i < n; i++) {
      if(next + m <= a[i]) {
        count++;
        next = a[i];
      }
    }
    return (count >= k);
  };
  int l = 1, h = *max_element(a.begin(), a.end()), ans = 0;
  while(l <= h) {
    int mid = l+(h-l) / 2;
    // deb(mid);
    if(check(mid)) {
      ans = max(mid, ans);
      l = mid + 1;
    } else {
      h = mid - 1;
    }
  }
  cout << ans << endl;
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