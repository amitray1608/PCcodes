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
    ll count = 0, idx = 0;
    for(auto &i : a) {
      ll l = 0, h = m, tmp = 0;
      while(l <= h) {
        ll mid = l + (h-l)/2;
        ll maxi = (ceil)(mid/i[1]) * i[0] + (((ceil(mid/i[1])) - 1) * i[2]);
        (maxi <= x) ? l = mid + 1 : h = mid - 1;
      }
      ans[idx++] = l;
      count += l;
      if(count >= m) break;
    }
    return (count >= m); 
  };

  ll l = 0, h = 1e8;
  while(l <= h) {
    ll mid = l + (h-l)/2;
    cout << mid << endl;
    (check(mid)) ? h = mid - 1 :  l = mid + 1;
  }
  cout << l << endl;
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
