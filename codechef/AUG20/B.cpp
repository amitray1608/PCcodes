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
  ll a[n];
  for(ll &i : a) cin >> i;
  ll mini = INT_MAX, ans = -1;
  for(int i = 0; i < n; i++) {
    if(a[i] > k) continue;
    ll x = k - a[i];
    if(x % a[i] == 0) {
      x /= a[i];
      if(x < mini) {
        mini = x;
        ans = a[i];
      }
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
  cin >> t;
  for(int tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  