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
  ll a, b, x, y, n;
  cin >> a >> b >> x >> y >> n;
  ll da = a-x, db = b-y, res;
  ll N = max((ll)0, n-da), A = a - min(n, da), B = b;
  if(N)
    B = b - min(N, db);
  res = (B*A);
  N = max((ll)0, n-db);
  B = b - min(n, db);
  A = a;
  if(N)
      A = a - min(N, da);
  res = min(res, A*B);
  cout << res << endl;
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