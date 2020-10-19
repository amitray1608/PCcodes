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
  ll n;
  cin >> n;
  vector<ll> a(n);
  ll prod = 1;
  for(ll &i : a) cin >> i, prod *= i;
  ll gcd = 0;
  for(ll &i : a) {
    gcd = __gcd(i, gcd);
  }
  cout << "GCD : " << gcd << endl;
  cout << "LCM : " << prod/gcd << endl;
  cout << (int)pow(2, 31)%5 << endl;
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
