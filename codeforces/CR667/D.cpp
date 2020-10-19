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
  ll n, s; 
  cin >> n >> s;
  ll r = n, d = 0, count = 0, x = 0;;
  while(r > 0){
    count++;
    d += r % 10;
    r /= 10;
  }
  if(d <= s){
    cout << x << endl;
  } else {
    deb(d);
    ll c = 10;
    x = (ll)pow(c, count);
    deb(x);
    deb(n);
    deb(x-n);
    ll ans = x-n;
    cout << ans << endl;
  }
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