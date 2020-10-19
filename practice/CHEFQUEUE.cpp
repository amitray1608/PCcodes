//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
vector<int> a(siz), f(siz);
const int INF = 1000000000;

int get(int x) {
  int res = INF;
  while(x > 0) {
    res = min(res, f[x]);
    x = (x & (x+1)) -1;
  }
  return res;
}

void upd(int x, int d) {
  while(x <= 1e6) {
    f[x] = min(f[x], d);
    x = x | (x+1);
  }
}

void solve() {
  int n, k;
  cin >> n >> k;
  for(int i = 1; i <= n; i++) 
    cin >> a[i];
  fill(f.begin(), f.end(), INF);
  ll ans = 1;
  for(int i = n; i >= 1; i--) {
    int v = get(a[i]-1);
    upd(a[i], i);
    if(v == INF)
      continue;
    ll x = v-i+1;
    ans = (ans*x)%MOD;
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