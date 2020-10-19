//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
const ll INF = 1e16;

vector<ll> a;
ll n, k;
bool check(ll x) {
  ll maxi = 0;
  for(ll i = 0 ; i < n; i++) {
    if(a[i] <= x) continue;
    maxi += (a[i]+ x -1)/x;
    maxi--;
  }
  return maxi <= k;
}

void solve() {
  cin >> n >> k;
  ll l = 1, h = INF;
  a = vector<ll> (n);
  for(ll &i : a) cin >> i;
  ll count = 0;
  while(l <= h) {
    ll mid = (l+h)/2;
    if(check(mid)) {
      count = mid;
      h = mid-1;
    } else {
      l = mid+1;
    }
  }
  cout << count << endl;
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