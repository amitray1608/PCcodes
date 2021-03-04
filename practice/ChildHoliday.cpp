#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef double dd;
const int MOD = 1e9 + 7;

void solve(){
  ll m, n;
  cin >> m >> n;
  vector<array<ll, 3>>a(n);
  for(auto &i : a)
    cin >> i[0] >> i[1] >> i[2];
  vector<ll>ans(n, 0);

  auto check = [&](ll x) {
    ll count = 0, j = 0;
    vector<ll> res(n, 0);
    for(auto &i : a) {
      ll t, z, y;
      ll tmp = x;
      t = i[0], z = i[1], y = i[2];
      ll done = tmp / (t * z + y) * z + min(z, (tmp % (t * z + y) ) / t);
      count += done;
      res[j++] = done;
    }
    if (count >= m) {
      for (int i = 0; i < n; i++) {
        ans[i] = res[i];
      }
      return true;
    } return false;
  };

  ll l = 0, h = 1e10, res = 0;
  while(l <= h) {
    ll mid = l + (h - l) / 2;
    if (check(mid)) 
      h = mid - 1, res = mid;
    else 
      l = mid + 1;
  }
  cout << res << endl;
  for(auto &i : ans)
    cout << i << ' ';
  cout << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
